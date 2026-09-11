#include "CPU.h"
#include "Memory.h"

CPU::CPU()
    : programCounter(0),
      halted(false),
      memory(nullptr)
{
    reset();
}

void CPU::reset()
{
    for (auto& reg : registers)
        reg = 0;

    programCounter = 0;
    halted = false;
}

void CPU::connectMemory(Memory* newMemory)
{
    memory = newMemory;
}

bool CPU::step()
{
    if (halted || memory == nullptr)
        return false;

    unsigned char* ram = memory->data();

    if (ram == nullptr)
    {
        halted = true;
        return false;
    }

    if (programCounter >= memory->getSize())
    {
        halted = true;
        return false;
    }

    std::uint8_t opcode = ram[programCounter];

    programCounter++;

    return executeInstruction(opcode);
}

bool CPU::executeInstruction(std::uint8_t opcode)
{
    switch (opcode)
    {
        // 0x00 = NOP
        case 0x00:
            return true;

        // 0x01 = HALT
        case 0x01:
            halted = true;
            return true;

        // 0x02 = INC R0
        case 0x02:
            registers[0]++;
            return true;

        // 0x03 = DEC R0
        case 0x03:
            registers[0]--;
            return true;

        default:
            // Unknown instruction
            halted = true;
            return false;
    }
}

bool CPU::isHalted() const
{
    return halted;
}

std::uint64_t CPU::getRegister(int index) const
{
    if (index < 0 || index >= 8)
        return 0;

    return registers[index];
}

std::uint64_t CPU::getProgramCounter() const
{
    return programCounter;
}
