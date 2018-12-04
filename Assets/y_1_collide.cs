using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class y_1_collide : MonoBehaviour {

    public GameObject yellow;
    public Vector3 position;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    void OnTriggerExit(Collider other){
        Instantiate(yellow, position, Quaternion.identity);
    }
}
