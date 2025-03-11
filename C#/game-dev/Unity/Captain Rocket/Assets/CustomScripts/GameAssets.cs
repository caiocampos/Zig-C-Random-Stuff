using UnityEngine;
using System.Collections;
using Soomla.Store;



	public class GameAssets:IStoreAssets 
{
	public int GetVersion() {
		return 0;
	}

	public VirtualCurrency[] GetCurrencies() {
		return new VirtualCurrency[]{};
	}
	

	public VirtualGood[] GetGoods() {
		return new VirtualGood[] { NO_ADS};
	}

	public VirtualCurrencyPack[] GetCurrencyPacks() {
		return new VirtualCurrencyPack[] {};
	}

	public VirtualCategory[] GetCategories() {
		return new VirtualCategory[]{};
	}
	
	/** LifeTimeVGs **/
	// Note: create non-consumable items using LifeTimeVG with PuchaseType of PurchaseWithMarket
	public static VirtualGood NO_ADS = new LifetimeVG(
		"No Ads", 														// name
		"No More Ads!",				 									// description
		"no_ads",														// item id
		new PurchaseWithMarket(PlayerPrefs.GetString("INAPP_PURCHASE_REMOVE_ADS"), 0.99));	// the way this virtual good is purchased
	


}

