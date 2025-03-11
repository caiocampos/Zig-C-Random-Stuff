using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlatformScript : MonoBehaviour {

    public float move_Speed = 2f;
    public float bound_Y = 6f;

    public bool moving_Platform_Left, moving_Platform_Right, is_Breakable, is_Spike, is_Platform;

    private Animator anim;

    void Awake() {
        if (is_Breakable)
            anim = GetComponent<Animator>();
    }

    void Update() {
        Move();
    }

    void Move() {

        Vector2 temp = transform.position;
        temp.y += move_Speed * Time.deltaTime;
        transform.position = temp;

        if(temp.y >= bound_Y) {
            gameObject.SetActive(false);
        }

    } // move

    void BreakableDeactivate() {
        Invoke("DeactivateGameObject", 0.35f);
    }

    void DeactivateGameObject() {
         SoundManager.instance.IceBreakSound();
        gameObject.SetActive(false);
    }

    void OnTriggerEnter2D(Collider2D target) {

        if(target.tag == "Player") { 

            if(is_Spike) {

                target.transform.position = new Vector2(1000f, 1000f);
                SoundManager.instance.GameOverSound();
                 GameManager.instance.RestartGame();

            }

        }

    } // on trigger enter

    void OnCollisionEnter2D(Collision2D target) {

        if(target.gameObject.tag == "Player") { 

            if(is_Breakable) {
                SoundManager.instance.LandSound();
                anim.Play("Break");
            }

            if(is_Platform) {
                SoundManager.instance.LandSound();
            }


        }

    } // on collision enter

    void OnCollisionStay2D(Collision2D target) {

        if(target.gameObject.tag == "Player") { 
       
            if(moving_Platform_Left) {
                target.gameObject.GetComponent<PlayerMovement>().PlatformMove(-1f);
            }

            if (moving_Platform_Right) {
                target.gameObject.GetComponent<PlayerMovement>().PlatformMove(1f);
            }

        }

    } // on collision stay

} // class







































