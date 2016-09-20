// MemoryUtils.cpp: implementation of the CMemoryUtils class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemoryUtils.h"

// �������� ����������� ���������
bool CMemoryUtils::IsValidPointer(const void* pointer)
{
#ifdef _WIN32
     return _CrtIsValidHeapPointer(pointer) != 0;
#else
     return false;
#endif
}

// �������� ����������� ���������
bool CMemoryUtils::IsValidPointer(const void* pointer, unsigned int size, int access)
{
#ifdef _WIN32
     return _CrtIsValidPointer(pointer, size, access) != 0;
#else
     return false;
#endif
}

// ������ ������ ��� ���������
size_t CMemoryUtils::MemorySize(void* pointer)
{
#ifdef _WIN32
     return pointer ? _msize(pointer) : 0;
#else
     return 0;
#endif
}

// �������� ������
bool CMemoryUtils::CheckMemory(std::string& message)
{
#ifdef _WIN32
#ifdef _DEBUG
     // ������ �� �������� ������
     int Res = _CrtCheckMemory();
#endif     
     // �������� ��� ���������
     int result = _heapchk();     
     // ��������� �� �������� ������
     static const std::string MemoryCheckMessage[] = {
          "Initial header information is bad or cannot be found.",
          "Bad node has been found or heap is damaged.", 
          "Pointer into heap is not valid.",
          "Heap has not been initialized."
     };
     enum {    HEAPBADBEGIN,
               HEAPBADNODE,
               HEAPBADPTR,
               HEAPEMPTY               
     };
     switch (result) {
          case _HEAPBADBEGIN: {
               message = MemoryCheckMessage[HEAPBADBEGIN];
          }
          case _HEAPBADNODE: {
               message = MemoryCheckMessage[HEAPBADNODE];
          }
          case _HEAPBADPTR: {
               message = MemoryCheckMessage[HEAPBADPTR];
          }
          case _HEAPEMPTY: {
               message = MemoryCheckMessage[HEAPEMPTY];
          }
          case _HEAPOK: { // Heap appears to be consistent.
               message = "";
          }
     }
#ifdef _DEBUG
     return TRUE == Res && _HEAPOK == result;
#else
     return  _HEAPOK == result;
#endif     
#else
     return true;
#endif     
}

// �������� ������
void CMemoryUtils::CheckMemory()
{
     static std::string message;
     // �������� ������
     bool res = CheckMemory(message);     
     // ��� ������ �������
     if (!res) {
          /*Console::GetSinglenton().AddMessage(Console::ERROR_MESSAGE, "%s%s", 
               Console::StdMessage[Console::FATAL_ERROR], message.c_str());*/
       ::MessageBox(NULL, message.c_str(), "������ � �������", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);
	}     
}

// ������ �������������� ������ OC
bool CMemoryUtils::ReleaseUnusedMemory()
{
#ifdef _WIN32
     // ������� �� �������������� ������
     int res = _heapmin();
     if (res != -1) {
          return true;
     }
     /*Console::GetSinglenton().AddMessage(Console::ERROR_MESSAGE, "%s%s%s", 
          strerror(errno), "\n");*/
       ::MessageBox(NULL, strerror(errno), "������ � �������", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);

     return false;
#else
     return true;
#endif
}