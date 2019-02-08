#include "stdafx.h"
#include "mapEdit.h"
void MAPEDIT::callBackMapWall()
{
	printf_s("Wall버튼을 눌렀네요\n");
}

void MAPEDIT::callBackMapTerrain()
{
	printf_s("Terrain버튼을 눌렀네요\n");
}

void MAPEDIT::callBackMapObject()
{
	printf_s("Object버튼을 눌렀네요\n");
}

void MAPEDIT::callBackMapSave()
{
	printf_s("Save버튼을 눌렀네요\n");
}

void MAPEDIT::callBackMapLoad()
{
	printf_s("Load버튼을 눌렀네요\n");
}

MAPEDIT::MAPEDIT()
{
}

MAPEDIT::~MAPEDIT()
{
}

HRESULT MAPEDIT::init()
{
	RelicUITypePageBG = IMAGEMANAGER->addImage("RelicUITypePageBG", "resource/UI/RelicUITypePageBG.bmp", 576, 600, true, RGB(255, 0, 255));
	RelicUIDrawer = IMAGEMANAGER->addFrameImage("RelicUIDrawer", "resource/UI/RelicUIDrawer.bmp", 469, 520, 1, 5, true, RGB(255, 0, 255));
	RelicUIBG = IMAGEMANAGER->addImage("UIBackGround", "resource/UI/RelicUIBG.bmp", 600, 900, true, RGB(255, 0, 255));
	RelicUIBG2 = IMAGEMANAGER->addImage("UIBackGround2", "resource/UI/RelicUIBG2.bmp", 600, 900, true, RGB(255, 0, 255)); 
	IMAGEMANAGER->addFrameImage("Wall", "resource/UI/WallUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Terrain", "resource/UI/TerrainUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Object", "resource/UI/ObjectUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Save", "resource/UI/SaveUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Load", "resource/UI/LoadUItitle.bmp", 213, 192, 1, 3, true, RGB(255, 0, 255));
	rcTypePage = RectMake(1015, 277, RelicUITypePageBG->GetWidth(), RelicUITypePageBG->GetHeight());

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
	_drawerVertexSize = 20;
	_mapEditstate = MAPEDITSTATE::MAPEDITMENU;

	return S_OK;
}

void MAPEDIT::update()
{
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		updateMenu();
	}
}

void MAPEDIT::release()
{
	//_pMapTool->release();
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		_btnWall->release();
		_btnTerrain->release();
		_btnObject->release();
		_btnLoad->release();
		_btnSave->release();
	}
}

void MAPEDIT::render()
{
	RelicUIBG->render(getMemDC(), 1000, 0);
	if (_mapEditstate == MAPEDITSTATE::MAPEDITMENU)
	{
		renderMenu();
	}
	for (int i = 0; i < 4; i++)
	{
		RectangleMake(getMemDC(), rcTypePageVertex[i].left, rcTypePageVertex[i].top, rcTypePageVertex[i].right - rcTypePageVertex[i].left, rcTypePageVertex[i].bottom - rcTypePageVertex[i].top);
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
	rcTypePageVertex[0] = RectMake(rcTypePage.left, rcTypePage.top, _drawerVertexSize, _drawerVertexSize);
	//오른쪽 위 모서리
	rcTypePageVertex[1] = RectMake(rcTypePage.right - _drawerVertexSize, rcTypePage.top, _drawerVertexSize, _drawerVertexSize);
	//오른쪽 아래 모서리
	rcTypePageVertex[2] = RectMake(rcTypePage.right - _drawerVertexSize, rcTypePage.bottom - _drawerVertexSize, _drawerVertexSize, _drawerVertexSize);
	//왼쪽 아래 모서리
	rcTypePageVertex[3] = RectMake(rcTypePage.left, rcTypePage.bottom - _drawerVertexSize, _drawerVertexSize, _drawerVertexSize);

	//창 무브
	for (int i = 0; i < 4; i++)
	{
		if(PtInRect(&rcTypePageVertex[i], _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				_clickVertex = true;
			}
		}
	}
	if (_clickVertex == true)
	{
		rcTypePage.left = _ptMouse.x - 10;
		rcTypePage.top = _ptMouse.y - 10;
		rcTypePage.right = rcTypePage.left + RelicUITypePageBG->GetWidth();
		rcTypePage.bottom = rcTypePage.top + RelicUITypePageBG->GetHeight();
		for (int i = 0; i < 5; i++)
		{
			rcRelicUIDrawer[i] = RectMake(53 + rcTypePage.left, rcTypePage.top + 61 + 96 * i, 470, 88);
			rcBtnTitle[i] = RectMake(53 + rcTypePage.left, 61 + 96 * i, IMAGEMANAGER->findImage("Wall")->getFrameWidth(), IMAGEMANAGER->findImage("Wall")->getFrameHeight());
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_clickVertex = false;
		}
	}

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
				RelicUIDrawer->SetFrameY(_index);
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
				if (_index >= RelicUIDrawer->getMaxFrameY())
				{
					_index = RelicUIDrawer->getMaxFrameY();
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
			RelicUIDrawer->SetFrameX(0);
			RelicUIDrawer->SetFrameY(0);
			_index = 0;
		}
	}

	//1. 다른메뉴창 선택시 index를 0으로
	if (_ptInbtn[0] == _ptInbtn[1] == _ptInbtn[2] == _ptInbtn[3] == _ptInbtn[4] == false)
	{
		RelicUIDrawer->SetFrameX(0);
		RelicUIDrawer->SetFrameY(0);
		_index = 0;
	}
	_count++;
}

void MAPEDIT::updateWall()
{
}

void MAPEDIT::updateTerrain()
{
}

void MAPEDIT::updateObject()
{
}

void MAPEDIT::renderMenu()
{
	RelicUITypePageBG->render(getMemDC(), rcTypePage.left, rcTypePage.top);
	for (int i = 0; i < 5; i++)
	{
		if (_ptInbtn[i] == true)
		{
			RelicUIDrawer->frameRender(getMemDC(), rcRelicUIDrawer[i].left, rcRelicUIDrawer[i].top);
		}
	}
	_btnWall->render(getMemDC(), _moveY[0]);
	_btnTerrain->render(getMemDC(), _moveY[1]);
	_btnObject->render(getMemDC(), _moveY[2]);
	_btnSave->render(getMemDC(), _moveY[3]);
	_btnLoad->render(getMemDC(), _moveY[4]);
}

void MAPEDIT::renderWall()
{
}

void MAPEDIT::renderTerrain()
{
}

void MAPEDIT::renderObject()
{
}
