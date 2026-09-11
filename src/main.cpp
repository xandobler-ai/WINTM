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

    /*
        Our tiny CPU instruction set:

        0x00 = NOP
        0x01 = HALT
        0x02 = INC R0
        0x03 = DEC R0

        Program:

        INC R0
        INC R0
        INC R0
        HALT
    */

    // We need access to RAM for our test program.
    // For now, we'll add a temporary way through Memory.
    // This will be improved when we implement the memory bus.

    vm.start();

    std::cout << "VM started.\n";

    std::cout << "CPU R0: "
              << vm.getCPU().getRegister(0)
              << "\n";

    vm.stop();

    std::cout << "VM stopped.\n";

    return 0;
}
