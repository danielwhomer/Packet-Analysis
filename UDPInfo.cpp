#include "UDPInfo.h"
#include <sstream>

std::string UDPInfo::info()
{
    std::stringstream ss;

    ss << head_info() << "SRC PORT: " << srcPort
       << ", DST PORT: " << dstPort << std::endl;

    return (ss.str());
}
