#include "pow.h"

namespace alpha::consensus {

bool valid_proof(
    const std::string& block_hash,
    uint32_t difficulty
) {
    if (difficulty > block_hash.size()) {
        return false;
    }

    for (uint32_t i = 0; i < difficulty; ++i) {
        if (block_hash[i] != '0') {
            return false;
        }
    }

    return true;
}

bool mine(
    std::string& block_hash,
    uint64_t& nonce,
    uint32_t difficulty
) {
    // TODO(v0.1): connect nonce search to block hashing.
    nonce = 0;
    return valid_proof(block_hash, difficulty);
}

}
