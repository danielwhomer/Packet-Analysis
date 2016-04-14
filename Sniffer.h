#ifndef SNIFFER_H_INCLUDED
#define SNIFFER_H_INCLUDED

#include <string>

#include "panal.h"
#include "PacketInfo.h"

#define SNIFF_FAILED_INIT -123

class Sniffer
{
private :
    pcap_t *listener;

    unsigned char errbits;

    static void handler(unsigned char*, const struct pcap_pkthdr*, const unsigned char*);
    static PacketInfo* handler(tcpHeader*);
    static PacketInfo* handler(udpHeader*);

public :
    Sniffer(const char*);
    Sniffer(std::string&);

    void start();
    void start(int);
    void terminate();

};

#endif // SNIFFER_H_INCLUDED
