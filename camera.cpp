#include "stdafx.h"
#include "camera.h"

CAMERA::CAMERA()
{
}

CAMERA::~CAMERA()
{
}

void CAMERA::init(int posX, int posY, int width, int height)
{
	_posX = static_cast<float>(posX);
	_posY = static_cast<float>(posY);
	_width = width;
	_height = height;
	setLeftTop();

	_rcCameraLimit = { 0,0,_width,_height };

	_pCameraBuffer = IMAGEMANAGER->addImage("camera", _width, _height);
}

void CAMERA::update()
{
}

void CAMERA::render(HDC hdc)
{
	_pCameraBuffer->render(hdc, 0, 0, _left, _top, _width, _height);
}

void CAMERA::renderinit()
{
	PatBlt(_pCameraBuffer->getMemDC(), 0, 0, _width, _height, WHITENESS);

}

void CAMERA::setting(int nPosX, int nPosY)
{
	_posX = static_cast<float>(nPosX);
	_posY = static_cast<float>(nPosY);
	outOfRange();
	setLeftTop();
}



void CAMERA::settingCameraRange(int nLeft, int nTop, int nRight, int nBottom)
{
	_rcCameraLimit = { nLeft,nTop,nRight,nBottom };
}

void CAMERA::setLeftTop()
{
	_left = static_cast<int>(_posX) - _width / 2;
	_top  = static_cast<int>(_posY) - _height / 2;
}

void CAMERA::moveRight(float offset)
{
	_posX += offset;
	if (_posX + _width / 2 >= _rcCameraLimit.right)
	{
		_posX = static_cast<float>(_rcCameraLimit.right - _width / 2);
	}
	setLeftTop();

}

void CAMERA::moveLeft(float offset)
{
	_posX -= offset;
	if (_posX - _width / 2 <= 0)
	{
		_posX = static_cast<float>(_width / 2);
	}
	setLeftTop();

}

void CAMERA::moveUp(float offset)
{
	_posY -= offset;
	if (_posY - _height / 2 <= 0)
	{
		_posY = static_cast<float>(_height / 2);
	}
	setLeftTop();

}

void CAMERA::moveDown(float offset)
{
	_posY += offset;

	if (_posY + _height / 2 >= _rcCameraLimit.bottom)
	{
		_posY = static_cast<float>(_rcCameraLimit.bottom - _height / 2);
	}
	setLeftTop();
}

void CAMERA::outOfRange()
{
	if (_posX + _width / 2 >= _rcCameraLimit.right)
	{
		_posX = static_cast<float>(_rcCameraLimit.right - _width / 2);
	}
	else if (_posX - _width / 2 <= 0)
	{
		_posX = static_cast<float>(_width / 2);
	}

	if (_posY - _height / 2 <= 0)
	{
		_posY = static_cast<float>(_height / 2);
	}
	else if (_posY + _height / 2 >= _rcCameraLimit.bottom)
	{
		_posY = static_cast<float>(_rcCameraLimit.bottom - _height / 2);
	}
}
