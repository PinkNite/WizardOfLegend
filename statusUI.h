#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
class STATUSUI:public OBJECT
{
private:
	//�����̴� ���� �� �׸�
	//�ȿ� �ڽ��� ���� �׸���
	//����Ʈ �ڽ� ���� �׸��� 
	STATUSBOX* _pStatusBox[6];
	STATUSSELECT* _pStatusSelect;
	int _num;//��ȭ��

	int _count;
	
public:
	STATUSUI();
	~STATUSUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void collision();
	void spaceKeyAndLButton();
};

