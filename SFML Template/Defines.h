#pragma once
#define TEXTURE_MANAGER (ResourceMgr<sf::Texture>::Instance())
#define FONT_MANAGER (ResourceMgr<sf::Font>::Instance())
#define FRAMEWORK (Framework::Instance())

/// <summary>
/// SceneMgr¿« Scene ∫§≈Õ¿« ¿Œµ¶Ω∫
/// </summary>
enum class SceneIds {
	None = -1,

	Dev1,
	Dev2,


	Count
};

enum class Origins {
	None = -1,
	//T M B
	//L C R
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom,

	OriginCnt
};