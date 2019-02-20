#include "stdafx.h"
#include "magic.h"
#include "camera.h"
#include "player.h"
MAGIC::MAGIC()
{
}

MAGIC::~MAGIC()
{
}

void MAGIC::init(int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, const string& strKey, bool bIsCollisionRemove)
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
	_bIsTrun = false;
	_fTurnTime = 0.0f;
	OBJECT::setPosX(_fPosX);
	OBJECT::setPosY(_fPosY);
	OBJECT::setPosZ(nHeight);
	OBJECT::setHeight(nHeight);
	OBJECT::setImage(pImg);
	_fDamage = 10.0f;
	_bIsCollisionRemove = bIsCollisionRemove;
}

void MAGIC::init(int nWidth, int nHeight, image * pImg, animation * pAni, float fTotalTime, const string & strkey, bool bIsCollisionRemove)
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
	_bIsTrun = false;
	_fTurnTime = 0.0f;
	OBJECT::setPosX(_fPosX);
	OBJECT::setPosY(_fPosY);
	OBJECT::setPosZ(nHeight);
	OBJECT::setHeight(nHeight);
	OBJECT::setImage(pImg);
	_fDamage = 10.0f;
	_bIsCollisionRemove = bIsCollisionRemove;

}

void MAGIC::init(int nWidth, int nHeight, image * pImg, int nFrameX, int nFrameY, float fTotalTime, const string & strkey, bool bIsCollisionRemove)
{
	_fPosX = -2000.0f;
	_fPosY = -2000.0f;
	_nWidth = nWidth;
	_nHeight = nHeight;
	_pImg = pImg;
	_nFrameX = nFrameX;
	_nFrameY = nFrameY;
	_fActiveTime = 0.0f;
	_fTotalTime = fTotalTime;
	_bIsActive = false;
	_bIsPlayer = false;
	_strKey = strkey;
	_bIsAnimation = false;
	_bIsTrun = false;
	_fTurnTime = 0.0f;
	OBJECT::setPosX(_fPosX);
	OBJECT::setPosY(_fPosY);
	OBJECT::setPosZ(nHeight);
	OBJECT::setHeight(nHeight);
	OBJECT::setImage(pImg);
	_fDamage = 10.0f;
	_bIsCollisionRemove = bIsCollisionRemove;

}

void MAGIC::init(int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, float fTurnTime, const string & strKey)
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
	_bIsTrun = true;
	_fTurnTime = fTurnTime;


	OBJECT::setPosX(_fPosX);
	OBJECT::setPosY(_fPosY);
	OBJECT::setPosZ(nHeight);
	OBJECT::setHeight(nHeight);
	OBJECT::setImage(pImg);
	_fDamage = 10.0f;
	_bIsCollisionRemove = false;
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
		if (isCollisionWall()) {
			_bIsActive = false;
			if (!_bIsPlayer)
			{
				_bIsTrun = true;
			}

			return;
		}

		if (_fActiveTime >= _fTotalTime)
		{


			_bIsActive = false;
			if (!_bIsPlayer)
			{
				_bIsTrun = true;
			}

			return;
		}


		if (!_bIsTrun)
		{
			_fPosX += Mins::presentPowerX(_fMoveAngle, _fMoveSpeed * TIMEMANAGER->getElapsedTime());
			_fPosY += Mins::presentPowerY(_fMoveAngle, _fMoveSpeed * TIMEMANAGER->getElapsedTime());

		}
		else if (!_bIsPlayer)
		{
			if (_fActiveTime <= _fTurnTime)
			{
				_fMoveAngle += PI2 / 18;
				//
				_fPosX = _fCirclePosX + Mins::presentPowerX(_fMoveAngle, _fMoveSpeed);
				_fPosY = _fCirclePosY + Mins::presentPowerY(_fMoveAngle, _fMoveSpeed);
			}
			else
			{
				if (_bIsTrun)
				{
					_bIsTrun = false;
					_fMoveAngle = getAngle(_fPosX, _fPosY, _pPlayer->getPosX(), _pPlayer->getPosY());
					_fMoveSpeed = 1000.0f;
				}
			}

		}
		OBJECT::setPosX(_fPosX);
		OBJECT::setPosY(_fPosY);

		if (!_bIsDamage)
		{
			_rcCollision = RectMakeCenter(_fPosX, _fPosY, _nWidth, _nHeight);
		}
		else
		{
			_rcCollision = RectMakeCenter(0, 0, 0, 0);
		}

		if (_bIsAnimation)
		{
			_pEffectAni->frameUpdate(TIMEMANAGER->getElapsedTime());
		}


	}


	_pCamera->pushRenderObject(this);

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
		_pImg->frameRenderCenter(hdc, static_cast<int>(_fPosX), static_cast<int>(_fPosY), _nFrameX, _nFrameY);
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
	setIsDamage(false);
	_rcCollision = RectMakeCenter(_fPosX, _fPosY, _nWidth, _nHeight);

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
	_nFrameX = nFrameX;
	_nFrameY = nFrameY;
	setIsDamage(false);
	_rcCollision = RectMakeCenter(_fPosX, _fPosY, _nWidth, _nHeight);

}


void MAGIC::create(bool bIsPlayer, float fCirclePosX, float fCirclePosY, float fRadius, float fAngle)
{
	_fCirclePosX = fCirclePosX;
	_fCirclePosY = fCirclePosY;


	_pEffectAni->start();
	_fActiveTime = 0.0f;
	_bIsActive = true;

	_fMoveAngle = fAngle;
	_fMoveSpeed = fRadius * 2.0f;

	_fPosX = _fCirclePosX + Mins::presentPowerX(_fMoveAngle, _fMoveSpeed);
	_fPosY = _fCirclePosY + Mins::presentPowerY(_fMoveAngle, _fMoveSpeed);


	_bIsPlayer = bIsPlayer;
	setIsDamage(false);
	_rcCollision = RectMakeCenter(_fPosX, _fPosY, _nWidth, _nHeight);

}

void MAGIC::returnPool()
{
	_fActiveTime = 0.0f;
	_fPosX = -2000;
	_fPosY = -2000;
	if (_bIsAnimation)
	{
		_pEffectAni->stop();
	}
	_fMoveAngle = 0.0f;
	_fMoveSpeed = 0.0f;
}

bool MAGIC::isCollisionWall()
{
	if (!_bIsCollisionRemove)
	{
		return false;
	}

	RECT rcTmp;
	bool bIsCollision = false;

	//3칸을 보고 밀자?
	//자신 밑 옆을 보고 못가면 좌표계만 밀고
	//자신의 밑 아래를 보고 못가면 좌표계만 밀어버린다
	//그리고 setting을 한다
	//왼쪽이 비면 가고
	//위쪽이 비면 간다
	int	nTileIndexX = 0;
	int	nTileIndexY = 0;
	nTileIndexX = static_cast<int>(_fPosX) / _pMap->getTileSize();
	nTileIndexY = (static_cast<int>(_fPosY) + (_height / 2)) / _pMap->getTileSize();
	RECT rcCollision = RectMakeCenter(_fPosX, (_fPosY)+(_height / 2), 16, 16);
	if (IntersectRect(&rcTmp, &_pMap->getTile(nTileIndexX, nTileIndexY)->getRectTile(), &rcCollision))
	{
		if (_pMap->getTile(nTileIndexX, nTileIndexY)->getTerrian() != TILE::TERRIAN::PASS)
		{
			return true;
		}
	}

	return false;
}
