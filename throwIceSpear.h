#pragma once
#include "object.h"
#include "rotateImgMaker.h"

//	��µ��� ������Ʈ �ɾ��� ��.
//	UseSkill(POINTFLOAT* bossPos, POINTFLOAT* playerPos, int spearNum); �� �ѹ��� ������. �������ִ°�
//					������ǥ �ּ�, �÷��̾���ǥ �ּ�, �� ���Ǿ� ����
//	init�� ��÷�� �ѹ� �ɾ��ְ�, update, render�� ��Ӱɾ��ְ�,
//	END_SKILLTIME�� �Ǹ�(����10��) ���� �ʱ�ȭ�ǰ� ���̻� �۵�����(update��, ������)
//	END_SKILLTIME �Ǳ����� ��ų �� ������.


class throwIceSpear :public OBJECT
{
private:
	image* _iceSpearDefault;
	image* _iceSpearImg[36];
	
	struct tagIceSpear {
		image* img;					//	�����, �ǽð� set
		POINTFLOAT pos;				//	�����, �ѹ��� set
		POINT adjustPos;		//	���� �Ӹ� �� �߽ɿ��� �󸶳� �������ִ°�. ������ (â�� �������ϰ��)
		RECT rc;					//	�����, �ѹ��� set -> �� ��, ��� ����
		POINTFLOAT judgePos[2];		//	�� �ѹ��� set, ����, ��� ����
		RECT judgeRc[2];			//	�� �� ��� ����
		POINTFLOAT vec;				//	�� �ѹ��� set
		//	POINTFLOAT atkDestPos;		//	�� �ѹ��� set		//�Ⱦ�
		float angle;				//	�����, �ǽð� set
		int alpha;					//	�����, �ǽð� set
		
		//bool isOnceSetSpearPrepareValue;	//	�����, �ѹ��� �ʱ�ȭ���ִ°� üũ
		bool isOnceSetSpearShotValue;		//	��, �ѹ��� �ʱ�ȭ���ִ°� üũ
		//bool isShotPrepareEnd;
		
	};
	vector<tagIceSpear*> _iceSpear;
	//	float _spearTipLength;		�Ⱦ��ϴ�. SPEAR_TIP_LENGTH �� ��ü
	POINTFLOAT* _bossPos;
	POINTFLOAT* _playerPos;
	int _spearNum;

	float _prepareShotElapsedTime;
	float _totalSkillElapsedTime;


	float _augAlpha;
	

	bool _isStart;
	bool _isRdyToShot;


	const int SPEAR_MAXNUM = 20;			//	�ִ�� �� �� �ִ� â�� ����
	const float SPEAR_SPD = 30;				//	â�� ���󰡴� ���ǵ�
	const float SPEAR_TIP_LENGTH = 17.0f;	//	â���� ����(������Ʈ ������ ���)
	const double PREPARE_SHOTTIME = 1.0;	//	��������� ���ð�
	const int JUDGERC_WID = 17;				//	������Ʈ �Ѻ� ����
	

	const float END_SKILLTIME = 2.2f;		//	�ִ� ���ӽð� ��, �ð��ٵǸ� �ʱ�ȭ
	
	//	���� wid 150 / hei 200.22

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

