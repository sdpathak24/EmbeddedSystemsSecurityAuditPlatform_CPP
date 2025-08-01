#ifndef CAN_SECURITY_H
#define CAN_SECURITY_H

#include <cstdint>

bool authenticate_can_msg(uint32_t id, uint8_t *data, uint8_t len, uint32_t expected_auth);

#endif
