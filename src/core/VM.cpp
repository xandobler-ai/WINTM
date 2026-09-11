#include "VM.h"

VM::VM()
    : running(false)
{
    cpu.connectMemory(&memory);
}

bool VM::create(unsigned int memoryMB)
{

    bool VM::writeMemory(std::size_t address, unsigned char value)
{
    return memory.write(address, value);
}
    if (memoryMB == 0)
        return false;

    if (!memory.allocate(memoryMB))
        return false;

    cpu.reset();

    return true;
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

void VM::run(unsigned int instructions)
{
    if (!running)
        return;

    for (unsigned int i = 0; i < instructions; i++)
    {
        if (!cpu.step())
            break;

        if (cpu.isHalted())
            break;
    }
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

CPU& VM::getCPU()
{
    return cpu;
}
