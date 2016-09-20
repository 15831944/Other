// City.h: interface for the CCity class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CITY_H__
#define _CITY_H__

#include "HVKDbObject.h"
#include "HVkApi.h"

class CCity : public CHVKDbObject  
{
protected:
public:
	double m_MinTempHeatingSeason;		// ���. ����. ����. �������
	double m_MiddleTempHeatingSeason;	// ������� ����. ����. �������
	double m_MiddleTempCoolMounth;		// ������� ����. ����. ���. ������	
	double m_TempHeatSeason;			// ����. ����
	int	   m_HeatingSeasonLen;			// ����������������� ����. �������
	double m_WindSpeed;					// �������� �����			
public:
	virtual int Init();
	CCity();
	virtual ~CCity();
	double GetMinTempHeatingSeason   ();	
	double GetMiddleTempHeatingSeason();
	double GetMiddleTempCoolMounth   ();
	int	  GetHeatingSeasonLen       ();	
	double GetWindSpeed              ();

	void SetMinTempHeatingSeason   (double value);
	void SetMiddleTempHeatingSeason(double value);
	void SetMiddleTempCoolMounth   (double value);	
	void SetHeatingSeasonLen       (int  value);
	void SetWindSpeed              (double value);
	int const& operator==(CCity const& op2);
};

#endif // ndef _CITY_H__
