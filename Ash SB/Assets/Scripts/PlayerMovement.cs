using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour {

    public HoleController CurrentHole;

	// Use this for initialization
	void Start () {
		
	}

	// Update is called once per frame
	void Update () {


        //Basic Player movement via Arrow Keys
        if (Input.GetKeyDown(KeyCode.UpArrow) && CurrentHole.Up )
        {
            transform.position = CurrentHole.Up.position;
            CurrentHole = CurrentHole.Up.gameObject.GetComponent<HoleController>();
        }
        if (Input.GetKeyDown(KeyCode.DownArrow) && CurrentHole.Down)
        {
            transform.position = CurrentHole.Down.position;
            CurrentHole = CurrentHole.Down.gameObject.GetComponent<HoleController>();
        }
        if (Input.GetKeyDown(KeyCode.LeftArrow) && CurrentHole.Left)
        {
            transform.position = CurrentHole.Left.position;
            CurrentHole = CurrentHole.Left.gameObject.GetComponent<HoleController>();
        }
        if (Input.GetKeyDown(KeyCode.RightArrow) && CurrentHole.Right)
        {
            transform.position = CurrentHole.Right.position;
            CurrentHole = CurrentHole.Right.gameObject.GetComponent<HoleController>();
        }

    }
}
