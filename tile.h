#pragma once
#include "stdafx.h"
#include "object.h"
//0 이면 벽
//139 이면 길

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
		TERRIAN terrain;		//지형
		OBJECT obj;				//오브젝트
		RECT rc;				//렉트
		int terrainFrameX;		//터레인 번호
		int terrainFrameY;		//터레인 번호
		int objFrameX;			//ㅇㅂㅈㅌ 번호
		int objFrameY;			//ㅇㅂㅈㅌ 번호
	};

public:
	TILE();
	~TILE();

private:
	int		_nAroundWall;		//주변벽값을 가진다.
	
	bool	_bIsWall;			//벽인지 아닌지 아직 2개 밖에 없어서 가능한 방식 나중에는 바꾸어야한다 테리안으로
	TERRIAN	_terrian;			//2가지가 아니라면 terrian을 사용해서 찾아야 한다.
	
	image*	_pImage;			//이미지를 담을 것이다.
	int		_nFrameX;			//프레임 넘버 X
	int		_nFrameY;			//프레임 넘버 Y
	int		_nObjFrameX;		//오브젝트 프레임 넘버 X
	int		_nObjFrameY;		//오브젝트 프레임 넘버 Y
	RECT	_rcTile;			//사각형
	int		_nNodeIndex;		//몇번째 노드인지 넣는 함수
	OBJECT	_object;			//무슨 오브젝트가 있는지
	image*	_pObjectImage;		//오브젝트 이미지 none이면 아무것도 안그림

	RECT	_rcCameraLimit;
	char	str[128];
	int		_terrainPageIndex;

public:
	void	setttingObject();
	void	setttingTerrain();
	void	setttingObject2();
	void	setttingTerrain2();

public:
	//초기 초기화
	void	init(int nTileLeft, int nTileTop, int nTileSize,image* pImg,int nNodeIndex);
	void	passInit(int nTileLeft, int nTileTop, int nTileSize, image* pImg);

	//그려주는 함수
	virtual void	render(HDC hdc) override;
	virtual void	render(HDC hdc, bool Map);
	
	//메모리 해제
	virtual void	release() override;
	virtual void	update() override;
	//타일 세팅
	void	settingTile(int nFrameX, int nFrameY, bool bIsWall,OBJECT object);
	
	//타일 세팅이 끝나면 재조정한 것을 받아온다 클릭을 멈추는 순간에 업데이트를 한번에 해서 받아온다.
	void	readjustWall(int nAroundWall, int nFrameX, int nFrameY);

	string	makeSaveString();

	bool	setObject(OBJECT object);
	OBJECT	getObject();

	void	move(int vertical,int horizontal);


	void	Tilesefewa();
	bool	bIsTrue;
public:
	//setter
	inline	void	setAroundWall(int nAroundWall) { _nAroundWall = nAroundWall; }
	inline	void	setIsWall(bool isWall) { _bIsWall = isWall; }
	inline	void	setImg(image* pImg) { _pImage = pImg; }
	inline	void	setObjimg(image* pObjimg) { _pObjectImage = pObjimg; }
	inline	void	setFrameX(int nFrameX) { _nFrameX = nFrameX; }
	inline	void	setFrameY(int nFrameY) { _nFrameY = nFrameY; }
	inline	void	setObjFrameX(int nObjFrameX) { _nObjFrameX = nObjFrameX; }
	inline	void	setObjFrameY(int nObjFrameY) { _nObjFrameY = nObjFrameY; }
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


	void renderBackGround(HDC hdc);
};