using System;
using System.Collections.Generic;
using System.Text;
using ADODB;
using System.Windows.Forms;

namespace AdoDbApi
{
    public class CADORecord
    {
        public Recordset m_Recordset;

        static Connection m_Connection;

	      enum MaxNum{MaxNumBaseFld = 8};
        public enum Types{Integer, Double, String};

	      //CADORecord(_ConnectionPtr pConn = NULL);
	      //virtual ~CADORecord();

        //CADORecord* Copy(CADORecord const& op2);
	      //CADORecord operator=(CADORecord const &op2);

        public CADORecord()
        {
          m_Recordset = new Recordset();
        }
        public static bool OpenConnection()
        {
          //создать объект Connection
          m_Connection = new Connection();
          try
          { 
            //для SQL
            //m_ptrConn->CursorLocation=adUseServer;
            //соединение через udl файл
            m_Connection.ConnectionString = "File Name=HVKDesign.udl";
            m_Connection.Open("", "", "", -1);
          }catch(Exception e)
          {
            return GenerateError(e);
          }
          return true;
        }
	      public bool Open(string strSource)
        {
            try{
              if (m_Recordset == null)
              m_Recordset = new Recordset();
              m_Recordset.Open(strSource, 
                m_Connection.ConnectionString,
        //			L"Provider=sqloledb;Data Source=;Integrated Security='SSPI';Initial Catalog=Equipment;User Id=;Password=;",

              CursorTypeEnum.adOpenDynamic, LockTypeEnum.adLockOptimistic, (int)(CommandTypeEnum.adCmdText));
            }
            catch(Exception e)
            {
                return GenerateError(e);
            }
            return true;
        }
        public bool GetData<T>(long NumFld, ref T Data)
        {
          try
          {
            if (Data == null) return false;
            if (m_Recordset.Fields[NumFld].ActualSize > 0)
              Data = (T)(m_Recordset.Fields[NumFld].Value);
          }
          catch (Exception e)
          {
            return GenerateError(e);
          }
          return true;
        }
        public bool GetData<T>(string NameFld, ref T Data)
        {
          try
          {
            if (Data == null) return false;
            if (m_Recordset.Fields[NameFld].ActualSize > 0)
              Data = (T)(m_Recordset.Fields[NameFld].Value);
          }
          catch (Exception e)
          {
            return GenerateError(e);
          }
          return true;
        }
      bool New() { return true; }
	    bool Update(){return true;}
	    void DeleteCurrentRecord(string strSource){;}
      static bool GenerateError(Exception e)
      {
          MessageBox.Show(e.Message);
          return false;
      }
      public void Close()
      {
          m_Recordset.Close();
      }
      public bool BOF()
      {
          return m_Recordset.BOF;
      }
      public bool EOF()
      {
          return m_Recordset.EOF;
      }
      public void MoveFirst()
      {
          m_Recordset.MoveFirst();
      }
      public object FieldData(object Index)
      {
          return m_Recordset.Fields[Index].Value;
      }

      public void MoveNext()
      {
          m_Recordset.MoveNext();
      }
      public void ProcRecordset(){;}
      
      public bool GetRecordset(string strSource)
      {
        try
        {
          m_Recordset.Open(strSource,
                            CADORecord.m_Connection.ConnectionString,
            //      L"Provider=sqloledb;Data Source=;Integrated Security='SSPI';Initial Catalog=Equipment;User Id=;Password=;",
                            CursorTypeEnum.adOpenDynamic, LockTypeEnum.adLockOptimistic, (int)CommandTypeEnum.adCmdUnspecified);
          if(!BOF())
            m_Recordset.MoveFirst();
          do
          {
            ProcRecordset();
          } while (!EOF());

          return true;
        }
        catch (Exception e)
        {
          return GenerateError(e);
        }
      }
    }
}
