#include "Clock.h"

Clock* Clock::m_pInstance = nullptr;

Clock::Clock()
{
	m_fCurrentTime = 0.0f;
}


Clock::~Clock()
{
}

Clock* Clock::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new Clock();
	}

	return m_pInstance;
}

void Clock::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

Clock* Clock::GetInstance()
{
	return Create();
}

void Clock::Update(float fDeltaTime)
{
	m_fDeltaTime = fDeltaTime;
	m_fCurrentTime += fDeltaTime;
}
