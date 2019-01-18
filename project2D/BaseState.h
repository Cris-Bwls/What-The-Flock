#pragma once
class StateMachine;

class BaseState
{
public:
	inline BaseState(StateMachine* owner) { m_Owner = owner; };
	inline virtual ~BaseState() {};

	virtual void Update(float fDeltaTime) = 0;
	virtual void Start() = 0;
	virtual void Stop() = 0;

protected:
	StateMachine* m_Owner;
};

