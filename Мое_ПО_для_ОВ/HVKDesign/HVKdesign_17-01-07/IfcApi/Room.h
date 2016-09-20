// Room.h: interface for the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ROOM_H__
#define _ROOM_H__

#include "HVKDbObject.h"
#include "HVkApi.h"
#include "Floor.h"
#include "DustGasExcretion.h"

#include "CalcHeatBalance.h"

class CDustGasExcretion;
class CRoom:public CHVKDbObject 
{
public:
	CFloor* m_pFlr;
	CHVKVector	m_pFenceVect;		//список ограждений

	double m_Length, m_Width, m_Height;
	double m_V;						//объем помещения

	double m_TwzW, m_TwzS;			//температура рабочей зоны
	double m_TprW, m_TprS;			//температура притока
	double m_ThzW, m_ThzS;			//температура верхней зоны
	double m_TdW, m_TdS;			//температура душирования

	double m_VlwzW, m_VlwzS;		//влажность рабочей зоны
	double m_VlprW, m_VlprS;		//влажность притока
	double m_VlhzW, m_VlhzS;		//влажность верхней зоны
	double m_VldW, m_VldS;			//влажность душирования

	double m_LOutMechLoc;			//вытяжной воздух местной мех. вент
	double m_LOutMechGlob;			//вытяжной воздух общеобмен. мех. вент
	double m_LOutTech;				//вытяжной воздух технологич. вент
	double m_LOutReal;				//вытяжной воздух естественной вент
	double m_LOutSum;				//вытяжной воздух суммарный
	CDustGasExcretion m_Excretion;	//пылегазовыделения
	double m_LOutExcr;				//количество воздуха по вредностям
	double m_LInMechLoc;			//приточный воздух местной мех. вент
	double m_LInMechGlob;			//приточный воздух общеобмен. мех. вент
	double m_LInTech;				//приточный воздух технологич. вент
	double m_LInReal;				//приточный воздух естественной вент
	double m_LInSum;				//приточный воздух суммарный

	double m_k;						//кратность воздухообмена

	double m_QInTech;				//теплопоступления от технологического оборудования
	double m_QInMath;				//теплопоступления от остывающих материалов
	double m_QInSunRadS;			//теплопоступления от солнечной радиации
	double m_QInSumW;				//теплопоступления суммарные
	double m_QInSumS;				//теплопоступления суммарные

//сейчас исхожу из того что теплопотери толькозимой,
//хоть и заложила возможность считать их и для лета... надо подумать
	double m_QOutFenceW;			//теплопотери через ограждения с инфильтрацией
	double m_QOutMathW;				//теплопотери на нагрев материалов и транспорта
	double m_QOutAirHzW;			//теплопотери с уходящим воздухом из верхней зоны
	double m_QOutAirHzS;			//теплопотери с уходящим воздухом из верхней зоны
	double m_QOutAirTechW;			//теплопотери с воздухом на технологию
	double m_QOutAirTechS;			//теплопотери с воздухом на технологию
	double m_QOutAirLocW;			//теплопотери с местными отсосами
	double m_QOutAirLocS;			//теплопотери с местными отсосами
	double m_QOutSumW;				//теплопотери суммарные
	double m_QOutSumS;				//теплопотери суммарные

	double m_QOutFence5W;			//теплопотери через ограждения с инфильтрацией

	double m_dQW;					//теплоизбытки/теплонедостатки(-)
	double m_dQS;					//теплоизбытки/теплонедостатки(-)

	double m_dqW;					//теплонапряженность
	double m_dqS;					//теплонапряженность

	double m_LdQW;					//количество воздуха по тепловыделениям
	double m_LdQS;					//количество воздуха по тепловыделениям

	double m_QLInW;					//тепло возмещаемое приточной вентиляцией	
	double m_QInHeatingW;			//тепло возмещаемое системой отопления
private:

public:
	CRoom* Copy(CRoom const& op2);
	virtual CHVKDbObject* Clone();
	int Distruct();

	CRoom(CFloor* pFlr = NULL);
	CRoom(CRoom const& op2);
	virtual ~CRoom();

	CRoom const& operator=(CRoom const &op2);
	int const& operator==(CRoom const& op2);
	int const& operator!=(CRoom const& op2);
	virtual int const& CmpObj(CHVKDbObject* op2);

	virtual int Open(_ConnectionPtr  ptrCon = NULL);
	virtual int Init();
	virtual int Save(int IsNew = FALSE);
	virtual CHVKDbObject* New();
	virtual int Delete();
	virtual int DeleteEx();

	int ShowInFrmView(CIfcFormView* FrmView);
	int HideInFrmView(CIfcFormView* FrmView);
	virtual int ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent = TVI_ROOT);
//	virtual int UpdateCalcData(CHVKCalcObject* pclcObj){return TRUE};

	double CalcSumFenceHeatLoss();		//посчитать суммарные потери по ограждениям
	double CalcV();						//посчитать объем
	double CalcLOutReal();
	double CalcLInReal();
	double CalcLOutSum();
	double CalcLInSum();
	double CalcK();
	double CalcQInSumW();
	double CalcQInSumS();
	double CalcQOutSum();
	double CalcdQW();
	double CalcdQS();
	double CalcdqW();
	double CalcdqS();
	double CalcLdQW();
	double CalcLdQS();
	double CalcQLInW();
	double CalcQInHeatingW();

	double CalcQOutAirHzW();
	double CalcQOutAirHzS();
	double CalcQOutAirTechW();
	double CalcQOutAirTechS();
	double CalcQOutAirLocW();
	double CalcQOutAirLocS();

	int CalcHeatBalance(){;};
};

#endif // ndef _ROOM_H__
