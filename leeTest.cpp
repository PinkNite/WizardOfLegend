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
	_pUI = new UI;
	_pUI->init();
	_pItemManager = new ITEMMANAGER;
	_pItemManager->init();

	return S_OK;
}

void LEETEST::release()
{
}

void LEETEST::update()
{
	_pUI->update();
	_pItemManager->update();

}

void LEETEST::render()
{
	_pUI->render(getMemDC());
	_pItemManager->render(getMemDC());

}
