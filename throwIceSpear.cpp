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
	//	원본이미지 넣었다 치고,
	IMAGEMANAGER->addImage("iceSpearDefault", "resource/boss/ice/iceSpear.bmp", 96, 96, true, 0xFF00FF);
	
	_iceSpearDefault = IMAGEMANAGER->findImage("iceSpearDefault");
	_imgMaker = new rotateImgMaker;

	//	회전이미지 생성
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

		//	첫 번째면,
		if (i == -1)
		{
			tmpIceSpear->adjustPos = { 0,0 };
		}
		//	짝수번째면,
		else if (i % 2 == 0)
		{
			tmpIceSpear->adjustPos = { 100* ((i / 2)+1) ,0 };
		}
		//	홀수번째면
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
		//	모든 창들에 대하여,
		//_prepareShotElapsedTime += TIMEMANAGER->getElapsedTime();

		for (int i = 0; i < _spearNum; i++) {

			//	쏠 준비중이면
			//if (_prepareShotElapsedTime < PREPARE_SHOTTIME) {
			if(!_isRdyToShot){
				

				//	한번도 창준비값을 설정한적이 없다면,
				//if (!_iceSpear[i]->isOnceSetSpearPrepareValue) {

				//	_iceSpear[i]->isOnceSetSpearPrepareValue = true;
					//	spear 초기위치 세팅
				//	SetSpearPrepareValueOnce(i, *_bossPos);
				//}
				//	항상 업데이트 해줘야 하는 값들 세팅(angle, angle적용이미지)
				SetSpearPrepareValue(i, *_playerPos, *_bossPos);


			}	//	쏠 준비중 끝

			//	쏠 시간 됐으면!
			else {
				//	한번만 계산하는애들 계산하즈아
				if (!_iceSpear[i]->isOnceSetSpearShotValue) {
					_iceSpear[i]->isOnceSetSpearShotValue = true;
					//	판정렉트 좌표			//	vector 계산
					SetSpearShotValueOnce(i);
				}

				//	가랏! 게오볼그!!! //	판정렉트도 이동해서 다시그리기
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
	
	//	각 받아오고,
	_iceSpear[idx]->angle = getAngle(_iceSpear[idx]->pos.x, _iceSpear[idx]->pos.y, playerPos.x, playerPos.y);
	
	//if (_iceSpear[idx]->angle < 0)		_iceSpear[idx]->angle += PI * 2;
	//if (_iceSpear[idx]->angle >= PI*2)	_iceSpear[idx]->angle -= PI * 2;

	//	좌표설정시이작
	_iceSpear[idx]->pos = bossPos;
	if (idx - 1 == -1) {
		//	첫놈은 그대로
	}
	//짝수는
	else if (idx % 2 == 0) {
		_iceSpear[idx]->pos.x += _iceSpear[idx]->adjustPos.x * cosf(_iceSpear[0]->angle + PI / 2);
		_iceSpear[idx]->pos.y += _iceSpear[idx]->adjustPos.x * -sinf(_iceSpear[0]->angle + PI / 2);
	}
	else {
		_iceSpear[idx]->pos.x += _iceSpear[idx]->adjustPos.x * cosf(_iceSpear[0]->angle - PI / 2);
		_iceSpear[idx]->pos.y += _iceSpear[idx]->adjustPos.x * -sinf(_iceSpear[0]->angle - PI / 2);

	}
	
	_iceSpear[idx]->rc = RectMakeCenter(_iceSpear[idx]->pos.x, _iceSpear[idx]->pos.y, _iceSpearDefault->GetWidth() / 2, _iceSpearDefault->GetHeight() / 2);

	//	각에 따른 이미지 세팅
	int spearImgIdx = (_iceSpear[idx]->angle + PI / 36) / (PI / 18);
	//		예외처리
	if (spearImgIdx == 36) {
		_iceSpear[idx]->img = _iceSpearImg[0];
	}
	else {
		_iceSpear[idx]->img = _iceSpearImg[spearImgIdx];
	}

	//알프아아아아아
	_iceSpear[idx]->alpha += _augAlpha;
	if (_iceSpear[idx]->alpha >= 255) {
		_iceSpear[idx]->alpha = 255.0f;
		//마지막까지 알파가 끝나믄
		if (idx == _spearNum - 1) {
			_isRdyToShot = true;
		}
	}
}

void throwIceSpear::SetSpearShotValueOnce(int idx)
{
	//	판정렉트 좌표
	_iceSpear[idx]->judgePos[0].x = _iceSpear[idx]->pos.x + (SPEAR_TIP_LENGTH * 3 / 4) * cosf(_iceSpear[idx]->angle);
	_iceSpear[idx]->judgePos[0].y = _iceSpear[idx]->pos.y + (SPEAR_TIP_LENGTH * 3 / 4) * -sinf(_iceSpear[idx]->angle);
											   
	_iceSpear[idx]->judgePos[1].x = _iceSpear[idx]->pos.x + (SPEAR_TIP_LENGTH * 1 / 4) * cosf(_iceSpear[idx]->angle);
	_iceSpear[idx]->judgePos[1].y = _iceSpear[idx]->pos.y + (SPEAR_TIP_LENGTH * 1 / 4) * -sinf(_iceSpear[idx]->angle);


	//	vector 계산
	_iceSpear[idx]->vec.x = SPEAR_SPD * cosf(_iceSpear[idx]->angle);
	_iceSpear[idx]->vec.y = SPEAR_SPD * -sinf(_iceSpear[idx]->angle);
}

void throwIceSpear::SetSpearShotValue(int idx)
{
	//	가랏! 게오볼그!!!
	_iceSpear[idx]->pos.x += _iceSpear[idx]->vec.x;
	_iceSpear[idx]->pos.y += _iceSpear[idx]->vec.y;
	_iceSpear[idx]->rc = RectMakeCenter(_iceSpear[idx]->pos.x, _iceSpear[idx]->pos.y, _iceSpearDefault->GetWidth() / 2, _iceSpearDefault->GetHeight() / 2);

	//	판정렉트도 이동해서 다시그리기
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
		

	



	