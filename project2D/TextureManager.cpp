#include "TextureManager.h"

TextureManager* TextureManager::m_pInstance = nullptr;

TextureManager::TextureManager()
{
	int nTotal = (int)ETextures::TOTAL;
	if (nTotal != m_csPaths.size())
	{
		char* message = "Path size != name total";
		//assert(!message);

		nTotal = m_csPaths.size();
	}

	for (int i = 0; i < nTotal; ++i)
	{
		char* path = m_csPaths[i];
		m_pTextures.push_back(new Texture(path));
	}
}


TextureManager::~TextureManager()
{
	for (int i = 0; i < m_pTextures.size(); ++i)
	{
		delete m_pTextures[i];
	}
}

TextureManager* TextureManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new TextureManager();
	}

	return m_pInstance;
}

void TextureManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

TextureManager* TextureManager::GetInstance()
{
	return Create();
}

//-------------------------------------------------------------------------
// GetTexture
//		returns specified texture
//-------------------------------------------------------------------------
Texture* TextureManager::GetTexture(ETextures texture)
{
	return m_pTextures[(int)texture];
}
