#include "stdafx.h"
#include "menu.h"




MENU::MENU()
	: _menuCount(0), _count(0)
{
}

MENU::~MENU()
{
}

HRESULT MENU::init()
{
	IMAGEMANAGER->addImage("button", "resource/intro/button.bmp", 20, 20, true, RGB(255, 0, 255));
	_pButton = new image;
	_pButton = IMAGEMANAGER->findImage("button");
	tagInfoSetting();
	
	
	return S_OK;
}

void MENU::release()
{
	_pButton = nullptr;
	_option.image = nullptr;
}

void MENU::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))/////////임시 지워얗됨
	{
		_pressButton.isSelect = true;
	}
	//메뉴 나가기
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_back.rc, _ptMouse))
	{
		
		_option.isSelect = false;
		_menuCount = 0;
	}
	fontSetting();
}

void MENU::render(HDC hdc)
{
	if (!_pressButton.isSelect) //button오프일ㄸㅐ

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
		fontRender(hdc, "PRESS ANI BUTTON", "휴먼둥근헤드라인", _pressButton.x, _pressButton.y, 15, RGB(_pressButton.r, _pressButton.g, _pressButton.b));

	}


	if (_pressButton.isSelect)
	{


		fontRender(hdc, "SINGLEPLAYER", _changeFont, _singlePlayer.x, _singlePlayer.y, _singlePlayer.size, RGB(_singlePlayer.r, _singlePlayer.g, _singlePlayer.b));
		fontRender(hdc, "MAPEDITOR", _changeFont, _mapEditor.x, _mapEditor.y, _mapEditor.size, RGB(_mapEditor.r, _mapEditor.g, _mapEditor.b));
		fontRender(hdc, "OPTIONS", _changeFont, _option.x, _option.y, _option.size, RGB(_option.r, _option.g, _option.b));
		fontRender(hdc, "CREDITS", _changeFont, _credit.x, _credit.y, _credit.size, RGB(_credit.r, _credit.g, _credit.b));
		fontRender(hdc, "QUIT", _changeFont, _quit.x, _quit.y, _quit.size, RGB(_quit.r, _quit.g, _quit.b));
		fontRender(hdc, " ", _changeFont, WINSIZEX / 2, WINSIZEY / 2, 20, RGB(255, 51, 153));

	}
	


	//옵션 클릭되면 나오게
	if (_option.isSelect)
	{
		_back.isSelect = false;
		_option.image->render(hdc, 0, 0);
		Rectangle(hdc, _back.rc);
		fontRender(hdc, "FONT", _changeFont, WINSIZEX / 2-200, WINSIZEY / 2, 30, RGB(255, 255, 255));
		fontRender(hdc, "SOUND", _changeFont, WINSIZEX / 2 - 200, WINSIZEY / 2-100, 30, RGB(255, 255, 255));
		fontRender(hdc, "BACK", _changeFont, _back.x, _back.y, 30, RGB(255, 255, 255));
		fontRender(hdc, _changeFont, _changeFont, WINSIZEX / 2 +100, WINSIZEY / 2, 30, RGB(160, 70, 10));
		_pButton->render(hdc, _font.rc.left,_font.rc.top);
		_pButton->render(hdc, _font.rc.left, _font.rc.top-100);
	}
	if (_back.isSelect)
	{
		_option.isSelect = false;
	}
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(hdc, _singlePlayer.rc);
		Rectangle(hdc, _mapEditor.rc);
		Rectangle(hdc, _option.rc);
		Rectangle(hdc, _credit.rc);
		Rectangle(hdc, _quit.rc);
	}

}

void MENU::tagInfoSetting()
{
	//버튼들
	//프레스버튼셋
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
	_back.r = 255;
	_back.g = 255;
	_back.b = 255;
	_back.count = 0;
	_back.size = 30;
	_back.x = WINSIZEX / 2;// WINSIZEX / 2 - 20;
	_back.y = WINSIZEY - 200;
	_back.isSelect = false;
	_back.rc = RectMakeCenter(_back.x, _back.y, (strlen("BACK") - 1)*_back.size, _back.size);
	_font.r = 255;
	_font.g = 255;
	_font.b = 255;
	_font.count = 0;
	_font.size = 20;
	_font.x = WINSIZEX / 2;// WINSIZEX / 2 - 20;
	_font.y = WINSIZEY /2;
	_font.isSelect = false;
	_font.rc = RectMakeCenter(_font.x-100, _font.y, 20, _font.size);


	


	//옵션 이미지
	_option.image = new image;
	_option.image = IMAGEMANAGER->addImage("option", "resource/intro/option.bmp", 1600, 900, true, RGB(255, 0, 255));
}

void MENU::fontSetting()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)&&PtInRect(&_font.rc,_ptMouse))
	{
		_count++;
	}
		switch (_count%3)
		{
		case 0:
			_changeFont = "휴먼둥근헤드라인";
			break;
		case 1:
			_changeFont = "elephant";
			break;
		case 2:
			_changeFont = "굴림체";
			break;
		}
	
	
}

void MENU::singlePlayer()
{
	SCENEMANAGER->changeScene("MinTest");
}

void MENU::mapEditor()
{
	SCENEMANAGER->changeScene("leeTest");
}

void MENU::option()
{
	if (!_option.isSelect)
	{
		_option.isSelect = true;
	}
	//옵션 창 폰트


	


}

void MENU::credit()
{
}



void MENU::quit()
{
}

void MENU::buttonClick()
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
		
		//나가기
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_quit.rc, _ptMouse))
		{
			quit();
		}
	}
}

void MENU::fontRender(HDC hdc, const char * str, const char * str2, int x, int y, int num, COLORREF color)
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

void MENU::test()
{
	SCENEMANAGER->changeScene("mapEditScene");
}

