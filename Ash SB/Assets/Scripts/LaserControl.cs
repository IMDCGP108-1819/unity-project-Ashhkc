using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class LaserControl : MonoBehaviour
{
    public Transform[] StartLocation;
    public Transform[] TargetLocations;
    public Vector3 TargetPosition;
    public LineRenderer LaserRenderer;
    public float LaserDistance;
    public float CastDistance;
    public float LaserLife;
    public float LaserScaleTime;
    public GameObject Player;
    public GameObject Power;

    Vector3 TargetPoint;
    Vector3 StartPoint;
    public string sceneToLoad;
    [Header("Duplication Parameters")]
    public float maxTimer;
    public float curTimer;
    public GameObject laserScriptHolder;
    public bool countDown = false;
    public int maxDupes = 5;
    public int curDupes;

    public PlayerPower playerPowerUp;

    // Use this for initialization
    void Start()
    {
        PickTarget();

        laserScriptHolder = this.gameObject;
        curTimer = maxTimer;
        curDupes++;
        countDown = true;

       playerPowerUp = Player.GetComponent<PlayerPower>();
    }

    // Update is called once per frame
    void Update()
    {

        if (countDown == true)
        {
            curTimer -= Time.deltaTime;
            if (curTimer <= 0)
            {
                NewLaser();
                curTimer = 15;
            }
        }
        if (curDupes == maxDupes)
        {
            countDown = false;
        }
        if (LaserRenderer.widthMultiplier > 0.9f && Player.activeSelf)
        {
            RaycastHit2D[] RayHit = Physics2D.CircleCastAll(StartPoint, 1.0f, (TargetPoint - StartPoint), CastDistance);

            Debug.Log("fire laser");

            if (RayHit.Length > 0)
            {
                if (!playerPowerUp.Power.activeSelf)
                {
                    Debug.Log("hit player with laser");
                    Player.SetActive(false);
                    StartCoroutine("RespawnThing");
                }
            }
        }

        if (Player.activeSelf == false)
        {
            LaserRenderer.enabled = false;
        }
        else
        {
            LaserRenderer.enabled = true;
        }

    }

    private IEnumerator RespawnThing()
    {
        yield return new WaitForSeconds(5);
        SceneManager.LoadScene(sceneToLoad);
    }

    private IEnumerator ScaleLaser()
    {
        yield return new WaitForSeconds(LaserScaleTime);

        LaserRenderer.widthMultiplier = 1.0f;
        Debug.DrawRay(StartPoint, (TargetPoint - StartPoint), Color.green, LaserLife);

        yield return new WaitForSeconds(LaserLife);

        PickTarget();
    }

    private void PickTarget()
    {

        LaserRenderer.widthMultiplier = 0.1f;
        TargetPoint = TargetLocations[Random.Range(0, TargetLocations.Length)].position;
        TargetPoint.z = 0.0f;

        StartPoint = StartLocation[Random.Range(0, StartLocation.Length)].position;
        StartPoint.z = 0.0f;
        TargetPosition = (TargetPoint - StartPoint) * LaserDistance;
        LaserRenderer.SetPositions(new Vector3[] { StartPoint, TargetPosition });

        StartCoroutine(ScaleLaser());
    }

    private void NewLaser()
    {
        Instantiate(laserScriptHolder, transform.position, transform.rotation);
        countDown = false;
        curDupes++;
        LaserScaleTime = LaserScaleTime + 0.5f;
    }
}