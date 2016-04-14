#include "structs.h"

#include <sstream>

unsigned char hex_char(unsigned char a) {
    a = a & 0x0f;

    if (a < 10) {
        return ('0' + a);
    } else {
        return ('a' - 10 + a);
    }
}

std::string to_hex(unsigned char a) {
    std::stringstream hex;

    hex << hex_char(a >> 4) << hex_char(a);

    return (hex.str());
}

std::string IPv4::addr_str(const IPv4::addr& address)
{
    std::stringstream ss;

    for (int i=0; i<4; ++i) {
        ss << (int)address.bytes[i];
        if (i != 3) {
            ss << '.';
        }
    }

    return (ss.str());
}

std::string IPv6::addr_str(const IPv6::addr& address)
{
    std::stringstream ss;

    int best_s = -1, s = -1;
    int best_len = 0, len = 0;
    bool curr = false;

    for (int i=0; i<16; i+=2) {
        if (address.bytes[i] == 0 && address.bytes[i + 1] == 0) {
            if (curr) {
                ++len;
            } else {
                curr = true;
                s = i/2;
            }
        } else {
            curr = false;
            if (len > best_len) {
                best_len = len;
                best_s = s;
            }
        }
    }

    if (curr) {
        if (len > best_len) {
                best_len = len;
                best_s = s;
            }
    }

    bool empty = true;
    for (int i=0; i<8; ++i) {
        if (!(i >= best_s && i<= best_s + best_len)) {
            bool leading = true;
            unsigned char c = hex_char(address.bytes[i * 2] >> 4);
            if (!leading || c != '0') {
                leading = false;
                ss << c;
            }

            c = hex_char(address.bytes[i * 2]);
            if (!leading || c != '0') {
                leading = false;
                ss << c;
            }

            c = hex_char(address.bytes[i * 2 + 1] >> 4);
            if (!leading || c != '0') {
                leading = false;
                ss << c;
            }

            c = hex_char(address.bytes[i * 2 + 1]);
        ss << c;
        }
        if (best_s + best_len == i || i != 7 && !(i >= best_s && i< best_s + best_len)) {
            ss << ':';
        }
    }

    return (ss.str());
}

std::ostream& operator<<(std::ostream& os, const IPv4::addr& ad)
{
    return (os << IPv4::addr_str(ad));
}

std::ostream& operator<<(std::ostream& os, const IPv6::addr& ad)
{
    return (os << IPv6::addr_str(ad));
}
