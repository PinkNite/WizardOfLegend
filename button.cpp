#include "stdafx.h"
#include "button.h"


button::button()
{
}


button::~button()
{
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnDownFramePoint, POINT btnUpFramePoint, function<void(void)> cbFunction)
{
	_callbackFunction = move(cbFunction);

	_direction = BUTTONDIRECTION_NULL;

	_x = static_cast<float>(x);
	_y = static_cast<float>(y);

	_btnCollisionFramePoint = btnUpFramePoint;
	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());


	return S_OK;
}

HRESULT button::initRc(const char * imageName, RECT rc, int intervalX, int intervalY, POINT btnCollisionFramePoint, POINT btnDownFramePoint, POINT btnUpFramePoint, function<void(void)> cbFunction)
{
	_callbackFunction = move(cbFunction);

	_direction = BUTTONDIRECTION_NULL;

	_x = static_cast<float>(rc.left);
	_y = static_cast<float>(rc.top);

	_btnCollisionFramePoint = btnCollisionFramePoint;
	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;
	_intervalX = intervalX;
	_intervalY = intervalY;
	
	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMake(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);


	return S_OK;
}



void button::release()
{
}

void button::update()
{
	if (PtInRect(&_rc, _ptMouse))
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			_direction = BUTTONDIRECTION_DOWN;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && _direction == BUTTONDIRECTION_DOWN)
		{
			_direction = BUTTONDIRECTION_UP;
			_callbackFunction();
		}
		else
		{
			_direction = BUTTONDIRECTION_COLLISION;
		}
	}
	else _direction = BUTTONDIRECTION_NULL;


}

void button::render(HDC hdc)
{
	switch (_direction)
	{
		case BUTTONDIRECTION_NULL:	case BUTTONDIRECTION_UP:
			_image->frameRender(hdc, _rc.left, _rc.top,
				_btnUpFramePoint.x, _btnUpFramePoint.y);
		break;
		case BUTTONDIRECTION_DOWN:
			_image->frameRender(hdc, _rc.left, _rc.top,
				_btnDownFramePoint.x, _btnDownFramePoint.y);
		break;
	
	}
}

void button::render(HDC hdc, int moveY)
{
	switch (_direction)
	{
	case BUTTONDIRECTION_NULL:
		_image->frameRender(hdc, _rc.left + _intervalX, _rc.top + _intervalY + moveY,
			_btnUpFramePoint.x, _btnUpFramePoint.y);
		break;
	case BUTTONDIRECTION_COLLISION:
		_image->frameRender(hdc, _rc.left + _intervalX, _rc.top + _intervalY + moveY,
			_btnCollisionFramePoint.x, _btnCollisionFramePoint.y);
		break;
	case BUTTONDIRECTION_UP:
		_image->frameRender(hdc, _rc.left + _intervalX, _rc.top + _intervalY + moveY,
			_btnUpFramePoint.x, _btnUpFramePoint.y);
		break;
	case BUTTONDIRECTION_DOWN:
		_image->frameRender(hdc, _rc.left + _intervalX, _rc.top + _intervalY + moveY,
			_btnDownFramePoint.x, _btnDownFramePoint.y);
		break;
	}
}
