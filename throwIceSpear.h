#pragma once
#include "object.h"
#include "rotateImgMaker.h"

//	쏘는동안 업데이트 걸어줄 것.
//	UseSkill(POINTFLOAT* bossPos, POINTFLOAT* playerPos, int spearNum); 은 한번만 쓰세여. 시작해주는거
//					보스좌표 주소, 플레이어좌표 주소, 쏠 스피어 갯수
//	init은 맨첨에 한번 걸어주고, update, render는 계속걸어주고,
//	END_SKILLTIME이 되면(현재10초) 몽땅 초기화되고 더이상 작동안함(update도, 렌더도)
//	END_SKILLTIME 되기전에 스킬 또 못씀요.


class throwIceSpear :public OBJECT
{
private:
	image* _iceSpearDefault;
	image* _iceSpearImg[36];
	
	struct tagIceSpear {
		image* img;					//	쏘기전, 실시간 set
		POINTFLOAT pos;				//	쏘기전, 한번만 set
		POINT adjustPos;		//	보스 머리 위 중심에서 얼마나 떨어져있는가. 보정용 (창이 여러개일경우)
		RECT rc;					//	쏘기전, 한번만 set -> 쏜 후, 계속 갱신
		POINTFLOAT judgePos[2];		//	쏠때 한번만 set, 쏜후, 계속 갱신
		RECT judgeRc[2];			//	쏜 후 계속 갱신
		POINTFLOAT vec;				//	쏠때 한번만 set
		//	POINTFLOAT atkDestPos;		//	쏠때 한번만 set		//안씀
		float angle;				//	쏘기전, 실시간 set
		int alpha;					//	쏘기전, 실시간 set
		
		//bool isOnceSetSpearPrepareValue;	//	쏘기전, 한번만 초기화해주는거 체크
		bool isOnceSetSpearShotValue;		//	쏠때, 한번만 초기화해주는거 체크
		//bool isShotPrepareEnd;
		
	};
	vector<tagIceSpear*> _iceSpear;
	//	float _spearTipLength;		안씀니다. SPEAR_TIP_LENGTH 로 교체
	POINTFLOAT* _bossPos;
	POINTFLOAT* _playerPos;
	int _spearNum;

	float _prepareShotElapsedTime;
	float _totalSkillElapsedTime;


	float _augAlpha;
	

	bool _isStart;
	bool _isRdyToShot;


	const int SPEAR_MAXNUM = 20;			//	최대로 쏠 수 있는 창의 갯수
	const float SPEAR_SPD = 30;				//	창이 날라가는 스피드
	const float SPEAR_TIP_LENGTH = 17.0f;	//	창날의 길이(판정렉트 생성에 사용)
	const double PREPARE_SHOTTIME = 1.0;	//	쏘기전까지 대기시간
	const int JUDGERC_WID = 17;				//	판정렉트 한변 길이
	

	const float END_SKILLTIME = 2.2f;		//	최대 지속시간 및, 시간다되면 초기화
	
	//	보스 wid 150 / hei 200.22

	rotateImgMaker* _imgMaker;
	
	

public:
	throwIceSpear();
	~throwIceSpear();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void UseSkill(POINTFLOAT* bossPos, POINTFLOAT* playerPos, int spearNum);
	void SetSpearPrepareValue(int idx, POINTFLOAT playerPos, POINTFLOAT bossPos);
	void SetSpearShotValueOnce(int idx);
	void SetSpearShotValue(int idx);
	void ResetAll();

	void setIsStart(bool value) { _isStart = value; }
	bool getIsStart() { return _isStart; }

	
};

