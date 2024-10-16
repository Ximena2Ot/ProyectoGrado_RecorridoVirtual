// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Uniminuto : ModuleRules
{
	public Uniminuto(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
