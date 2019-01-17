#include "Animator.h"
#include "Clock.h"
#include <iostream>

#define MILLISECOND 0.001f;

Animator::Animator(Texture * pTexture, float fInterval, int nFrameCount, int nPixelWidth, int nPixelHeight)
{
	m_pTexture = pTexture;
	m_fInterval = fInterval * MILLISECOND;
	m_nFrameCount = nFrameCount;
	m_nPixelHeight = nPixelHeight;
	m_nPixelWidth = nPixelWidth;
	m_nCurrentFrame = 0;
}

Animator::~Animator()
{
}

void Animator::Update(float fDeltaTime)
{
	if (!m_bIsActive)
		return;

	float fCurrentTime = Clock::GetInstance()->GetCurrentTime();

	if (fCurrentTime - m_fTimer > m_fInterval)
	{
		m_fTimer = fCurrentTime;

		m_nCurrentFrame++;
		if (m_nCurrentFrame > m_nFrameCount)
			m_nCurrentFrame = 0;
	}
}

void Animator::Draw(Renderer2D* pRenderer, Vector2 v2Pos, float fRot, float fDepth)
{
	if (!m_bIsActive)
		return;

	float fUVStartX = (float)m_nCurrentFrame / m_nFrameCount;
	float fUVWidth = 1.0f / m_nFrameCount;
	pRenderer->setUVRect(fUVStartX, 0.0f, fUVWidth, 1.0f);
	pRenderer->drawSprite(m_pTexture, v2Pos.x, v2Pos.y, m_nPixelWidth, m_nPixelHeight, fRot, fDepth);
	pRenderer->setUVRect(0.0f, 0.0f, 1.0f, 1.0f);
}

void Animator::Start()
{
	m_bIsActive = true;

	m_fTimer = Clock::GetInstance()->GetCurrentTime();
}

void Animator::Restart()
{
	m_nCurrentFrame = 0;
	Start();
}

void Animator::End()
{
	m_bIsActive = false;
}

void Animator::SetFrame(int nFrame)
{
	if (nFrame > m_nFrameCount)
		m_nCurrentFrame = m_nFrameCount;
	else
		m_nCurrentFrame = nFrame;
}
