#pragma once
#include "StateMachine.h"
#include "Renderer2D.h"
#include "GameState.h"

class GameSauce : public StateMachine
{
public:
	GameSauce();
	~GameSauce();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	void PauseActiveState();
	void ResumePausedState();

private:
	GameState* m_pPausedState;
};

