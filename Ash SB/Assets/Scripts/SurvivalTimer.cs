using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SurvivalTimer : MonoBehaviour {
    public Text timerLabel;
    public GameObject Player;
    

    private float time;
    // Update is called once per frame
    void Update ()
    {
        if(Player.activeSelf != false)
        {
           time += Time.deltaTime; 
        }

        if(Player.activeSelf == false)
        {
            time = 0f;
            time += Time.deltaTime;
        }

        timerLabel.text = string.Format("{0:F2}", time);

        
	}
}
