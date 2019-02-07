#include "stdafx.h"
#include "itemManager.h"





ITEMMANAGER::ITEMMANAGER()
{
}

ITEMMANAGER::~ITEMMANAGER()
{
}

HRESULT ITEMMANAGER::init()
{
	_pItem = new ITEM;
	_pItem->init();
	return S_OK;
}

void ITEMMANAGER::release()
{
}

void ITEMMANAGER::update()
{
	_pItem->update();
}

void ITEMMANAGER::render(HDC hdc)
{
	_pItem->render(hdc);
}
