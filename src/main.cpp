#include <iostream>
#include "memory/memory.h"

int main() {
	Memory memory = Memory("explorer.exe");

	std::cout << "ProcessID: " << memory.GetProcessId() << '\n';

	while (true) {

	}
}
