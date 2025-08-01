#include "can_security.h"

// Simple authentication (for demo; use proper MAC/HMAC in real systems)
bool authenticate_can_msg(uint32_t id, uint8_t *data, uint8_t len, uint32_t expected_auth)
{
    uint32_t auth = id;
    for (uint8_t i = 0; i < len; ++i)
    {
        auth ^= data[i];
    }
    return (auth == expected_auth);
}
