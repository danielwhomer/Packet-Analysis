#ifndef TCPINFO_H
#define TCPINFO_H

#include "PacketInfo.h"

class TCPInfo : public PacketInfo
{
    friend class Sniffer;

private :
    unsigned short srcPort;
    unsigned short dstPort;

public :
    std::string info();
};

#endif // TCPINFO_H
