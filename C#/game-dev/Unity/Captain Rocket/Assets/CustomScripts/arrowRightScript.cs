using UnityEngine;
using System.Collections;
using UnityEngine.EventSystems;
using System.Collections.Generic;
using System;

public class arrowRightScript : MonoBehaviour, IPointerDownHandler
{
	public GameObject character;
	
	public List<Action<PointerEventData>> OnMouseDownListeners = new List<Action<PointerEventData>>();
	
	public void Start()
	{
		character = GameObject.Find ("Character") as GameObject;
	}
	public void OnPointerDown(PointerEventData eventData)
	{
		//Debug.Log ("mouse down");
		character.GetComponent<character> ().isMovingRight = true;
		foreach (var callback in OnMouseDownListeners)
		{
			callback(eventData);
		}
	}
	
	
	public void AddOnMouseDownListener(Action<PointerEventData> action)
	{
		OnMouseDownListeners.Add(action);
	}
	
	public void MouseUpEvent()
	{
		//Debug.Log ("Mouse up!");
		character.GetComponent<character> ().isMovingRight = false;
	}
}