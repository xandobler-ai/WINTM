#pragma once

#include <cstddef>
#include <vector>

class Memory
{
public:
    Memory();

    bool allocate(std::size_t megabytes);

    bool write(std::size_t address, unsigned char value);
    unsigned char read(std::size_t address) const;

    void clear();

    std::size_t getSize() const;

    unsigned char* data();

private:
    std::vector<unsigned char> memory;
};
