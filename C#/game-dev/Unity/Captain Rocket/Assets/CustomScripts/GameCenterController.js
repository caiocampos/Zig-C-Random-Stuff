#pragma strict
import UnityEngine.SocialPlatforms;
import UnityEngine.SocialPlatforms.GameCenter;

function Start () {
	DontDestroyOnLoad(gameObject);
    // Authenticate and register a ProcessAuthentication callback
    // This call needs to be made before we can proceed to other calls in the Social API
	Social.localUser.Authenticate (ProcessAuthentication);
	//GameCenterPlatform.ShowDefaultAchievementCompletionBanner(true);
}

// This function gets called when Authenticate completes
// Note that if the operation is successful, Social.localUser will contain data from the server. 
function ProcessAuthentication (success: boolean) {
	if (success) {
		Debug.Log ("Authenticated, checking achievements");

	// Request loaded achievements, and register a callback for processing them
		//Social.LoadAchievements (ProcessLoadedAchievements);
	}
	else
	Debug.Log ("Failed to authenticate");
}

// This function gets called when the LoadAchievement call completes
function ProcessLoadedAchievements (achievements: IAchievement[]) {
	if (achievements.Length == 0)
		Debug.Log ("Error: no achievements found");
	else
		Debug.Log ("Got " + achievements.Length + " achievements");

}