// COMApi.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "COMApi.h"

/*BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}
*/

//���������������� ����� MSCOM
struct COMAPI InitOle {
    InitOle()  { ::CoInitialize(NULL); }
    ~InitOle() { ::CoUninitialize();   }
} _init_InitOle_;

COMAPI void GenerateError(HRESULT hr, PWSTR pwszDescription)
{
char strError[256];
  switch (hr)
  { case -2147217843:
      strcpy(strError, "�������� ��� ������������ � ������\n���������� ����� �������");
      break;
    case -2147217873:
      strcpy(strError, "�������� �� ���������\n������ ������� ������ �� ������� ���� ������ � ������ �������");
      break;
    case -2147217911:
      strcpy(strError, "� ��� ��� ���� �� ���������� ���� ��������");
      break;
    case -2146825023:
      strcpy(strError, "������ � ��������� ���� ������\n������� ���� �� ����������");
      break;
    default:
      //������������� � ������� ��������� �� ������
      sprintf(strError, "������ ������� ���������� '%d(%x)'\n\n%s",
          hr, hr, pwszDescription);
  }
  ::MessageBox(NULL, strError, "������ ������� ����������", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);
}

COMAPI _ConnectionPtr OpenConnection()
{
  _ConnectionPtr m_ptrConn;
  _bstr_t     bstrEmpty(L"");
  try
  { //������� ������ Connection
    m_ptrConn.CreateInstance(__uuidof(Connection));
    //��� SQL
    //m_ptrConn->CursorLocation=adUseServer;
    //���������� ����� udl ����
    m_ptrConn->ConnectionString = _bstr_t("File Name=HVKDesign.udl");
    m_ptrConn->Open(L"", bstrEmpty, bstrEmpty, -1);
  }catch(_com_error &e)
  { GenerateError(e.Error(), e.Description());
    return NULL;
  }
  return m_ptrConn;
}


