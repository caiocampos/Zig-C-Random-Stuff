using UnityEngine;
using System.Collections;

public class Wave : MonoBehaviour {

	public float amplitude = 1.5f;
	public float speed = 1.0f;

	private float originY;
	// Use this for initialization
	void Start () {
		originY = transform.position.y;
	}
	
	// Update is called once per frame
	void Update () {
		transform.position = new Vector3 (transform.position.x, -1 * Mathf.PingPong (Time.time, amplitude) * speed, transform.position.z);
		transform.position = new Vector3 (transform.position.x, transform.position.y + originY, transform.position.z);
	}
}
