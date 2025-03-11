using UnityEngine;
using System.Collections;

public class PingPongRotationScript : MonoBehaviour {

	public float rotateSpeed = 1;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		transform.rotation = Quaternion.Euler(new Vector3(0,0, Mathf.PingPong(Time.time * rotateSpeed, 120.0f)));
		//transform.rotation = Quaternion.Euler(0.0, Mathf.PingPong(Time.time * rotateSpeed, 90.0), 0.0);

	}
}
