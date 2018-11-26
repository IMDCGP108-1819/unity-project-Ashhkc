using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerLoss : MonoBehaviour
{

    public GameObject Player;
    public float RespawnCountdown = 10.0f;
    GameObject RespawnPoint;
    public float TimeMultiplier = 0.1f;
    public Transform SpawnPoint;
    



    // Use this for initialization
    void Update()
    {
        if(Player.activeSelf == false)
        {
            
            RespawnCountdown -= Time.deltaTime * TimeMultiplier;

            if(RespawnCountdown < 0)
            {
                RespawnCountdown = 10.0f;
                Player.SetActive(true);
                Player.transform.SetPositionAndRotation(SpawnPoint.position, Quaternion.identity);
            }
        }


    }

}