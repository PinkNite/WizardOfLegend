#include "stdafx.h"
#include "throwIceSpear.h"


throwIceSpear::throwIceSpear()
{
}


throwIceSpear::~throwIceSpear()
{
}

HRESULT throwIceSpear::init()
{
	//	�����̹��� �־��� ġ��,
	IMAGEMANAGER->addImage("iceSpearDefault", "resource/boss/ice/iceSpear.bmp", 96, 96, true, 0xFF00FF);
	
	_iceSpearDefault = IMAGEMANAGER->findImage("iceSpearDefault");
	_imgMaker = new rotateImgMaker;

	//	ȸ���̹��� ����
	float angle = 0;
	float augAngle = PI * 2 / 36;

	for (int i = 0; i < 36; i++) {
		_iceSpearImg[i] = _imgMaker->MakeRotateImg(_iceSpearDefault, 0, 0,
			_iceSpearDefault->GetWidth(), _iceSpearDefault->GetHeight(),
			angle, true, 0xFF00FF);
		angle += augAngle;
		_iceSpearImg[i]->setTransColor(true, 0xFF00FF);
	}
	delete _imgMaker;
	_imgMaker = nullptr;

	_prepareShotElapsedTime = 0.f;
	_totalSkillElapsedTime = 0.f;
	
	for (int i = -1; i < SPEAR_MAXNUM-1; i++) {
		tagIceSpear* tmpIceSpear = new tagIceSpear;
		tmpIceSpear->alpha = 0;

		//	ù ��°��,
		if (i == -1)
		{
			tmpIceSpear->adjustPos = { 0,0 };
		}
		//	¦����°��,
		else if (i % 2 == 0)
		{
			tmpIceSpear->adjustPos = { 100* ((i / 2)+1) ,0 };
		}
		//	Ȧ����°��
		else
		{
			tmpIceSpear->adjustPos = { 100 * ((i / 2)+1), 0 };
		}

		//tmpIceSpear->isOnceSetSpearPrepareValue = false;
		tmpIceSpear->isOnceSetSpearShotValue = false;
		
		_iceSpear.push_back(tmpIceSpear);
	}
	
	_augAlpha = 255 / (PREPARE_SHOTTIME*60);

	_isStart = false;
	_isRdyToShot = false;
	//_spearTipLength = _iceSpearDefault->GetHeight() / 2;

	return S_OK;
}

void throwIceSpear::release()
{
	_iceSpearDefault = nullptr;
	for (int i = 0; i < 36; i++)
	{
		_iceSpearImg[i] = nullptr;
	}
	_bossPos = nullptr;
	_playerPos = nullptr;
}

void throwIceSpear::update()
{
	if (_isStart) {
		//	��� â�鿡 ���Ͽ�,
		//_prepareShotElapsedTime += TIMEMANAGER->getElapsedTime();

		for (int i = 0; i < _spearNum; i++) {

			//	�� �غ����̸�
			//if (_prepareShotElapsedTime < PREPARE_SHOTTIME) {
			if(!_isRdyToShot){
				

				//	�ѹ��� â�غ��� ���������� ���ٸ�,
				//if (!_iceSpear[i]->isOnceSetSpearPrepareValue) {

				//	_iceSpear[i]->isOnceSetSpearPrepareValue = true;
					//	spear �ʱ���ġ ����
				//	SetSpearPrepareValueOnce(i, *_bossPos);
				//}
				//	�׻� ������Ʈ ����� �ϴ� ���� ����(angle, angle�����̹���)
				SetSpearPrepareValue(i, *_playerPos, *_bossPos);


			}	//	�� �غ��� ��

			//	�� �ð� ������!
			else {
				//	�ѹ��� ����ϴ¾ֵ� ��������
				if (!_iceSpear[i]->isOnceSetSpearShotValue) {
					_iceSpear[i]->isOnceSetSpearShotValue = true;
					//	������Ʈ ��ǥ			//	vector ���
					SetSpearShotValueOnce(i);
				}

				//	����! �Կ�����!!! //	������Ʈ�� �̵��ؼ� �ٽñ׸���
				SetSpearShotValue(i);

			}

		}
		_totalSkillElapsedTime += TIMEMANAGER->getElapsedTime();

		if (_totalSkillElapsedTime > END_SKILLTIME) {
			ResetAll();
		}
	}
}

void throwIceSpear::render(HDC hdc)
{
	if (_isStart) {
		for (int i = 0; i < _spearNum; i++) {
			_iceSpear[i]->img->alphaRender(hdc, _iceSpear[i]->rc.left, _iceSpear[i]->rc.top, _iceSpear[i]->alpha);
		}
	}

	//for (int i = 0; i < 36; i++) {
	//	if (i < 12) {
	//		_iceSpearImg[i]->render(hdc, 50 * i + 50, 50);
	//	}
	//	else if (13 <= i && i <= 25) {
	//		_iceSpearImg[i]->render(hdc, 50 * (i-13) + 50, 100);
	//	}
	//	else {
	//		_iceSpearImg[i]->render(hdc, 50 * (i-26) + 50, 150);
	//	}
	//}
	
	char str[128];
	
	
	if (_isStart) {
		

		//sprintf_s(str, "_prepareShotElapsedTime [%f]", _prepareShotElapsedTime);
		//TextOut(getMemDC(), 50, 50, str, strlen(str));

		

		//for (int i = 0; i < _iceSpear.size(); i++) {
			
			//sprintf_s(str, "angle[%d] : %d", i,(int)degree);
			//TextOut(getMemDC(), 50, 50 + i * 20, str, strlen(str));
		//}
	}
	
	
}

void throwIceSpear::UseSkill(POINTFLOAT * bossPos, POINTFLOAT * playerPos, int spearNum)
{
	_bossPos = bossPos;
	_playerPos = playerPos;
	if (_spearNum > SPEAR_MAXNUM) {
		_spearNum = SPEAR_MAXNUM;
	}
	else {
		_spearNum = spearNum;
	}
	

	
	
	_isStart = true;
	
}


void throwIceSpear::SetSpearPrepareValue(int idx, POINTFLOAT playerPos, POINTFLOAT bossPos)
{
	
	//	�� �޾ƿ���,
	_iceSpear[idx]->angle = getAngle(_iceSpear[idx]->pos.x, _iceSpear[idx]->pos.y, playerPos.x, playerPos.y);
	
	//if (_iceSpear[idx]->angle < 0)		_iceSpear[idx]->angle += PI * 2;
	//if (_iceSpear[idx]->angle >= PI*2)	_iceSpear[idx]->angle -= PI * 2;

	//	��ǥ����������
	_iceSpear[idx]->pos = bossPos;
	if (idx - 1 == -1) {
		//	ù���� �״��
	}
	//¦����
	else if (idx % 2 == 0) {
		_iceSpear[idx]->pos.x += _iceSpear[idx]->adjustPos.x * cosf(_iceSpear[0]->angle + PI / 2);
		_iceSpear[idx]->pos.y += _iceSpear[idx]->adjustPos.x * -sinf(_iceSpear[0]->angle + PI / 2);
	}
	else {
		_iceSpear[idx]->pos.x += _iceSpear[idx]->adjustPos.x * cosf(_iceSpear[0]->angle - PI / 2);
		_iceSpear[idx]->pos.y += _iceSpear[idx]->adjustPos.x * -sinf(_iceSpear[0]->angle - PI / 2);

	}
	
	_iceSpear[idx]->rc = RectMakeCenter(_iceSpear[idx]->pos.x, _iceSpear[idx]->pos.y, _iceSpearDefault->GetWidth() / 2, _iceSpearDefault->GetHeight() / 2);

	//	���� ���� �̹��� ����
	int spearImgIdx = (_iceSpear[idx]->angle + PI / 36) / (PI / 18);
	//		����ó��
	if (spearImgIdx == 36) {
		_iceSpear[idx]->img = _iceSpearImg[0];
	}
	else {
		_iceSpear[idx]->img = _iceSpearImg[spearImgIdx];
	}

	//�����ƾƾƾƾ�
	_iceSpear[idx]->alpha += _augAlpha;
	if (_iceSpear[idx]->alpha >= 255) {
		_iceSpear[idx]->alpha = 255.0f;
		//���������� ���İ� ������
		if (idx == _spearNum - 1) {
			_isRdyToShot = true;
		}
	}
}

void throwIceSpear::SetSpearShotValueOnce(int idx)
{
	//	������Ʈ ��ǥ
	_iceSpear[idx]->judgePos[0].x = _iceSpear[idx]->pos.x + (SPEAR_TIP_LENGTH * 3 / 4) * cosf(_iceSpear[idx]->angle);
	_iceSpear[idx]->judgePos[0].y = _iceSpear[idx]->pos.y + (SPEAR_TIP_LENGTH * 3 / 4) * -sinf(_iceSpear[idx]->angle);
											   
	_iceSpear[idx]->judgePos[1].x = _iceSpear[idx]->pos.x + (SPEAR_TIP_LENGTH * 1 / 4) * cosf(_iceSpear[idx]->angle);
	_iceSpear[idx]->judgePos[1].y = _iceSpear[idx]->pos.y + (SPEAR_TIP_LENGTH * 1 / 4) * -sinf(_iceSpear[idx]->angle);


	//	vector ���
	_iceSpear[idx]->vec.x = SPEAR_SPD * cosf(_iceSpear[idx]->angle);
	_iceSpear[idx]->vec.y = SPEAR_SPD * -sinf(_iceSpear[idx]->angle);
}

void throwIceSpear::SetSpearShotValue(int idx)
{
	//	����! �Կ�����!!!
	_iceSpear[idx]->pos.x += _iceSpear[idx]->vec.x;
	_iceSpear[idx]->pos.y += _iceSpear[idx]->vec.y;
	_iceSpear[idx]->rc = RectMakeCenter(_iceSpear[idx]->pos.x, _iceSpear[idx]->pos.y, _iceSpearDefault->GetWidth() / 2, _iceSpearDefault->GetHeight() / 2);

	//	������Ʈ�� �̵��ؼ� �ٽñ׸���
	_iceSpear[idx]->judgePos[0].x += _iceSpear[idx]->vec.x;
	_iceSpear[idx]->judgePos[0].x += _iceSpear[idx]->vec.y;
	_iceSpear[idx]->judgePos[1].x += _iceSpear[idx]->vec.x;
	_iceSpear[idx]->judgePos[1].x += _iceSpear[idx]->vec.y;
	_iceSpear[idx]->judgeRc[0] = RectMakeCenter(_iceSpear[idx]->judgePos[0].x, _iceSpear[idx]->judgePos[0].y, JUDGERC_WID, JUDGERC_WID);
	_iceSpear[idx]->judgeRc[1] = RectMakeCenter(_iceSpear[idx]->judgePos[1].x, _iceSpear[idx]->judgePos[1].y, JUDGERC_WID, JUDGERC_WID);
}

void throwIceSpear::ResetAll()
{
	_isStart = false;
	_isRdyToShot = false;
	//_prepareShotElapsedTime = 0;
	_totalSkillElapsedTime = 0;

	for (int i = 0; i < _iceSpear.size(); i++) {
		//_iceSpear[i]->isOnceSetSpearPrepareValue = false;
		_iceSpear[i]->isOnceSetSpearShotValue = false;
		_iceSpear[i]->alpha = 0;

	}

	


}
		

	



	