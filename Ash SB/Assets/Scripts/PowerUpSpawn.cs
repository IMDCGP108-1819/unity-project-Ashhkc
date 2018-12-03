using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerUpCooldown : MonoBehaviour {

    public GameObject ScreamCharge;
    public float SpawnCountdown = 100.0f;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        SpawnCountdown = SpawnCountdown - (Time.deltaTime * Random.Range(2.5f, 7.5f));
        
        if(SpawnCountdown < 0)
        {
            SpawnCountdown = 0.0f;
            ScreamCharge.SetActive(true);
        }

        if(ScreamCharge.activeSelf == false)
        {
            SpawnCountdown = 100.0f;
            SpawnCountdown = SpawnCountdown - (Time.deltaTime * Random.Range(2.5f, 7.5f));
        }
     
		
	}
}
