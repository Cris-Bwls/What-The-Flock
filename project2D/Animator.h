#pragma once
#include "Texture.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "ETag.h"

using aie::Texture;
using aie::Renderer2D;

class Animator
{
public:
	Animator(Texture* pTexture, float fInterval, int nFrameCount, int nPixelWidth, int nPixelHeight);
	~Animator();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* pRenderer, Vector2 v2Pos, float fRot = 0.0f, float fDepth = 0.0f);

	void Start();
	void Restart();
	void End();

	void SetFrame(int nFrame);

	inline void SetTag(ETag eTag) { m_eTag = eTag; };
	inline ETag GetTag() { return m_eTag; };

private:
	bool m_bIsActive = false;

	Texture* m_pTexture;

	float m_fTimer;
	float m_fInterval;

	int m_nFrameCount;
	int m_nCurrentFrame;

	int m_nPixelWidth;
	int m_nPixelHeight;

	ETag m_eTag = ETag::Animator;
};

