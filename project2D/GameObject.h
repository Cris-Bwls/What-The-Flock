#pragma once
#include <string>
#include "Matrix3.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ETag.h"

using std::string;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Reset();

	virtual inline void Update(float fDeltaTime) {};
	virtual inline void Draw(aie::Renderer2D* pRenderer2D) {};

	inline Matrix3 GetTransform() { return m_m3Transform; };
	inline void SetPos(Vector2 v2NewPos) { m_m3Transform.SetPosition(v2NewPos); };
	inline Vector2 GetPos() { return m_m3Transform.GetPosition(); };
	inline void SetRotation(float fNewRot) { m_m3Transform.SetRotate2D(fNewRot); m_fRotation = fNewRot; };
	inline float GetRotation() { return m_fRotation; };

	inline void SetIsAlive(bool bIsAlive) { m_bIsAlive = bIsAlive; };
	inline bool GetIsAlive() { return m_bIsAlive; };

	inline ETag GetTag() { return m_eTag; };

protected:
	aie::Texture* m_pTexture;

	Matrix3 m_m3Transform;
	float	m_fRotation;
	bool	m_bIsAlive;
	ETag m_eTag = ETag::GameObject;
};

