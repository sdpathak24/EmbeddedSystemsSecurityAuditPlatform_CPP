#include "crypto.h"
#include <cstdint>

void xor_encrypt(uint8_t *data, uint8_t len, uint8_t key)
{
    for (uint8_t i = 0; i < len; ++i)
    {
        data[i] ^= key;
    }
}
