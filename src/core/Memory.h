#pragma once

#include <cstddef>
#include <vector>

class Memory
{
public:
    Memory();

    bool allocate(std::size_t megabytes);

    void clear();

    std::size_t getSize() const;

    unsigned char* data();

private:
    std::vector<unsigned char> memory;
};
