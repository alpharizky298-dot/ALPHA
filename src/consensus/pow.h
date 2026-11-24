#pragma once

#include <cstdint>
#include <string>

namespace alpha::consensus {

bool valid_proof(
    const std::string& block_hash,
    uint32_t difficulty
);

bool mine(
    std::string& block_hash,
    uint64_t& nonce,
    uint32_t difficulty
);

}
