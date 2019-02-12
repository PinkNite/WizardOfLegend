#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
class ITEM;

class STATUSUI :public OBJECT
{
private:
	//�����̴� ���� �� �׸�
	//�ȿ� �ڽ��� ���� �׸���
	//����Ʈ �ڽ� ���� �׸��� 
	//���â ����
	STATUSBOX* _pStatusBox[7];
	STATUSSELECT* _pStatusSelect;
	ITEM* _pItem[2];//2���� ���̹���
	int _num;//��ȭ��

	int _count;

	int _numA;//������ ��ȣ
	
	int _x;
	int _y;
	int _alpha;
	RECT _rcText;

	bool _isClick;
public:
	STATUSUI();
	~STATUSUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void collision();
	void spaceKeyAndLButton();
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void fontRender2(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
public :
	//������
	bool getIsClick() { return _isClick; }
	void setIsClick(bool num) { _isClick = num; }

};

