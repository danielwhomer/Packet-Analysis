#ifndef UDPINFO_H_INCLUDED
#define UDPINFO_H_INCLUDED

#include "PacketInfo.h"

class UDPInfo : public PacketInfo
{
    friend class Sniffer;

private :
    unsigned short srcPort;
    unsigned short dstPort;

public :
    std::string info();
};

#endif // UDPINFO_H_INCLUDED
