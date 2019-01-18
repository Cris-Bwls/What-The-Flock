#pragma once
#include "BaseState.h"
#include <map>

using std::map;

class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();

	virtual inline void Update(float fDeltaTime) { m_ActiveState->Update(fDeltaTime); }

	void ChangeState(int nState);

protected:
	map<int, BaseState*> m_States;
	BaseState* m_ActiveState;
};

