using UnityEngine;
using System.Collections;

public class rocketChild : MonoBehaviour {
	
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void DestroyParent()
	{
		gameObject.SendMessageUpwards ("Explode");
	}

	void DeactivateParent()
	{
		gameObject.SendMessageUpwards ("Deactivate");
	}

	void JumpPerformed()
	{
		gameObject.SendMessageUpwards ("Jump");
	}
}
