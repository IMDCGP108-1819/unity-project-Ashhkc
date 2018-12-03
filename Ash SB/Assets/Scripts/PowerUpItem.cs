using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerUpItem : MonoBehaviour {
    public GameObject ScreamCharge;
 




	// Use this for initialization
	void Start ()
    {
		
	}

    // Update is called once per frame
    void OnTriggerEnter2D(Collider2D PowerUp)
    {
        if(PowerUp.tag == "Power Up")
        {
            Debug.Log("Add 35 Scream!");
            transform.parent.GetComponent<PlayerPower>().PowerBar += Random.Range(35f, 60);

            Destroy(PowerUp.gameObject);
        }

    }
}
