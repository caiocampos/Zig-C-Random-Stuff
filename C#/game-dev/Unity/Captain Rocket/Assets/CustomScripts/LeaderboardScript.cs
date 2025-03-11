using UnityEngine;
using System.Collections;
using UnityEngine.SocialPlatforms;
using UnityEngine.SocialPlatforms.GameCenter;


public class LeaderboardScript : MonoBehaviour {

	// Use this for initialization
	void Start () {

		string LEADERBOARD_ID = PlayerPrefs.GetString ("leaderboardid");
		Social.localUser.Authenticate (success => {
			if (success) {
				Debug.Log ("Authentication successful");
				GameCenterPlatform.ShowLeaderboardUI(LEADERBOARD_ID, TimeScope.AllTime);
				//Social.ShowLeaderboardUI();
			}
			else
				Debug.Log ("Social: Authentication failed");
		});

	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	// Method not used
	void LoadScores(){
		string LEADERBOARD_ID = PlayerPrefs.GetString ("leaderboardid");
		Social.LoadScores(LEADERBOARD_ID, scores => {
			if (scores.Length > 0) {
				Debug.Log ("Got " + scores.Length + " scores");
				string myScores = "Leaderboard:\n";
				foreach (IScore score in scores)
					myScores += "\t" + score.userID + " " + score.formattedValue + " " + score.date + "\n";
				Debug.Log (myScores);
			}
			else
			{
				Debug.Log ("No scores loaded");
			}
		});
	}

}
