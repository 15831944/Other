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
	CHVKVector	m_pFenceVect;		//������ ����������

	double m_Length, m_Width, m_Height;
	double m_V;						//����� ���������

	double m_TwzW, m_TwzS;			//����������� ������� ����
	double m_TprW, m_TprS;			//����������� �������
	double m_ThzW, m_ThzS;			//����������� ������� ����
	double m_TdW, m_TdS;			//����������� �����������

	double m_VlwzW, m_VlwzS;		//��������� ������� ����
	double m_VlprW, m_VlprS;		//��������� �������
	double m_VlhzW, m_VlhzS;		//��������� ������� ����
	double m_VldW, m_VldS;			//��������� �����������

	double m_LOutMechLoc;			//�������� ������ ������� ���. ����
	double m_LOutMechGlob;			//�������� ������ ���������. ���. ����
	double m_LOutTech;				//�������� ������ ����������. ����
	double m_LOutReal;				//�������� ������ ������������ ����
	double m_LOutSum;				//�������� ������ ���������
	CDustGasExcretion m_Excretion;	//�����������������
	double m_LOutExcr;				//���������� ������� �� ����������
	double m_LInMechLoc;			//��������� ������ ������� ���. ����
	double m_LInMechGlob;			//��������� ������ ���������. ���. ����
	double m_LInTech;				//��������� ������ ����������. ����
	double m_LInReal;				//��������� ������ ������������ ����
	double m_LInSum;				//��������� ������ ���������

	double m_k;						//��������� �������������

	double m_QInTech;				//���������������� �� ���������������� ������������
	double m_QInMath;				//���������������� �� ���������� ����������
	double m_QInSunRadS;			//���������������� �� ��������� ��������
	double m_QInSumW;				//���������������� ���������
	double m_QInSumS;				//���������������� ���������

//������ ������ �� ���� ��� ����������� �����������,
//���� � �������� ����������� ������� �� � ��� ����... ���� ��������
	double m_QOutFenceW;			//����������� ����� ���������� � �������������
	double m_QOutMathW;				//����������� �� ������ ���������� � ����������
	double m_QOutAirHzW;			//����������� � �������� �������� �� ������� ����
	double m_QOutAirHzS;			//����������� � �������� �������� �� ������� ����
	double m_QOutAirTechW;			//����������� � �������� �� ����������
	double m_QOutAirTechS;			//����������� � �������� �� ����������
	double m_QOutAirLocW;			//����������� � �������� ��������
	double m_QOutAirLocS;			//����������� � �������� ��������
	double m_QOutSumW;				//����������� ���������
	double m_QOutSumS;				//����������� ���������

	double m_QOutFence5W;			//����������� ����� ���������� � �������������

	double m_dQW;					//������������/���������������(-)
	double m_dQS;					//������������/���������������(-)

	double m_dqW;					//������������������
	double m_dqS;					//������������������

	double m_LdQW;					//���������� ������� �� ���������������
	double m_LdQS;					//���������� ������� �� ���������������

	double m_QLInW;					//����� ����������� ��������� �����������	
	double m_QInHeatingW;			//����� ����������� �������� ���������
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

	double CalcSumFenceHeatLoss();		//��������� ��������� ������ �� �����������
	double CalcV();						//��������� �����
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
