#include "GameSauce.h"
#include "Clock.h"
#include "TextureManager.h"

GameSauce::GameSauce()
{
	Clock::Create();
	TextureManager::Create();

	m_pPlayer = new Player();
}


GameSauce::~GameSauce()
{
	delete m_pPlayer;

	TextureManager::Destroy();
	Clock::Destroy();
}

void GameSauce::Update(float fDeltaTime)
{
	Clock::GetInstance()->Update(fDeltaTime);

	m_pPlayer->Update(fDeltaTime);
}

void GameSauce::Draw(aie::Renderer2D* pRenderer)
{
	m_pPlayer->Draw(pRenderer);
}
