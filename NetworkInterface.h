#ifndef NETWORKINTERFACE_H_INCLUDED
#define NETWORKINTERFACE_H_INCLUDED

#include <iostream>
#include "panal.h"

#define NET_IF_INVALID_PARAM -15
#define NET_IF_FAIL_IN_FIND  -22

class NetworkInterface
{
private :
    char *name;
    char *description;
    unsigned int flags;

    NetworkInterface();
    NetworkInterface(char*, char*, unsigned int);

    static NetworkInterface* findAllInterfaces(int&);

    void setName(char*);
    void setDescription(char*);

public :
    ~NetworkInterface();

    static void findAllInterfaces(NetworkInterface*&, int&);

    const char* getName();
    const char* getDescription();

    friend std::ostream& operator<<(std::ostream&, const NetworkInterface&);
};

#endif // NETWORKINTERFACE_H_INCLUDED
