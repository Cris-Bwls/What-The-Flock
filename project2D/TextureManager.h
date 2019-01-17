#pragma once
#include "Texture.h"
#include <assert.h>
#include <vector>

using std::vector;
using aie::Texture;

enum class ETextures
{
	BALL = 0,
	PLAYER,
	PLAYER_SHEET,

	TOTAL,
};

class TextureManager
{
public:
	static TextureManager* Create();
	static void Destroy();
	static TextureManager* GetInstance();

	Texture* GetTexture(ETextures texture);

private:
	TextureManager();
	~TextureManager();

	static TextureManager* m_pInstance;
	vector<Texture*> m_pTextures;

	const vector<char*> m_csPaths =
	{
		"./textures/ball.png",
		"./textures/player.png",
		"./textures/player_sheet01.png"
	};
};

