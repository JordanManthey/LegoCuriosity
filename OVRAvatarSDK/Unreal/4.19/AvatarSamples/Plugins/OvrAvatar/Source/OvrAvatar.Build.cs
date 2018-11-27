using UnrealBuildTool;
using System;
using System.IO;

public class OvrAvatar : ModuleRules
{
	public OvrAvatar(ReadOnlyTargetRules Target) : base(Target)
	{
        //OptimizeCode = CodeOptimization.Never;

        string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, ".."));
        string thirdParty = Path.Combine(BaseDirectory, "ThirdParty");

        PublicIncludePaths.AddRange(
            new string[] {
                "OvrAvatar/Private",
                "OvrAvatar/Classes",
                thirdParty + "/include",
            }
        );

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"Sockets",
				"Projects",
                "RenderCore",
                "RHI",
                "Voice"
            }   
        );

        PrivateIncludePathModuleNames.AddRange(
            new string[]
            {
                "OculusInput",			// For IOculusInputPlugin.h
                "InputDevice",			// For IInputDevice.h
				"HeadMountedDisplay",   // For IMotionController.h
                "OnlineSubsystem"
            }
        );

        PublicIncludePathModuleNames.AddRange(
            new string[]
            {
                "OVRPlugin"
            }
        );

        PublicDependencyModuleNames.AddRange(new string[] {"OVRPlugin", "LibOVRPlatform", "OnlineSubsystem" });

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(thirdParty + "/lib/libovravatar.lib");
            PublicDelayLoadDLLs.Add("libovravatar.dll");
            PublicDelayLoadDLLs.Add("LibOVRPlatform64_1.dll");
            PublicDelayLoadDLLs.Add("OVRPlugin.dll");
            RuntimeDependencies.Add("$(EngineDir)/Binaries/ThirdParty/Oculus/OVRPlugin/OVRPlugin/" + Target.Platform.ToString() + "/OVRPlugin.dll");
        }
        else
        {
            PrecompileForTargets = PrecompileTargetsType.None;
        }
    }
}
