#include <stdlib.h>
#include <string.h>

#include "NetworkInterface.h"
#include "panal.h"

NetworkInterface::NetworkInterface()
{
    name = NULL;
    description = NULL;
    flags = 0;
}

NetworkInterface::NetworkInterface(char *name, char *description, unsigned int flags)
{
    setName(name);
    setDescription(description);
    this->flags = flags;
}

NetworkInterface::~NetworkInterface()
{
    delete [] name;
    delete [] description;
}

NetworkInterface* NetworkInterface::findAllInterfaces(int& count)
{
    pcap_if_t *devices;
    count = 0;
    char buffer[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &devices, buffer) == -1) {
        fprintf(stderr,"Error in pcap_findalldevs: %s\n", buffer);
        exit(NET_IF_FAIL_IN_FIND);
    }

    for (pcap_if_t* curr = devices; curr; curr=curr->next) {
        ++count;
    }

    NetworkInterface* nifs = new NetworkInterface[count];

    int i=0;
    for (pcap_if_t* curr = devices; i<count; curr=curr->next) {
        nifs[i].setName(curr->name);
        nifs[i].setDescription(curr->description);
        nifs[i].flags = curr->flags;
        ++i;
    }

    pcap_freealldevs(devices);
    return (nifs);
}

void NetworkInterface::findAllInterfaces(NetworkInterface*& interfaces, int& count)
{
    interfaces = findAllInterfaces(count);
}

const char* NetworkInterface::getDescription() {
    return (description);
}

const char* NetworkInterface::getName() {
    return (name);
}

void NetworkInterface::setDescription(char *description)
{
    if (description != NULL) {
        int len = strlen(description);
        this->description = new char[len + 1];
        for (int i=0; i<=len; ++i) {
            this->description[i] = description[i];
        }
    } else {
        this->description = "No description";
    }
}

void NetworkInterface::setName(char *name)
{
    int len = strlen(name);
    this->name = new char[len + 1];
    for (int i=0; i<=len; ++i) {
        this->name[i] = name[i];
    }
}

std::ostream& operator<<(std::ostream& os, const NetworkInterface& nif)
{
    return (os << nif.name << std::endl << nif.description << std::endl);
}
