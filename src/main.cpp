#include <iostream>
#include <fstream>
#include <cstdint>
#include "can_security.h"
#include "crypto.h"

int main()
{
    uint8_t message[8] = {0x42, 0x38, 0x10, 0x46, 0x21, 0x55, 0x06, 0x78};
    uint32_t can_id = 0x123;
    uint32_t expected_auth = can_id ^ message[0]; // Demo logic

    std::ofstream report("scan_report.txt");
    if (authenticate_can_msg(can_id, message, 8, expected_auth))
        report << "CAN Message Authenticated\n";
    else
        report << "CAN Message Authentication FAILED\n";

    xor_encrypt(message, 8, 0x5A);
    report << "Encrypted message output:\n";
    for (uint8_t i = 0; i < 8; ++i)
        report << std::hex << (int)message[i] << " ";
    report << "\n";

    report.close();
    std::cout << "Security audit complete. Check scan_report.txt.\n";
    return 0;
}
