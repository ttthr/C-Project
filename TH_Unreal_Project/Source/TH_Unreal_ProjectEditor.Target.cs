// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TH_Unreal_ProjectEditorTarget : TargetRules
{
	public TH_Unreal_ProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "TH_Unreal_Project" } );
	}
}
