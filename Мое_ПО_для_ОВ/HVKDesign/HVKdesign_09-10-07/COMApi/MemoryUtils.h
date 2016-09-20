// MemoryUtils.h: interface for the CMemoryUtils class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __MEMORYUTILS__
#define __MEMORYUTILS__

#include "ComApi.h"

//#include "exceptions.h"
#include "crtdbg.h"
#include "malloc.h"
#include <string>

 // вспомогательный класс для работы с памятью
class COMAPI CMemoryUtils
{
private:
public:
	CMemoryUtils(){};
public:
     enum {    READ,          // доступ для чения
               WRITE          // доступ для записи
	 };     
     // проверка правильного указателя
     static bool IsValidPointer(const void* pointer);
     // проверка правильного указателя
     static bool IsValidPointer(const void* pointer, unsigned int size, int access);
     // размер памяти под указатель
     static size_t MemorySize(void* pointer);
     // проверка памяти
     static bool CheckMemory(std::string& message);
     // проверка памяти
     static void CheckMemory();
     // отдача неиспользуемой памяти OC
     static bool ReleaseUnusedMemory();
     ~CMemoryUtils(){};
};

#endif // __MEMORYUTILS__
