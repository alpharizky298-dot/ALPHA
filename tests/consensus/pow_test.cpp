#include <cassert>
#include <string>

#include "../../src/consensus/pow.h"

int main() {
    assert(
        alpha::consensus::valid_proof(
            "0000abcdef",
            4
        )
    );

    assert(
        !alpha::consensus::valid_proof(
            "0001abcdef",
            4
        )
    );

    return 0;
}
