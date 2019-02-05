#pragma once
#include "singletonBase.h"
#include <bitset>

using namespace std;

#define KEYMAX 256 //Ű�� �������� ��� ���������� 256��

class keyManager : public singletonBase<keyManager>
{
private:
	enum {KEYMAXCOUNT = 256};

	enum class KEYINPUT{
		KEY_STAY_UP = 0,		//Ű�� �ȴ��� ���·� �ӹ��� �ִ�.
		KEY_UP,					//Ű�� �ö�Դ�.
		KEY_STAY_DOWN,			//Ű�� ���� �����̴�.
		KEY_DOWN,				//Ű�� ���ȴ�.
		MAX
	};

private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

	
	bool _isDBCLbutton;
	bool _isDBCRButton;

	KEYINPUT	_arKey[KEYMAXCOUNT];
	bool		_arKeyDouble[KEYMAXCOUNT];
	int			_arKeyDownCount[KEYMAXCOUNT];
	float		_fDoubleClickTime;
	
private:
	void	initKeyDouble();

public:
	keyManager();
	~keyManager();

	HRESULT init();
	void release();
	void update();
	//Ű�� �ѹ��� ������
	bool isOnceKeyDown(int key);
	//Ű�� ������ ����
	bool isOnceKeyUp(int key);
	//Ű�� ��� ������ ������
	bool isStayKeyDown(int key);
	//����̸��� ��� üũ�ǰ��ִ� ���� �ƴѰ���? ����������
	bool isToggleKey(int key);

	bitset<KEYMAX> getKeyUp() { return _keyUp; }
	bitset<KEYMAX> getKeyDown() { return _keyDown; }

	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }
	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }

	bool isDBClickLButton();
	bool isDBClickRButton();


	bool TranslateMessage(const MSG * pMSG);
};

