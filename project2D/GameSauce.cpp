#include "GameSauce.h"
#include "Clock.h"
#include "TextureManager.h"

GameSauce::GameSauce()
{
	Clock::Create();
	TextureManager::Create();
}


GameSauce::~GameSauce()
{
	TextureManager::Destroy();
	Clock::Destroy();
}

void GameSauce::Update(float fDeltaTime)
{
	Clock::GetInstance()->Update(fDeltaTime);

	m_ActiveState->Update(fDeltaTime);
}

void GameSauce::Draw(aie::Renderer2D* pRenderer)
{
	m_pPlayer->Draw(pRenderer);
}

void GameSauce::PauseActiveState()
{
}

void GameSauce::ResumePausedState()
{
}
