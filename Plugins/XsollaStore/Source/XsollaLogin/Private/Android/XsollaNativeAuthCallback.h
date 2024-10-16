// Copyright 2024 Xsolla Inc. All Rights Reserved.

#pragma once

#include "XsollaLoginSubsystem.h"

#include "XsollaNativeAuthCallback.generated.h"


class UXsollaLoginSubsystem;

UCLASS()
class XSOLLALOGIN_API UXsollaNativeAuthCallback : public UObject
{
	GENERATED_BODY()

public:
	void BindSuccessDelegate(const FOnAuthUpdate& OnSuccess, UXsollaLoginSubsystem* InLoginSubsystem);
	void BindCancelDelegate(const FOnAuthCancel& OnCancel);
	void BindErrorDelegate(const FOnAuthError& OnError);

	void ExecuteSuccess(const FXsollaLoginData& LoginData);
	void ExecuteCancel();
	void ExecuteError(const FString& ErrorMessage);

private:
	UPROPERTY()
	FOnAuthUpdate OnAuthSuccessDelegate;
	UPROPERTY()
	FOnAuthCancel OnAuthCancelDelegate;
	UPROPERTY()
	FOnAuthError OnAuthErrorDelegate;

	UPROPERTY()
	UXsollaLoginSubsystem* LoginSubsystem;
};
