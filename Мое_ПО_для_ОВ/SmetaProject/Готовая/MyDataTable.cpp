// MyDataTable.cpp: implementation of the CMyDataTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SmetaProject.h"
#include "MyDataTable.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CMyDataTable::~CMyDataTable()
{
	Delete();
}

void CMyDataTable::Delete()
{
	Clear();
	delete tmpRazdel;
	tmpRazdel = NULL;
}

void CMyDataTable::Clear()
{
	for(int i =0; i<List.size(); i++)
		delete List[i];
	List.clear();
}

void CMyDataTable::Prepare()
{
	Grid.SetColWidth(0,3000);
	Grid.SetColWidth(1,3000);
	Grid.SetTextMatrix(0,0,"Наименование работ");
	Grid.SetTextMatrix(0,1,"Аналог");
	Grid.Refresh();
}

void CMyDataTable::Update()
{
//работа с отображением данных в таблице
	Grid.Clear();
	Prepare();
	int GridSize;
	GridSize = List.size()+2;
	if(GridSize < gridsize) Grid.SetRows(gridsize);
	else Grid.SetRows(GridSize);
	for(int i = 0; i<List.size(); i++)
	{	
		Grid.SetTextMatrix(i+1, 0, List[i]->GetName());
		Grid.SetTextMatrix(i+1, 1, List[i]->GetAnalog().GetName());
	}
	Grid.Refresh();
}

int CMyDataTable::Add(CRazdelZdanie* Razdel)
{
    /*
	int SelectionRow;
	SelectionRow = Grid.GetRow();
	if(SelectionRow > List.size()+1) return 0;
//вставка в список
    if(List.begin())
		List.insert(&List[SelectionRow-1],Razdel);
	else 
		List.push_back(Razdel);
	//обновить содержимое
	Update();*/
	return 1;
}
int CMyDataTable::Replace(CRazdelZdanie* Razdel)  //замена в таблице
{
	int SelectionRow;
	SelectionRow = Grid.GetRow()-1;
	//замена в списке
	List[SelectionRow] = Razdel;
	//обновить содержимое
	Update();
	return 1;
}

CRazdelZdanie* CMyDataTable::Remove() //удаление в таблице
{
	int SelectionItemIndex = 0;
	SelectionItemIndex = Grid.GetRow()-1;
	if(SelectionItemIndex >= List.size()) 
		return NULL;
	CRazdelZdanie* r;
	//удаление в списке
	r = new CRazdelZdanie(*List[SelectionItemIndex]);
	//List.erase(&List[SelectionItemIndex]);
	//обновить содержимое
	Update();
	return r;
}

int CMyDataTable::Cut() //вырезать в таблице
{
	tmpRazdel = Remove();
	//обновить содержимое
	Update();
	return 1;
}

int CMyDataTable::Copy() //копировать в таблице
{
	int SelectionItemIndex;
	SelectionItemIndex = Grid.GetRow()-1;
	if(SelectionItemIndex >= List.size())
	{	tmpRazdel = NULL;
		return 0;
	}
	if(List[SelectionItemIndex])
		tmpRazdel = List[SelectionItemIndex]->Duplicate();
	return 1;
}

int CMyDataTable::Paste() //вырезать в таблице
{
	if(tmpRazdel) 
		if(Add(tmpRazdel)) tmpRazdel = NULL;
	//обновить содержимое
	Update();
	return 1;
}
