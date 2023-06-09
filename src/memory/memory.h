#pragma once
// must be included first!
#include <windows.h>
// windows sdk for enumerating and manipulating processes
#include <tlhelp32.h>
#include <iostream>

class Memory {
private:
	// process id in operating system 
	DWORD processId = 0;

	// pointer or a reference for manipulating an object in operating system
	HANDLE process = NULL;

public:
	Memory(const char* processName);
	~Memory();

	DWORD GetProcessId();

	HANDLE GetProcess();

	uintptr_t GetModuleAddress(const char* moduleName);

	// windows api function that reads specified memory address value
	template<typename T>
	T Read(uintptr_t address) {
		T value;
		ReadProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), NULL);
		return value;
	}

	// windows api function that writes specified memory address value
	template<typename T>
	bool Write(uintptr_t address, T value) {
		return WriteProcessMemory(this->process, (LPVOID)address, &value, sizeof(T), NULL);
	}
};
