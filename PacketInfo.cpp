#include "PacketInfo.h"

#include <sstream>

std::string PacketInfo::destination()
{
    return (dst);
}

std::string PacketInfo::head_info()
{
    std::stringstream ss;

    ss << "Protocol: " << protocol_long_string(my_proto) << std::endl
       << "SRC: " << src << std::endl
       << "DST: " << dst << std::endl
       << "Length: " << len << std::endl;

    return (ss.str());
}

std::string PacketInfo::info()
{
    return (head_info());
}

unsigned int PacketInfo::length()
{
    return (len);
}

std::string PacketInfo::protocol()
{
    return (protocol_short_string(my_proto));
}

std::string PacketInfo::source()
{
    return (src);
}

std::ostream& operator<<(std::ostream& os, PacketInfo& pi)
{
    return (os << pi.info());
}
