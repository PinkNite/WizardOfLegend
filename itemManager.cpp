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
	for (int i = 0; i < 12; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init(-100, -100);

	}
	return S_OK;
}

void ITEMMANAGER::release()
{
}

void ITEMMANAGER::update()
{
	for (int i = 0; i < 12; i++)
	{
		_pItem[i]->update();
	}
}

void ITEMMANAGER::render(HDC hdc)
{
	for (int i = 0; i < 12; i++)
	{

		_pItem[i]->render(hdc);
	}
}
