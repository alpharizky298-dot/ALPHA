#include "block.h"

namespace alpha {

Block::Block(const BlockHeader& header)
    : header_(header) {}

const BlockHeader& Block::header() const {
    return header_;
}

}
