#pragma once
#include "GameObject.h"
#include "Bounds.h"

class AreaObject :
	public GameObject
{
public:
	AreaObject();
	~AreaObject();

	Bounds m_Bounds;
};

