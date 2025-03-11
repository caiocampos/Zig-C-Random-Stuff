using UnityEngine;
using System.Collections;
using Soomla.Store;
using System.Collections.Generic;
using System;
using ChartboostSDK;
using UnityEngine.SocialPlatforms;
using UnityEngine.SocialPlatforms.GameCenter;
using GoogleMobileAds.Api;
using UnityEngine.UI;


public class UIManagerScript : MonoBehaviour {

	public string APP_ID_ITUNES_CONNECT = "600633777";
	public string APP_ID_GOOGLE_PLAY = "123456789";
	public string LEADERBOARD_ID = "com.appfresh.swingtestleaderboard";
	public string TWITTER_MESSAGE = "Download this app.";
	public string ADMOB_BANNER_ID = "ca-app-pub-1174246192301173/8285202841";
	public string INAPP_PURCHASE_REMOVE_ADS = "com.appfresh.swingtestremoveads2";

	public int audioIsOff = 0;
	public GameObject soundButtonON;
	public GameObject soundButtonOFF;

	public BannerView bannerView;
	public bool AdsRemoved = false;
	public GameObject AdsButton;
	public GameObject RestoreAdsButton;

	// Use this for initialization
	void Start () {

		audioIsOff = PlayerPrefs.GetInt("audioisoff");
		if (audioIsOff == 0) {
			// set audio ON
			soundButtonOFF.SetActive(false);
			soundButtonON.SetActive(true);
		} else {
			// set audio ON
			soundButtonOFF.SetActive(true);
			soundButtonON.SetActive(false);
		}

		PlayerPrefs.SetString ("leaderboardid", LEADERBOARD_ID);
		PlayerPrefs.SetString("twittertext", TWITTER_MESSAGE);
		PlayerPrefs.SetString("admobbannerid", ADMOB_BANNER_ID);
		PlayerPrefs.SetString ("INAPP_PURCHASE_REMOVE_ADS", INAPP_PURCHASE_REMOVE_ADS);
		Social.localUser.Authenticate (ProcessAuthentication);


		PlayBackgroundMusic ();

		Chartboost.didFailToLoadMoreApps += didFailToLoadMoreApps;
		Chartboost.didDismissMoreApps += didDismissMoreApps;
		Chartboost.didCloseMoreApps += didCloseMoreApps;
		Chartboost.didClickMoreApps += didClickMoreApps;
		Chartboost.didCacheMoreApps += didCacheMoreApps;
		Chartboost.shouldDisplayMoreApps += shouldDisplayMoreApps;
		Chartboost.didDisplayMoreApps += didDisplayMoreApps;
		Chartboost.cacheMoreApps (CBLocation.HomeScreen);

		AdsRemoved = PlayerPrefs.GetInt ("adsremoved") == 1;
		if (AdsRemoved) {
			HideAdsButton();
		}else{
			RequestBanner ();
		}

		StoreEvents.OnMarketItemsRefreshFailed += storeRefreshFailed;
		StoreEvents.OnMarketPurchase += onMarketPurchase;
		StoreEvents.OnItemPurchased += onItemPurchased;
		StoreEvents.OnRestoreTransactionsFinished += onRestoreTransactionsFinished;
		SoomlaStore.Initialize(new GameAssets());

	
	}
	
	// Update is called once per frame
	void Update () {
	}


	public void StartGame()
	{
		Application.LoadLevel("play");
	}

	private bool IsSoundOn()
	{
		return 0 == PlayerPrefs.GetInt ("audioisoff");
	}

	public void TurnSoundOn()
	{
		audioIsOff = PlayerPrefs.GetInt("audioisoff");
		PlayerPrefs.SetInt("audioisoff", 0);

		soundButtonOFF.SetActive(false);
		soundButtonON.SetActive(true);

		AudioSource audio = GetComponent<AudioSource> ();
		audio.Play ();

		Debug.Log ("sound on ");
	}

	public void TurnSoundOff()
	{
		audioIsOff = PlayerPrefs.GetInt("audioisoff");
		PlayerPrefs.SetInt("audioisoff", 1);
		
		soundButtonOFF.SetActive(true);
		soundButtonON.SetActive(false);

		AudioSource audio = GetComponent<AudioSource> ();
		audio.Stop ();

		Debug.Log ("sound  off");
	}

	public void RemoveAds()
	{
		Debug.Log ("remove ads");
		IAPHandler.errorMsg ="Waiting...Connecting to store.";
		
		if (Application.platform == RuntimePlatform.Android || Application.platform == RuntimePlatform.IPhonePlayer ) {
			//if (!StoreInventory.NonConsumableItemExists(GameAssets.NO_ADS.ItemId)) {
			StoreInventory.BuyItem(GameAssets.NO_ADS.ItemId);

			//}else{
			//SoomlaHandler.errorMsg ="You have already \n bought that item.";
			//}
		}else {
			//Testing on the computer e.g
			//SoomlaHandler.errorMsg ="Thanks for your purchase. \n It means a lot!";
		}
	}

	public void MoreApps()
	{
		Debug.Log ("more apps");
		Chartboost.showMoreApps (CBLocation.HomeScreen);
	}

	public void Leaderboard()
	{
		Debug.Log ("leaderboard");
	}


	void didFailToLoadMoreApps(CBLocation location, CBImpressionError error) {
		Debug.Log(string.Format("didFailToLoadMoreApps: {0} at location: {1}", error, location));
	}
	
	void didDismissMoreApps(CBLocation location) {
		Debug.Log(string.Format("didDismissMoreApps at location: {0}", location));
	}
	
	void didCloseMoreApps(CBLocation location) {
		Debug.Log(string.Format("didCloseMoreApps at location: {0}", location));
	}
	
	void didClickMoreApps(CBLocation location) {
		Debug.Log(string.Format("didClickMoreApps at location: {0}", location));
	}
	
	void didCacheMoreApps(CBLocation location) {
		Debug.Log(string.Format("didCacheMoreApps at location: {0}", location));
	}
	
	bool shouldDisplayMoreApps(CBLocation location) {
		Debug.Log(string.Format("shouldDisplayMoreApps at location: {0}", location));
		return true;
	}
	
	void didDisplayMoreApps(CBLocation location){
		Debug.Log("didDisplayMoreApps: " + location);
	}

	void OnDisable() {

		if (!AdsRemoved) {
			bannerView.Hide (); 
			bannerView.Destroy ();
		}
		// Remove event handlers

		Chartboost.didFailToLoadMoreApps -= didFailToLoadMoreApps;
		Chartboost.didDismissMoreApps -= didDismissMoreApps;
		Chartboost.didCloseMoreApps -= didCloseMoreApps;
		Chartboost.didClickMoreApps -= didClickMoreApps;
		Chartboost.didCacheMoreApps -= didCacheMoreApps;
		Chartboost.shouldDisplayMoreApps -= shouldDisplayMoreApps;
		Chartboost.didDisplayMoreApps -= didDisplayMoreApps;


		StoreEvents.OnMarketItemsRefreshFailed -= storeRefreshFailed;
		StoreEvents.OnMarketPurchase -= onMarketPurchase;
		StoreEvents.OnItemPurchased -= onItemPurchased;
		StoreEvents.OnRestoreTransactionsFinished -= onRestoreTransactionsFinished;

	}


	void storeRefreshFailed(string msg)
	{
		Debug.Log("store refresh failed: " + msg);
	}


	public void RateApp()
	{
		#if UNITY_ANDROID
		Application.OpenURL("market://details?id=" + APP_ID_GOOGLE_PLAY);
		#elif UNITY_IPHONE
		Application.OpenURL("itms-apps://itunes.apple.com/app/id" + APP_ID_ITUNES_CONNECT);
		#endif
	}


	void ProcessAuthentication (bool success) {
		if (success) {
			Debug.Log ("Authenticated, checking achievements");
			
			// Request loaded achievements, and register a callback for processing them
			//Social.LoadAchievements (ProcessLoadedAchievements);
		}
		else
			Debug.Log ("Failed to authenticate");
	}

	private void RequestBanner()
	{	
		// Create a 320x50 banner at the top of the screen.
		bannerView = new BannerView(ADMOB_BANNER_ID, AdSize.Banner, AdPosition.Bottom);
		// Create an empty ad request.
		AdRequest request = new AdRequest.Builder().Build();
		// Load the banner with the request.
		bannerView.LoadAd(request);
	}

	private void PlayBackgroundMusic()
	{

		if (IsSoundOn ()) {
			Debug.Log ("playing bg music");
			AudioSource audio = GetComponent<AudioSource> ();
			audio.Play ();
		} else {
			Debug.Log ("NOT playing bg music");
		}
	}
	
	// IAP
	public void onMarketPurchase(PurchasableVirtualItem pvi, string payload, Dictionary<string, string> extra) {
		if (pvi.ItemId == GameAssets.NO_ADS.ItemId) {
			InvokeRepeating("HideAds", 0.1f, 1.0f);
		}
	}

	public void onItemPurchased(PurchasableVirtualItem pvi, string payload) {
		if (pvi.ItemId == GameAssets.NO_ADS.ItemId) {
			InvokeRepeating("HideAds", 0.1f, 1.0f);
		}
	}

	public void onRestoreTransactionsFinished(bool success) {
		if (success) {
			//InvokeRepeating("HideAds", 0.1f, 1.0f);
			Debug.Log ("restore successful");
			
			foreach(VirtualGood vg in StoreInfo.Goods) {
				Debug.Log (StoreInventory.GetItemBalance(vg.ItemId));
			}
			
			
			if(StoreInventory.GetItemBalance(GameAssets.NO_ADS.ItemId) == 1)
			{
				//StoreInventory.EquipVirtualGood(GameAssets.NO_ADS.ItemId);
				InvokeRepeating("HideAds", 0.1f, 1.0f);
				Debug.Log ("restore: virtual good found in inventory");
			}
			else {
				Debug.Log ("restore: virtual good NOT found in inventory");
			}
			//StoreInventory.NonConsumableItemExists(GameAssets.NO_ADS.ItemId);
			
		}  else {
			Debug.Log("Restore failed");
		}
	}

	public void HideAds()
	{
		AdsRemoved = true;
		PlayerPrefs.SetInt ("adsremoved", 1);
		bannerView.Hide ();
		HideAdsButton();
		//Invoke("ReloadMenu", 0.6f);
	}

	public void HideAdsButton()
	{
		AdsButton.transform.position = new Vector2 (-1000, -1000);
		RestoreAdsButton.transform.position = new Vector2 (-1000, -1000);
	}


	public void RestoreRemoveAds()
	{
		Debug.Log ("restoring: remove ads");
		IAPHandler.errorMsg ="Waiting...Connecting to store.";
		
		if (Application.platform == RuntimePlatform.Android || Application.platform == RuntimePlatform.IPhonePlayer ) {
			SoomlaStore.RestoreTransactions();
		}else {
		}
	}



	public void ReloadMenu(){
		Application.LoadLevel ("menu");
	}





	
}
