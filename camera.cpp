#include "stdafx.h"
#include "camera.h"

CAMERA::CAMERA()
{
}

CAMERA::~CAMERA()
{
}



void CAMERA::init(int posX, int posY, int windowWidth, int windowHeight, int mapWidth, int mapHeight)
{
	_posX = static_cast<float>(posX);
	_posY = static_cast<float>(posY);
	_width = windowWidth;
	_height = windowHeight;
	setLeftTop();
	_nMapHeight = mapHeight*2;
	_nMapWidth = mapWidth*2;

	_rcCameraLimit = { 0,0,windowWidth,windowHeight };

	_pCameraBuffer = IMAGEMANAGER->addImage("camera", _width, _height);
	_listRenderObject.clear();
}

void CAMERA::update()
{
	_listRenderObject.clear();

}

void CAMERA::render(HDC hdc)
{
	list<OBJECT*>::iterator	iter = _listRenderObject.begin();
	list<OBJECT*>::iterator	end = _listRenderObject.end();

	while (iter != end)
	{
		OBJECT* pObject = (*iter);
		if (pObject->getPosX() > _left + 64 &&
			pObject->getPosY() > _top + 64 &&
			pObject->getPosX() < _left + _width + 64 &&
			pObject->getPosY() < _top + _height + 64 )
		{
			pObject->render(getMemDC());
		}
		iter++;
	}

	_pCameraBuffer->render(hdc, 0, 0, _left, _top, _width, _height);
}

void CAMERA::release()
{
	_listRenderObject.clear();
}

void CAMERA::renderinit()
{
	PatBlt(_pCameraBuffer->getMemDC(), 0, 0, _nMapWidth, _nMapHeight, BLACKNESS);
	
}

void CAMERA::setting(int nPosX, int nPosY)
{
	_posX = static_cast<float>(nPosX);
	_posY = static_cast<float>(nPosY);
	//outOfRange();
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

void CAMERA::setCameraBuffer(image * pImg)
{
	_pCameraBuffer = pImg;
	_nMapHeight = _pCameraBuffer->GetHeight();
	_nMapWidth = _pCameraBuffer->GetWidth();
}

void CAMERA::pushRenderObject(OBJECT * pObject)
{
	//���ĵ� �Ǿ��Ѵ�
	float fZorder = pObject->getPosY();// +static_cast<float>(pObject->getPosZ());

	list<OBJECT*>::iterator	iter = _listRenderObject.begin();
	list<OBJECT*>::iterator	end = _listRenderObject.end();

	bool bIsSearch = false;

	while (iter != end)
	{
		float fTmp = (*iter)->getPosY();// +static_cast<float>((*iter)->getPosZ());
		if (fTmp > fZorder)
		{
			_listRenderObject.insert(iter, pObject);
			iter = end;
			bIsSearch = true;
		}
		else
		{
			iter++;
		}
	}

	if (!bIsSearch)
	{
		_listRenderObject.push_back(pObject);
	}

}
