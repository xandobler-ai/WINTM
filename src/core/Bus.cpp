#include "wintm/core/Bus.h"
#include "wintm/core/Memory.h"

namespace wintm::core {

Bus::Bus()
    : memory(nullptr)
{
}

void Bus::connectMemory(Memory* newMemory)
{
    memory = newMemory;
}

bool Bus::read8(
    std::size_t address,
    std::uint8_t& value) const
{
    if (memory == nullptr)
        return false;

    return memory->read8(address, value);
}

bool Bus::write8(
    std::size_t address,
    std::uint8_t value)
{
    if (memory == nullptr)
        return false;

    return memory->write8(address, value);
}

}
