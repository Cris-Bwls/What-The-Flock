#pragma once
#include "BaseState.h"
class GameState : public BaseState
{
public:
	GameState(StateMachine* owner);
	virtual ~GameState();
};

