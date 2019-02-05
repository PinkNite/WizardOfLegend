#include "stdafx.h"
#include "keyManager.h"




keyManager::keyManager()
{
}


keyManager::~keyManager()
{
}
void keyManager::initKeyDouble()
{
	for (int i = 0; i < KEYMAXCOUNT; i++)
	{
		_arKeyDouble[i] = false;
		_arKeyDownCount[i] = 0;
	}
}

HRESULT keyManager::init()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		//��� Ű�� ���� �ȴ����� �����̴�.
		this->getKeyUp().set(i, false);
	}

	for (int i = 0; i < KEYMAXCOUNT; i++)
	{
		_arKey[i] = KEYINPUT::KEY_STAY_UP;
	}
	initKeyDouble();
	_fDoubleClickTime = 0.0f;

	return S_OK;
}

void keyManager::release()
{
}

void keyManager::update()
{
	//����Ŭ�� �ʱ�ȭ
	if (_fDoubleClickTime == 0.0f)
	{
		initKeyDouble();
	}

	//��ǲ ����
	for (int i = 0; i < KEYMAXCOUNT; i++)
	{
		if (_arKey[i] == KEYINPUT::KEY_STAY_UP)
		{
			if ((GetAsyncKeyState(i) & 0x8000))	//Ű�� ���� �����̸�
			{
				_arKey[i] = KEYINPUT::KEY_DOWN;			//Ű�� ���� ���·� ����
				_arKeyDownCount[i]++;
			}
			else {
				_arKey[i] = KEYINPUT::KEY_STAY_UP;		//�ƴϸ� �ȴ��� ���� �״�� ����
			}
		}
		else if (_arKey[i] == KEYINPUT::KEY_DOWN)
		{
			if ((GetAsyncKeyState(i) & 0x8000))	//Ű�� ���� �����̸�
			{
				_arKey[i] = KEYINPUT::KEY_STAY_DOWN;	//Ű�� ���� ���·� ����
			}
			else {
				_arKey[i] = KEYINPUT::KEY_UP;		//�ƴϸ� �ȴ��� ���� �״�� ����
			}
		}
		else if (_arKey[i] == KEYINPUT::KEY_STAY_DOWN)
		{
			if ((GetAsyncKeyState(i) & 0x8000))	//Ű�� ���� �����̸�
			{
				_arKey[i] = KEYINPUT::KEY_STAY_DOWN;	//Ű�� ���� ���·� ����
			}
			else {
				_arKey[i] = KEYINPUT::KEY_UP;		//�ƴϸ� �ȴ��� ���� �״�� ����
			}
		}
		else if (_arKey[i] == KEYINPUT::KEY_UP)
		{
			if ((GetAsyncKeyState(i) & 0x8000))	//Ű�� ���� �����̸�
			{
				_arKey[i] = KEYINPUT::KEY_DOWN;			//Ű�� ���� ���·� ����
				_arKeyDownCount[i]++;
			}
			else {
				_arKey[i] = KEYINPUT::KEY_STAY_UP;		//�ƴϸ� �ȴ��� ���� �״�� ����
			}
		}
	}

	
	//0.5�ʵ��� ���� Ű�� 2�� �̻��̸� ����Ŭ������ ����
	//�����̴� �����Ѵ�!!
	_fDoubleClickTime += TIMEMANAGER->getElapsedTime();
	if (_fDoubleClickTime > 0.5f)
	{
		for (int i = 0; i < KEYMAXCOUNT; i++)
		{
			if (_arKeyDownCount[i] >= 2)
			{
				_arKeyDouble[i] = true;
			}
			_arKeyDownCount[i] = 0;
		}

		_fDoubleClickTime = 0.0f;
	}
}


bool keyManager::isOnceKeyDown(int key)
{
	//GetASyncKeyState		Ű���� ���¸� üũ�ϴµ� �񵿱�ȭ
	//GetKeyState			Ű���� ���¸� üũ�ϴµ� ����ȭ

	//if (GetAsyncKeyState(key) & 0x8000)
	//{
	//	if (!this->getKeyDown()[key])
	//	{
	//		this->setKeyDown(key, true);
	//		return true;
	//	}
	//}

	//else this->setKeyDown(key, false);

	
	if (_arKey[key] == KEYINPUT::KEY_DOWN)
	{
		return true;
	}

	return false;
}

bool keyManager::isOnceKeyUp(int key)
{
	//if (GetAsyncKeyState(key) & 0x8000)
	//{
	//	this->setKeyUp(key, true);
	//}
	//else
	//{
	//	if (this->getKeyUp()[key])
	//	{
	//		this->setKeyUp(key, false);
	//		return true;
	//	}

	//}

	//return false;
	if (_arKey[key] == KEYINPUT::KEY_UP)
	{
		return true;
	}

	return false;
}

bool keyManager::isStayKeyDown(int key)
{
	//if (GetAsyncKeyState(key) & 0x8000) return true;

	//return false;

	if (_arKey[key] == KEYINPUT::KEY_STAY_DOWN)
	{
		return true;
	}

	return false;
}

bool keyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;

	return false;
}

bool keyManager::isDBClickLButton()
{
	if (_isDBCLbutton  == true)
	{
		_isDBCLbutton = false;
		return true;
	}
	
	return false;
}

bool keyManager::isDBClickRButton()
{
	if (_isDBCRButton == true)
	{
		_isDBCRButton = false;
		return true;
	}
	return false;
}

bool keyManager::TranslateMessage(const MSG * pMSG)
{
	switch (pMSG->message)
	{
		
	case WM_LBUTTONDBLCLK:
		_isDBCLbutton = true;
		return true;
	case WM_RBUTTONDBLCLK:
		_isDBCRButton = true;
		return true;
	}

	return false;
}
