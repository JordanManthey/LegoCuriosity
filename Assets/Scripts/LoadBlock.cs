using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LoadBlock : MonoBehaviour {
	bool x = false;
    bool but1State;
    bool but2State;
    bool but3State;
    bool but4State;
    public OVRInput.Controller controller;
    int count = -1;
    // Use this for initialization
    void Start () {
		
	}

    // Update is called once per frame
    void Update() {
        but1State = OVRInput.Get(OVRInput.Button.One, controller);
        bool key = Input.GetKey("space");

        but2State = OVRInput.Get(OVRInput.Button.Two, controller);
        bool key2 = Input.GetKey("enter");

        but3State = OVRInput.Get(OVRInput.Button.Three, controller);
        bool key3 = Input.GetKey("a");

        but4State = OVRInput.Get(OVRInput.Button.Four, controller);
        bool key4 = Input.GetKey("b");


        if (count > -1)
        {
            if (count == 30)
            {
                count = -1;
            } else
            {
                count++;
            }
        }
        else if (key || but1State)
        {
            count++;
            print("Index State: " + but1State);
            // Need to check where the user is looking to teleport him
            if (true) //(TeleportMarker.activeSelf)
            {
                GameObject block = Instantiate(Resources.Load("yellow_2x4")) as GameObject;
                block.transform.position = new Vector3(15.65f, .774f, -20.5f);
            }
        }
        else if (key2 || but2State)
        {
            count++;
            print("Index State: " + but2State);
            // Need to check where the user is looking to teleport him
            if (true) //(TeleportMarker.activeSelf)
            {
                GameObject block = Instantiate(Resources.Load("yellow_2x2")) as GameObject;
                block.transform.position = new Vector3(15.65f, .774f, -20.5f);
            }
        }
        else if (key3 || but3State)
        {
            count++;
            print("Index State: " + but3State);
            // Need to check where the user is looking to teleport him
            if (true) //(TeleportMarker.activeSelf)
            {
                GameObject block = Instantiate(Resources.Load("yellow_2")) as GameObject;
                block.transform.position = new Vector3(15.65f, .774f, -20.5f);
            }
        }
        else if (key4 || but4State)
        {
            count++;
            print("Index State: " + but4State);
            // Need to check whe4e the user is looking to teleport him
            if (true) //(TeleportMarker.activeSelf)
            {
                GameObject block = Instantiate(Resources.Load("yellow_1")) as GameObject;
                block.transform.position = new Vector3(15.65f, .774f, -20.5f);
            }
        }
    }

}

