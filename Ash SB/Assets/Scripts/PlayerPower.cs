using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class PlayerPower : MonoBehaviour
{

    public GameObject Power;
    public GameObject Player;
    public float PowerBar = 0.0f;
    public float PowerChargeMultiplier = 4.5f;
    public float PowerUseMultiplier = 12f;
    public float PowerActiveTime = 4.0f;
    public Slider powerUpSlider;

    // Use this for initialization
    void Start()
    {
        powerUpSlider.maxValue = 100;
    }

    // Update is called once per frame
    void Update()
    {
        powerUpSlider.value = PowerBar;
        if (Player.activeSelf == true)
        {
            PowerBar = PowerBar + (Time.deltaTime * PowerChargeMultiplier);

        }
        if (PowerBar >= 100)
        {
            PowerBar = 100f;
            PowerChargeMultiplier = 0f;

            if (PowerBar == 100f && Input.GetKeyDown(KeyCode.Space))
            {
                Power.SetActive(true);
                Debug.Log("Power Active");

            }

        }

        if (Power.activeSelf)
        {
            PowerBar = PowerBar - (Time.deltaTime * PowerUseMultiplier);
            Debug.Log("Take Away");
        }

        if (PowerBar <= 0)
        {
            Power.SetActive(false);
            PowerBar = 0.0f;
            PowerBar = PowerBar + (Time.deltaTime * PowerChargeMultiplier);
        }

    }
    
}
