// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBadBot_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_BadBot;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_BadBot()
	{
		if (!Z_Registration_Info_UPackage__Script_BadBot.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/BadBot",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x20D4575E,
				0xBB95000E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_BadBot.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_BadBot.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_BadBot(Z_Construct_UPackage__Script_BadBot, TEXT("/Script/BadBot"), Z_Registration_Info_UPackage__Script_BadBot, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x20D4575E, 0xBB95000E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
