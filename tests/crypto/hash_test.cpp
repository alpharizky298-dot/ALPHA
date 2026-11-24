#include <cassert>
#include <string>

#include "../../src/crypto/hash.h"

int main() {
    const std::string input = "alpha";

    const std::string hash =
        alpha::crypto::sha256(input);

    // SHA-256 implementation will be connected next.
    assert(hash.empty());

    return 0;
}
