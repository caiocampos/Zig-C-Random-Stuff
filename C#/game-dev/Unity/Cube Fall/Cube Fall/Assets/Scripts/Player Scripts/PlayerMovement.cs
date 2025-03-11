using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour {

    private Rigidbody2D myBody;

    public float moveSpeed = 2f;

    void Awake() {
        myBody = GetComponent<Rigidbody2D>();
    }

    void FixedUpdate() {
        Move();
    }

    void Move() {
     
        if(Input.GetAxisRaw("Horizontal") > 0f) {
            myBody.velocity = new Vector2(moveSpeed, myBody.velocity.y);
        }

        if (Input.GetAxisRaw("Horizontal") < 0f) {
            myBody.velocity = new Vector2(-moveSpeed, myBody.velocity.y);
        }
    } // move

    public void PlatformMove(float x) {
        myBody.velocity = new Vector2(x, myBody.velocity.y);
    }

} // class







































