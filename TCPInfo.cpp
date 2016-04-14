#include "TCPInfo.h"
#include <sstream>

std::string TCPInfo::info()
{
    std::stringstream ss;

    ss << head_info() << "SRC PORT: " << srcPort
       << ", DST PORT: " << dstPort << std::endl;

    return (ss.str());
}
