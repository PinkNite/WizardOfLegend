#pragma once
#include "stdafx.h"
#include "object.h"
//0 �̸� ��
//139 �̸� ��

enum {PASS = 139};

class TILE :public OBJECT
{
public:

	enum OBJECT
	{
		NONE = 0,
		PLAYER,
		ENEMY01,
		ENEMY02,
		ENEMY03,
		ENEMY04,
		BOSS,
		ITEM,
		NOMAL_OBJECT,
		MAX
	};

	enum class TERRIAN
	{
		NONE = 0,
		WALL,
		PASS,
		DMAGE_PASS,
		MAX
	};

	struct tagTile
	{
		TERRIAN terrain;		//����
		OBJECT obj;				//������Ʈ
		RECT rc;				//��Ʈ
		int terrainFrameX;		//�ͷ��� ��ȣ
		int terrainFrameY;		//�ͷ��� ��ȣ
		int objFrameX;			//�������� ��ȣ
		int objFrameY;			//�������� ��ȣ
	};

public:
	TILE();
	~TILE();

private:
	int		_nAroundWall;		//�ֺ������� ������.
	
	bool	_bIsWall;			//������ �ƴ��� ���� 2�� �ۿ� ��� ������ ��� ���߿��� �ٲپ���Ѵ� �׸�������
	TERRIAN	_terrian;			//2������ �ƴ϶�� terrian�� ����ؼ� ã�ƾ� �Ѵ�.
	
	image*	_pImage;			//�̹����� ���� ���̴�.
	int		_nFrameX;			//������ �ѹ� X
	int		_nFrameY;			//������ �ѹ� Y
	RECT	_rcTile;			//�簢��
	int		_nNodeIndex;		//���° ������� �ִ� �Լ�
	OBJECT	_object;			//���� ������Ʈ�� �ִ���
	image*	_pObjectImage;		//������Ʈ �̹��� none�̸� �ƹ��͵� �ȱ׸�

	RECT	_rcCameraLimit;
	char	str[128];
	int		_terrainPageIndex;

public:
	void	setttingObject();
	void	setttingTerrain();
	void	setttingObject2();
	void	setttingTerrain2();

public:
	//�ʱ� �ʱ�ȭ
	void	init(int nTileLeft, int nTileTop, int nTileSize,image* pImg,int nNodeIndex);
	void	passInit(int nTileLeft, int nTileTop, int nTileSize, image* pImg);

	//�׷��ִ� �Լ�
	virtual void	render(HDC hdc) override;

	//�޸� ����
	virtual void	release() override;
	virtual void	update() override;
	//Ÿ�� ����
	void	settingTile(int nFrameX, int nFrameY, bool bIsWall,OBJECT object);
	
	//Ÿ�� ������ ������ �������� ���� �޾ƿ´� Ŭ���� ���ߴ� ������ ������Ʈ�� �ѹ��� �ؼ� �޾ƿ´�.
	void	readjustWall(int nAroundWall, int nFrameX, int nFrameY);

	string	makeSaveString();

	bool	setObject(OBJECT object);
	OBJECT	getObject();

	void	move(int vertical,int horizontal);

public:
	//setter
	inline	void	setAroundWall(int nAroundWall) { _nAroundWall = nAroundWall; }
	inline	void	setIsWall(bool isWall) { _bIsWall = isWall; }
	inline	void	setImg(image* pImg) { _pImage = pImg; }
	inline	void	setObjimg(image* pObjimg) { _pObjectImage = pObjimg; }
	inline	void	setFrameX(int nFrameX) { _nFrameX = nFrameX; }
	inline	void	setFrameY(int nFrameY) { _nFrameY = nFrameY; }
	inline	void	setRectTile(RECT& rcTile) {	_rcTile = rcTile;}
	inline	void	setRectTile(int nLeft, int nTop, int nWidth, int nHeight) { _rcTile = RectMake(nLeft, nTop, nWidth, nHeight); }
	inline	void	setNodeIndex(int nIndex) { _nNodeIndex = nIndex; }
	inline	void	setLimitRect(RECT rc) { _rcCameraLimit = rc; }
	inline	void	setTerrian(TERRIAN terrian) { _terrian = terrian; }
	inline	void	setTerrainPageIndex(int terrainPageIndex) {	_terrainPageIndex = terrainPageIndex; }

	//getter
	inline	int				getAroundWall() { return _nAroundWall; }
	inline	bool			getIsWall() { return _bIsWall; }
	inline	image*			getimg() { return _pImage; }
	inline	int				getFrameX() { return _nFrameX; }
	inline	int				setFrameY() { return _nFrameY; }
	inline	RECT			getRectTile() { return _rcTile; }
	inline	int				getNodeIndex() { return _nNodeIndex; }
	inline	TILE::TERRIAN	getTerrian() {return _terrian; }
	inline	int				getTerrainPageIndex() { return _terrainPageIndex; }
};