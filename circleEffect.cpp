#include "stdafx.h"
#include "circleEffect.h"

CIRCLEEFFECT::CIRCLEEFFECT()
{
}

CIRCLEEFFECT::~CIRCLEEFFECT()
{
}

void CIRCLEEFFECT::init()
{
	_pCircle = IMAGEMANAGER->addImage("circleEffect", "resource/player/whiteCircle.bmp", 128, 128, true, RGB(255, 0, 255));
	_pTarget = IMAGEMANAGER->addImage("targetEffect", "resource/player/whitePoint.bmp", 16, 16, true, RGB(255, 0, 255));
}

void CIRCLEEFFECT::release()
{
	_pCircle = nullptr;
	_pTarget = nullptr;
}

void CIRCLEEFFECT::update(float fPosX, float fPosY, float fAngle)
{
	_fPosX = fPosX;
	_fPosY = fPosY;
	
	_fTargetPosX = _fPosX + Mins::presentPowerX(fAngle, 72.0f);
	_fTargetPosY = _fPosY + Mins::presentPowerY(fAngle, 72.0f);

}

void CIRCLEEFFECT::render(HDC hdc)
{
	_pCircle->alphaRender(hdc, static_cast<int>(_fPosX) - 64, static_cast<int>(_fPosY) - 64, 128);
	_pTarget->alphaRender(hdc, static_cast<int>(_fTargetPosX) - 8, static_cast<int>(_fTargetPosY) - 8, 128);
}
