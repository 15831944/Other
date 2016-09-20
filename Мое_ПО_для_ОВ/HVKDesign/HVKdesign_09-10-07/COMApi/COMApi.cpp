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

//Инициализировать среду MSCOM
struct COMAPI InitOle {
    InitOle()  { ::CoInitialize(NULL); }
    ~InitOle() { ::CoUninitialize();   }
} _init_InitOle_;

COMAPI void GenerateError(HRESULT hr, PWSTR pwszDescription, const string& ExtInfo)
{
char strError[256];
  switch (hr)
  {
	case -2146824556:
      sprintf(strError, "Сервер не может завершить операцию\nДополнительная информация(%s)", ExtInfo.c_str());
      break;
    case -2146825023:
      sprintf(strError, "Ошибка в структуре базы данных\nНужного поля не существует\nДополнительная информация(%s)", ExtInfo.c_str());
      break;
	case -2146825267:
      sprintf(strError, "Запись не найдена\nДополнительная информация(%s)", ExtInfo.c_str());
      break;
	case -2147217843:
      sprintf(strError, "Неверное имя пользователя и пароль\nПриложение будет закрыто\nДополнительная информация(%s)", ExtInfo.c_str());
      break;
    case -2147217873:
      sprintf(strError, "Операция не выполнена\nНельзя удалить запись на которую есть ссылка в другой таблице\nДополнительная информация(%s)", ExtInfo.c_str());
      break;
    case -2147217911:
      sprintf(strError, "У Вас нет прав на выполнение этой операции\nДополнительная информация(%s)", ExtInfo.c_str());
      break;
    default:
      //форматировать и вернуть сообщение об ошибке
      sprintf(strError, "Ошибка времени выполнения '%d(%x)'\n\n%s",
          hr, hr, pwszDescription);
  }
  ::MessageBox(NULL, strError, "Ошибка времени выполнения", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);
}
/*
COMAPI _ConnectionPtr OpenConnection()
{
  _ConnectionPtr m_ptrConn;
  _bstr_t     bstrEmpty(L"");
  try
  { //создать объект Connection
    m_ptrConn.CreateInstance(__uuidof(Connection));
    //для SQL
    //m_ptrConn->CursorLocation=adUseServer;
    //соединение через udl файл
    m_ptrConn->ConnectionString = _bstr_t("File Name=HVKDesign.udl");
    m_ptrConn->Open(L"", bstrEmpty, bstrEmpty, -1);
  }catch(_com_error &e)
  { GenerateError(e.Error(), e.Description(), string(m_ptrConn->ConnectionString));
    return NULL;
  }
  return m_ptrConn;
}
*/

