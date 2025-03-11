using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using ChartboostSDK;
using GoogleMobileAds.Api;

public class SettingsGameOver : MonoBehaviour {

	public int reward1PointsNeeded = 50;
	public int reward2PointsNeeded = 100;
	public int reward3PointsNeeded = 200;
	public int reward4PointsNeeded = 500;

	public Text scoreText;
	public Text scoreHighText;

	public int score = 0;
	public int highScore = 0;

	public AudioClip audioHighScore;
	public AudioClip audioScoreUpTick;

	private int fullScreenAdCount = 0;

	private int currentScoreIndex = 0;
	private bool isNewHighScore = false;
	private bool AdsRemoved = false;

	private BannerView bannerView;
	// Use this for initialization
	void Start () {
		score = GetScore ();
		highScore = GetHighScore ();


		GameObject star = GameObject.Find ("star") as GameObject;
		star.GetComponent<Renderer> ().sortingOrder = -1;

		InvokeRepeating ("IncreaseScoreDisplay", 0, 0.1f);

		if (score > highScore) {
			SetNewHighScore (score);
		}
		scoreHighText.text = highScore.ToString();

		CheckForReward ();


		fullScreenAdCount = PlayerPrefs.GetInt ("fullscreenadcount");
		int fullscreenadfrequency = PlayerPrefs.GetInt ("fullscreenadfrequency");



		AdsRemoved = PlayerPrefs.GetInt ("adsremoved") == 1;
		if (!AdsRemoved) {
			RequestBanner ();
		}

		//Debug.Log ("ad count:" + fullScreenAdCount + " | frequency: " + fullscreenadfrequency);
		if (!AdsRemoved && fullScreenAdCount % fullscreenadfrequency == 0) {
			Chartboost.showInterstitial(CBLocation.GameOver);
		}



	}
	
	// Update is called once per frame
	void Update () {
	
	}


	public int GetScore()
	{
		return PlayerPrefs.GetInt ("score");
	}


	public int GetHighScore()
	{
		return PlayerPrefs.GetInt ("highscore");
	}

	public void SetNewHighScore(int points){
		highScore = points;
		PlayerPrefs.SetInt ("highscore", points);

		GameObject star = GameObject.Find ("star") as GameObject;
		star.GetComponent<Renderer> ().sortingOrder = 10;

		scoreHighText.text = highScore.ToString();
		isNewHighScore = true;

	}


	public void CheckForReward(){
		if (score >= reward4PointsNeeded) {
			GameObject reward = GameObject.Find ("reward-4") as GameObject;
			reward.GetComponent<Renderer> ().sortingOrder = 10;
		}
		else if (score >= reward3PointsNeeded) {
			GameObject reward = GameObject.Find ("reward-3") as GameObject;
			reward.GetComponent<Renderer> ().sortingOrder = 10;
		}
		if (score >= reward2PointsNeeded) {
			GameObject reward = GameObject.Find ("reward-2") as GameObject;
			reward.GetComponent<Renderer> ().sortingOrder = 10;
		}
		if (score >= reward1PointsNeeded) {
			GameObject reward = GameObject.Find ("reward-1") as GameObject;
			reward.GetComponent<Renderer> ().sortingOrder = 10;
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

	private bool IsSoundOn()
	{
		return 0 == PlayerPrefs.GetInt ("audioisoff");
	}

	private void IncreaseScoreDisplay()
	{
		if (currentScoreIndex >= score) {
			if(isNewHighScore)
			{
				if (IsSoundOn()) {
					AudioSource audio = GetComponent<AudioSource> ();
					audio.PlayOneShot (audioHighScore);
				}
			}
			CancelInvoke();
			return;
		}

		currentScoreIndex++;
		if (IsSoundOn()) {
			AudioSource audio = GetComponent<AudioSource> ();
			audio.PlayOneShot (audioScoreUpTick);
		}

		scoreText.text = currentScoreIndex.ToString();
	}

	void OnDisable() {
		if (!AdsRemoved) {
			bannerView.Hide (); 
			bannerView.Destroy ();
		}
	}


}








