/**
 * Had to make this so that it would compile and to define the needed things
 * @author Michael van Dyk
 **/

#ifndef PANAL_HEADER_H
#define PANAL_HEADER_H

/** Unhappy if these were not typedef'd **/
typedef unsigned char  u_char;
typedef unsigned int   u_int;
typedef unsigned short u_short;

/** Required by WinPCap Library **/
//#define WPCAP
//#define HAVE_REMOTE

#include <winsock2.h>

/** pcap interface **/
#include <pcap.h>

/** contains structs for headers and other important things **/
#include "structs.h"

/** headers that are needed for this application **/
#include "NetworkInterface.h"
#include "Sniffer.h"

#endif PANAL_HEADER_H
