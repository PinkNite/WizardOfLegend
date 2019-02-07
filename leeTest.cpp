#include "stdafx.h"
#include "leeTest.h"




LEETEST::LEETEST()
{
}

LEETEST::~LEETEST()
{
}

HRESULT LEETEST::init()
{
	_pItemManager = new ITEMMANAGER;
	_pItemManager->init();
	return S_OK;
}

void LEETEST::release()
{
}

void LEETEST::update()
{
	_pItemManager->update();
}

void LEETEST::render()
{
	_pItemManager->render(getMemDC());
}
