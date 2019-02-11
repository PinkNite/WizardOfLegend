#include "stdafx.h"
#include "skillEffect.h"

SKILL_EFFECT::SKILL_EFFECT():
	_fPosX(0.0f),
	_fPosY(0.0f),
	_pImg(nullptr),
	_bIsActivity(false),
	_pAni(nullptr)
{
}

SKILL_EFFECT::~SKILL_EFFECT()
{
}

void SKILL_EFFECT::init(image * pImg, int nFPS, int nFrameMaxX, int nFrameMaxY)
{
	_fPosX = -2000.0f;
	_fPosY = -2000.0f;
	_pImg = pImg;
	_bIsActivity = false;
	_pAni = new animation;

	_pAni->init(_pImg->GetWidth(), _pImg->GetHeight(), nFrameMaxX, nFrameMaxY);
	_pAni->setDefPlayFrame(false, false);
	_pAni->setFPS(nFPS);
	_pAni->stop();

}

void SKILL_EFFECT::create(float fPosX, float fPosY)
{
	_fPosX = fPosX;
	_fPosY = fPosY;
	_bIsActivity = true;
	_pAni->start();
}

void SKILL_EFFECT::update()
{
	if (_bIsActivity && !_pAni->isPlay())
	{
		_bIsActivity = false;
	}
}

void SKILL_EFFECT::release()
{
	_pAni->release();
	delete _pAni;
	_pAni = nullptr;
	_pImg = nullptr;
}

void SKILL_EFFECT::render(HDC hdc)
{
	if (_bIsActivity)
	{
		_pImg->aniRenderCenter(hdc, static_cast<int>(_fPosX), static_cast<int>(_fPosY), _pAni);
	}
}

bool SKILL_EFFECT::deleteEffect()
{
	if (_bIsActivity)
	{
		return false;
	}
	else {
		return true;
	}
	
}
