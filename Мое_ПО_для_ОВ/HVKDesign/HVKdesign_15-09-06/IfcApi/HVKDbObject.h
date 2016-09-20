// HVKDbObject.h: interface for the CHVKDbObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _HVKDBOBJECT_H__
#define _HVKDBOBJECT_H__

//#include "Commctrl.h"
#include "HVKApi.h"
#include "../ComApi/ADORecord.h"

//#include <afxcmn.h>


/* Вообще сейчас гружу свойства объекта в Init, сразу после конструктора*/
/* может в ближайшее будущее перенсу даже в конструктор                 */
/* А вообще надо хранить только id и брать значение прямо из таблицы в  */
/* методах Set.. и Get.., правда может предется хранить название таблицы*/
/* но это надо еще продумать                                            */
class CIfcTreeView;
class CIfcFormView;
class CADORecord;
class CHVKCalcObject;

class HVKAPI CHVKDbObject  
{
//protected:
public:
	int   m_ID;
	char* m_Name;
	char* m_NameWindow;
	char  m_DbName[256];
public:
	static 	CADORecord* m_ptrAdoRc;
	int CreateOpenStrID(char* str);
	int CreateOpenStrName(char* str);
	int CreateDeleteStrID(char* str);
	int CreateDeleteStrName(char* str);

	CHVKDbObject* Copy(CHVKDbObject const& op2);
	int Distruct();
	virtual CHVKDbObject* Clone();

	CHVKDbObject();
	CHVKDbObject(CHVKDbObject const& op2);
	virtual ~CHVKDbObject();

	CHVKDbObject const& operator=(CHVKDbObject const &op2);
	int const& operator==(CHVKDbObject const& op2);
	int const& operator!=(CHVKDbObject const& op2);
	virtual int const& CmpObj(CHVKDbObject* op2);

	virtual int Init();
	int InitByID();
	int InitByName();
	int GetID(){return m_ID;};
	char* GetName(){return m_Name;};
	void SetID(int ID){m_ID = ID;};
	void SetName(char* Name){strcpy(m_Name, Name);};
	virtual int ShowInFrmView(CIfcFormView* FrmView)/*=0*/{return 1;};
	virtual int HideInFrmView(CIfcFormView* FrmView)/*=0*/{return 1;};
	virtual int ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM Parent = TVI_ROOT);
	virtual int UpdateCalcData(CHVKCalcObject* pclcObj){return TRUE;};
	virtual int Save(int IsNew = FALSE);
	virtual CHVKDbObject* New();
	virtual int Delete();
	virtual int DeleteEx();
	virtual int CreateNew(){return TRUE;};
	int SetID();
	int const& IdCmp(CHVKDbObject const& op2);
};

#endif // ndef _HVKDBOBJECT_H__
