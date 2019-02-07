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
}

void MINTESTSCENE::release()
{
}

void MINTESTSCENE::render()
{
	_pPlayer->render(getMemDC());
}
