#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace wintm::core {

class Memory {
public:
    Memory();

    bool allocate(std::size_t sizeBytes);
    void clear();

    std::size_t size() const;

    bool read8(std::size_t address, std::uint8_t& value) const;
    bool write8(std::size_t address, std::uint8_t value);

    std::uint8_t* data();
    const std::uint8_t* data() const;

private:
    std::vector<std::uint8_t> memory;
};

}
