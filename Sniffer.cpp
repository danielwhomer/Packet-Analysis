#include <stdlib.h>

#include "Sniffer.h"
#include "structs.h"

#include "panal.h"
#include "protocols.h"
#include "PacketInfo.h"
#include "TCPInfo.h"
#include "UDPInfo.h"

void handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);
PacketInfo* handler(tcpHeader *header);
PacketInfo* handler(udpHeader *header);

Sniffer::Sniffer(const char* dev_name) {
    errbits = 0;
    char buffer[PCAP_ERRBUF_SIZE];
    if ((listener = pcap_open(dev_name, 65536, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, buffer)) == NULL)
    {
        errbits |= SNIFF_FAILED_INIT;
    }
}

Sniffer::Sniffer(std::string& dev_name)
{
    Sniffer(dev_name.c_str());
}

void Sniffer::start()
{
    start(0);
}

void Sniffer::start(int limit)
{
    pcap_loop(listener, limit, Sniffer::handler, NULL);
}

void Sniffer::terminate()
{
    pcap_breakloop(listener);
}

/**
  Modified from: http://www.winpcap.org/docs/docs_412/html/group__wpcap__tut6.html
 **/
void Sniffer::handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    PacketInfo* pi;
    /* retireve the position of the ip header */
    if ((*(char *)(pkt_data + 14))>>4 == 4) {
        IPv4::header *ih;
        unsigned int ip_len;
        ih = (IPv4::header *) (pkt_data + 14); //length of ethernet header
        ip_len = (ih->ver_IHL & 0xf) * 4;

        switch (ih->protocol)
        {
        case Protocol::TCP :
            pi = handler((tcpHeader *) ((unsigned char*)ih + ip_len));
            break;

        case Protocol::UDP :
            pi = handler((udpHeader *) ((unsigned char*)ih + ip_len));
            break;

        default:
            pi = new PacketInfo();
        }

        pi->my_proto = (Protocol)ih->protocol;
        pi->src = IPv4::addr_str(ih->src);
        pi->dst = IPv4::addr_str(ih->dst);
        pi->len = ih->length;
        /* retireve the position of the udp header */

        //uh = (udpHeader *) ((u_char*)ih + ip_len);


        std::cout << *pi << std::endl;
    } else {
        IPv6::header * ihv6 = (IPv6::header *) (pkt_data + 14); //length of ethernet header
        unsigned int header_len = 40 * 8;

        switch (ihv6->next) {
        case Protocol::TCP :
            pi = handler((tcpHeader *) ((unsigned char*)ihv6 + header_len));
            break;

        case Protocol::UDP :
            pi = handler((udpHeader *) ((unsigned char*)ihv6 + header_len));
            break;

        default:
            pi = new PacketInfo();
        }

        pi->my_proto = (Protocol)ihv6->next;
        pi->src = IPv6::addr_str(ihv6->src);
        pi->dst = IPv6::addr_str(ihv6->dst);
        pi->len = ihv6->length;

        std::cout << *pi << std::endl;
    }
}

PacketInfo* Sniffer::handler(tcpHeader *header)
{
    TCPInfo* ret = new TCPInfo();

    ret->dstPort = ntohs(header->dstPort);
    ret->srcPort = ntohs(header->srcPort);

    return (ret);
}

PacketInfo* Sniffer::handler(udpHeader *header)
{
    UDPInfo* ret = new UDPInfo();

    ret->dstPort = ntohs(header->dstPort);
    ret->srcPort = ntohs(header->srcPort);

    return (ret);
}
