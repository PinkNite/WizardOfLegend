#include "stdafx.h"
#include "explainUse.h"



EXPLAINUSE::EXPLAINUSE()
	:_frameX(0), _x(0), _y(0), _isSelect(0), _alpha(255)
{
}

EXPLAINUSE::~EXPLAINUSE()
{
}

HRESULT EXPLAINUSE::init(int x, int y)
{
	_x = x;
	_y = y;
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("explain", "resource/UI/explainUse.bmp", 435, 62, 3, 1, true, RGB(255, 0, 255)));
	return S_OK;
}

void EXPLAINUSE::release()
{
}

void EXPLAINUSE::update()
{


}

void EXPLAINUSE::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, _x, _y, _frameX, 0, _alpha);
}

void EXPLAINUSE::alphaPlus(int alpha)
{
	switch (_frameX)
	{
	case 0:
		_alpha = 255;
		break;
	case 1:
		_alpha += 4;
		if (_alpha > 250)
		{
			_alpha = alpha;
		}
		break;
	}

}
