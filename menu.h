#pragma once
//#include "button.h"
enum KEYBOARDCURSOR
{
	KEY_UP,
	KEY_DOWN,
	KEY_EMPTY
};
enum MOUSECURSOR
{
	MOUSE_ON,
	MOUSE_OFF
};

class MENU
{

private:
	struct TAGINTRO
	{
		float x, y;
		int alpha;
		image* image;
		int currentX;
		int currentY;
		int r, g, b;
		int count;
		int size;
		bool isSelect;
		float speed;
		RECT rc;
		bool isCursor;

	};
	int _menuCount;


	TAGINTRO _pressButton;
	TAGINTRO _singlePlayer;
	TAGINTRO _credit;
	TAGINTRO _option;
	TAGINTRO _mapEditor;
	TAGINTRO _quit;
	TAGINTRO _back;
	TAGINTRO _font;
	TAGINTRO _temp;//빈곳
	image* _pButton;
	//button* _pButton;
	//POINT _point1;
	//POINT _point2;
	int _count;

	const char* _changeFont;
	RECT _selectButton;//메뉴 선택용 
	int _x;//좌표
	int _y;//메뉴선택박스 좌표

	int _keyCount;
	MOUSECURSOR _mouseCursor;
	KEYBOARDCURSOR _keyCursor;

public:
	MENU();
	~MENU();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void pressRender(HDC hdc);
	void tagInfoSetting();
	void fontSetting();
	void fontCollision();
	void selectButtonSetting();
	
	///////////////////////////////////////////////메뉴선택//////////////////////////////
	void singlePlayer();//싱글플레이어
	void mapEditor();//맵에디터
	void option();//옵션
	void credit();//크레딧
	void quit();//게임 나가기
	void buttonClick();//버튼 클릭
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);//폰트 렌더할 함수
	bool getPressButton() { return _pressButton.isSelect; }
	void setPressButton(bool num) { _pressButton.isSelect = num; }
	void test();
	
};


