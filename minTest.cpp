#include "stdafx.h"
#include "minTest.h"

MINTESTSCENE::MINTESTSCENE()
{
}

MINTESTSCENE::~MINTESTSCENE()
{
}

HRESULT MINTESTSCENE::init()
{
	_pPlayer = new PLAYER();
	_pPlayer->init();
	_fTime = 0.0f;
	return S_OK;
}

void MINTESTSCENE::update()
{
	_fTime += TIMEMANAGER->getElapsedTime();
	if (_fTime > 2.0f) {
		_pPlayer->update();
	}
	_pPlayer->update();
}

void MINTESTSCENE::release()
{
	_pPlayer->release();
}

void MINTESTSCENE::render()
{
	_pPlayer->render(getMemDC());
	char str[20]{};
	sprintf_s(str, "%f", _fTime);
	TextOut(getMemDC(), 400, 400, str, strlen(str));
}
