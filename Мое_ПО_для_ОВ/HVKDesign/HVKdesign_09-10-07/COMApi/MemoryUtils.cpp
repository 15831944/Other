// MemoryUtils.cpp: implementation of the CMemoryUtils class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemoryUtils.h"

// проверка правильного указателя
bool CMemoryUtils::IsValidPointer(const void* pointer)
{
#ifdef _WIN32
     return _CrtIsValidHeapPointer(pointer) != 0;
#else
     return false;
#endif
}

// проверка правильного указателя
bool CMemoryUtils::IsValidPointer(const void* pointer, unsigned int size, int access)
{
#ifdef _WIN32
     return _CrtIsValidPointer(pointer, size, access) != 0;
#else
     return false;
#endif
}

// размер памяти под указатель
size_t CMemoryUtils::MemorySize(void* pointer)
{
#ifdef _WIN32
     return pointer ? _msize(pointer) : 0;
#else
     return 0;
#endif
}

// проверка памяти
bool CMemoryUtils::CheckMemory(std::string& message)
{
#ifdef _WIN32
#ifdef _DEBUG
     // запрос на проверку памяти
     int Res = _CrtCheckMemory();
#endif     
     // получить код сообщения
     int result = _heapchk();     
     // сообщения по проверке памяти
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

// проверка памяти
void CMemoryUtils::CheckMemory()
{
     static std::string message;
     // проверка памяти
     bool res = CheckMemory(message);     
     // при ошибке вывести
     if (!res) {
          /*Console::GetSinglenton().AddMessage(Console::ERROR_MESSAGE, "%s%s", 
               Console::StdMessage[Console::FATAL_ERROR], message.c_str());*/
       ::MessageBox(NULL, message.c_str(), "Ошибка с памятью", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);
	}     
}

// отдача неиспользуемой памяти OC
bool CMemoryUtils::ReleaseUnusedMemory()
{
#ifdef _WIN32
     // возврат ос неиспользуемой памяти
     int res = _heapmin();
     if (res != -1) {
          return true;
     }
     /*Console::GetSinglenton().AddMessage(Console::ERROR_MESSAGE, "%s%s%s", 
          strerror(errno), "\n");*/
       ::MessageBox(NULL, strerror(errno), "Ошибка с памятью", MB_OK|MB_ICONERROR|MB_SYSTEMMODAL|MB_ICONSTOP);

     return false;
#else
     return true;
#endif
}