#include "stdafx.h"
#include "mapEdit.h"
void MAPEDIT::callBackMapWall()
{
	printf_s("Wall버튼을 눌렀네요\n");
	_mapEditstate = MAPEDITSTATE::MAPEDITWALL;
}

void MAPEDIT::callBackMapTerrain()
{
	printf_s("Terrain버튼을 눌렀네요\n");
	_mapEditstate = MAPEDITSTATE::MAPEDITTERRAIN;
}

void MAPEDIT::callBackMapObject()
{
	printf_s("Object버튼을 눌렀네요\n");
	_mapEditstate = MAPEDITSTATE::MAPEDITOBJECT;
}

void MAPEDIT::callBackMapSave()
{
	printf_s("Save버튼을 눌렀네요\n");
	_pMapTool->save();
}

void MAPEDIT::callBackMapLoad()
{
	printf_s("Load버튼을 눌렀네요\n");
	_pMapTool->load();
}

void MAPEDIT::callBackMapSizeUp()
{
	_pMapTool->mapResize(_pMapTool->getMapCountX(), _pMapTool->getMapCountY() - 1);
}

void MAPEDIT::callBackMapSizeDown()
{
	_pMapTool->mapResize(_pMapTool->getMapCountX(), _pMapTool->getMapCountY() + 1);
}

void MAPEDIT::callBackMapSizeLeft()
{
	_pMapTool->mapResize(_pMapTool->getMapCountX() - 1, _pMapTool->getMapCountY());
}

void MAPEDIT::callBackMapSizeRight()
{
	_pMapTool->mapResize(_pMapTool->getMapCountX() + 1, _pMapTool->getMapCountY());
}

MAPEDIT::MAPEDIT()
{
}

MAPEDIT::~MAPEDIT()
{
}

HRESULT MAPEDIT::init()
{
	_pCamera = new CAMERA();
	_pCamera->init((WINSIZEX) / 2 - 18, WINSIZEY / 2 - 18, WINSIZEX, WINSIZEY, 2048, 2048);

	_pMapTool = new MAPTOOL();
	_pMapTool->passInit(25, 14, 32);
	_pMapTool->setCamera(_pCamera);
	
	_rcTileCountX = new RECT[_pMapTool->getMapCountX()];
	_rcTileCountY = new RECT[_pMapTool->getMapCountY()];
	
	imgRelicUITypePageBG = IMAGEMANAGER->addImage("RelicUITypePageBG", "resource/UI/RelicUITypePageBG.bmp", 576, 600, true, RGB(255, 0, 255));
	imgRelicUIDrawer = IMAGEMANAGER->addFrameImage("RelicUIDrawer", "resource/UI/RelicUIDrawer.bmp", 469, 520, 1, 5, true, RGB(255, 0, 255));
	imgRelicUIBG = IMAGEMANAGER->addImage("UIBackGround", "resource/UI/RelicUIBG.bmp", 600, 900, true, RGB(255, 0, 255));
	imgRelicUIBG2 = IMAGEMANAGER->addImage("UIBackGround2", "resource/UI/RelicUIBG2.bmp", 600, 900, true, RGB(255, 0, 255)); 
	imgRelicUISelectPageBG = IMAGEMANAGER->addImage("RelicUISelectPageBG", "resource/UI/RelicUISelectPageBG4.bmp", 490, 568, true, RGB(255, 0, 255)); // 53, 125
	imgMapPalletIce1 = IMAGEMANAGER->addFrameImage("MapPalletIce1", "resource/UI/icetileset3.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletCastle1 = IMAGEMANAGER->addFrameImage("MapPalletCastle1", "resource/UI/castletileset.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletEarth1 = IMAGEMANAGER->addFrameImage("MapPalletEarth1", "resource/UI/earthtileset.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletFire1 = IMAGEMANAGER->addFrameImage("MapPalletFire1", "resource/UI/firetileset.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	imgMapEraser = IMAGEMANAGER->addFrameImage("MapEraser", "resource/UI/eraser.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletIce2 = IMAGEMANAGER->addFrameImage("MapPalletIce2", "resource/UI/icetileset2.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletCastle2 = IMAGEMANAGER->addFrameImage("MapPalletCastle2", "resource/UI/castletileset2.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletEarth2 = IMAGEMANAGER->addFrameImage("MapPalletEarth2", "resource/UI/earthtileset2.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	imgMapPalletFire2 = IMAGEMANAGER->addFrameImage("MapPalletFire2", "resource/UI/firetileset2.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	imgMapEraser2 = IMAGEMANAGER->addFrameImage("MapEraser2", "resource/UI/eraser2.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	imgMapObject = IMAGEMANAGER->addFrameImage("MapOBJECT", "resource/UI/OBJECT.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	imgMapObject2 = IMAGEMANAGER->addFrameImage("MapOBJECT2", "resource/UI/OBJECT2.bmp", 384, 384, 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MapOBJECT3", "resource/UI/OBJECT3.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Wall", "resource/UI/WallUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Terrain", "resource/UI/TerrainUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Object", "resource/UI/ObjectUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Save", "resource/UI/SaveUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Load", "resource/UI/LoadUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));

	for (int i = 0; i < _pMapTool->getMapCountX(); i++)
	{
		_rcTileCountX[i] = RectMake(18 + i * imgMapPalletIce1->getFrameWidth(), 0, imgMapPalletIce1->getFrameWidth(), imgMapPalletIce1->getFrameWidth() / 2 + 2);
	}
	for (int i = 0; i < _pMapTool->getMapCountY(); i++)
	{
		_rcTileCountY[i] = RectMake(0, 18 + i * imgMapPalletIce1->getFrameHeight(), imgMapPalletIce1->getFrameHeight() / 2 + 2, imgMapPalletIce1->getFrameWidth());
	}

	rcTypePage = RectMake(1015, 277, imgRelicUITypePageBG->GetWidth(), imgRelicUITypePageBG->GetHeight());
	rcSelectPage = RectMake(1015, 277, imgRelicUISelectPageBG->GetWidth(), imgRelicUISelectPageBG->GetHeight());
	
	//TerrainPage
	rcMapPalletIce1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
	_vTerrainPage.push_back(IMAGEMANAGER->findImage("MapPalletIce1"));
	rcMapPalletEarth1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
	_vTerrainPage.push_back(IMAGEMANAGER->findImage("MapPalletCastle1"));
	rcMapPalletFire1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
	_vTerrainPage.push_back(IMAGEMANAGER->findImage("MapPalletEarth1"));
	rcMapPalletCastle1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
	_vTerrainPage.push_back(IMAGEMANAGER->findImage("MapPalletFire1"));
	rcMapPalletEraser = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
	_vTerrainPage.push_back(IMAGEMANAGER->findImage("MapEraser"));
	rcMapOBJECT = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
	_vObjectPage.push_back(IMAGEMANAGER->findImage("MapOBJECT"));
	_vObjectPage2.push_back(IMAGEMANAGER->findImage("MapOBJECT2"));
	for (int i = 0; i < 5; i++)
	{
		rcRelicUIDrawer[i] = RectMake(53 + 1015, 277 + 61 + 96 * i, 470, 88);
		rcBtnTitle[i] = RectMake(53 + 1015, 61 + 96 * i, IMAGEMANAGER->findImage("Wall")->getFrameWidth(), IMAGEMANAGER->findImage("Wall")->getFrameHeight());
		_ptInbtn[i] = false;
		_moveY[i] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		pt[i].x = 0;
		pt[i].y = i;
	}

	_btnWall = new button();
	_btnTerrain = new button();
	_btnObject = new button();
	_btnSave = new button();
	_btnLoad = new button();
	_btnWall->initRc("Wall", rcRelicUIDrawer[0], 133, 15, pt[1], pt[2], pt[0], bind(&MAPEDIT::callBackMapWall, this));
	_btnTerrain->initRc("Terrain", rcRelicUIDrawer[1], 133, 15, pt[1], pt[2], pt[0], bind(&MAPEDIT::callBackMapTerrain, this));
	_btnObject->initRc("Object", rcRelicUIDrawer[2], 133, 15, pt[1], pt[2], pt[0], bind(&MAPEDIT::callBackMapObject, this));
	_btnSave->initRc("Save", rcRelicUIDrawer[3], 133, 15, pt[1], pt[2], pt[0], bind(&MAPEDIT::callBackMapSave, this));
	_btnLoad->initRc("Load", rcRelicUIDrawer[4], 133, 15, pt[1], pt[2], pt[0], bind(&MAPEDIT::callBackMapLoad, this));

	_index = _count = 0;
	movingWindow.x = movingWindow.y = 0;
	_drawerVertexSize = 40;
	_mapEditstate = MAPEDITSTATE::MAPEDITMENU;
	_terrainPageIndex = 0;
	_objectPageIndex = 0;

	return S_OK;
}

void MAPEDIT::update()
{
	_rcTileCountX = new RECT[_pMapTool->getMapCountX()];
	_rcTileCountY = new RECT[_pMapTool->getMapCountY()];

	for (int i = 0; i < _pMapTool->getMapCountX(); i++)
	{
		_rcTileCountX[i] = RectMake(18 + _pMapTool->getVvMap()[0][i]->getRectTile().left , 0, imgMapPalletIce1->getFrameWidth(), imgMapPalletIce1->getFrameWidth() / 2 + 2);
	}
	for (int i = 0; i < _pMapTool->getMapCountY(); i++)
	{
		_rcTileCountY[i] = RectMake(0, 18 + _pMapTool->getVvMap()[i][0]->getRectTile().top, imgMapPalletIce1->getFrameHeight() / 2 + 2, imgMapPalletIce1->getFrameWidth());
	}

	//격자 그리기, 현재 인덱스
	for (int i = 0; i < _pMapTool->getMapCountX(); i++)
	{
		if (_ptMouse.x >= _rcTileCountX[i].left && _ptMouse.x <= _rcTileCountX[i].right)
		{
			_currentIndex.x = i;
		}
	}
	for (int i = 0; i < _pMapTool->getMapCountY(); i++)
	{
		if (_ptMouse.y >= _rcTileCountY[i].top && _ptMouse.y <= _rcTileCountY[i].bottom)
		{
			_currentIndex.y = i;
		}
	}
	
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		updateMenu();
	}
	else if (_mapEditstate == MAPEDITSTATE::MAPEDITWALL)
	{
		updateWall();
	}
	else if (_mapEditstate == MAPEDITSTATE::MAPEDITTERRAIN)
	{
		updateTerrain();
	}
	else if (_mapEditstate == MAPEDITSTATE::MAPEDITOBJECT)
	{
		updateObject();
	}
	if (KEYMANAGER->isStayKeyDown('1'))
	{
		if (_pMapTool->getMapCountY() > 1)
		{
			callBackMapSizeUp();
		}
	}
	else if (KEYMANAGER->isStayKeyDown('2'))
	{
		callBackMapSizeDown();
	}
	else if (KEYMANAGER->isStayKeyDown('3'))
	{
		if (_pMapTool->getMapCountX() > 1)
		{
			callBackMapSizeLeft();
		}
	}
	else if(KEYMANAGER->isStayKeyDown('4'))
	{
		callBackMapSizeRight();
	}

	_pMapTool->update();
}

void MAPEDIT::release()
{
	_pMapTool->release();
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		_btnWall->release();
		_btnTerrain->release();
		_btnObject->release();
		_btnLoad->release();
		_btnSave->release();
	}
	delete[] _rcTileCountX;
	delete[] _rcTileCountY;
}

void MAPEDIT::render()
{
	_pCamera->renderinit();
	_pMapTool->render(_pCamera->getMemDC());
	_pCamera->render(getMemDC());

	//RectangleMake(getMemDC(), _rcTileCountX[0].left, _rcTileCountX[0].top, 32, 16);
	//타일 격자 그리기
	for (int i = 0; i < _pMapTool->getMapCountX(); i++)
	{
		if (i == _currentIndex.x)
		{
			HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 0));
			HBRUSH oBrush = (HBRUSH)SelectObject(getMemDC(), Brush);
			RectangleMake(getMemDC(), _rcTileCountX[i].left, _rcTileCountX[i].top, 32, 18);
			SelectObject(getMemDC(), oBrush);
			DeleteObject(Brush);

			sprintf_s(str, "%d", i);
			SetTextColor(getMemDC(), RGB(255, 255, 255)); 
			SetBkMode(getMemDC(), TRANSPARENT);
			TextOut(getMemDC(), _rcTileCountX[i].right - 16 - (strlen(str) * 8 / 2), _rcTileCountX[i].top + 1, str, strlen(str));
		}
		else
		{
			RectangleMake(getMemDC(), _rcTileCountX[i].left, _rcTileCountX[i].top, 32, 18);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf_s(str, "%d", i);
			TextOut(getMemDC(), _rcTileCountX[i].right - 16 - (strlen(str) * 8 / 2), _rcTileCountX[i].top + 1, str, strlen(str));
		}
	}
	for (int i = 0; i < _pMapTool->getMapCountY(); i++)
	{
		if (i == _currentIndex.y)
		{
			HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 0));
			HBRUSH oBrush = (HBRUSH)SelectObject(getMemDC(), Brush);
			RectangleMake(getMemDC(), _rcTileCountY[i].left, _rcTileCountY[i].top, 18, 32);
			SelectObject(getMemDC(), oBrush);
			DeleteObject(Brush);

			sprintf_s(str, "%d", i);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			SetBkMode(getMemDC(), TRANSPARENT);
			TextOut(getMemDC(), _rcTileCountY[i].left + 1, _rcTileCountY[i].top + 8, str, strlen(str));
		}
		else
		{
			RectangleMake(getMemDC(), _rcTileCountY[i].left, _rcTileCountY[i].top, 18, 32);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf_s(str, "%d", i);
			TextOut(getMemDC(), _rcTileCountY[i].left + 1, _rcTileCountY[i].top + 8, str, strlen(str));
		}		
	}

	//imgRelicUIBG->render(getMemDC(), 1000, 0);
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		renderMenu();
	}
	else if (_mapEditstate == MAPEDITSTATE::MAPEDITWALL)
	{
		renderWall();
	}
	else if (_mapEditstate == MAPEDITSTATE::MAPEDITTERRAIN)
	{
		renderTerrain();
	}
	else if (_mapEditstate == MAPEDITSTATE::MAPEDITOBJECT)
	{
		//renderTerrain();
		renderObject();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		_mapEditstate = MAPEDITSTATE::MAPEDITMENU;
	}
}

void MAPEDIT::updateMenu()
{
	_btnWall->update(rcRelicUIDrawer[0]);
	_btnTerrain->update(rcRelicUIDrawer[1]);
	_btnObject->update(rcRelicUIDrawer[2]);
	_btnLoad->update(rcRelicUIDrawer[3]);
	_btnSave->update(rcRelicUIDrawer[4]);

	//왼쪽 위 모서리
	rcTypePageVertex = RectMake(rcTypePage.left, rcTypePage.top, _drawerVertexSize, _drawerVertexSize);
	
	//창 무브
	moveWindow();

	//서랍장 열리는 frameindex 설정
	for (int i = 0; i < 5; i++)
	{
		if (PtInRect(&rcRelicUIDrawer[i], _ptMouse))
		{
			_VarationY[0] = i;
			if (_count % 10 == 0)
			{
				_VarationY[1] = i;
				_index++;
				imgRelicUIDrawer->SetFrameY(_index);
				if (_index == 0)
				{
					_moveY[i] = 0;
				}
				else if (_index == 1)
				{
					_moveY[i] = 3;
				}
				else if (_index == 2)
				{
					_moveY[i] = 6;
				}
				else if (_index == 3)
				{
					_moveY[i] = 12;
				}
				else
				{
					_moveY[i] = 18;
				}
				if (_index >= imgRelicUIDrawer->getMaxFrameY())
				{
					_index = imgRelicUIDrawer->getMaxFrameY();
				}
				_count = 0;
			}
			_ptInbtn[i] = true;
		}
		else
		{
			_ptInbtn[i] = false;
			_moveY[i] = 0;
		}
		//마우스를 빠르게 이동할때 1.예외처리가 걸리지 못했을 때 index를 0으로
		if (_VarationY[0] != _VarationY[1])
		{
			imgRelicUIDrawer->SetFrameX(0);
			imgRelicUIDrawer->SetFrameY(0);
			_index = 0;
		}
	}

	//1. 다른메뉴창 선택시 index를 0으로
	if (_ptInbtn[0] == _ptInbtn[1] == _ptInbtn[2] == _ptInbtn[3] == _ptInbtn[4] == false)
	{
		imgRelicUIDrawer->SetFrameX(0);
		imgRelicUIDrawer->SetFrameY(0);
		_index = 0;
	}
	_count++;
}

void MAPEDIT::updateWall()
{
	//왼쪽 위 모서리
	rcSelectPageVertex = RectMake(rcTypePage.left, rcTypePage.top, _drawerVertexSize, _drawerVertexSize);
	moveWindow();
}

void MAPEDIT::updateTerrain()
{
	//왼쪽 위 모서리
	rcSelectPageVertex = RectMake(rcTypePage.left, rcTypePage.top, _drawerVertexSize, _drawerVertexSize);
	moveWindow();
	if (!PtInRect(&rcTypePage, _ptMouse) || !PtInRect(&rcSelectPage, _ptMouse))
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			for (int j = 0; j <= _vTerrainPage[_terrainPageIndex]->getMaxFrameY(); j++)
			{

				for (int i = 0; i <= _vTerrainPage[_terrainPageIndex]->getMaxFrameX(); i++)
				{
					if (i >= _clickDownStart.x && i <= _clickDownEnd.x &&
						j >= _clickDownStart.y && j <= _clickDownEnd.y)
					{
						//맵 사이즈 외로 타일맵 세팅해주는걸 막음
						if (_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2) >= 0 && _currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2) >= 0
							&& _currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2) < _pMapTool->getMapCountY() && _currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2) < _pMapTool->getMapCountX())
						{
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
								[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setImg(_vTerrainPage[_terrainPageIndex]);
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
								[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setFrameX(i);
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
								[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setFrameY(j);
							if (_terrainPageIndex == _vTerrainPage.size() - 1)
							{
								if (i >= 0 && i <= 4 && j >= 0 && j <= 11)
								{
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
										[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrian(TILE::TERRIAN::DMAGE_PASS);
									_pMapTool->setisWall(true);
									_pMapTool->setObject(TILE::OBJECT::NONE);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
										[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setObject(TILE::OBJECT::NONE);
								}
								else if (i >= 5 && i <= 6 && j >= 0 && j <= 6)
								{
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
										[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
									_pMapTool->setisWall(true);
									_pMapTool->setObject(TILE::OBJECT::NONE);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
										[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setObject(TILE::OBJECT::NONE);
								}
								else
								{
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
										[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
									_pMapTool->setisWall(true);
									_pMapTool->setObject(TILE::OBJECT::NONE);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
										[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setObject(TILE::OBJECT::NONE);
								}
							}
							else if (i == 0 || i == 11)
							{
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
									[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								_pMapTool->setisWall(true);
								_pMapTool->setObject(TILE::OBJECT::NONE);
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
									[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setObject(TILE::OBJECT::NONE);
							}
							else if ((j >= 0 && j <= 3) || j == 11)
							{
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
									[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								_pMapTool->setisWall(true);
								_pMapTool->setObject(TILE::OBJECT::NONE);
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
									[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setObject(TILE::OBJECT::NONE);
							}
							else
							{
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
									[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrian(TILE::TERRIAN::PASS);
								_pMapTool->setisWall(false);
								_pMapTool->setObject(TILE::OBJECT::NONE);
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
									[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setObject(TILE::OBJECT::NONE);
							}
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart.y - j) - ceil(abs(static_cast<float>(_clickDownEnd.y) - static_cast<float>(_clickDownStart.y)) / 2)]
								[_currentIndex.x - (_clickDownStart.x - i) - ceil(abs(static_cast<float>(_clickDownEnd.x) - static_cast<float>(_clickDownStart.x)) / 2)]->setTerrainPageIndex(_terrainPageIndex);
						}
					}
				}
			}
		}
	}

	//선택 알파 블랜드
	if (PtInRect(&rcMapPalletIce1, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int j = 0; j <= _vTerrainPage[_terrainPageIndex]->getMaxFrameY(); j++)
			{
				for (int i = 0; i <= _vTerrainPage[_terrainPageIndex]->getMaxFrameX(); i++)
				{
					if (_ptMouse.x >= rcMapPalletIce1.left + i * _vTerrainPage[_terrainPageIndex]->getFrameWidth() && _ptMouse.x <= rcMapPalletIce1.left + i * _vTerrainPage[_terrainPageIndex]->getFrameWidth() + _vTerrainPage[_terrainPageIndex]->getFrameWidth()
						&& _ptMouse.y >= rcMapPalletIce1.top + j * _vTerrainPage[_terrainPageIndex]->getFrameHeight() && _ptMouse.y <= rcMapPalletIce1.top + j * _vTerrainPage[_terrainPageIndex]->getFrameHeight() + _vTerrainPage[_terrainPageIndex]->getFrameHeight())
					{
						_clickDownStart.x = i;
						_clickDownStart.y = j;
					}
				}
			}
			_clickMap = true;
		}
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			for (int j = 0; j <= _vTerrainPage[_terrainPageIndex]->getMaxFrameY(); j++)
			{

				for (int i = 0; i <= _vTerrainPage[_terrainPageIndex]->getMaxFrameX(); i++)
				{
					if (_ptMouse.x >= rcMapPalletIce1.left + i * _vTerrainPage[_terrainPageIndex]->getFrameWidth() && _ptMouse.x <= rcMapPalletIce1.left + i * _vTerrainPage[_terrainPageIndex]->getFrameWidth() + _vTerrainPage[_terrainPageIndex]->getFrameWidth()
						&& _ptMouse.y >= rcMapPalletIce1.top + j * _vTerrainPage[_terrainPageIndex]->getFrameHeight() && _ptMouse.y <= rcMapPalletIce1.top + j * _vTerrainPage[_terrainPageIndex]->getFrameHeight() + _vTerrainPage[_terrainPageIndex]->getFrameHeight())
					{
						_clickDownEnd.x = i;
						_clickDownEnd.y = j;
					}
				}
			}
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_clickMap = false;
		}
	}
}

void MAPEDIT::updateObject()
{
	//왼쪽 위 모서리
	rcSelectPageVertex = RectMake(rcTypePage.left, rcTypePage.top, _drawerVertexSize, _drawerVertexSize);
	moveWindow();
	if (!PtInRect(&rcTypePage, _ptMouse) || !PtInRect(&rcSelectPage, _ptMouse))
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			for (int j = 0; j <= _vObjectPage[_objectPageIndex]->getMaxFrameY(); j++)
			{

				for (int i = 0; i <= _vObjectPage[_objectPageIndex]->getMaxFrameX(); i++)
				{
					if (i >= _clickDownStart2.x && i <= _clickDownEnd2.x &&
						j >= _clickDownStart2.y && j <= _clickDownEnd2.y)
					{
						if (_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2) >= 0 && _currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2) >= 0
							&& _currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2) < _pMapTool->getMapCountY() && _currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2) < _pMapTool->getMapCountX())
						{
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
								[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setObjimg(_vObjectPage2[_objectPageIndex]);
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
								[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setObjFrameX(i);
							_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
								[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setObjFrameY(j);
							
							//페이지별 지형 결정해주기.
							if (_objectPageIndex == 0)
							{
								//_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
								//	[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								//_pMapTool->setisWall(false);
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
									[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setObject(TILE::OBJECT::NOMAL_OBJECT);
								_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
									[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::PASS);
								if (i >= 0 && i <= 7 && j >= 0 && j <= 1)
								{
									//_pMapTool->setObject(TILE::OBJECT::NOMAL_OBJECT);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
										[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								}
								if (i >= 0 && i <= 7 && j >= 5 && j <= 6)
								{
									//_pMapTool->setObject(TILE::OBJECT::NOMAL_OBJECT);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
										[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								}
								if (i >= 8 && i <= 9 && j >= 3 && j <= 4)
								{
									//_pMapTool->setObject(TILE::OBJECT::NOMAL_OBJECT);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
										[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								}
								if (i >= 10 && i <= 11 && j >= 2 && j <= 3)
								{
									//_pMapTool->setObject(TILE::OBJECT::NOMAL_OBJECT);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
										[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								}
								if (i >= 3 && i <= 5 && j == 10)
								{
									//_pMapTool->setObject(TILE::OBJECT::NOMAL_OBJECT);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
										[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								}
								if (i == 1 && j >= 9 && j <= 10)
								{
									//_pMapTool->setObject(TILE::OBJECT::NOMAL_OBJECT);
									_pMapTool->getVvMap()[_currentIndex.y - (_clickDownStart2.y - j) - ceil(abs(static_cast<float>(_clickDownEnd2.y) - static_cast<float>(_clickDownStart2.y)) / 2)]
										[_currentIndex.x - (_clickDownStart2.x - i) - ceil(abs(static_cast<float>(_clickDownEnd2.x) - static_cast<float>(_clickDownStart2.x)) / 2)]->setTerrian(TILE::TERRIAN::WALL);
								}
							}
						}
					}
				}
			}
		}
	}

	//선택 알파 블랜드
	if (PtInRect(&rcMapPalletIce1, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int j = 0; j <= _vObjectPage[_objectPageIndex]->getMaxFrameY(); j++)
			{

				for (int i = 0; i <= _vObjectPage[_objectPageIndex]->getMaxFrameX(); i++)
				{
					if (_ptMouse.x >= rcMapPalletIce1.left + i * _vObjectPage[_objectPageIndex]->getFrameWidth() && _ptMouse.x <= rcMapPalletIce1.left + i * _vObjectPage[_objectPageIndex]->getFrameWidth() + _vObjectPage[_objectPageIndex]->getFrameWidth()
						&& _ptMouse.y >= rcMapPalletIce1.top + j * _vObjectPage[_objectPageIndex]->getFrameHeight() && _ptMouse.y <= rcMapPalletIce1.top + j * _vObjectPage[_objectPageIndex]->getFrameHeight() + _vObjectPage[_objectPageIndex]->getFrameHeight())
					{
						_clickDownStart2.x = i;
						_clickDownStart2.y = j;
					}
				}
			}
			_clickMap = true;
		}
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			for (int j = 0; j <= _vObjectPage[_objectPageIndex]->getMaxFrameY(); j++)
			{

				for (int i = 0; i <= _vObjectPage[_objectPageIndex]->getMaxFrameX(); i++)
				{
					if (_ptMouse.x >= rcMapPalletIce1.left + i * _vObjectPage[_objectPageIndex]->getFrameWidth() && _ptMouse.x <= rcMapPalletIce1.left + i * _vObjectPage[_objectPageIndex]->getFrameWidth() + _vObjectPage[_objectPageIndex]->getFrameWidth()
						&& _ptMouse.y >= rcMapPalletIce1.top + j * _vObjectPage[_objectPageIndex]->getFrameHeight() && _ptMouse.y <= rcMapPalletIce1.top + j * _vObjectPage[_objectPageIndex]->getFrameHeight() + _vObjectPage[_objectPageIndex]->getFrameHeight())
					{
						_clickDownEnd2.x = i;
						_clickDownEnd2.y = j;
					}
				}
			}
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_clickMap = false;
		}
	}
}

void MAPEDIT::renderMenu()
{
	imgRelicUITypePageBG->render(getMemDC(), rcTypePage.left, rcTypePage.top);
	for (int i = 0; i < 5; i++)
	{
		if (_ptInbtn[i] == true)
		{
			imgRelicUIDrawer->frameRender(getMemDC(), rcRelicUIDrawer[i].left, rcRelicUIDrawer[i].top);
		}
	}
	_btnWall->render(getMemDC(), _moveY[0]);
	_btnTerrain->render(getMemDC(), _moveY[1]);
	_btnObject->render(getMemDC(), _moveY[2]);
	_btnLoad->render(getMemDC(), _moveY[3]);
	_btnSave->render(getMemDC(), _moveY[4]);
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), rcTypePageVertex.left, rcTypePageVertex.top, rcTypePageVertex.right - rcTypePageVertex.left, rcTypePageVertex.bottom - rcTypePageVertex.top);

	}
}

void MAPEDIT::renderWall()
{
	imgRelicUISelectPageBG->render(getMemDC(), rcTypePage.left, rcTypePage.top);
	IMAGEMANAGER->findImage("Wall")->frameRender(getMemDC(), rcTypePage.left + 147, rcTypePage.top + 40, 0, 0);
	
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), rcSelectPageVertex.left, rcSelectPageVertex.top, rcSelectPageVertex.right - rcSelectPageVertex.left, rcSelectPageVertex.bottom - rcSelectPageVertex.top);
	}
}

void MAPEDIT::renderTerrain()
{
	imgRelicUISelectPageBG->render(getMemDC(), rcTypePage.left, rcTypePage.top);
	IMAGEMANAGER->findImage("Terrain")->frameRender(getMemDC(), rcTypePage.left + 147, rcTypePage.top + 40, 0, 0);
	//IMAGEMANAGER->findImage("MapPalletIce1")->render(getMemDC(), rcMapPalletIce1.left, rcMapPalletIce1.top);
	if (_clickMap == false)
	{
		_vTerrainPage[_terrainPageIndex]->render(getMemDC(), rcMapPalletIce1.left, rcMapPalletIce1.top);
	}
	//페이지 글꼴
	sprintf_s(_pageIndex, "%d/%d", _terrainPageIndex + 1, _vTerrainPage.size());
	HFONT font = CreateFont(30, 0, 0, 0, 1000, 0, 0, 0,
		DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Edwardian Script ITC"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(88, 76, 64));
	SetBkMode(getMemDC(), TRANSPARENT);
	TextOut(getMemDC(), rcTypePage.left + 400, rcTypePage.top + 40, _pageIndex, strlen(_pageIndex));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

	if (_clickMap == true)
	{
		for (int j = 0; j <= _vTerrainPage[_terrainPageIndex]->getMaxFrameY(); j++)
		{

			for (int i = 0; i <= _vTerrainPage[_terrainPageIndex]->getMaxFrameX(); i++)
			{
				if (i >= _clickDownStart.x && i <= _clickDownEnd.x &&
					j >= _clickDownStart.y && j <= _clickDownEnd.y)
				{
					_vTerrainPage[_terrainPageIndex]->alphaFrameRender(getMemDC(), rcMapPalletIce1.left + i * _vTerrainPage[_terrainPageIndex]->getFrameWidth(), rcMapPalletIce1.top + j * _vTerrainPage[_terrainPageIndex]->getFrameHeight(), i, j, 127);
				}
				else
				{
					_vTerrainPage[_terrainPageIndex]->alphaFrameRender(getMemDC(), rcMapPalletIce1.left + i * _vTerrainPage[_terrainPageIndex]->getFrameWidth(), rcMapPalletIce1.top + j * _vTerrainPage[_terrainPageIndex]->getFrameHeight(), i, j, 255);
				}
			}
		}
	}
	else
	{
		for (int j = 0; j <= _vTerrainPage[_terrainPageIndex]->getMaxFrameY(); j++)
		{
			for (int i = 0; i <= _vTerrainPage[_terrainPageIndex]->getMaxFrameX(); i++)
			{
				if (i >= _clickDownStart.x && i <= _clickDownEnd.x &&
					j >= _clickDownStart.y && j <= _clickDownEnd.y)
				{
					_vTerrainPage[_terrainPageIndex]->alphaFrameRender(getMemDC(),
						_ptMouse.x + (i - _clickDownStart.x) * _vTerrainPage[_terrainPageIndex]->getFrameWidth() - ((_clickDownEnd.x - _clickDownStart.x) * _vTerrainPage[_terrainPageIndex]->getFrameWidth() / 2 + (_vTerrainPage[_terrainPageIndex]->getFrameWidth() / 2)),
						_ptMouse.y + (j - _clickDownStart.y) * _vTerrainPage[_terrainPageIndex]->getFrameHeight() - ((_clickDownEnd.y - _clickDownStart.y) * _vTerrainPage[_terrainPageIndex]->getFrameHeight() / 2 + (_vTerrainPage[_terrainPageIndex]->getFrameHeight() / 2)),
						i, j, 127);
				}
			}
		}
	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), rcSelectPageVertex.left, rcSelectPageVertex.top, rcSelectPageVertex.right - rcSelectPageVertex.left, rcSelectPageVertex.bottom - rcSelectPageVertex.top);

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_terrainPageIndex >= _vTerrainPage.size() - 1)
		{
			_terrainPageIndex = _vTerrainPage.size() - 1;
		}
		else
		{
			_terrainPageIndex++;
		}
	} else if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_terrainPageIndex <= 0)
		{
			_terrainPageIndex = 0;
		}
		else
		{
			_terrainPageIndex--;
		}
	}
	
}

void MAPEDIT::renderObject()
{
	imgRelicUISelectPageBG->render(getMemDC(), rcTypePage.left, rcTypePage.top);
	IMAGEMANAGER->findImage("Object")->frameRender(getMemDC(), rcTypePage.left + 147, rcTypePage.top + 40, 0, 0);
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), rcSelectPageVertex.left, rcSelectPageVertex.top, rcSelectPageVertex.right - rcSelectPageVertex.left, rcSelectPageVertex.bottom - rcSelectPageVertex.top);
	}
	
	if (_clickMap == false)
	{
		_vObjectPage[_objectPageIndex]->render(getMemDC(), rcMapPalletIce1.left, rcMapPalletIce1.top);
	}
	//페이지 글꼴
	sprintf_s(_pageIndex, "%d/%d", _objectPageIndex + 1, _vObjectPage.size());
	HFONT font = CreateFont(30, 0, 0, 0, 1000, 0, 0, 0,
		DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Edwardian Script ITC"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(88, 76, 64));
	SetBkMode(getMemDC(), TRANSPARENT);
	TextOut(getMemDC(), rcTypePage.left + 400, rcTypePage.top + 40, _pageIndex, strlen(_pageIndex));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

	

	if (_clickMap == true)
	{
		for (int j = 0; j <= _vObjectPage[_objectPageIndex]->getMaxFrameY(); j++)
		{

			for (int i = 0; i <= _vObjectPage[_objectPageIndex]->getMaxFrameX(); i++)
			{
				if (i >= _clickDownStart2.x && i <= _clickDownEnd2.x &&
					j >= _clickDownStart2.y && j <= _clickDownEnd2.y)
				{
					_vObjectPage[_objectPageIndex]->alphaFrameRender(getMemDC(), rcMapPalletIce1.left + i * _vObjectPage[_objectPageIndex]->getFrameWidth(), rcMapPalletIce1.top + j * _vObjectPage[_objectPageIndex]->getFrameHeight(), i, j, 127);
				}
				else
				{
					_vObjectPage[_objectPageIndex]->alphaFrameRender(getMemDC(), rcMapPalletIce1.left + i * _vObjectPage[_objectPageIndex]->getFrameWidth(), rcMapPalletIce1.top + j * _vObjectPage[_objectPageIndex]->getFrameHeight(), i, j, 255);
				}
			}
		}
	}
	else
	{
		for (int j = 0; j <= _vObjectPage[_objectPageIndex]->getMaxFrameY(); j++)
		{

			for (int i = 0; i <= _vObjectPage[_objectPageIndex]->getMaxFrameX(); i++)
			{
				if (i >= _clickDownStart2.x && i <= _clickDownEnd2.x &&
					j >= _clickDownStart2.y && j <= _clickDownEnd2.y)
				{
					_vObjectPage[_objectPageIndex]->alphaFrameRender(getMemDC(),
						_ptMouse.x + (i - _clickDownStart2.x) * _vObjectPage[_objectPageIndex]->getFrameWidth() - ((_clickDownEnd2.x - _clickDownStart2.x) * _vObjectPage[_objectPageIndex]->getFrameWidth() / 2 + (_vObjectPage[_objectPageIndex]->getFrameWidth() / 2)),
						_ptMouse.y + (j - _clickDownStart2.y) * _vObjectPage[_objectPageIndex]->getFrameHeight() - ((_clickDownEnd2.y - _clickDownStart2.y) * _vObjectPage[_objectPageIndex]->getFrameHeight() / 2 + (_vObjectPage[_objectPageIndex]->getFrameHeight() / 2)),
						i, j, 127);
				}
			}
		}
	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), rcSelectPageVertex.left, rcSelectPageVertex.top, rcSelectPageVertex.right - rcSelectPageVertex.left, rcSelectPageVertex.bottom - rcSelectPageVertex.top);

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_objectPageIndex >= _vObjectPage.size() - 1)
		{
			_objectPageIndex = _vObjectPage.size() - 1;
		}
		else
		{
			_objectPageIndex++;
		}
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_objectPageIndex <= 0)
		{
			_objectPageIndex = 0;
		}
		else
		{
			_objectPageIndex--;
		}
	}
}

void MAPEDIT::moveWindow()
{
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		//창 무브
		if (PtInRect(&rcTypePageVertex, _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				_clickVertex = true;
			}
		}
	}
	else
	{
		if (PtInRect(&rcSelectPageVertex, _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				_clickVertex = true;
			}
		}
	}
	
	if (_clickVertex == true)
	{
		rcSelectPage.left = _ptMouse.x - _drawerVertexSize / 2;
		rcSelectPage.top = _ptMouse.y - _drawerVertexSize / 2;
		rcSelectPage.right = rcSelectPage.left + imgRelicUISelectPageBG->GetWidth();
		rcSelectPage.bottom = rcSelectPage.top + imgRelicUISelectPageBG->GetHeight();
		rcTypePage.left = _ptMouse.x - _drawerVertexSize / 2;
		rcTypePage.top = _ptMouse.y - _drawerVertexSize / 2;
		rcTypePage.right = rcTypePage.left + imgRelicUITypePageBG->GetWidth();
		rcTypePage.bottom = rcTypePage.top + imgRelicUITypePageBG->GetHeight();
		for (int i = 0; i < 5; i++)
		{
			rcRelicUIDrawer[i] = RectMake(53 + rcTypePage.left, rcTypePage.top + 61 + 96 * i, 470, 88);
			rcBtnTitle[i] = RectMake(53 + rcTypePage.left, 61 + 96 * i, IMAGEMANAGER->findImage("Wall")->getFrameWidth(), IMAGEMANAGER->findImage("Wall")->getFrameHeight());
			rcMapPalletIce1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
			rcMapPalletEarth1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
			rcMapPalletFire1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
			rcMapPalletCastle1 = RectMake(rcSelectPage.left + 53, rcSelectPage.top + 125, 768, 768);
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_clickVertex = false;
		}
	}
}