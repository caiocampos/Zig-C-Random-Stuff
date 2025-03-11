/* 
  To report an achievement status use this function.
  for success, achievement must be reported to 100.0
  if you want to track some certain tasks, like blasted ball count.
  you can calculate a percentage and when user blasted a ball, 
  you can report this percentage instead of 100.0
*/
Social.ReportProgress ("achievementID", 100.0, function(result) {
	if (result){
		Debug.Log ("Successfully reported achievement progress");
		// you can do whatever you want in this if-statement.
		// this if statement is only called when achievement report is succesfull.
		// for example you can give extra coins for every succesfull achievement
	}
	else
		Debug.Log ("Failed to report achievement");
	});

/*
  This function can be used for reporting scores to certain leaderboards
  that defined in iTunes Connect.
  When you want to report score, just call ReportScore(100, myLeaderBoard);
*/

function ReportScore (score : int, leaderboardID : String) {
	Debug.Log ("Reporting score " + score + " on leaderboard " + leaderboardID);
	var message : String;
	Social.ReportScore (score, leaderboardID, function(result){
	if(result){
		message = "Reported succesfully";
	}else{
		message = "Failed to report score";
	}
	Debug.Log(message);
	});
}
