#include "protocols.h"
#include <sstream>

std::string protocol_long_string(Protocol proto) {
    switch (proto)
    {
    case Protocol::ICMP :
        return ("Internet Control Message Protocol");
    case Protocol::IGMP :
        return ("Internet Group Management Protocol");
    case Protocol::TCP :
        return ("Transmission Control Protocol");
    case Protocol::UDP :
        return ("User Datagram Protocol");
    default :
        std::stringstream ss;
        ss << "undefined : " << (unsigned int)proto;
        return (ss.str());
    }
}

std::string protocol_short_string(Protocol proto)
{
    switch (proto)
    {
    case Protocol::ICMP :
        return ("ICMP");
    case Protocol::IGMP :
        return ("IGMP");
    case Protocol::TCP :
        return ("TCP");
    case Protocol::UDP :
        return ("UDP");
    default :
        std::stringstream ss;
        ss << "undefined : " << (unsigned int)proto;
        return (ss.str());
    }
}
