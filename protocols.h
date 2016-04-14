#ifndef PROTOCOLS_H_INCLUDED
#define PROTOCOLS_H_INCLUDED

#include <string>

enum Protocol : unsigned char {
    ICMP = 0x01,
    IGMP = 0x02,
    TCP = 0x06,
    UDP = 0x11,
    UNDEF = 0xFF
};

std::string protocol_long_string(Protocol);
std::string protocol_short_string(Protocol);

#endif // PROTOCOLS_H_INCLUDED
