#pragma once

#include "Memory.h"

class VM
{
public:
    VM();

    bool create(unsigned int memoryMB);

    void start();
    void stop();

    bool isRunning() const;

    unsigned int getMemoryMB() const;

private:
    Memory memory;
    bool running;
};
