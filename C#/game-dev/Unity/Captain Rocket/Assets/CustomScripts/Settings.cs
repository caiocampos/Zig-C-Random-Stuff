using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using ChartboostSDK;
using GoogleMobileAds.Api;

public class Settings : MonoBehaviour {

	public int FullScreenAdFrequency = 1;
	public bool TestModeOn = false;
	public Text scoreText;
	public float characterSpeedX = 10.0f;
	public float rocketStandardSpeedX = -7.0f;
	public float rocketFastSpeedX = -12.0f;
	public float rocketCrazySpeedX = -8.0f;
	public float positionXThreshold = -20.0f;

	public float timeToWaitBeforeStartingGame = 1.0f;
	public bool gameStarted = false;

	public float characterInitialImpulseX = 6.0f;
	public float characterInitialImpulseY = 21.0f;

	public GameObject instructions;
	private float startTime;

	private bool processed = false;
	private Vector2 characterPosition;

	public float timeBetweenRocktSpawns = 0.8f;
	public float timeBetweenFastRocketSpawns = 10.0f;
	public float timeBetweenCrazyRocketSpawns = 14.0f;
	public float[] rocketSpawnPositionsY;

	public float[] bgItemsSpawnPositionsX;
	public GameObject bgItemsParent;

	public float leftBoundX = -6.3f;

	private GameObject background1;
	private GameObject background2;
	private bool canShiftBackground = false;
	private float characterResetPositionX = -3.0f;
	private float characterMaxPositionX = 3.0f;
	private float screenShiftXSpeed = -10.0f;
	private float initialGravityScale;
	private Vector2 initialVelocity;

	GameObject characterIdle;
	GameObject dummy;
	public GameObject laser;

	private float forceX = -7.0f;

	public bool parallaxIsActive = false;
	bool gameOver = false;

	public int score = 0;
	public int scoreIncrement = 2;
	private int highScore = 0;
	private bool processedNewHighScore = false;

	public GameObject dummyScoreObject;
	bool checkLeftBoundary = false;
	bool controlsEnabled = false;

	private int fullScreenAdCount = 0;

	private bool laserIsActive = false;
	private float lastTimeScoreChanged;
	public float laserSpeed = 1.0f;

	public float timeToWaitBeforeLaserArrives = 4.5f;

	public AudioClip audioScoreUp;
	private bool AdsRemoved = false;

	private BannerView bannerView;

	// Use this for initialization
	void Start () {
		startTime = Time.time;
		gameStarted = false;
		processed = false;

		characterIdle = GameObject.Find ("Character") as GameObject;
		characterIdle.GetComponent<character> ().activated = false;
		characterPosition = new Vector2 (characterIdle.transform.position.x, characterIdle.transform.position.y);
		initialGravityScale = characterIdle.GetComponent<Rigidbody2D> ().gravityScale;

		background1 = GameObject.Find ("background1") as GameObject;
		background2 = GameObject.Find ("background2") as GameObject;

		background1.GetComponent<Parallax> ().parallaxIsActive = false;
		background1.GetComponent<Parallax> ().handleBackgroundItems = true;
		background2.GetComponent<Parallax> ().parallaxIsActive = false;

		dummy = GameObject.Find ("Dummy") as GameObject;

		Invoke ("SpawnInitialRockets", 1.1f);
		Invoke ("SpawnInitialRockets", 1.6f);
		InvokeRepeating ("SpawnRocket", 2.0f, timeBetweenRocktSpawns);
		InvokeRepeating ("SpawnRocketFast", 10.0f, timeBetweenFastRocketSpawns );
		InvokeRepeating ("SpawnRocketCrazy", 11.0f, timeBetweenCrazyRocketSpawns );


		SpawnBackgroundItem (0);

		AdsRemoved = PlayerPrefs.GetInt ("adsremoved") == 1;

		GetFullScreenAdCount ();
		Invoke ("RemoveInstructions", 4.5f);

		Chartboost.cacheInterstitial (CBLocation.GameOver);
		PlayerPrefs.SetInt ("fullscreenadfrequency", FullScreenAdFrequency);

		if (!AdsRemoved) {
			RequestBanner ();
		}
		PlaceBestScoreFlag ();
	}
	
	// Update is called once per frame
	void Update () {
		if (!processed && Time.time > startTime + timeToWaitBeforeStartingGame) {
			processed = true;
		}

		if (processed && !gameStarted) {
			StartGame();
			gameStarted = true;
		}

		if (gameStarted) {
			if(!characterIdle.GetComponent<character>().isDead)
			{
				if(parallaxIsActive){
					ShiftObjectsLeft();
				}
				else{

					CheckIfBeatBestScore();
					CheckForLaser ();
					DiscardUnusedObjects();
					if(laserIsActive)
					{
						laser.transform.position = new Vector2(laser.transform.position.x + Time.deltaTime * laserSpeed, laser.transform.position.y);
					}

					float distance = -1 * characterSpeedX * Time.deltaTime;
					
					//AdjustCharacterPositionX();
					if (characterIdle.GetComponent<character>().isMovingRight && controlsEnabled) {
						
						Rigidbody2D rb = characterIdle.GetComponent<Rigidbody2D> ();
						rb.velocity = new Vector2 (characterSpeedX / 2.0f, rb.velocity.y);
						
						background1.SendMessage("MoveXBy",distance);
						background2.SendMessage("MoveXBy", distance);

						GameObject flag = GameObject.Find ("bestscore");
						flag.transform.position = new Vector2 (flag.transform.position.x + distance, flag.transform.position.y);

						
						
						dummyScoreObject.transform.position = new Vector2(dummyScoreObject.transform.position.x + distance/2.0f, dummyScoreObject.transform.position.y);
						DetermineScore();
						
					} else if (characterIdle.GetComponent<character>().isMovingLeft && controlsEnabled) {
						Rigidbody2D rb = characterIdle.GetComponent<Rigidbody2D> ();
						rb.velocity = new Vector2 (-1 * characterSpeedX, rb.velocity.y);
					} else if(characterIdle.GetComponent<character>().activated){
						Rigidbody2D rb = characterIdle.GetComponent<Rigidbody2D> ();
						rb.velocity = new Vector2(0, rb.velocity.y);
					}
					
					if (characterIdle.transform.position.x > characterMaxPositionX)
					{
						if(!parallaxIsActive){
							TurnOnParallax();
						}
					}
					else if(checkLeftBoundary && characterIdle.transform.position.x < leftBoundX)
					{
						//Debug.Log("death: too close to left side");
						characterIdle.GetComponent<character> ().SendMessage ("Die");
						characterIdle.transform.position = new Vector2(leftBoundX, characterIdle.transform.position.y);
					}
				}
			}
		}
	
	}

	void StartGame()
	{
		scoreText.text = "0 M";

		background1.GetComponent<Parallax> ().parallaxIsActive = true;
		background2.GetComponent<Parallax> ().parallaxIsActive = true;
		// play character-walk for x seconds
		//GameObject characterIdle = GameObject.Find ("Character") as GameObject;
		GameObject characterWalk = GameObject.Find ("character-walk_0") as GameObject;
		characterWalk.transform.position = new Vector2 (characterPosition.x, characterPosition.y);
		characterIdle.transform.position = new Vector2 (characterPosition.x - 30.0f, characterPosition.y);
		//characterIdle.SetActive (false);



		// start platform moving
		GameObject platform = GameObject.Find ("starting-platform") as GameObject;
		platform.GetComponent<platform> ().isMoving = true;

		// start rockets
		// display instructions for x seconds
		// display score
		// hide character walk after x seconds and display standard character
		// start spawning background objects (boats, buoys, etc...)
		Invoke ("SetGameStarted", 0.7f);



	}
	void SetGameStarted()
	{
		gameStarted = true;
		//GameObject characterIdle = GameObject.Find ("Character") as GameObject;
		GameObject characterWalk = GameObject.Find ("character-walk_0") as GameObject;
		characterWalk.transform.position = new Vector2 (characterPosition.x - 30.0f, characterPosition.y);
		characterIdle.transform.position = new Vector2 (characterPosition.x, characterPosition.y);

		//CharacterJumps ();
		Invoke ("CharacterJumps", 0.1f);
		Invoke ("EnableCheckLeftBoundary", 1.0f);
		Invoke ("EnableControls", 0.4f);
		Invoke ("DimArrowControls", 3.0f);

		background1.GetComponent<Parallax> ().parallaxIsActive = false;
		background2.GetComponent<Parallax> ().parallaxIsActive = false;

	}

	void CharacterJumps(){
		//GameObject characterIdle = GameObject.Find ("Character") as GameObject;
		//characterIdle.GetComponent<Rigidbody2D> ().gravityScale = 0;
		//characterIdle.GetComponent<character> ().SendMessage ("Jump"); 
		//Debug.Log ("character now jumps: " + characterIdle.name);

		characterIdle.SendMessage ("PlayJumpSound");
		Rigidbody2D rb = characterIdle.GetComponent<Rigidbody2D> ();
		rb.velocity = new Vector2 (rb.velocity.x, 0);
		rb.AddForce (new Vector2 (characterInitialImpulseX, characterInitialImpulseY), ForceMode2D.Impulse);
		Invoke ("ActivateCharacter", 2.0f);
		//canShiftBackground = true;
		Invoke ("PreventBackgroundShift", 1.2f);

	}

	void EnableControls()
	{
		controlsEnabled = true;
	}


	void EnableCheckLeftBoundary()
	{
		checkLeftBoundary = true;
	}

	void PreventBackgroundShift()
	{
		canShiftBackground = false;
	}

	void ActivateCharacter()
	{
		characterIdle.GetComponent<character> ().activated = true;
	}

	void SpawnInitialRockets()
	{
		float posY = rocketSpawnPositionsY [0];
		string name = "rocket-simpl";
		if (TestModeOn) {
			name = "rocket-dev";
		}
		GameObject rocket = GameObject.Find (name) as GameObject;
		GameObject newRocket = Instantiate(rocket as Object,new Vector2(7, posY), Quaternion.Euler(0, 0, 0)) as GameObject;

	}
	void SpawnRocket()
	{
		if (!gameStarted) {
			//CancelInvoke();
		}
		int factor = Random.Range (0, 100);
		int index = Random.Range (2, rocketSpawnPositionsY.Length);
		if (factor < 70) {
			index = Random.Range (0, 2);
		}
		float posY = rocketSpawnPositionsY [index];
		string name = "rocket-simpl";
		if (TestModeOn) {
			name = "rocket-dev";
		}
		GameObject rocket = GameObject.Find (name) as GameObject;

		GameObject newRocket = Instantiate(rocket as Object,new Vector2(7, posY), Quaternion.Euler(0, 0, 0)) as GameObject;

	}

	void SpawnRocketStandardUp()
	{
		if (!gameStarted) {
			//CancelInvoke();
		}
		int index = Random.Range (3, rocketSpawnPositionsY.Length);
		float posY = rocketSpawnPositionsY [index];
		GameObject rocket = GameObject.FindGameObjectWithTag ("rocket") as GameObject;
		
		Instantiate(rocket as Object,new Vector2(7, posY), Quaternion.Euler(0, 0, 0));

	}


	void SpawnRocketFast()
	{
		if (!gameStarted) {
			//CancelInvoke();
		}
		//Debug.Log ("Spawning fast rocket");
		int factor = Random.Range (0, 100);
		int index = Random.Range (0, rocketSpawnPositionsY.Length);
		if (factor > 70) {
			index = Random.Range (0, rocketSpawnPositionsY.Length / 2);
		}
		float posY = rocketSpawnPositionsY [index];
		GameObject rocket = GameObject.FindGameObjectWithTag ("rockfast") as GameObject;
		
		Instantiate(rocket as Object,new Vector2(10, posY), Quaternion.Euler(0, 0, 0));	
	}

	void SpawnRocketCrazy()
	{
		if (!gameStarted) {
			//CancelInvoke();
		}
		//Debug.Log ("Spawning crazy rocket");
		int factor = Random.Range (0, 100);
		int index = Random.Range (0, rocketSpawnPositionsY.Length);
		if (factor > 50) {
			index = Random.Range (0, rocketSpawnPositionsY.Length / 2);
		}
		float posY = rocketSpawnPositionsY [index];
		GameObject rocket = GameObject.FindGameObjectWithTag ("rocketcrazy") as GameObject;
		
		Instantiate(rocket as Object,new Vector2(10, posY), Quaternion.Euler(0, 0, 0));
	}


	void AdjustCharacterPositionX()
	{

	}

	void TurnOffParallax()
	{
		background1.GetComponent<Parallax> ().parallaxIsActive = false;
		background2.GetComponent<Parallax> ().parallaxIsActive = false;
		parallaxIsActive = false;
		characterIdle.GetComponent<Rigidbody2D> ().gravityScale = initialGravityScale;
		characterIdle.GetComponent<Rigidbody2D> ().velocity = new Vector2 (initialVelocity.x, initialVelocity.y);
	}

	void TurnOnParallax()
	{
		background1.GetComponent<Parallax> ().parallaxIsActive = true;
		background2.GetComponent<Parallax> ().parallaxIsActive = true;
		parallaxIsActive = true;
		initialVelocity = new Vector2 (characterIdle.GetComponent<Rigidbody2D> ().velocity.x, characterIdle.GetComponent<Rigidbody2D> ().velocity.y);
	}


	void AddForceToRockets(float forceX)
	{
		GameObject[] rockets = GameObject.FindGameObjectsWithTag("rocket");
		foreach(GameObject rk in rockets)
		{
			if(rk.name.Contains("Clone") )
			{
				rk.GetComponent<Rigidbody2D> ().AddForce (new Vector2 (forceX, 0), ForceMode2D.Impulse);
			}
		}
	}

	void ShiftObjectsLeft()
	{
		Rigidbody2D charRB = characterIdle.GetComponent<Rigidbody2D> ();
		if (charRB.position.x > characterResetPositionX) {

			charRB.velocity = new Vector2 (0, 0);
			charRB.gravityScale = 0.0f;
			charRB.MovePosition (new Vector2 (charRB.position.x + screenShiftXSpeed * Time.deltaTime, charRB.position.y));
	
			GameObject[] rockets = GameObject.FindGameObjectsWithTag ("rocket");
			foreach (GameObject rk in rockets) {
				if (rk.name.Contains ("Clone") ) {
					rk.transform.position = new Vector2 (rk.transform.position.x + screenShiftXSpeed * Time.deltaTime, rk.transform.position.y);
				}
			}

			GameObject[] rocketsFast = GameObject.FindGameObjectsWithTag ("rockfast");
			foreach (GameObject rk in rocketsFast) {
				if (rk.name.Contains ("Clone") && rk.GetComponent<rocket> ().activated) {
					rk.transform.position = new Vector2 (rk.transform.position.x + screenShiftXSpeed * Time.deltaTime, rk.transform.position.y);
				}
			}

			GameObject[] rocketsCrazy = GameObject.FindGameObjectsWithTag ("rocketcrazy");
			foreach (GameObject rk in rocketsCrazy) {
				if (rk.name.Contains ("Clone") && rk.GetComponent<rocket> ().activated) {
					//Debug.Log("pingpong value:" + Mathf.PingPong(Time.time, 20));
					rk.transform.position = new Vector2 (rk.transform.position.x + screenShiftXSpeed * Time.deltaTime, Mathf.PingPong (Time.time, 20) + rk.transform.position.y);
				}
			}

			//GameObject flag = GameObject.FindGameObjectWithTag("best-score");
			//flag.transform.position = new Vector2 (flag.transform.position.x + screenShiftXSpeed * Time.deltaTime, flag.transform.position.y);

			background1.SendMessage("MoveXBy", screenShiftXSpeed * Time.deltaTime);
			background2.SendMessage("MoveXBy", screenShiftXSpeed * Time.deltaTime);
		} else {
			TurnOffParallax();
		}

	}


	public void GameOver()
	{
		SaveScore ();
		IncrementFullScreenAdCount ();
		Application.LoadLevel("GameOver");
	}

	void SaveScore()
	{
		PlayerPrefs.SetInt("score",score);
	}

	void DetermineScore()
	{
		int newScore = (int)(characterIdle.transform.position.x - dummyScoreObject.transform.position.x);
		if(newScore > score)
		{

			score = newScore;
			if (score < 0) {
				score = 0;
			}
			scoreText.text = score.ToString() + " M";

			if(score % 5 == 0)
			{
				SpawnBackgroundItem(14.0f);
			}

			HideLaser();
		}
	}

	void SpawnBackgroundItem(float offsetX)
	{
		int index = Random.Range (0, 100);
		int selectedIndex = 0;

		for (int i = 0; i < bgItemsSpawnPositionsX.Length; i++) 
		{
			float posX= bgItemsSpawnPositionsX [i];
			
			string itemName = "bg-item-" + (int)Random.Range (1, 5);
			//Debug.Log ("bg item name is: " + itemName);
			GameObject item = GameObject.Find (itemName) as GameObject;
			
			
			GameObject newItem = Instantiate(item as Object,new Vector2(posX + offsetX, item.transform.position.y), Quaternion.Euler(0, 0, 0)) as GameObject;
			newItem.transform.SetParent (bgItemsParent.transform);
		}

	}



	void GetFullScreenAdCount (){
		fullScreenAdCount = PlayerPrefs.GetInt ("fullscreenadcount");
	}


	public void IncrementFullScreenAdCount()
	{
		fullScreenAdCount += 1;
		PlayerPrefs.SetInt("fullscreenadcount",fullScreenAdCount);
	}


	private void RequestBanner()
	{	
		string adUnitId = PlayerPrefs.GetString ("admobbannerid");
		// Create a 320x50 banner at the top of the screen.
		bannerView = new BannerView(adUnitId, AdSize.Banner, AdPosition.Bottom);
		// Create an empty ad request.
		AdRequest request = new AdRequest.Builder().Build();
		// Load the banner with the request.
		bannerView.LoadAd(request);
	}

	void RemoveInstructions()
	{
		instructions.transform.position = new Vector2 (-1000, -1000);
	}

	void PlaceBestScoreFlag()
	{
		highScore = PlayerPrefs.GetInt ("highscore");
		if (highScore > 0) {

			int posX = (int)( highScore - characterIdle.transform.position.x);
			GameObject flag = GameObject.Find ("bestscore");
			flag.transform.position = new Vector2 (posX, flag.transform.position.y);
		}
	}

	void CheckIfBeatBestScore()
	{
		if (!processedNewHighScore && score > highScore) {
			processedNewHighScore = true;
			if (IsSoundOn()) {
				AudioSource audio = GetComponent<AudioSource> ();
				audio.PlayOneShot (audioScoreUp);
			}
		}
	}

	void CheckForLaser ()
	{
		if (!laserIsActive && score > 0 && Time.time - lastTimeScoreChanged > timeToWaitBeforeLaserArrives) {
			BringLaser ();
		} 
	}
	void BringLaser()
	{
		laser.transform.position = new Vector2 (-6.2f, laser.transform.position.y);
		laserIsActive = true;
	}

	void HideLaser(){
		laser.transform.position = new Vector2 (-12.0f, laser.transform.position.y);
		lastTimeScoreChanged = Time.time;
		laserIsActive = false;
	}

	private bool IsSoundOn()
	{
		return 0 == PlayerPrefs.GetInt ("audioisoff");
	}


	private void DimArrowControls()
	{
		Debug.Log ("dimming components");
		GameObject arrL = GameObject.FindGameObjectWithTag("arrowLeft");
		GameObject arrR = GameObject.FindGameObjectWithTag("arrowRight");

		arrL.GetComponent<UnityEngine.UI.Image>().CrossFadeAlpha(0, 1.0f, false);
		arrR.GetComponent<UnityEngine.UI.Image>().CrossFadeAlpha(0, 1.0f, false);

	}


	private void DiscardUnusedObjects()
	{
		GameObject[] rockets = GameObject.FindGameObjectsWithTag("rocket");
		foreach(GameObject rk in rockets)
		{
			if(rk.name.Contains("Clone") && rk.transform.position.x < positionXThreshold)
			{
				Destroy(rk);
				return;
			}
		}

		GameObject[] rocketsFast = GameObject.FindGameObjectsWithTag("rockfast");
		foreach(GameObject rk in rocketsFast)
		{
			if(rk.name.Contains("Clone") && rk.transform.position.x < positionXThreshold)
			{
				Destroy(rk);
				return;
			}
		}

		GameObject[] rocketsCrazy = GameObject.FindGameObjectsWithTag("rocketcrazy");
		foreach(GameObject rk in rocketsCrazy)
		{
			if(rk.name.Contains("Clone") && rk.transform.position.x < positionXThreshold)
			{
				Destroy(rk);
				return;
			}
		}


		GameObject[] bgItems = GameObject.FindGameObjectsWithTag("bgitem");
		foreach(GameObject rk in bgItems)
		{
			if(rk.name.Contains("Clone") && rk.transform.position.x < positionXThreshold)
			{
				Destroy(rk);
				return;
			}
		}

	}


	void OnDisable() {
		if (!AdsRemoved) {
			bannerView.Hide (); 
			bannerView.Destroy ();
		}
	}
	


}








