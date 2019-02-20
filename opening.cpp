#include "stdafx.h"
#include "opening.h"




OPENING::OPENING()
	:_jumpPower(0), _time(NULL), _fontX(0), _angle(0), _speed(7), _count(0), _end(0), _timer(0), _jumpCount(0), _gravity(0), _isStart(0), _saveTime(0)
{
}

OPENING::~OPENING()
{
}

HRESULT OPENING::init()
{
	_fontX = WINSIZEX / 2 - 200;
	for (int i = 0; i < 8; i++)
	{

		_arrFontY[i] = WINSIZEY / 2 - 200;

	}
	_angle = PI;
	_gravity = 0.6f;
	_jumpCount = 1;
	setImage();
	_pMenu = new MENU;
	_pMenu->init();

	return S_OK;
}

void OPENING::release()
{
	_title.image = nullptr;
	_99.image = nullptr;
	_logo.image = nullptr;
	_introPeople.image = nullptr;
	_hello.image = nullptr;
}

void OPENING::update()
{
	_pMenu->update();
	//시간을 계산할 식
	_time += TIMEMANAGER->getElapsedTime();

	//이미지 오프
	if (_jumpCount != 2)
	{
		openingMove();

	}
	helloManMove();//움직이는 나그네

	//임시
	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		_jumpCount = 2;
	}

	//엔터키나 마우스클릭하면 버튼 화면 사라짐
	if (_jumpCount == 2 && !_pMenu->getPressButton()&& (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) || KEYMANAGER->isOnceKeyDown(VK_RETURN)))
	{
		_pMenu->setPressButton(1);
		//로고창 위로 살짝
		_saveTime = _time;
	}
	if (_pMenu->getPressButton())
	{
		//로고창 위로 살짝
		if (_logo.y > -150)
		{
			_logo.y -= 10;

		}
		if (_title.alpha > 125 && _logo.alpha > 125)
		{
			_title.alpha = 120;
			_logo.alpha = 120;
		}
		//버튼 클릭

		if (_time > _saveTime + 1)
		{
			_pMenu->buttonClick();
		}
	}
	_pMenu->update();
}

void OPENING::render(HDC hdc)
{
	
	if (_time < 6)
	{
		_99.image->alphaRender(hdc, _99.x, _99.y, _99.alpha);
	}
	if (_time > 6 && _time < 16)
	{
		_introPeople.image->alphaRender(hdc, _introPeople.x, _introPeople.y, _introPeople.alpha);
	}
	if (_time < 18)
	{
		fontMove(hdc);
	}
	if (_time > 20)
	{
		_title.image->alphaRender(hdc, _title.x, _title.y, _title.alpha);
	}
	if (_time > 20)
	{
		_logo.image->alphaRender(hdc, _logo.x, _logo.y, _logo.alpha);
		_pMenu->pressRender(hdc);
	}

	if (_jumpCount == 2)
	{
		_pMenu->render(hdc);
	}
	
}

void OPENING::setImage()
{

	//이미지
	_title.image = new image;
	_title.image = IMAGEMANAGER->addImage("title", "resource/intro/title.bmp", 1600, 900, false, RGB(0, 0, 0));
	_title.alpha = 0;
	_title.x = 0;
	_title.y = 0;
	_logo.image = new image;
	_logo.image = IMAGEMANAGER->addImage("logo", "resource/intro/logo.bmp", 1600, 900, true, RGB(255, 0, 255));
	_logo.alpha = 255;
	_logo.x = 0;
	_logo.y = -700;
	_99.image = new image;
	_99.image = IMAGEMANAGER->addImage("99small", "resource/intro/99small.bmp", 1600, 900, true, RGB(255, 0, 255));
	_99.alpha = 255;
	_99.x = 0;
	_99.y = 0;

	//=IMAGEMANAGER->addImage("99big", "resource/intro/99big.bmp", 524, 236, true, RGB(255, 0, 255));
	_introPeople.image = new image;
	_introPeople.image = IMAGEMANAGER->addImage("introPeople", "resource/intro/introPeople.bmp", 200, 200, true, RGB(255, 0, 255));
	_introPeople.alpha = 0;
	_introPeople.x = WINSIZEX / 2 - _introPeople.image->GetWidth() / 2;
	_introPeople.y = WINSIZEY / 2 - _introPeople.image->GetHeight() / 2;

	//키애니메이션
	_hello.image = new image;
	_hello.image = IMAGEMANAGER->addFrameImage("hello", "resource/intro/hello.bmp", 240, 78, 4, 1, true, RGB(255, 0, 255));
	_hello.alpha = 0;
	_hello.x = WINSIZEX - IMAGEMANAGER->findImage("hello")->getFrameWidth() - 10;
	_hello.y = WINSIZEY - IMAGEMANAGER->findImage("hello")->getFrameHeight() - 10;
	_hello.currentX = 0;
	_hello.currentY = 0;
	_hello.speed = 0;

	



}

void OPENING::helloManMove()
{
	//충돌
	if (isCollision(_fontX + 350, _arrFontY[7], _hello.x, _hello.y))
	{
		_hello.speed = 25;
	}
	_hello.x -= _hello.speed;
	_hello.y -= _hello.speed;
}

void OPENING::openingMove()
{
	actionOff(3, 6, &_99.alpha, 5);
	actionOn(6, 16, &_introPeople.alpha, 5);
	actionOff(16, 20, &_introPeople.alpha, 5);
	actionOn(20, 24, &_title.alpha, 5);
	//글자를 떨굼
	actionJump(20, 24, &_logo.y, &_title.y);//2024
}

void OPENING::fontMove(HDC hdc)
{
	
	

	if (_time < 20)
	{
		for (int i = 0; i < 8; i++)
		{

			switch (i)
			{
			case 0:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "P", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 1:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "I", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 2:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "N", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 3:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "K", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 4:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "N", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 5:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "I", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 6:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "T", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 7:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(hdc, "E", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f&&_time < 18)
					{
						
						if (_time < 14)
						{
							_angle += 0.1f;
						}
						if(_time>14)
						{
							
							_angle = getAngle(_fontX + i * 50, _arrFontY[i], _hello.x+30, _hello.y+30);
							_angle = 2 * PI - PI / 6;
						}
						
						_speed += 0.1f;
						_fontX += cosf(_angle) * _speed;

						_arrFontY[i] += -sinf(_angle) * _speed;
						if (isCollision(_fontX + i * 50, _arrFontY[i], _hello.x + 30, _hello.y + 30))
						{
							_angle = 2 * PI - PI / 6;
						}
					}
				}
				break;

			}

		}
	}
	if (_time > 6 && _time < 20)
	{
		draw(hdc);
	}
	if (_jumpCount == 2)
	{
		//이쪽에 메뉴렌더
	}
}

void OPENING::actionOff(float numA, float numB, int * alpha, int numC)
{
	//이 이미지가 몇초있다 사라지게  함 그 함수를 만들자
	if (numA <= _time && (*alpha) > 0 && numB >= _time)//에이와 비사이의 시간에 작동
	{
		//0보다 크면 계속 알파값 줄여나감
		//system("pause");

		(*alpha) -= numC;
	}
}

void OPENING::actionOn(float numA, float numB, int * alpha, int numC)
{
	//이 이미지가 몇초있다 사라지게  함 그 함수를 만들자
	if (numA <= _time && (*alpha) < 255 && numB >= _time)//에이와 비사이의 시간에 작동
	{
		//0보다 크면 계속 알파값 줄여나감


		(*alpha) += numC;
	}
}

void OPENING::actionJump(float numA, float numB, float * y, float * y2)
{
	//중력받고 해당된 시간에 떨어진다 카운트값 1상태
	//해당 좌표를 지나치면 다시 점프파워를 획득한다.

	if (_time >= numA && _jumpCount == 1)
	{
		(*y) -= _jumpPower;
		_jumpPower -= _gravity;
		if ((*y) >= 0)
		{

			_jumpCount--;
		}
	}
	if (_jumpCount == 0)
	{
		_jumpPower = 10.5f;
		_jumpCount = 3;

	}
	if (_jumpCount == 3)
	{

		(*y) -= _jumpPower;

		if ((*y) <= 0)
		{
			_jumpPower -= _gravity;
		}
		if ((*y) >= 0)
		{
			(*y) = 0;
			*y2 = 0;
			_jumpCount = 2;
		}
		_timer = _time;

	}


	if (_jumpCount == 3 && _timer <= _time + 2.0f)//_time > numB
	{
		(*y2) = RND->getFromIntTo(0, 10);

	}
}

void OPENING::fontRender(HDC hdc, const char * str, const char * str2, int x, int y, int num, COLORREF color)
{
	//char str1[500];
	//SetTextColor(hdc, color);
	//HFONT font, oldfont;
	//SetBkMode(hdc, TRANSPARENT);
	//font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	//oldfont = (HFONT)SelectObject(hdc, font);
	//sprintf_s(str1, str);
	//TextOut(hdc, x, y, str, strlen(str));
	////DeleteObject(oldfont);
	//DeleteObject(font);

	RECT rcText;
	rcText = RectMakeCenter(x, y, strlen(str)*num, num);


	char str1[500];
	SetTextColor(hdc, color);
	HFONT font, oldfont;
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	oldfont = (HFONT)SelectObject(hdc, font);

	DrawText(hdc, TEXT(str), strlen(str), &rcText, DT_CENTER);
	SelectObject(hdc, oldfont);

	DeleteObject(font);
}

void OPENING::draw(HDC hdc)
{
	_count++;
	if (_count % 10 == 0)
	{
		_hello.currentX++;
		if (_hello.currentX > _hello.image->getMaxFrameX())
		{
			_hello.currentX = 0;
		}
		_count = 0;
	}

	_hello.image->frameRender(hdc, _hello.x, _hello.y, _hello.currentX, _hello.currentY);
}

bool OPENING::isCollision(int x, int y, int x2, int y2)
{
	//반지름 5로 가정
	RECT rc = RectMake(x2, y2, 100, 100);
	if (PtInRect(&rc, PointMake(x, y)))
	{

		return true;
	}
	return false;
}


