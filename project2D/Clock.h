#pragma once
class Clock
{
public:
	static Clock* Create();
	static void Destroy();
	static Clock* GetInstance();

	void Update(float fDeltaTime);

	inline float GetCurrentTime() { return m_fCurrentTime; };
	inline float GetDeltaTime() { return m_fDeltaTime; };

private:
	Clock();
	~Clock();

	static Clock* m_pInstance;

	float m_fCurrentTime;
	float m_fDeltaTime;
};