using UnityEngine;
using System.Collections;

public class rocket : MonoBehaviour {

	public bool activated = true;
	bool exploded = false;
	bool jumping = false;


	float lastJumpTime;
	float spanBetweenJumpsInSeconds = 0.15f;

	float speedX = -4.0f;
	float positionXThreshold = -20.0f;
	
	private float originY;

	GameObject settingsObject;

	void Start () 
	{
		lastJumpTime = Time.time;

		settingsObject = GameObject.FindWithTag("Settings") as GameObject;
		speedX = settingsObject.GetComponent<Settings>().rocketStandardSpeedX;

		originY = transform.position.y;

		if (this.tag.Contains ("fast"))
		{
			speedX = settingsObject.GetComponent<Settings>().rocketFastSpeedX;
		}
		else if (this.tag.Contains ("crazy"))
		{
			speedX = settingsObject.GetComponent<Settings>().rocketCrazySpeedX;
		}


		positionXThreshold = settingsObject.GetComponent<Settings>().positionXThreshold;
		activated = true;

	}
	
	// Update is called once per frame
	void Update ()
	{
		if (settingsObject.GetComponent<Settings> ().parallaxIsActive) {
			return;
		}
		//Debug.Log("tag is:" + tag);
		if (tag.Contains ("rocketcrazy")) {
			//Debug.Log ("pingpong value:" + Mathf.PingPong (Time.time, 20));
			transform.position = new Vector2 (transform.position.x, -1 * Mathf.PingPong (Time.time, 0.6f) * 40);
			transform.position = new Vector2 (transform.position.x, transform.position.y + originY);
			//
			this.transform.position = new Vector2 (this.transform.position.x + speedX * Time.deltaTime, Mathf.PingPong (0.1f, 3) * this.transform.position.y);
		} else {
			this.transform.position = new Vector2 (this.transform.position.x + speedX * Time.deltaTime, this.transform.position.y);
		}

		if (this.transform.position.x < positionXThreshold) 
		{
			if(this.name.Contains("Clone") )
			{
				//Debug.Log("destroying self");
				//Destroy(this);
				return;
			}
		}

		if (jumping) {
			if(lastJumpTime + spanBetweenJumpsInSeconds < Time.time)
			{
				jumping = false;
			}
		}

		if (!activated) {
				this.transform.position = new Vector2(this.transform.position.x, this.transform.position.y + speedX * Time.deltaTime);
		}
		
	}


	void Explode()
	{
		if (jumping) {
			return;
		}
		//Debug.Log("rocket exploding...");
		exploded = true;
		// kill character
		GameObject character = GameObject.FindWithTag("Player") as GameObject;
		character.SendMessage ("Die");

		GameObject explo = GameObject.Find ("explosion_0");
		GameObject exploNew = Instantiate(explo as Object,new Vector2(this.gameObject.transform.position.x, this.gameObject.transform.position.y), Quaternion.Euler(0, 0, 0)) as GameObject;
		transform.position = new Vector2 (-1000.0f, -1000.0f);
	}


	void Deactivate()
	{
		//Debug.Log ("rocket deactivating...");
		activated = false;
	}

	void Jump()
	{
		//Debug.Log ("rocket parent jumping...");
		lastJumpTime = Time.time;
		jumping = true;
		activated = false;
	}
	
}
