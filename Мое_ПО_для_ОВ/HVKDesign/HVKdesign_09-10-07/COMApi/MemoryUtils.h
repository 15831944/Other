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

 // ��������������� ����� ��� ������ � �������
class COMAPI CMemoryUtils
{
private:
public:
	CMemoryUtils(){};
public:
     enum {    READ,          // ������ ��� �����
               WRITE          // ������ ��� ������
	 };     
     // �������� ����������� ���������
     static bool IsValidPointer(const void* pointer);
     // �������� ����������� ���������
     static bool IsValidPointer(const void* pointer, unsigned int size, int access);
     // ������ ������ ��� ���������
     static size_t MemorySize(void* pointer);
     // �������� ������
     static bool CheckMemory(std::string& message);
     // �������� ������
     static void CheckMemory();
     // ������ �������������� ������ OC
     static bool ReleaseUnusedMemory();
     ~CMemoryUtils(){};
};

#endif // __MEMORYUTILS__
