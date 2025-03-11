using UnityEngine;
using System.Collections;

public class platform : MonoBehaviour {

	public float speedX = -4.0f;
	public float positionXThreshold = -26.0f;

	public bool isMoving = false;

	// Use this for initialization
	void Start () {
		isMoving = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (isMoving) {
			this.transform.position = new Vector3 (this.transform.position.x + speedX * Time.deltaTime, this.transform.position.y, this.transform.position.z);
		
			if (this.transform.position.x < positionXThreshold) {
				Destroy (this);
			}
		}
	}
}
