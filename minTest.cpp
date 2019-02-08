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
	return S_OK;
}

void MINTESTSCENE::update()
{
	
	_pPlayer->update();
}

void MINTESTSCENE::release()
{
	_pPlayer->release();
}

void MINTESTSCENE::render()
{
	_pPlayer->render(getMemDC());

}
