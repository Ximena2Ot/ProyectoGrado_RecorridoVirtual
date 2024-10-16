// Copyright 2024 Xsolla Inc. All Rights Reserved.

#pragma once

#include "Engine/DataTable.h"

#include "XsollaStoreCurrencyFormat.generated.h"

USTRUCT(Blueprintable)
struct XSOLLASTORE_API FXsollaStoreCurrencySymbol
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	FString grapheme;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	FString format;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	bool rtl;

	FXsollaStoreCurrencySymbol()
		: rtl(false){};
};

USTRUCT(Blueprintable)
struct XSOLLASTORE_API FXsollaStoreCurrency : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	int32 fractionSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Xsolla Currency")
	FXsollaStoreCurrencySymbol symbol;

	FXsollaStoreCurrency()
		: fractionSize(0)
	{
	}
};
