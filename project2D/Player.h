#pragma once
#include "GameObject.h"
#include <vector>
#include "Animator.h"

using std::vector;

class Player :
	public GameObject
{
public:
	Player();
	~Player();
	
	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

private:
	void Setup();

	float m_fDrag;
	Vector2 m_v2Velocity;

	vector<Animator*> m_Animators;
};

