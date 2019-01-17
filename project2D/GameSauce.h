#pragma once
#include "Renderer2D.h"
#include "Player.h"

class GameSauce
{
public:
	GameSauce();
	~GameSauce();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

private:
	Player* m_pPlayer;
};

