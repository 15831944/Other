// MyDataTable.h: interface for the CMyDataTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYDATATABLE_H__E1E9B74E_5839_4991_8D14_D59A0272F300__INCLUDED_)
#define AFX_MYDATATABLE_H__E1E9B74E_5839_4991_8D14_D59A0272F300__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "msflexgrid.h"
#include "RazdelZdanie.h"

#include <vector>
using namespace std;

class CMyDataTable  
{
private:
	int gridsize; 
	CRazdelZdanie* tmpRazdel;		//для вырезать/вставить
	void Delete();
public:
	CMSFlexGrid Grid;
	vector <CRazdelZdanie*> List;	//список разделов сметы по зданию
	CMyDataTable():gridsize(20), tmpRazdel(NULL){}
	~CMyDataTable();
	void Clear();
	void Prepare();
	void Update();
	int Add(CRazdelZdanie* Razdel);	//добавление в таблицу
	int Replace(CRazdelZdanie* Razdel);  //замена в таблице
	CRazdelZdanie* Remove(); //удаление в таблице
	int Cut(); //вырезать в таблице
	int Copy(); //копировать в таблице
	int Paste(); //вставить в таблице

};

#endif // !defined(AFX_MYDATATABLE_H__E1E9B74E_5839_4991_8D14_D59A0272F300__INCLUDED_)
