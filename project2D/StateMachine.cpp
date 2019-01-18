#include "StateMachine.h"

StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
	for each (std::pair<int, BaseState*> var in m_States)
	{
		delete var.second;
	}
}

void StateMachine::ChangeState(int nState)
{
	// Stop current state
	m_ActiveState->Stop();
	
	// Change to new state and start it
	m_ActiveState = m_States[nState];
	m_ActiveState->Start();
}
