#include "hash.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

#include <openssl/evp.h>

namespace alpha::crypto {

std::string sha256(const std::string& input) {

    EVP_MD_CTX* context = EVP_MD_CTX_new();

    if (context == nullptr) {
        throw std::runtime_error(
            "Failed to create SHA-256 context"
        );
    }

    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_length = 0;

    if (EVP_DigestInit_ex(
            context,
            EVP_sha256(),
            nullptr
        ) != 1) {

        EVP_MD_CTX_free(context);

        throw std::runtime_error(
            "Failed to initialize SHA-256"
        );
    }

    if (EVP_DigestUpdate(
            context,
            input.data(),
            input.size()
        ) != 1) {

        EVP_MD_CTX_free(context);

        throw std::runtime_error(
            "Failed to update SHA-256"
        );
    }

    if (EVP_DigestFinal_ex(
            context,
            digest,
            &digest_length
        ) != 1) {

        EVP_MD_CTX_free(context);

        throw std::runtime_error(
            "Failed to finalize SHA-256"
        );
    }

    EVP_MD_CTX_free(context);

    std::ostringstream result;

    result << std::hex
           << std::setfill('0');

    for (unsigned int i = 0;
         i < digest_length;
         ++i) {

        result << std::setw(2)
               << static_cast<unsigned int>(digest[i]);
    }

    return result.str();
}

}