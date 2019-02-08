#include "stdafx.h"
#include "introScene.h"




INTROSCENE::INTROSCENE()
	:_jumpPower(0),_time(NULL),_fontX(0),_angle(0),_speed(5),_count(0),_end(0),_timer(0),_jumpCount(0),_gravity(0)
{
}

INTROSCENE::~INTROSCENE()
{
}

HRESULT INTROSCENE::init()
{
	//_time = 0;
	_fontX = WINSIZEX/2 - 200;
	for (int i = 0; i < 8; i++)
	{

	_arrFontY[i] = WINSIZEY / 2 - 200;
	
	}
	_angle = PI;
	_gravity = 0.6f;
	_jumpCount = 1;
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
	actionOff(3,6, &_99.alpha,5);
	actionOn(6,16, &_introPeople.alpha, 5);
	actionOff(16,20, &_introPeople.alpha, 5);
	actionOn(20,24, &_title.alpha,5);
	actionJump(20, 24, &_logo.y, &_title.y);
	//글자를 떨굼
	
	//이미지 온
	
	
}

void INTROSCENE::render()
{

	
	_99.image->alphaRender(getMemDC(), _99.x, _99.y, _99.alpha);
	_title.image->alphaRender(getMemDC(), _title.x, _title.y, _title.alpha);
	_logo.image->alphaRender(getMemDC(),_logo.x,_logo.y,_logo.alpha);
	_introPeople.image->alphaRender(getMemDC(), _introPeople.x, _introPeople.y, _introPeople.alpha);
	
	char str[220];
	sprintf_s(str, "%d", _introPeople.alpha);
	TextOut(getMemDC(), 400, 400, str, strlen(str));
	

	if (_time < 20)
	{
		for (int i = 0; i < 8; i++)
		{

			switch (i)
			{
			case 0:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "P", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 1:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "I", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 2:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "N", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 3:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "K", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 4:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "N", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 5:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "I", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 6:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "T", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f)
					{
						_arrFontY[i] += GRAVITY;
					}
				}
				break;
			case 7:
				if (_time > 8 + i * 0.2f && _time < 20)
				{
					fontRender(getMemDC(), "E", "쉐도우9", _fontX + i * 50, _arrFontY[i], 50, RGB(255, 51, 153));
					if (_time > 10 + i * 0.2f&&_time<16)
					{
						if (_time < 14)
						{
							_angle += 0.1f;
						}
						else
						{
							_angle = 2 * PI - PI / 4;
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
	if (_time > 14.5f&&_time<20)
	{
		draw();
	}
	if (_jumpCount == 0 && _timer <= _time + 2.0f)
	{
		fontRender(getMemDC(), "PRESS ANI BUTTON", "쉐도우9", WINSIZEX / 2 - 40, WINSIZEY -200, 40, RGB(255, 255, 255));
	}

	fontRender(getMemDC(), " ", "굴림체", WINSIZEX / 2 + 20, WINSIZEY / 2, 20, RGB(255, 51, 153));
}

void INTROSCENE::imageSetting()
{
	//이미지
	_title.image = new image;
	_title.image = IMAGEMANAGER->addImage("title", "resource/intro/title.bmp", 1422, 800, false, RGB(0, 0, 0));
	_title.alpha = 0;
	_title.x = 0;
	_title.y = 0;
	_logo.image = new image;
	_logo.image = IMAGEMANAGER->addImage("logo", "resource/intro/logo.bmp", 1422, 800, true, RGB(255, 0, 255));
	_logo.alpha = 255;
	_logo.x = 0;
	_logo.y = -700;
	_99.image = new image;
	_99.image = IMAGEMANAGER->addImage("99small", "resource/intro/99small.bmp", 1422, 800, true, RGB(255, 0, 255));
	_99.alpha = 255;
	_99.x = 0;
	_99.y = 0;

	//=IMAGEMANAGER->addImage("99big", "resource/intro/99big.bmp", 524, 236, true, RGB(255, 0, 255));
	_introPeople.image = new image;
	_introPeople.image = IMAGEMANAGER->addImage("introPeople", "resource/intro/introPeople.bmp", 200, 200, true, RGB(255, 0, 255));
	_introPeople.alpha = 0;
	_introPeople.x = WINSIZEX/2-_introPeople.image->GetWidth()/2;
	_introPeople.y = WINSIZEY / 2-_introPeople.image->GetHeight()/2;

	//키애니메이션
	_hello.image = new image;
	_hello.image = IMAGEMANAGER->addFrameImage("hello", "resource/intro/hello.bmp", 240, 78, 4, 1, true, RGB(255, 0, 255));
	_hello.alpha = 0;
	_hello.x = WINSIZEX - IMAGEMANAGER->findImage("hello")->getFrameWidth() - 10;
	_hello.y = WINSIZEY - IMAGEMANAGER->findImage("hello")->getFrameHeight() - 10;
	_hello.currentX = 0;
	_hello.currentY = 0;
	
}

void INTROSCENE::actionOff(float numA,float numB,int* alpha,int numC)//에이와 비 시간 사이에 알파값 감소
{
	//이 이미지가 몇초있다 사라지게  함 그 함수를 만들자
	if (numA <= _time&&(*alpha)>0&&numB>=_time)//에이와 비사이의 시간에 작동
	{
		//0보다 크면 계속 알파값 줄여나감
		//system("pause");
		
		(*alpha)-=numC;
	}
}

void INTROSCENE::actionOn(float numA,float numB,int * alpha, int numC)
{
	
	
		//이 이미지가 몇초있다 사라지게  함 그 함수를 만들자
	if (numA <= _time && (*alpha) <255&&numB>=_time)//에이와 비사이의 시간에 작동
	{
		//0보다 크면 계속 알파값 줄여나감
		

		(*alpha) += numC;
	}
}

void INTROSCENE::actionJump(float numA, float numB, float* y, float* y2)
{
	
	if ((*y) < 0 && _time >= numA)
	{
		(*y) -= _jumpPower;
		_jumpPower -= _gravity;
	}
	if ((*y) >= 0 && _jumpCount == 1)
	{

		_jumpPower = 10.5f;
		(*y) -= _jumpPower;
		_jumpCount--;

		_timer = _time;

	}
	if (_jumpCount==0&&_timer <= _time + 2.0f)//_time > numB
	{
		(*y2) = RND->getFromIntTo(0, 10);
	}

	if ((*y) >= 0 && _jumpCount == 0)
	{
		(*y) = 0;
		(*y2) = 0;
	}
}

void INTROSCENE::fontRender(HDC hdc, const char * str,const char* str2, int x, int y, int num, COLORREF color)
{
	char str1[500];
	SetTextColor(hdc, color);
	HFONT font, oldfont;
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	oldfont = (HFONT)SelectObject(hdc, font);
	sprintf_s(str1, str);
	TextOut(hdc, x, y, str, strlen(str));
	//DeleteObject(oldfont);
	DeleteObject(font);
}

void INTROSCENE::draw()
{
	_count++;
	if (_count % 10==0)
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


