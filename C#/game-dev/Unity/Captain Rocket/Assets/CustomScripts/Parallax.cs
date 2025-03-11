using UnityEngine;
using System.Collections;

public class Parallax : MonoBehaviour {

	public float parallaxSpeedX = -0.3f;

	public bool parallaxIsActive = false;
	public bool handleBackgroundItems = false;

	public float positionXResetTrigger = -26.0f;
	public float positionXResetDestination = 34.74f;
	// Use this for initialization
	void Start () {
		if (parallaxIsActive) {
			this.transform.position = new Vector2 (this.transform.position.x + parallaxSpeedX * Time.deltaTime, this.transform.position.y);
			if (transform.position.x < positionXResetTrigger) {
				transform.position = new Vector2(positionXResetDestination, transform.position.y);
			}

			if(handleBackgroundItems)
			{

				GameObject[] bgItems = GameObject.FindGameObjectsWithTag("bgitem");
				//Debug.Log("parallax script found " + bgItems.Length + " BGitems");
				foreach(GameObject item in bgItems)
				{
					if(item.name.Contains("Clone"))
					{
						item.transform.position = new Vector2 (item.transform.position.x + parallaxSpeedX * Time.deltaTime, item.transform.position.y);
					}
				}

			}
		}
	
	}
	
	// Update is called once per frame
	void Update () {

		// reusing background by rotating them horizontally)
		if (transform.position.x < positionXResetTrigger) {
			transform.position = new Vector2(positionXResetDestination, transform.position.y);
		}

		// testing bg rotations:
		//transform.position = new Vector2(transform.position.x - 0.1f, transform.position.y);
	}

	public void MoveXBy(float distanceX)
	{
		//Debug.Log ("Moving by " + distanceX.ToString ());

		this.transform.position = new Vector2 (this.transform.position.x + distanceX, this.transform.position.y);
		
		/*if (transform.position.x < positionXResetTrigger) {
			transform.position = new Vector2(positionXResetDestination, transform.position.y);
		}*/
		
		if(handleBackgroundItems)
		{

			GameObject[] bgItems = GameObject.FindGameObjectsWithTag("bgitem");
			//Debug.Log("parallax script found " + bgItems.Length + " BGitems");
			foreach(GameObject item in bgItems)
			{
				if(item.name.Contains("Clone"))
				{
					item.transform.position = new Vector2 (item.transform.position.x + distanceX, item.transform.position.y);
				}
			}
			
		}

	}
}








