// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_Learning : ModuleRules
{
	public CPP_Learning(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });
	}
}
