#include "VM.h"

VM::VM()
    : running(false)
{
}

bool VM::create(unsigned int memoryMB)
{
    if (memoryMB == 0)
        return false;

    return memory.allocate(memoryMB);
}

void VM::start()
{
    if (memory.getSize() == 0)
        return;

    running = true;
}

void VM::stop()
{
    running = false;
}

bool VM::isRunning() const
{
    return running;
}

unsigned int VM::getMemoryMB() const
{
    return static_cast<unsigned int>(
        memory.getSize() / (1024 * 1024)
    );
}
