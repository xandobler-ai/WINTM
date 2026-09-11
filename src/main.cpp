#include <iostream>

#include "core/VM.h"

int main()
{
    std::cout << "====================\n";
    std::cout << "       WinVM\n";
    std::cout << "====================\n\n";

    VM vm;

    if (!vm.create(16))
    {
        std::cerr << "Failed to create VM.\n";
        return 1;
    }

    std::cout << "VM created.\n";
    std::cout << "RAM: "
              << vm.getMemoryMB()
              << " MB\n\n";

    // Tiny guest program:
    //
    // 0x02 = INC R0
    // 0x02 = INC R0
    // 0x02 = INC R0
    // 0x01 = HALT

    vm.writeMemory(0, 0x02);
    vm.writeMemory(1, 0x02);
    vm.writeMemory(2, 0x02);
    vm.writeMemory(3, 0x01);

    vm.start();

    std::cout << "Running guest program...\n";

    vm.run(100);

    std::cout << "Guest program stopped.\n\n";

    std::cout << "R0 = "
              << vm.getCPU().getRegister(0)
              << "\n";

    std::cout << "Program Counter = "
              << vm.getCPU().getProgramCounter()
              << "\n";

    std::cout << "\nVM shutting down...\n";

    vm.stop();

    return 0;
}v
