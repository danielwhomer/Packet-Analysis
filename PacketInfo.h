#ifndef PACKETDATA_H_INCLUDED
#define PACKETDATA_H_INCLUDED

#include "protocols.h"
#include <string>
#include <ostream>

class PacketInfo
{
    friend class Sniffer;

private :
    Protocol my_proto;

    std::string src;
    std::string dst;

    unsigned int len;

protected :
    std::string head_info();

public :
    std::string protocol();
    std::string source();
    std::string destination();
    unsigned int length();

    virtual std::string info();

    friend std::ostream& operator<<(std::ostream&, PacketInfo&);
};

#endif // PACKETDATA_H_INCLUDED
