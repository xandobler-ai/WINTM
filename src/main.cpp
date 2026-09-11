#include <iostream>
#include "core/VM.h"

int main()
{
    std::cout << "WinVM starting...\n";

    VM vm;

    if (!vm.create(512))
    {
        std::cerr << "Failed to create VM.\n";
        return 1;
    }

    std::cout << "VM created successfully.\n";
    std::cout << "RAM: " << vm.getMemoryMB() << " MB\n";

    vm.start();

    std::cout << "VM is running: "
              << (vm.isRunning() ? "yes" : "no")
              << "\n";

    vm.stop();

    std::cout << "VM stopped.\n";

    return 0;
}
