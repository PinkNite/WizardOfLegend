#include "stdafx.h"
#include "introScene.h"




INTROSCENE::INTROSCENE()
{
}

INTROSCENE::~INTROSCENE()
{
}

HRESULT INTROSCENE::init()
{
	imageSetting();
	return S_OK;
}

void INTROSCENE::release()
{
	_title.image = nullptr;
	_99.image = nullptr;
	_logo.image = nullptr;
	_introPeople.image = nullptr;
	_hello.image = nullptr;
}

void INTROSCENE::update()
{
}

void INTROSCENE::render()
{
	//IMAGEMANAGER->findImage("title")->alphaRender(getMemDC(), 0, 0,255);
	_99.image->alphaRender(getMemDC(),_99.x,_99.y,_99.alpha);
	//_title.image->alphaRender(getMemDC(),_title.x,_title.y,_title.alpha);
	//_logo.image->alphaRender(getMemDC(),_logo.x,_logo.y,_logo.alpha);
	//_introPeople.image->alphaRender(getMemDC(),_introPeople.x,_introPeople.y, _introPeople.alpha);
	//_hello.image->alphaRender(getMemDC(), _hello.x,_hello.y,_hello.alpha);
}

void INTROSCENE::imageSetting()
{
	//ÀÌ¹ÌÁö
	_title.image = new image;
	_title.image = IMAGEMANAGER->addImage("title", "resource/intro/title.bmp", 1422, 800, false, RGB(0, 0, 0));
	_title.alpha = 255;
	_title.x = 0;
	_title.y = 0;
	_logo.image = new image;
	_logo.image = IMAGEMANAGER->addImage("logo", "resource/intro/logo.bmp", 1422, 800, true, RGB(255, 0, 255));
	_logo.alpha = 255;
	_logo.x = 0;
	_logo.y = 0;
	_99.image = new image;
	_99.image = IMAGEMANAGER->addImage("99small", "resource/intro/99small.bmp", 1422, 800, true, RGB(255, 0, 255));
	_99.alpha = 255;
	_99.x = 0;
	_99.y = 0;

	//=IMAGEMANAGER->addImage("99big", "resource/intro/99big.bmp", 524, 236, true, RGB(255, 0, 255));
	_introPeople.image = new image;
	_introPeople.image = IMAGEMANAGER->addImage("introPeople", "resource/intro/introPeople.bmp", 200, 200, true, RGB(255, 0, 255));
	_introPeople.alpha = 255;
	_introPeople.x = WINSIZEX/2-32;
	_introPeople.y = WINSIZEY / 2 - 32;
	_hello.image = new image;
	_hello.image = IMAGEMANAGER->addFrameImage("hello", "resource/intro/hello.bmp", 240, 78, 4, 1, true, RGB(255, 0, 255));
	_hello.alpha = 255;
	_hello.x = WINSIZEX - IMAGEMANAGER->findImage("hello")->getFrameWidth() - 10;
	_hello.y = WINSIZEY - IMAGEMANAGER->findImage("hello")->getFrameHeight() - 10;

}

