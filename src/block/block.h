
#pragma once

#include <cstdint>
#include <string>

namespace alpha {

struct BlockHeader {
    uint32_t version;
    uint64_t timestamp;
    uint32_t difficulty;
    uint64_t nonce;

    std::string previous_hash;
    std::string merkle_root;
};

class Block {
public:
    explicit Block(const BlockHeader& header);

    const BlockHeader& header() const;

private:
    BlockHeader header_;
};

}
