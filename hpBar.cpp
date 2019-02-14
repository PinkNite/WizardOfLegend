#include "stdafx.h"
#include "hpBar.h"


HPBAR::HPBAR()
	:_x(0), _y(0), _frameY(0), _alpha(255), _width(0), _hpWidth(0), _damageWidth(0), _count(0)
{
}

HPBAR::~HPBAR()
{
}

HRESULT HPBAR::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("hpBar", "resource/UI/hpBar.bmp", 207, 54, 1, 2, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 207, 54);
	_x = x;
	_y = y;
	_width = OBJECT::getImage()->GetWidth();
	_rc = RectMake(_x, _y, _width, OBJECT::getImage()->getFrameHeight());
	_hpWidth = _width;
	return S_OK;
}

void HPBAR::release()
{
}

void HPBAR::update()
{
	_rc = RectMake(_x, _y, _width, OBJECT::getImage()->getFrameHeight());

}

void HPBAR::render(HDC hdc)
{

	//Rectangle(hdc, _x, _y+100, _width, OBJECT::getImage()->getFrameHeight()+_y);

	OBJECT::getImage()->alphaFrameRender(hdc, _rc.left, _rc.top, _width, OBJECT::getImage()->getFrameHeight(), 0, _frameY, _alpha);

}



void HPBAR::setGauge(float hp, float maxHP)
{

	if (hp >= 0)
	{
		hp = hp;
		_width = (hp / maxHP)*OBJECT::getImage()->GetWidth();
	}
	else
	{
		if (_width > 0)
		{
			_width--;
		}

	}
}

void HPBAR::setDamage(int hp)
{

	if (_count % 200 == 0)
	{
		if (_hpWidth > 0)
		{
			//현재 hp와 변동 hp를 구해서 간격을 구함 //변동조건?

			if (_hpWidth > _width)
			{
				_hpWidth--;
			}

		}

		_count = 0;
	}

}


