#pragma once

#include <cstdint>

class Memory;

class CPU
{
public:
    CPU();

    void reset();

    void connectMemory(Memory* memory);

    bool step();

    bool isHalted() const;

    std::uint64_t getRegister(int index) const;

    std::uint64_t getProgramCounter() const;

private:
    std::uint64_t registers[8];

    std::uint64_t programCounter;

    bool halted;

    Memory* memory;

    bool executeInstruction(std::uint8_t opcode);
};
