#pragma once

#include "stdafx.h"

class CIRCLEEFFECT {

private:
	float _fPosX;
	float _fPosY;

	float _fTargetPosX;
	float _fTargetPosY;

	image* _pCircle;
	image* _pTarget;

public:
	CIRCLEEFFECT();
	~CIRCLEEFFECT();


	void init();
	void release();
	void update(float fPosX, float fPosY,float fAngle);
	void render(HDC hdc);
};