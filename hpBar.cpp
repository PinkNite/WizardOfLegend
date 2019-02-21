#include "stdafx.h"
#include "hpBar.h"


HPBAR::HPBAR()
	:_x(0), _y(0), _frameY(0), _alpha(255), _width(0), _hpWidth(0), _count(0),_count2(0)
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

HRESULT HPBAR::initBoss(int x, int y)
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



void HPBAR::setGauge(float currentHp, float maxHP)
{
	 hp= currentHp;
	
	if (hp >= maxHP)
	{
		hp = maxHP;
		

	}
	else if (hp <= 0)
	{

		hp = 0;
		
	}
	
		_tempHp = (hp / maxHP)*OBJECT::getImage()->GetWidth();//비율값 넓이
	
	if (_tempHp < _width)//현재 체력 넓이가 그려지는 hp보다 높으면 현재 체력비율넓이까지 줄임 
	{
		
			_width--;
		
	}

	else if (_tempHp > _width)//현재 체력 넓이가 높아지면 현제 체력 비율넓이를 올림 현재 체력 넓이까지
	{
		
			_width++;
		
	}
	
		
	

}

void HPBAR::setDamage(float currentHp, float maxHP)
{
	float hp = currentHp;
	if (hp >= maxHP)
	{
		hp = maxHP;
	}
	if (hp <= 0)
	{
		hp = 0;
	}
	_count2++;
	_hpWidth = (hp / maxHP)*OBJECT::getImage()->GetWidth();
	
	if (_count2 % 3 == 0)
	{

		if (_hpWidth < _width)
		{
			_width--;
		}
		if (_hpWidth > _width+1)
		{
			_width++;
		}

		_count2 = 0;
	}



}


