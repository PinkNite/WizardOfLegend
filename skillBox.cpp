#include "stdafx.h"
#include "skillBox.h"



SKILLBOX::SKILLBOX()
:_frameX(1),_x(0),_y(0),_alpha(255),_alphaBlack(0),_skillCool(0)
{
}

SKILLBOX::~SKILLBOX()
{
}

HRESULT SKILLBOX::init(int x,int y,string imageName, float cool)
{
	_imageName = imageName;
	IMAGEMANAGER->addImage(_imageName, "resource/UI/coolDown.bmp", 60, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skillUI", "resource/UI/skillUI.bmp", 180, 60, 3, 1, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));
	OBJECT::init(x, y, 180, 60);
	_x = x;
	_y = y;
	_pSkillIcon = new SKILLICON;
	_pSkillIcon->init(_x + 8, _y + 8);
	coolDownSetting();

	fontSetting( cool);
	return S_OK;
}

void SKILLBOX::release()
{
	OBJECT::setImage(nullptr);
	
}

void SKILLBOX::update()
{
	coolDownUpdate();
	fontUpdate();
}

void SKILLBOX::render(HDC hdc)
{
	
	OBJECT::getImage()->alphaFrameRender(hdc,_x,_y, _frameX, 0,_alpha);
	_pSkillIcon->render(hdc);
	coolDownRender(hdc);
	fontRender(hdc);

	
}
void SKILLBOX::coolDownSetting()
{
	//픽셀 테스트용
	
		for (int j = 0; j < 4; j++)
		{

			_poly.pos[j].x = 30;//중점
			_poly.pos[j].y = 30;//중점

			switch (j)
			{
			case 1:

				_poly.angle[j] = PI / 2 - 0.06f;
				break;
			default:
				_poly.angle[j] = PI / 2;
				break;
			}
			_poly.isUse = UN_USE;
		}
		_rc = RectMake(0, 0, 60, 60);
}

void SKILLBOX::coolDownUpdate()
{
	
		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 1:
				_poly.pos[j].x = cosf(_poly.angle[j]) * 40 + 30;
				_poly.pos[j].y = -sinf(_poly.angle[j]) * 40 + 30;
				break;
			case 2:
				_poly.pos[j].x = cosf(_poly.angle[j]) * 50 + 30;
				_poly.pos[j].y = -sinf(_poly.angle[j]) * 50 + 30;
				break;

			}

		}

	

	//픽셀테스트용
	
		switch (_poly.isUse)
		{
		case USE:
			_poly.angle[1] -= 0.06f;
			_poly.angle[2] -= 0.06f;
			_skillCool -= 0.06f;

			break;
		case UN_USE:
			_poly.angle[1] = PI / 2 - 0.06f;
			_poly.angle[2] = PI / 2;
			_skillCool = 0;
			break;
		}
		for (int i = 0; i < 2; i++)
		{
			if (_poly.angle[i]<PI / 2 - 2 * PI+0.06f&&_poly.angle[i]>PI/2-2*PI)
			{
				//system("pause");
				if (_poly.angle[i] < PI / 2 + 0.1f)
				{
					_poly.isUse = UN_USE;
				}
			}
			
		}
}

void SKILLBOX::coolDownRender(HDC hdc)
{
	HPEN pen;
	HPEN oldPen;
	HBRUSH brush;
	HBRUSH oldBrush;
	
	
	
		IMAGEMANAGER->findImage(_imageName)->alphaRender(hdc, _x, _y, _alphaBlack);
	switch (_poly.isUse)
	{
	case USE:
		_alphaBlack = 155;
		_alpha = 155;
		pen = CreatePen(PS_SOLID, 0, RGB(255, 0, 255));
		oldPen = (HPEN)SelectObject(IMAGEMANAGER->findImage(_imageName)->getMemDC(), pen);
		brush = CreateSolidBrush(RGB(255, 0, 255));
		oldBrush = (HBRUSH)SelectObject(IMAGEMANAGER->findImage(_imageName)->getMemDC(), brush);
		Polygon(IMAGEMANAGER->findImage(_imageName)->getMemDC(), _poly.pos, 4);


		SelectObject(IMAGEMANAGER->findImage(_imageName)->getMemDC(), oldBrush);
		DeleteObject(brush);
		SelectObject(IMAGEMANAGER->findImage(_imageName)->getMemDC(), oldPen);
		DeleteObject(pen);
		break;
	 default:
		 _alphaBlack=0;
		 _alpha = 255;
		brush = CreateSolidBrush(RGB(0, 0, 0));
		FillRect(IMAGEMANAGER->findImage(_imageName)->getMemDC(), &_rc, brush);
		DeleteObject(brush);
		break;
	}

		

		char str[120];
		sprintf_s(str, "%2d", _poly.isUse);

		TextOut(hdc, _x, _y-300, str, strlen(str));
		sprintf_s(str, "앵글:%.1lf", _poly.angle[1]);

		TextOut(hdc, _x, _y - 400, str, strlen(str));



}

void SKILLBOX::fontSetting(float cool)
{
	_skillCool = cool;
}

void SKILLBOX::fontUpdate()
{
	//_tempFont.str=itoa(_pSkillIcon->getVSkillIcon()[_pSkillIcon->getNum()].coolDown,strTemp,10);
	
}

void SKILLBOX::fontRender(HDC hdc)
{
	fontRender(hdc, _skillCool, "HY센스L", _x+20, _y+20, 20, RGB(255, 255, 255));
	//fontRender(hdc, _tempFont.str, "elephant", _x, _y, 15, RGB(255, 255, 255));
}

void SKILLBOX::fontRender(HDC hdc,float coolTime, const char * str2, int x, int y, int num, COLORREF color)
{
	//RECT _rcText;
	//_rcText = RectMake(x, y, (strlen(str))*(num - 7), num);

	//Rectangle(hdc, _rcText);
	char str3[100];
	SetTextColor(hdc, color);
	HFONT font, oldfont;
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	oldfont = (HFONT)SelectObject(hdc, font);

	//DrawText(hdc, TEXT(str), -1, &_rcText, DT_CENTER);
	sprintf_s(str3, "%.1lf", coolTime);
	TextOut(hdc, x, y, str3, strlen(str3));
	SelectObject(hdc, oldfont);

	DeleteObject(font);
}
