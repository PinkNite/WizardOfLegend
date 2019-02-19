#pragma once


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

	};
	int _menuCount;


	TAGINTRO _pressButton;
	TAGINTRO _singlePlayer;
	TAGINTRO _credit;
	TAGINTRO _option;
	TAGINTRO _mapEditor;
	TAGINTRO _quit;
	TAGINTRO _back;
public:
	MENU();
	~MENU();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void tagInfoSetting();
	///////////////////////////////////////////////메뉴선택//////////////////////////////
	void singlePlayer();//싱글플레이어
	void mapEditor();//맵에디터
	void option();//옵션
	void credit();//크레딧
	void back();//메뉴창 나가기
	void quit();//게임 나가기
	void buttonClick();//버튼 클릭
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);//폰트 렌더할 함수
	bool getPressButton() { return _pressButton.isSelect; }
	void setPressButton(bool num) { _pressButton.isSelect = num; }
};

class menu
{
public:
	menu();
	~menu();
};

