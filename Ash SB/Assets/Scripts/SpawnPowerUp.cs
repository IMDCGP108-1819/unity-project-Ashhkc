using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnPowerUp : MonoBehaviour {

    public GameObject ScreamCharge;
    public Transform[] ItemSpawn;
    public float SpawnCountdown = 100.0f;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        SpawnCountdown = SpawnCountdown - (Time.deltaTime * Random.Range(2.5f, 7.5f));
        
        if(SpawnCountdown < 0)
        {
            Debug.Log("Power Up Spawned");
            SpawnCountdown = 0.0f;
            GameObject item = GameObject.Instantiate(ScreamCharge, ItemSpawn[Random.Range(0, ItemSpawn.Length)].position, transform.rotation);
            Destroy(item, 5);
            SpawnCountdown = 50.0f;

        }
		
	}
}
