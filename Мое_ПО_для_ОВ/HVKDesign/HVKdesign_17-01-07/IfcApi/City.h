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
	double m_MinTempHeatingSeason;		// мин. темп. отоп. периода
	double m_MiddleTempHeatingSeason;	// средн€€ темп. отоп. периода
	double m_MiddleTempCoolMounth;		// средн€€ темп. наиб. хол. мес€ца	
	double m_TempHeatSeason;			// темп. лета
	int	   m_HeatingSeasonLen;			// продолжительность отоп. периода
	double m_WindSpeed;					// скорость ветра			
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
