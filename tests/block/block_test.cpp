#include <cassert>

#include "../../src/block/block.h"

int main() {
    alpha::BlockHeader header{
        1,
        0,
        4,
        0,
        "0",
        "0"
    };

    alpha::Block block(header);

    assert(block.header().version == 1);
    assert(block.header().previous_hash == "0");

    return 0;
}
