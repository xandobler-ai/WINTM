#include "Memory.h"

Memory::Memory()
{
}

bool Memory::allocate(std::size_t megabytes)
{
    try
    {
        std::size_t bytes = megabytes * 1024 * 1024;

        memory.resize(bytes);

        return true;
    }
    catch (...)
    {
        memory.clear();
        return false;
    }
}

void Memory::clear()
{
    memory.clear();
}

std::size_t Memory::getSize() const
{
    return memory.size();
}

unsigned char* Memory::data()
{
    if (memory.empty())
        return nullptr;

    return memory.data();
}
