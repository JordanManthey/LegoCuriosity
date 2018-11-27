// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System;
using System.IO;

public class AvatarSamples : ModuleRules
{
	public AvatarSamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  "OvrAvatar" });

        string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));
        string thirdParty = Path.Combine(BaseDirectory, "Plugins", "OvrAvatar", "ThirdParty");

        PrivateIncludePaths.AddRange(
            new string[] {
                thirdParty + "/include",
        });
    }
}
