using UnityEngine;
using System.Collections;

public class character : MonoBehaviour {

	public float JumpHeight = 13.0f;

	public float horizontalDeathLineY = -7.0f;

	public bool isMovingRight = false;
	public bool isMovingLeft = false;

	public bool isDead = false;
	private float characterSpeedX;

	public AudioClip audioJump;
	public AudioClip audioExplosion;
	public AudioClip audioDrownInWater;

	public bool activated = false;

	private bool soundIsOn = false;
	//float localGravity = 0.0f;
	// Use this for initialization
	void Start () {
		soundIsOn = IsSoundOn ();

		GameObject settings = GameObject.Find ("Settings") as GameObject;
		characterSpeedX = settings.GetComponent<Settings>().characterSpeedX;

		SpriteRenderer sr = GetComponent<SpriteRenderer>();
		sr.color = Color.white;

	}
	
	// Update is called once per frame
	void Update () {
		if (isDead) {
			return;
		}

		if (activated && transform.position.y < horizontalDeathLineY) {
			//Debug.Log("character below line");
			if(soundIsOn)
			{
				AudioSource audio = GetComponent<AudioSource> ();
				audio.PlayOneShot(audioDrownInWater);
			}
			GameObject sett = GameObject.Find ("Settings") as GameObject;
			if(sett.GetComponent<Settings>().TestModeOn)
			{
				Jump();
			}
			else
			{
				Die ();
			}
		}
	
	}

	void OnCollisionEnter2D(Collision2D coll) {
		if (isDead) {
			return;
		}
		//Debug.Log ("character has collided with " + coll.gameObject.name + " with tag: " + coll.gameObject.tag);
		if (coll.gameObject.tag == "jump") {
			if (soundIsOn) {
				AudioSource audio = GetComponent<AudioSource> ();
				audio.PlayOneShot (audioJump);
			}
			//Debug.Log("character collided with a rocket and ready for jump");
			Rigidbody2D rb = GetComponent<Rigidbody2D> ();
			rb.velocity = new Vector2 (rb.velocity.x, 0);
			rb.AddForce(new Vector2(0, JumpHeight), ForceMode2D.Impulse);
			coll.gameObject.SendMessage("JumpPerformed");
		}
		else if (coll.gameObject.tag == "die") {
			coll.gameObject.SendMessage("DestroyParent");
		}

		else if (coll.gameObject.tag == "laser") {
			if (soundIsOn) {
				AudioSource audio = GetComponent<AudioSource> ();
				audio.PlayOneShot (audioExplosion);
			}
			Die ();
		}
	} 

	void Flash()
	{
		if(this.isActiveAndEnabled )
			this.gameObject.SetActive(false);
		else
			this.gameObject.SetActive(true);
	}

	void Die()
	{
		//Debug.Log ("character is dead");
		SpriteRenderer sr = GetComponent<SpriteRenderer>();
		sr.color = Color.black; 

		isDead = true;

		Rigidbody2D rb = GetComponent<Rigidbody2D> ();
		rb.velocity = new Vector2 (0, 0);
		//rb.AddForce (new Vector2 (0, JumpHeight), ForceMode2D.Impulse);

		if (soundIsOn) {
			AudioSource audio = GetComponent<AudioSource> ();
			audio.PlayOneShot (audioDrownInWater);
		}
		Invoke ("GameOver", 1.2f);

	}


	void Jump()
	{
		if (!isDead) {
			//Debug.Log ("character is jumping");
			if (soundIsOn) {
				AudioSource audio = GetComponent<AudioSource> ();
				audio.PlayOneShot (audioJump);
			}
			Rigidbody2D rb = GetComponent<Rigidbody2D> ();
			rb.velocity = new Vector2 (rb.velocity.x, 0);
			rb.AddForce (new Vector2 (0, JumpHeight), ForceMode2D.Impulse);
			//GetComponent<Rigidbody2D>().AddForce(new Vector2(0f, JumpHeight));

			if (soundIsOn) {
				AudioSource audio = GetComponent<AudioSource> ();
				audio.PlayOneShot (audioJump);
			}
		}
	}

	void GameOver()
	{
		GameObject sett = GameObject.Find ("Settings") as GameObject;
		sett.GetComponent<Settings>().SendMessage("GameOver");
	}


	private bool IsSoundOn()
	{
		return 0 == PlayerPrefs.GetInt ("audioisoff");
	}

	public void PlayJumpSound(){
		if (soundIsOn) {
			AudioSource audio = GetComponent<AudioSource> ();
			audio.PlayOneShot (audioJump);
		}
	}


}
