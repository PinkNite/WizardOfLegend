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
	TAGINTRO _temp;//���
	image* _pButton;
	//button* _pButton;
	//POINT _point1;
	//POINT _point2;
	int _count;

	const char* _changeFont;
	RECT _selectButton;//�޴� ���ÿ� 
	int _x;//��ǥ
	int _y;//�޴����ùڽ� ��ǥ

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
	
	///////////////////////////////////////////////�޴�����//////////////////////////////
	void singlePlayer();//�̱��÷��̾�
	void mapEditor();//�ʿ�����
	void option();//�ɼ�
	void credit();//ũ����
	void quit();//���� ������
	void buttonClick();//��ư Ŭ��
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);//��Ʈ ������ �Լ�
	bool getPressButton() { return _pressButton.isSelect; }
	void setPressButton(bool num) { _pressButton.isSelect = num; }
	void test();
	
};


