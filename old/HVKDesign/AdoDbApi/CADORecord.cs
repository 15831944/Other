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
        //         sprintf(strError, "Сервер не может завершить операцию\nДополнительная информация(%s)", ExtInfo.c_str());
        //        break;
        //      case -2146825023:
        //        sprintf(strError, "Ошибка в структуре базы данных\nНужного поля не существует\nДополнительная информация(%s)", ExtInfo.c_str());
        //        break;
        //      case -2146825267:
        //        sprintf(strError, "Запись не найдена\nДополнительная информация(%s)", ExtInfo.c_str());
        //        break;
        //      case -2147217843:
        //        sprintf(strError, "Неверное имя пользователя и пароль\nПриложение будет закрыто\nДополнительная информация(%s)", ExtInfo.c_str());
        //        break;
        //      case -2147217873:
        //        sprintf(strError, "Операция не выполнена\nНельзя удалить запись на которую есть ссылка в другой таблице\nДополнительная информация(%s)", ExtInfo.c_str());
        //        break;
        //      case -2147217911:
        //        sprintf(strError, "У Вас нет прав на выполнение этой операции\nДополнительная информация(%s)", ExtInfo.c_str());
        //        break;
        //      default:
        //        //форматировать и вернуть сообщение об ошибке
        //        sprintf(strError, "Ошибка времени выполнения '%d(%x)'\n\n%s",
        //            hr, hr, pwszDescription);
        //    }
        //    MessageBox(NULL, strError, "Ошибка времени выполнения", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);
        //}
        //ConnectionPtr OpenConnection()
        //{
        //  ConnectionPtr m_ptrConn;
        //  try
        //  { m_ptrConn.CreateInstance(__uuidof(Connection));
        //    //для SQL
        //    //m_ptrConn->CursorLocation=adUseServer;
        //    //соединение через udl файл
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
