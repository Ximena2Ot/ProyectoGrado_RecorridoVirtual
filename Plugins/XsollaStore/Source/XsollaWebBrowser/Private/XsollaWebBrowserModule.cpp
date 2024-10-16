// Copyright 2024 Xsolla Inc. All Rights Reserved.

#include "XsollaWebBrowserModule.h"

#include "XsollaWebBrowserAssetManager.h"

#include "IWebBrowserSingleton.h"
#include "Materials/Material.h"
#include "Modules/ModuleManager.h"
#include "WebBrowserModule.h"

const FName FXsollaWebBrowserModule::ModuleName = "XsollaWebBrowser";

void FXsollaWebBrowserModule::StartupModule()
{
	if (WebBrowserAssetMgr == nullptr)
	{
		WebBrowserAssetMgr = NewObject<UXsollaWebBrowserAssetManager>((UObject*)GetTransientPackage(), NAME_None, RF_Transient | RF_Public);
		WebBrowserAssetMgr->LoadDefaultMaterials();

		IWebBrowserSingleton* WebBrowserSingleton = IWebBrowserModule::Get().GetSingleton();
		if (WebBrowserSingleton)
		{
			WebBrowserSingleton->SetDefaultMaterial(WebBrowserAssetMgr->GetDefaultMaterial());
			WebBrowserSingleton->SetDefaultTranslucentMaterial(WebBrowserAssetMgr->GetDefaultTranslucentMaterial());
		}
	}
}

void FXsollaWebBrowserModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FXsollaWebBrowserModule, XsollaWebBrowser);
