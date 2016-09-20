using System;
using System.Collections.Generic;
using System.Text;
using AdoDbApi;

namespace HVKApi
{
    public class CHVKDbObject
    {
	    string m_NameWindow;
	    int    m_ID;
	    string m_Name;
	    string m_DbName;
        CADORecord m_ptrAdoRc;

        string OpenStrID()
        {
            return string.Format("select * from {1} where id={2}", m_DbName, m_ID);
        }
	      string OpenStrName()
        {
        	return string.Format("select * from {1} where Name=\"{2}\"", m_DbName, m_Name);
        }
	      string DeleteStrID()
        {
            return string.Format("delete * from {1} where id={2}", m_DbName, m_ID);
        }
	      string DeleteStrName()
        {
            return string.Format("delete* from {1} where Name=\"{2}\"", m_DbName, m_Name);

        }

	      CHVKDbObject Copy(CHVKDbObject op2){return null;}
        //int Distruct();
        //virtual CHVKDbObject* Clone();

        //CHVKDbObject();
        //CHVKDbObject(CHVKDbObject const& op2);
        //virtual ~CHVKDbObject();

        //CHVKDbObject const& operator=(CHVKDbObject const &op2);
        //int const& operator==(CHVKDbObject const& op2);
        //int const& operator!=(CHVKDbObject const& op2);
        //virtual int const& CmpObj(CHVKDbObject* op2);

	    bool GetData()
        {	bool stat = true;
            stat = m_ptrAdoRc.GetData("ID", ref m_ID);
	        if(stat)
                stat = m_ptrAdoRc.GetData("Name", ref m_Name);
	        return stat;
        }

//	    int Init();

        bool InitByID()
        {
	        bool stat = true;
            //try{
                string str = OpenStrID();
        //		CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
        //		CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		        if(!m_ptrAdoRc.Open(str)) return false;
		        stat = GetData();
		        m_ptrAdoRc.Close();
        //		delete CHVKDbObject::m_ptrAdoRc;
        //		CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
		        return stat;
            //}
            //catch(_com_error e)
            //{
            //    GenerateError(e.Error(), e.Description());
            //    return FALSE;
            //}
        }

        //private void GenerateError(object p, object p_2)
        //{
        //    throw new Exception("The method or operation is not implemented.");
        //}
/*
        bool InitByName()
        { 
	        string str; //переменная для комманд
	        bool stat;
	        str = CreateOpenStrName();

            CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	        if(CHVKDbObject::m_ptrAdoRc->Open(str))
	        {	stat = GetData();
		        (*CHVKDbObject::m_ptrAdoRc)->Close();
	        }else stat = FALSE;
        //	delete CHVKDbObject::m_ptrAdoRc;
	        CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
	        return stat;
        }*/
/*	    int GetID(){return m_ID;};
	    char* GetName(){return m_Name;};
	    void SetID(int ID){m_ID = ID;};
	    void SetName(char* Name){strcpy(m_Name, Name);};
	    virtual int UpdateCalcData(CHVKCalcObject* pclcObj){return TRUE;};
	    virtual int Save(int IsNew = FALSE);
	    virtual int Update(){return TRUE;};
	    virtual CHVKDbObject* New();
	    virtual int Delete();
	    virtual int DeleteEx();
	    virtual int CreateNew(){return TRUE;};
	    virtual void* ChangeParent(void* pParent){return NULL;};
	    int SetID();
	    int const& IdCmp(CHVKDbObject const& op2);
	    void Clear();
	    void SaveCurADORecord();
	    void RestorePrevADORecord();
*/
      void ProcRecordset()
      { ;}
    }
}
