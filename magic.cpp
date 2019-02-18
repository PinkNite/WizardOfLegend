#include "stdafx.h"
#include "magic.h"

MAGIC::MAGIC()
{
}

MAGIC::~MAGIC()
{
}

void MAGIC::init(int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,const string& strKey)
{
	_fPosX = -2000.0f;
	_fPosY = -2000.0f;
	_nWidth = nWidth;
	_nHeight = nHeight;
	_pImg = pImg;
	_pEffectAni = new animation();
	_pEffectAni->init(_pImg->GetWidth(), _pImg->GetHeight(), nFrameMaxX, nFrameMaxY);
	_pEffectAni->setDefPlayFrame(false, false);
	_pEffectAni->setFPS(nFps);
	_fActiveTime = 0.0f;
	_fTotalTime = fTotalTime;
	_bIsActive = false;
	_bIsPlayer = false;
	_strKey = strKey;
	_bIsAnimation = true;
}

void MAGIC::init(int nWidth, int nHeight, image * pImg, animation * pAni, float fTotalTime, const string & strkey)
{
	_fPosX = -2000.0f;
	_fPosY = -2000.0f;
	_nWidth = nWidth;
	_nHeight = nHeight;
	_pImg = pImg;
	_pEffectAni = pAni;

	_fActiveTime = 0.0f;
	_fTotalTime = fTotalTime;
	_bIsActive = false;
	_bIsPlayer = false;
	_strKey = strkey;
	_bIsAnimation = true;

}

void MAGIC::init(int nWidth, int nHeight, image * pImg, int nFrameX, int nFrameY, float fTotalTime, const string & strkey)
{
	_fPosX = -2000.0f;
	_fPosY = -2000.0f;
	_nWidth = nWidth;
	_nHeight = nHeight;
	_pImg = pImg;
	_pImg->SetFrameX(nFrameX);
	_pImg->SetFrameY(nFrameY);
	_fActiveTime = 0.0f;
	_fTotalTime = fTotalTime;
	_bIsActive = false;
	_bIsPlayer = false;
	_strKey = strkey;
	_bIsAnimation = false;

}

void MAGIC::release()
{

	//delete _pEffectAni;
	_pEffectAni = nullptr;
	_pImg = nullptr;
}

void MAGIC::update()
{
	if (_bIsActive)
	{
		_fActiveTime += TIMEMANAGER->getElapsedTime();

		
		if (_fActiveTime >= _fTotalTime)
		{
			_bIsActive = false;
			return;
		}

		_fPosX += Mins::presentPowerX(_fMoveAngle, _fMoveSpeed * TIMEMANAGER->getElapsedTime());
		_fPosY += Mins::presentPowerY(_fMoveAngle, _fMoveSpeed * TIMEMANAGER->getElapsedTime());
		

		_rcCollision = RectMakeCenter(_fPosX, _fPosY, _nWidth, _nHeight);
		_pEffectAni->frameUpdate(TIMEMANAGER->getElapsedTime());

	}

}

void MAGIC::render(HDC hdc)
{
	if (!_bIsActive)
		return;
	if (_bIsAnimation)
	{
		_pImg->aniRenderCenter(hdc, static_cast<int>(_fPosX), static_cast<int>(_fPosY), _pEffectAni);
	}
	else
	{
		_pImg->frameRenderCenter(hdc, static_cast<int>(_fPosX), static_cast<int>(_fPosY), _pImg->getFrameX(), _pImg->getFrameY());
	}
	//Rectangle(hdc, _rcCollision);
}

void MAGIC::create(float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer)
{
	_fPosX = fPosX;
	_fPosY = fPosY;
	_pEffectAni->start();
	_fActiveTime = 0.0f;
	_bIsActive = true;

	_fMoveAngle = fMoveAngle;
	_fMoveSpeed = fMoveSpeed;
	_bIsPlayer = bIsPlayer;
}

void MAGIC::create(float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer, int nFrameX, int nFrameY)
{
	_fPosX = fPosX;
	_fPosY = fPosY;
	_fActiveTime = 0.0f;
	_bIsActive = true;
	_fMoveAngle = fMoveAngle;
	_fMoveSpeed = fMoveSpeed;
	_bIsPlayer = bIsPlayer;
	_pImg->SetFrameX(nFrameX);
	_pImg->SetFrameY(nFrameY);
}

void MAGIC::returnPool()
{
	_fActiveTime = 0.0f;
	_fPosX = -2000;
	_fPosY = -2000;
	_pEffectAni->stop();
	_fMoveAngle = 0.0f;
	_fMoveSpeed = 0.0f;
}
