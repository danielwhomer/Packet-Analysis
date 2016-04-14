#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <string>
#include <iostream>

namespace IPv4 {
    /**
        For IPv4 addresses, a union for quick converstion
       to get the individual bytes and the address as a
       whole 32bits
    **/
    typedef union addr {
        unsigned char bytes[4];
        unsigned int  asInt;
    } addr;

    typedef struct header {
        unsigned char  ver_IHL;
        unsigned char  diffServ_ECN;
        unsigned short length;
        unsigned short id;
        unsigned short flags_offset;
        unsigned char  timeToLive;
        unsigned char  protocol;
        unsigned short checksum;
        addr           src;
        addr           dst;
        unsigned int   opt;
    } ipv4Header;

    std::string addr_str(const addr&);
}

namespace IPv6 {
    typedef struct addr {
        unsigned char bytes[16];
    } addr;

    typedef struct header {
        unsigned char   ver_traff;
        unsigned char   traff_flow;
        unsigned short  flow;
        unsigned short  length;
        unsigned char   next;
        unsigned char   hoplim;
        addr            src;
        addr            dst;
    } header;

    std::string addr_str(const addr&);
}

typedef struct ethHeader {
    unsigned char  dst[6];
    unsigned char  src[6];
    unsigned short etherType;
} ethHeader;

typedef struct tcpHeader {
    unsigned short srcPort;
    unsigned short dstPort;
    unsigned int   sequenceNum;
    unsigned int   ackNum;
    unsigned short doffReservedControl;
    unsigned short windowSize;
    unsigned short checksum;
    unsigned short urgentPtr;
} tcpHeader;

typedef struct udpHeader {
    unsigned short srcPort;
    unsigned short dstPort;
    unsigned short length;
    unsigned short checksum;
} udpHeader;

/** Display operations **/

std::ostream& operator<<(std::ostream&, const IPv4::addr&);
std::ostream& operator<<(std::ostream&, const IPv6::addr&);

#endif // STRUCTS_H_INCLUDED
