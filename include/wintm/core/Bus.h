#pragma once

#include <cstddef>
#include <cstdint>

namespace wintm::core {

class Memory;

class Bus {
public:
    Bus();

    void connectMemory(Memory* memory);

    bool read8(
        std::size_t address,
        std::uint8_t& value) const;

    bool write8(
        std::size_t address,
        std::uint8_t value);

private:
    Memory* memory;
};

}
