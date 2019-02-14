#include "stdafx.h"
#include "mpbar.h"

MPBAR::MPBAR()
	:_alpha(255),_x(0),_y(0), _width(0),_count(0),_mpWidth(0)
{
}

MPBAR::~MPBAR()
{
}

HRESULT MPBAR::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addImage("mpBar", "resource/UI/mpBar.bmp", 163, 14, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 163, 14);
	_x = x;
	_y = y;
	_width = OBJECT::getImage()->GetWidth();
	_rc = RectMake(_x, _y, _width, OBJECT::getImage()->GetHeight());
	_mpWidth = _width;
	return S_OK;
}

void MPBAR::release()
{
}

void MPBAR::update()
{
	_rc = RectMake(_x, _y, _width, OBJECT::getImage()->GetHeight());
}

void MPBAR::render(HDC hdc)
{
	
	OBJECT::getImage()->alphaRender(hdc, _rc.left, _rc.top, _width, OBJECT::getImage()->GetHeight() , _alpha);
}
void MPBAR::setGauge(float mp, float maxMP)
{

	if (mp <= 0)
	{
		
		mp = 0;
	}
	if (mp >= maxMP)
	{
		mp = maxMP;
	}
		_mpWidth = (mp / maxMP)*OBJECT::getWidth();
		if (_mpWidth > _width)
		{
			
			_width++;
		}
		else if (_mpWidth < _width)
		{
			_width--;
		}
	
	
		

	
}

