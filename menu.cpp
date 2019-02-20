#include "stdafx.h"
#include "menu.h"




MENU::MENU()
	: _menuCount(0), _count(0), _x(0), _y(0), _keyCount(0), _time(0)
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
	selectButtonSetting();

	return S_OK;
}

void MENU::release()
{
	_pButton = nullptr;
	_option.image = nullptr;
}

void MENU::update()
{
	if (_option.isSelect)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_back.rc, _ptMouse))
		{

			_option.isSelect = false;
			_menuCount = 0;
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
		{
			_option.isSelect = false;
			_menuCount = 0;
		}
	}
	fontSetting();
	if (_menuCount == 0)//옵션클릭하면 안들어옴
	{

		if (_time > 20)
		{
			fontCollision();
			_selectButton = RectMakeCenter(_x, _y, 20, 20);
		}
	}
}

void MENU::render(HDC hdc)
{



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
		_option.image->render(hdc);
		//	Rectangle(hdc, _back.rc);
		fontRender(hdc, "FONT", _changeFont, WINSIZEX / 2 - 200, WINSIZEY / 2, 30, RGB(255, 255, 255));
		fontRender(hdc, "SOUND", _changeFont, WINSIZEX / 2 - 200, WINSIZEY / 2 - 100, 30, RGB(255, 255, 255));
		fontRender(hdc, "BACK", _changeFont, _back.x, _back.y, 30, RGB(255, 255, 255));
		fontRender(hdc, _changeFont, _changeFont, WINSIZEX / 2 + 100, WINSIZEY / 2, 30, RGB(160, 70, 10));
		_pButton->render(hdc, _font.rc.left, _font.rc.top);
		_pButton->render(hdc, _font.rc.left, _font.rc.top - 100);
	}
	if (_back.isSelect)
	{
		_option.isSelect = false;
	}
	/*if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(hdc, _singlePlayer.rc);
		Rectangle(hdc, _mapEditor.rc);
		Rectangle(hdc, _option.rc);
		Rectangle(hdc, _credit.rc);
		Rectangle(hdc, _quit.rc);
	}*/
	/*char str[200];
	sprintf_s(str, "%d", _menuCount);
	TextOut(hdc, 800, 800, str, strlen(str));


	sprintf_s(str, "%d", _singlePlayer.isCursor);
	TextOut(hdc, 1200, 200, str, strlen(str));
	sprintf_s(str, "%d", _mapEditor.isCursor);
	TextOut(hdc, 1200, 300, str, strlen(str));
	sprintf_s(str, "%d", _option.isCursor);
	TextOut(hdc, 1200, 400, str, strlen(str));
	sprintf_s(str, "%d", _credit.isCursor);
	TextOut(hdc, 1200, 500, str, strlen(str));
	sprintf_s(str, "%d", _quit.isCursor);
	TextOut(hdc, 1200, 600, str, strlen(str));
*/

//Rectangle(hdc, _selectButton);
}

void MENU::pressRender(HDC hdc)
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
	_singlePlayer.r = 116;
	_singlePlayer.g = 112;
	_singlePlayer.b = 117;
	_singlePlayer.count = 0;
	_singlePlayer.size = 30;
	_singlePlayer.x = WINSIZEX / 2;//WINSIZEX / 2 - 75;
	_singlePlayer.y = WINSIZEY - 400;
	_singlePlayer.isSelect = false;
	_singlePlayer.rc = RectMakeCenter(_singlePlayer.x, _singlePlayer.y, (strlen("SINGLEPLAYER") - 4)*_singlePlayer.size, _singlePlayer.size);
	_singlePlayer.isCursor = false;
	_option.r = 116;
	_option.g = 112;
	_option.b = 117;
	_option.count = 0;
	_option.size = 30;
	_option.x = WINSIZEX / 2;// WINSIZEX / 2 - 40;
	_option.y = WINSIZEY - 300;
	_option.isSelect = false;
	_option.rc = RectMakeCenter(_option.x, _option.y, (strlen("OPTION") - 1)*_option.size, _option.size);
	_option.isCursor = false;
	//메뉴 클릭용
	_option.isSelect = false;
	_credit.r = 116;
	_credit.g = 112;
	_credit.b = 117;
	_credit.count = 0;
	_credit.size = 30;
	_credit.x = WINSIZEX / 2;// WINSIZEX / 2 - 38;
	_credit.y = WINSIZEY - 250;
	_credit.isSelect = false;
	_credit.rc = RectMakeCenter(_credit.x, _credit.y, (strlen("CREDIT") - 1)*_credit.size, _credit.size);
	_credit.isCursor = false;
	_mapEditor.r = 116;
	_mapEditor.g = 112;
	_mapEditor.b = 117;
	_mapEditor.count = 0;
	_mapEditor.size = 30;
	_mapEditor.x = WINSIZEX / 2;// WINSIZEX / 2 - 55;
	_mapEditor.y = WINSIZEY - 350;
	_mapEditor.isSelect = false;
	_mapEditor.rc = RectMakeCenter(_mapEditor.x, _mapEditor.y, (strlen("MAPEDITOR") - 3)*_mapEditor.size, _mapEditor.size);
	_mapEditor.isCursor = false;
	_quit.r = 116;
	_quit.g = 112;
	_quit.b = 117;
	_quit.count = 0;
	_quit.size = 30;
	_quit.x = WINSIZEX / 2;// WINSIZEX / 2 - 20;
	_quit.y = WINSIZEY - 200;
	_quit.isSelect = false;
	_quit.rc = RectMakeCenter(_quit.x, _quit.y, (strlen("QUIT") - 1)*_quit.size, _quit.size);
	_quit.isCursor = false;
	_back.r = 116;
	_back.g = 112;
	_back.b = 117;
	_back.count = 0;
	_back.size = 30;
	_back.x = WINSIZEX / 2;// WINSIZEX / 2 - 20;
	_back.y = WINSIZEY - 150;
	_back.isSelect = false;
	_back.rc = RectMakeCenter(_back.x, _back.y, (strlen("BACK") - 1)*_back.size, _back.size);
	_back.isCursor = false;
	_font.r = 116;
	_font.g = 112;
	_font.b = 117;
	_font.count = 0;
	_font.size = 20;
	_font.x = WINSIZEX / 2;// WINSIZEX / 2 - 20;
	_font.y = WINSIZEY / 2;
	_font.isSelect = false;
	_font.rc = RectMakeCenter(_font.x - 100, _font.y, 20, _font.size);





	//옵션 이미지
	_option.image = new image;
	_option.image = IMAGEMANAGER->addImage("option", "resource/intro/option.bmp", 1600, 900, true, RGB(255, 0, 255));
}

void MENU::fontSetting()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_font.rc, _ptMouse))
	{
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
		_count++;
	}
	switch (_count % 3)
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
	////해당 커서가 들어오면 글씨 조절됨



}

void MENU::fontCollision()
{
	RECT temp;
	//버튼들과 충돌하면 커서가 온이되고 온이되면 잠깐 글씨가 커진다 색깔도 좀 바뀌게하자
	if (IntersectRect(&temp, &_selectButton, &_singlePlayer.rc))//싱글플레이어 버튼과 충돌
	{
		_singlePlayer.isCursor = true;

	}
	else
	{
		_singlePlayer.isCursor = false;
	}
	if (IntersectRect(&temp, &_selectButton, &_mapEditor.rc))//map
	{
		_mapEditor.isCursor = true;


	}
	else
	{
		_mapEditor.isCursor = false;
	}
	if (IntersectRect(&temp, &_selectButton, &_option.rc))//싱글플레이어 버튼과 충돌
	{
		_option.isCursor = true;

	}
	else
	{
		_option.isCursor = false;
	}
	if (IntersectRect(&temp, &_selectButton, &_credit.rc))//싱글플레이어 버튼과 충돌
	{
		_credit.isCursor = true;

	}
	else
	{
		_credit.isCursor = false;
	}
	if (IntersectRect(&temp, &_selectButton, &_quit.rc))//싱글플레이어 버튼과 충돌
	{
		_quit.isCursor = true;


	}
	else
	{
		_quit.isCursor = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _y > WINSIZEY - 400)
	{
		_keyCursor = KEY_UP;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");

	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _y < WINSIZEY - 200)
	{
		_keyCursor = KEY_DOWN;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
	}
	if (_keyCursor == KEY_UP)
	{
		_y -= 25;
		_keyCursor = KEY_EMPTY;
	}
	if (_keyCursor == KEY_DOWN)
	{
		_y += 25;
		_keyCursor = KEY_EMPTY;
	}

	if (PtInRect(&_singlePlayer.rc, _ptMouse) && !_singlePlayer.isCursor&&_keyCount == 0)//셀렉트박스좌표가 옮겨짐
	{
		//_mouseCursor = MOUSE_ON;
		_y = WINSIZEY - 400;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
	}

	if (PtInRect(&_mapEditor.rc, _ptMouse) && !_mapEditor.isCursor&&_keyCount == 0)//셀렉트박스좌표가 옮겨짐
	{
		_y = WINSIZEY - 350;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
	}
	if (PtInRect(&_option.rc, _ptMouse) && !_option.isCursor&&_keyCount == 0)//셀렉트박스좌표가 옮겨짐
	{
		_y = WINSIZEY - 300;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
	}
	if (PtInRect(&_credit.rc, _ptMouse) && !_credit.isCursor&&_keyCount == 0)//셀렉트박스좌표가 옮겨짐
	{
		_y = WINSIZEY - 250;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
	}
	if (PtInRect(&_quit.rc, _ptMouse) && !_quit.isCursor&&_keyCount == 0)//셀렉트박스좌표가 옮겨짐
	{
		_y = WINSIZEY - 200;
		SOUNDMANAGER->stop("correct");
		SOUNDMANAGER->play("correct");
	}

	if (_singlePlayer.isCursor)
	{

		_singlePlayer.size = 40;
		_singlePlayer.r = 255;
		_singlePlayer.g = 255;
		_singlePlayer.b = 255;
	}
	else
	{
		_singlePlayer.size = 30;
		_singlePlayer.r = 116;
		_singlePlayer.g = 112;
		_singlePlayer.b = 117;
	}
	if (_mapEditor.isCursor)
	{

		_mapEditor.size = 40;
		_mapEditor.r = 255;
		_mapEditor.g = 255;
		_mapEditor.b = 255;
	}
	else
	{
		_mapEditor.size = 30;
		_mapEditor.r = 116;
		_mapEditor.g = 112;
		_mapEditor.b = 117;
	}
	if (_option.isCursor)
	{

		_option.size = 40;
		_option.r = 255;
		_option.g = 255;
		_option.b = 255;
	}
	else
	{
		_option.size = 30;
		_option.r = 116;
		_option.g = 112;
		_option.b = 117;
	}
	if (_credit.isCursor)
	{

		_credit.size = 40;
		_credit.r = 255;
		_credit.g = 255;
		_credit.b = 255;
	}
	else
	{
		_credit.size = 30;
		_credit.r = 116;
		_credit.g = 112;
		_credit.b = 117;
	}
	if (_quit.isCursor)
	{

		_quit.size = 40;
		_quit.r = 255;
		_quit.g = 255;
		_quit.b = 255;
	}
	else
	{
		_quit.size = 30;
		_quit.r = 116;
		_quit.g = 112;
		_quit.b = 117;
	}

}

void MENU::selectButtonSetting()
{
	//50씩 내려가면 된다.
	_x = WINSIZEX / 2;
	_y = WINSIZEY - 400;
	_selectButton = RectMakeCenter(_x, _y, 20, 20);

	_keyCursor = KEY_EMPTY;
	_mouseCursor = MOUSE_OFF;
}




void MENU::singlePlayer()
{
	SCENEMANAGER->changeScene("MinTest");
}

void MENU::mapEditor()
{
	SCENEMANAGER->changeScene("mapEditScene");
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
	SCENEMANAGER->changeScene("leeTest");

}



void MENU::quit()
{
	exit(2);
}

void MENU::buttonClick()
{
	//싱글플레이어
	if (_menuCount == 0)
	{
		if ((KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_singlePlayer.rc, _ptMouse)) || (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _singlePlayer.isCursor))
		{
			SOUNDMANAGER->stop("correct");
			SOUNDMANAGER->play("correct");
			SOUNDMANAGER->stop("title");
			SOUNDMANAGER->play("happy");
			singlePlayer();
		}
		//맵
		else if ((KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_mapEditor.rc, _ptMouse)) || (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _mapEditor.isCursor))
		{
			SOUNDMANAGER->stop("correct");
			SOUNDMANAGER->play("correct");
			SOUNDMANAGER->stop("title");
			SOUNDMANAGER->play("mapEditor");
			mapEditor();
		}
		//옵션
		else if ((KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_option.rc, _ptMouse)) || (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _option.isCursor))
		{
			SOUNDMANAGER->stop("correct");
			SOUNDMANAGER->play("correct");
			_menuCount = 1;
			option();
		}
		//크레딧
		else if ((KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_credit.rc, _ptMouse)) || (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _credit.isCursor))
		{
			SOUNDMANAGER->stop("correct");
			SOUNDMANAGER->play("correct");
			SOUNDMANAGER->stop("title");
			SOUNDMANAGER->play("credit");
			_menuCount = 1;
			credit();
		}

		//나가기
		else if ((KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_quit.rc, _ptMouse)) || (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _quit.isCursor) && (!_option.isSelect || !_credit.isSelect))
		{
			SOUNDMANAGER->stop("correct");
			SOUNDMANAGER->play("correct");
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

}

