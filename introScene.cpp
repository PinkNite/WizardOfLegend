#include "stdafx.h"
#include "introScene.h"




INTROSCENE::INTROSCENE()
	:_jumpPower(0), _time(NULL), _fontX(0), _angle(0), _speed(7), _count(0), _end(0), _timer(0), _jumpCount(0), _gravity(0), _isStart(0),
	_menuCount(0), _saveTime(0)
{
}

INTROSCENE::~INTROSCENE()
{
}

HRESULT INTROSCENE::init()
{
	//_time = 0;
	_fontX = WINSIZEX / 2 - 200;
	for (int i = 0; i < 8; i++)
	{

		_arrFontY[i] = WINSIZEY / 2 - 200;

	}
	_angle = PI;
	_gravity = 0.6f;
	_jumpCount = 1;
	//버튼들
	_pressButton.r = 255;
	_pressButton.g = 255;
	_pressButton.b = 255;
	_pressButton.count = 0;
	_pressButton.x = WINSIZEX / 2;//WINSIZEX / 2 - 70;
	_pressButton.y = WINSIZEY - 100;
	_pressButton.isSelect = false;
	_singlePlayer.r = 255;
	_singlePlayer.g = 255;
	_singlePlayer.b = 255;
	_singlePlayer.count = 0;
	_singlePlayer.size = 30;
	_singlePlayer.x = WINSIZEX / 2;//WINSIZEX / 2 - 75;
	_singlePlayer.y = WINSIZEY - 400;
	_singlePlayer.isSelect = false;
	_singlePlayer.rc = RectMakeCenter(_singlePlayer.x, _singlePlayer.y, (strlen("SINGLEPLAYER") - 4)*_singlePlayer.size, _singlePlayer.size);
	_option.r = 255;
	_option.g = 255;
	_option.b = 255;
	_option.count = 0;
	_option.size = 30;
	_option.x = WINSIZEX / 2;// WINSIZEX / 2 - 40;
	_option.y = WINSIZEY - 300;
	_option.isSelect = false;
	_option.rc = RectMakeCenter(_option.x, _option.y, (strlen("OPTION") - 1)*_option.size, _option.size);
	//메뉴 클릭용
	_option.isSelect = false;
	_credit.r = 255;
	_credit.g = 255;
	_credit.b = 255;
	_credit.count = 0;
	_credit.size = 30;
	_credit.x = WINSIZEX / 2;// WINSIZEX / 2 - 38;
	_credit.y = WINSIZEY - 250;
	_credit.isSelect = false;
	_credit.rc = RectMakeCenter(_credit.x, _credit.y, (strlen("CREDIT") - 1)*_credit.size, _credit.size);
	_mapEditor.r = 255;
	_mapEditor.g = 255;
	_mapEditor.b = 255;
	_mapEditor.count = 0;
	_mapEditor.size = 30;
	_mapEditor.x = WINSIZEX / 2;// WINSIZEX / 2 - 55;
	_mapEditor.y = WINSIZEY - 350;
	_mapEditor.isSelect = false;
	_mapEditor.rc = RectMakeCenter(_mapEditor.x, _mapEditor.y, (strlen("MAPEDITOR") - 3)*_mapEditor.size, _mapEditor.size);
	_quit.r = 255;
	_quit.g = 255;
	_quit.b = 255;
	_quit.count = 0;
	_quit.size = 30;
	_quit.x = WINSIZEX / 2;// WINSIZEX / 2 - 20;
	_quit.y = WINSIZEY - 200;
	_quit.isSelect = false;
	_quit.rc = RectMakeCenter(_quit.x, _quit.y, (strlen("QUIT") - 1)*_quit.size, _quit.size);
	ShowCursor(false);
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
	//시간을 계산할 식
	_time += TIMEMANAGER->getElapsedTime();

	//이미지 오프
	if (_jumpCount != 2)
	{
		actionOff(3, 6, &_99.alpha, 5);
		actionOn(6, 16, &_introPeople.alpha, 5);
		actionOff(16, 20, &_introPeople.alpha, 5);
		actionOn(20, 24, &_title.alpha, 5);
		//글자를 떨굼
		actionJump(20, 24, &_logo.y, &_title.y);//2024

	}
	//충돌
	if (isCollision(_fontX + 350, _arrFontY[7], _hello.x, _hello.y))
	{
		_hello.speed = 20;
	}
	_hello.x -= _hello.speed;
	_hello.y -= _hello.speed;

	//엔터키나 마우스클릭하면 버튼 화면 사라짐
	if (_jumpCount == 2 && !_pressButton.isSelect && (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) || KEYMANAGER->isOnceKeyDown(VK_RETURN)))
	{
		_pressButton.isSelect = true;
		//로고창 위로 살짝
		_saveTime = _time;
	}
	if (_pressButton.isSelect)
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
			buttonClick();
		}
	}


}

void INTROSCENE::render()
{


	if (_time < 6)
	{
		_99.image->alphaRender(getMemDC(), _99.x, _99.y, _99.alpha);
	}
	if (_time > 20)
	{
		_title.image->alphaRender(getMemDC(), _title.x, _title.y, _title.alpha);
	}
	if (_time > 20)
	{
		_logo.image->alphaRender(getMemDC(), _logo.x, _logo.y, _logo.alpha);
	}
	if (_time > 6 && _time < 16)
	{
		_introPeople.image->alphaRender(getMemDC(), _introPeople.x, _introPeople.y, _introPeople.alpha);
	}
	/*char str[220];
	sprintf_s(str, "%2lf", _saveTime);
	TextOut(getMemDC(), 300, 300, str, strlen(str));*/


	if (_time < 20)
	{
		for (int i = 0; i < 8; i++)
		{

			switch (i)
			{
			case 0:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "P", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 1:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "I", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 2:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "N", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 3:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "K", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 4:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "N", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 5:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "I", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 6:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "T", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 7:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "E", "양재블럭체", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f&&_time < 16)
					{
						if (_time < 14)
						{
							_angle += 0.1f;
						}
						else
						{
							_angle = 2 * PI - PI / 6;
						}
						_speed += 0.1f;
						_fontX += cosf(_angle) * _speed;

						_arrFontY[i] += -sinf(_angle) * _speed;
					}
				}
				break;

			}

		}
	}
	if (_time > 6 && _time < 20)
	{
		draw();
	}
	if (_jumpCount == 2 && !_pressButton.isSelect) //button오프일ㄸㅐ

	{

		switch (_pressButton.count % 2)
		{
		case 0:
			if (_pressButton.r > 94 && _pressButton.g > 94 && _pressButton.b > 94)
			{
				_pressButton.r -= 5;
				_pressButton.g -= 5;
				_pressButton.b -= 5;
				if (_pressButton.r == 90 && _pressButton.g == 90 && _pressButton.b == 90)
				{
					_pressButton.count++;
				}
			}
			break;
		default:
			if (_pressButton.r < 255 && _pressButton.g < 255 && _pressButton.b < 255)
			{
				_pressButton.r += 5;
				_pressButton.g += 5;
				_pressButton.b += 5;
				if (_pressButton.r == 255 && _pressButton.g == 255 && _pressButton.b == 255)
				{
					_pressButton.count++;
				}

			}

			break;
		}
		fontRender(getMemDC(), "PRESS ANI BUTTON", "휴먼둥근헤드라인", _pressButton.x, _pressButton.y, 15, RGB(_pressButton.r, _pressButton.g, _pressButton.b));

	}

	//메뉴창에서 나옴
	if (_pressButton.isSelect)
	{
		fontRender(getMemDC(), "SINGLEPLAYER", "elephant", _singlePlayer.x, _singlePlayer.y, _singlePlayer.size, RGB(_singlePlayer.r, _singlePlayer.g, _singlePlayer.b));
		fontRender(getMemDC(), "MAPEDITOR", "elephant", _mapEditor.x, _mapEditor.y, _mapEditor.size, RGB(_mapEditor.r, _mapEditor.g, _mapEditor.b));
		fontRender(getMemDC(), "OPTIONS", "elephant", _option.x, _option.y, _option.size, RGB(_option.r, _option.g, _option.b));
		fontRender(getMemDC(), "CREDITS", "elephant", _credit.x, _credit.y, _credit.size, RGB(_credit.r, _credit.g, _credit.b));
		fontRender(getMemDC(), "QUIT", "elephant", _quit.x, _quit.y, _quit.size, RGB(_quit.r, _quit.g, _quit.b));

	}
	fontRender(getMemDC(), " ", "굴림체", WINSIZEX / 2, WINSIZEY / 2, 20, RGB(255, 51, 153));

	//_fontX, _arrFontY[7], _hello.x, _hello.y
		//RectangleMake(getMemDC(), _fontX+350, _arrFontY[7], 5, 5);
		//RectangleMake(getMemDC(), _hello.x, _hello.y, 100, 100);
	_pMouse->render(getMemDC(), _ptMouse.x - 32, _ptMouse.y - 32);

	//옵션 클릭되면 나오게
	if (_option.isSelect)
	{
		_option.image->render(getMemDC(), 0, 0);
	}
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _singlePlayer.rc);
		Rectangle(getMemDC(), _mapEditor.rc);
		Rectangle(getMemDC(), _option.rc);
		Rectangle(getMemDC(), _credit.rc);
		Rectangle(getMemDC(), _quit.rc);
	}
}

void INTROSCENE::imageSetting()
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

	_pMouse = new image;
	_pMouse = IMAGEMANAGER->addImage("mouse", "resource/intro/mouseCursor.bmp", 64, 64, true, RGB(255, 0, 255));



	//옵션 이미지
	_option.image = new image;
	_option.image = IMAGEMANAGER->addImage("option", "resource/intro/option.bmp", 1600, 900, true, RGB(255, 0, 255));
}

void INTROSCENE::actionOff(float numA, float numB, int* alpha, int numC)//에이와 비 시간 사이에 알파값 감소
{

	//이 이미지가 몇초있다 사라지게  함 그 함수를 만들자
	if (numA <= _time && (*alpha) > 0 && numB >= _time)//에이와 비사이의 시간에 작동
	{
		//0보다 크면 계속 알파값 줄여나감
		//system("pause");

		(*alpha) -= numC;
	}
}

void INTROSCENE::actionOn(float numA, float numB, int * alpha, int numC)
{


	//이 이미지가 몇초있다 사라지게  함 그 함수를 만들자
	if (numA <= _time && (*alpha) < 255 && numB >= _time)//에이와 비사이의 시간에 작동
	{
		//0보다 크면 계속 알파값 줄여나감


		(*alpha) += numC;
	}
}

void INTROSCENE::actionJump(float numA, float numB, float* y, float* y2)
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

void INTROSCENE::fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color)
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

void INTROSCENE::draw()
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

	_hello.image->frameRender(getMemDC(), _hello.x, _hello.y, _hello.currentX, _hello.currentY);

}

bool INTROSCENE::isCollision(int x, int y, int x2, int y2)
{
	//반지름 5로 가정
	RECT rc = RectMake(x2, y2, 100, 100);
	if (PtInRect(&rc, PointMake(x, y)))
	{

		return true;
	}
	return false;
}

void INTROSCENE::buttonClick()
{
	//싱글플레이어
	if (_menuCount == 0)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_singlePlayer.rc, _ptMouse))
		{
			singlePlayer();
		}
		//맵
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_mapEditor.rc, _ptMouse))
		{
			mapEditor();
		}
		//옵션
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_option.rc, _ptMouse))
		{
			_menuCount = 1;
			option();
		}
		//크레딧
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_credit.rc, _ptMouse))
		{
			_menuCount = 1;
			credit();
		}
		//메뉴 나가기
		/*if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_back.rc, _ptMouse))
		{
			back();

		}*/
		//나가기
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_quit.rc, _ptMouse))
		{
			quit();
		}
	}
}

void INTROSCENE::singlePlayer()
{
	SCENEMANAGER->changeScene("MinTest");

}

void INTROSCENE::mapEditor()
{
	SCENEMANAGER->changeScene("leeTest");
}

void INTROSCENE::option()
{
	if (!_option.isSelect)
	{
		_option.isSelect = true;
	}
}

void INTROSCENE::credit()
{
	//엔딩은 나중에
}

void INTROSCENE::back()
{
	_menuCount = 0;
}

void INTROSCENE::quit()
{

}


