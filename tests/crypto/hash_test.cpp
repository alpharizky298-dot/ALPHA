#include <cassert>
#include <string>

#include "../../src/crypto/hash.h"

int main() {

    const std::string result =
        alpha::crypto::sha256("alpha");

    const std::string expected =
        "8ed3f6ad685b959ead7022518e1af76cd816f8e8ec7ccd7ca9e1b7f5f7f5b8f4";

    assert(result == expected);

    return 0;
}