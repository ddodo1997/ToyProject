#pragma once
#define TEXTURE_MANAGER (ResourceMgr<sf::Texture>::Instance())
#define FONT_MANAGER (ResourceMgr<sf::Font>::Instance())
#define FRAMEWORK (Framework::Instance())
#define SCENE_MANAGER (SceneMgr::Instance())

/// <summary>
/// SceneMgr의 Scene 벡터의 인덱스
/// </summary>
enum class SceneIds {
	None = -1,

	Dev1,
	Dev2,


	Count
};

/// <summary>
/// T M B  상 중 하
/// L C R  좌 중 우
/// 자주 쓰이는 오리진의 열거형
/// </summary>
enum class Origins {
	None = -1,

	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom,

	OriginCnt
};


/// <summary>
/// 플래피 버드의 색깔
/// </summary>
enum class BirdColor {
	Blue,
	Red,
	Yellow
};

enum class Arrow {
	None = -1,
	First,
	Second,
	Third
};