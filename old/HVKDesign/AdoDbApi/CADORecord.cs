using System;
using System.Collections.Generic;
using System.Text;
using ADODB;

namespace AdoDbApi
{
    public class CADORecord
    {
        Recordset m_ptrRecordset;
	    enum MaxNum{MaxNumBaseFld = 8};

        public enum Types{Integer, Double, String};
	    Connection m_ptrConnection;
	    string m_pstrSource;

	    //CADORecord(_ConnectionPtr pConn = NULL);
	    //virtual ~CADORecord();

    	//CADORecord* Copy(CADORecord const& op2);
	    //CADORecord operator=(CADORecord const &op2);
	
	    public bool Open(string strSource)
        {
            m_pstrSource = strSource;
            //try{
            m_ptrRecordset.Open(strSource, 
                m_ptrConnection.ConnectionString,
        //			L"Provider=sqloledb;Data Source=;Integrated Security='SSPI';Initial Catalog=Equipment;User Id=;Password=;",

	            CursorTypeEnum.adOpenDynamic,LockTypeEnum.adLockOptimistic, 1);
            //}
            //catch(_com_error &e)
            //{
            //    GenerateError(e.Error(), e.Description());//, m_pstrSource);
            //    return FALSE;
            //}
            return true;
        }
        public bool GetData(int NumFld, Types Type, Object Data) { return true; }
        public bool GetData(string NameFld, Types Type, Object Data) { return true; }
        bool New() { return true; }
	    bool Update(){return true;}
	    void DeleteCurrentRecord(string strSource){;}
	    bool OpenConnection(){return true;}

        //void GenerateError(HRESULT hr, PWSTR pwszDescription, string ExtInfo)
        //{
        //    string strError;
        //    switch (hr)
        //    {
        //      case -2146824556:
        //         sprintf(strError, "������ �� ����� ��������� ��������\n�������������� ����������(%s)", ExtInfo.c_str());
        //        break;
        //      case -2146825023:
        //        sprintf(strError, "������ � ��������� ���� ������\n������� ���� �� ����������\n�������������� ����������(%s)", ExtInfo.c_str());
        //        break;
        //      case -2146825267:
        //        sprintf(strError, "������ �� �������\n�������������� ����������(%s)", ExtInfo.c_str());
        //        break;
        //      case -2147217843:
        //        sprintf(strError, "�������� ��� ������������ � ������\n���������� ����� �������\n�������������� ����������(%s)", ExtInfo.c_str());
        //        break;
        //      case -2147217873:
        //        sprintf(strError, "�������� �� ���������\n������ ������� ������ �� ������� ���� ������ � ������ �������\n�������������� ����������(%s)", ExtInfo.c_str());
        //        break;
        //      case -2147217911:
        //        sprintf(strError, "� ��� ��� ���� �� ���������� ���� ��������\n�������������� ����������(%s)", ExtInfo.c_str());
        //        break;
        //      default:
        //        //������������� � ������� ��������� �� ������
        //        sprintf(strError, "������ ������� ���������� '%d(%x)'\n\n%s",
        //            hr, hr, pwszDescription);
        //    }
        //    MessageBox(NULL, strError, "������ ������� ����������", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);
        //}
        //ConnectionPtr OpenConnection()
        //{
        //  ConnectionPtr m_ptrConn;
        //  try
        //  { m_ptrConn.CreateInstance(__uuidof(Connection));
        //    //��� SQL
        //    //m_ptrConn->CursorLocation=adUseServer;
        //    //���������� ����� udl ����
        //    m_ptrConn->ConnectionString = "File Name=HVKDesign.udl";
        //    m_ptrConn->Open("", "", "", -1);
        //  }catch(com_error e)
        //  { GenerateError(e.Error(), e.Description(), string(m_ptrConn->ConnectionString));
        //    return NULL;
        //  }
        //  return m_ptrConn;
        //}

        public void Close()
        {
            this.Close();
        }
    }
}
