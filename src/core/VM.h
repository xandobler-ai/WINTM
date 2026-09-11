#pragma once

#include "Memory.h"
#include "CPU.h"

class VM
{
public: 
    VM();
    
    bool writeMemory(std::size_t address, unsigned char value);

    bool create(unsigned int memoryMB);

    void start();
    void stop();

    void run(unsigned int instructions);

    bool isRunning() const;

    unsigned int getMemoryMB() const;

    CPU& getCPU();

private:
    Memory memory;
    CPU cpu;

    bool running;
};
