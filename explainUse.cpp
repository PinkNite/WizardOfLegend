#include "stdafx.h"
#include "explainUse.h"



EXPLAINUSE::EXPLAINUSE()
{
}

EXPLAINUSE::~EXPLAINUSE()
{
}

HRESULT EXPLAINUSE::init()
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("explain", "resource/UI/explainUse.bmp", 435, 62, 3, 1, true, RGB(255, 0, 255)));
	return S_OK;
}

void EXPLAINUSE::release()
{
}

void EXPLAINUSE::update()
{
}

void EXPLAINUSE::render()
{
}
