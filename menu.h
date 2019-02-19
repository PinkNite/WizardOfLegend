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
	///////////////////////////////////////////////�޴�����//////////////////////////////
	void singlePlayer();//�̱��÷��̾�
	void mapEditor();//�ʿ�����
	void option();//�ɼ�
	void credit();//ũ����
	void back();//�޴�â ������
	void quit();//���� ������
	void buttonClick();//��ư Ŭ��
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);//��Ʈ ������ �Լ�
	bool getPressButton() { return _pressButton.isSelect; }
	void setPressButton(bool num) { _pressButton.isSelect = num; }
};

class menu
{
public:
	menu();
	~menu();
};

