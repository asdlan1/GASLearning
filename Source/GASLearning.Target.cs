// GAS

using UnrealBuildTool;
using System.Collections.Generic;

public class GASLearningTarget : TargetRules
{
	public GASLearningTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GASLearning" } );
	}
}
