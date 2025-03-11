using UnityEngine;
using System.Collections;
using UnityEngine.SocialPlatforms;
using UnityEngine.SocialPlatforms.GameCenter;

public class MenuGameOverScript : MonoBehaviour {

	private const string TWITTER_ADDRESS = "http://twitter.com/intent/tweet";
	private const string TWEET_LANGUAGE = "en"; 

	// Use this for initialization
	void Start () {
		Social.localUser.Authenticate (ProcessAuthentication);
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	public void PressedReplay()
	{
		Debug.Log ("replay");
		Application.LoadLevel("play");
	}

	public void PressedTwitter()
	{
		Debug.Log ("Twitter");
		PostToTwitter ();
	}

	public void PressedLeaderboard()
	{
		Debug.Log ("leaderboard");
		if (!Social.localUser.authenticated) {
			Social.localUser.Authenticate (ProcessAuthentication);
		}
		string leaderboardID = PlayerPrefs.GetString ("leaderboardid");
		GameCenterPlatform.ShowLeaderboardUI(leaderboardID, TimeScope.AllTime);
	}

	public void PressedHome()
	{
		Debug.Log ("go to home scene");
		Application.LoadLevel("menu");
	}

	void ProcessAuthentication (bool success) {
		if (success) {
			//Debug.Log ("Authenticated, checking achievements");
			
			// Request loaded achievements, and register a callback for processing them
			//Social.LoadAchievements (ProcessLoadedAchievements);
		}
		else
			Debug.Log ("Failed to authenticate");
	}


	void PostToTwitter()
	{
		string textToDisplay = PlayerPrefs.GetString ("twittertext");
		Application.OpenURL(TWITTER_ADDRESS + "?text=" + WWW.EscapeURL(textToDisplay) + "&amp;lang=" + WWW.EscapeURL(TWEET_LANGUAGE));

	}


}







