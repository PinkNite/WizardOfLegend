#include "stdafx.h"
#include "stoneStatue.h"

STONESTATUE::STONESTATUE()
{
}

STONESTATUE::~STONESTATUE()
{
}

void STONESTATUE::init(float fLeft, float fRight, int nWidth, int nHeight, image* pImage)
{
	OBJECT::init(fLeft + static_cast<float>(nWidth)/2.0f, fRight + static_cast<float>(nHeight) / 2.0f, nWidth, nHeight);
	OBJECT::setImage(pImage);
}

void STONESTATUE::update()
{
	_pCamera->pushRenderObject(this);
}

void STONESTATUE::release()
{
}

void STONESTATUE::render(HDC hdc)
{
	OBJECT::getImage()->renderCenter(hdc,static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()));
}
