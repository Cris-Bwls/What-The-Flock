#include "Player.h"
#include "Input.h"
#include "TextureManager.h"

using aie::Input;

// Primary Keys
#define UP_KEY		aie::INPUT_KEY_W
#define DOWN_KEY	aie::INPUT_KEY_S
#define LEFT_KEY	aie::INPUT_KEY_A
#define RIGHT_KEY	aie::INPUT_KEY_D

// Alternate Keys
#define ALT_UP_KEY		aie::INPUT_KEY_UP
#define ALT_DOWN_KEY	aie::INPUT_KEY_DOWN
#define ALT_LEFT_KEY	aie::INPUT_KEY_LEFT
#define ALT_RIGHT_KEY	aie::INPUT_KEY_RIGHT

// Other
#define FWD_SPEED 20.0f
#define SIDE_SPEED 20.0f
#define MAX_ROLL 1.0f

Player::Player()
{
	Setup();
}


Player::~Player()
{
}

void Player::Setup()
{
	TextureManager* pTextureManager = TextureManager::GetInstance();
	m_pTexture = pTextureManager->GetTexture(ETextures::PLAYER);

	Texture* tempTexture = pTextureManager->GetTexture(ETextures::PLAYER_SHEET);
	Animator* temp = new Animator(tempTexture, 50.0f, 4, 100, 100);
	temp->Start();

	m_Animators.push_back(temp);

	m_v2Velocity.Zero();
	m_fDrag = 2.5f;
}



void Player::Update(float fDeltaTime)
{
	if (m_bIsAlive)
	{
		// MOVE
		Vector2 v2Force;
		Vector2 v2Dampening;

		// Get Inputs
		Input* pInput = Input::getInstance();
		bool bMoveUp = pInput->isKeyDown(UP_KEY) || pInput->isKeyDown(ALT_UP_KEY);
		bool bMoveDown = pInput->isKeyDown(DOWN_KEY) || pInput->isKeyDown(ALT_DOWN_KEY);
		bool bMoveLeft = pInput->isKeyDown(LEFT_KEY) || pInput->isKeyDown(ALT_LEFT_KEY);
		bool bMoveRight = pInput->isKeyDown(RIGHT_KEY) || pInput->isKeyDown(ALT_RIGHT_KEY);

		if (bMoveUp)
			v2Force += m_m3Transform.GetFacing2D() * FWD_SPEED;
		if (bMoveDown)
			v2Force += m_m3Transform.GetFacing2D() * -FWD_SPEED;
		if (bMoveLeft)
			v2Force += m_m3Transform.GetRight() * -SIDE_SPEED;
		if (bMoveRight)
			v2Force += m_m3Transform.GetRight() * SIDE_SPEED;

		v2Dampening = -(m_v2Velocity * m_fDrag);

		Vector2 v2Accel = v2Force + v2Dampening;
		m_v2Velocity += v2Accel * fDeltaTime;

		Vector2 v2Pos = m_m3Transform.GetPosition();
		v2Pos += m_v2Velocity;

		m_m3Transform.SetPosition(v2Pos);

		for each (Animator* var in m_Animators)
		{
			var->Update(fDeltaTime);
		}
	}
}

void Player::Draw(aie::Renderer2D* pRenderer)
{
	Vector2 v2Pos = m_m3Transform.GetPosition();

	//pRenderer->drawSprite(m_pTexture, v2Pos.x, v2Pos.y);

	for each (Animator* var in m_Animators)
	{
		var->Draw(pRenderer, v2Pos);
	}
}