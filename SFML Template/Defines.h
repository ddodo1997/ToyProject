#pragma once
#define TEXTURE_MANAGER (ResourceMgr<sf::Texture>::Instance())
#define FONT_MANAGER (ResourceMgr<sf::Font>::Instance())
#define FRAMEWORK (Framework::Instance())
#define SCENE_MANAGER (SceneMgr::Instance())

/// <summary>
/// SceneMgr�� Scene ������ �ε���
/// </summary>
enum class SceneIds {
	None = -1,

	Dev1,
	Dev2,


	Count
};

/// <summary>
/// T M B  �� �� ��
/// L C R  �� �� ��
/// ���� ���̴� �������� ������
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
/// �÷��� ������ ����
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