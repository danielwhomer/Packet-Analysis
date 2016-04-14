#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T16:23:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Packet-Analysis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    NetworkInterface.cpp \
    PacketInfo.cpp \
    protocols.cpp \
    Sniffer.cpp \
    structs.cpp \
    UDPInfo.cpp \
    TCPInfo.cpp

HEADERS  += mainwindow.h \
    NetworkInterface.h \
    PacketInfo.h \
    panal.h \
    protocols.h \
    Sniffer.h \
    structs.h \
    UDPInfo.h \
    Include/pcap/bluetooth.h \
    Include/pcap/bpf.h \
    Include/pcap/namedb.h \
    Include/pcap/pcap.h \
    Include/pcap/sll.h \
    Include/pcap/usb.h \
    Include/pcap/vlan.h \
    Include/bittypes.h \
    Include/ip6_misc.h \
    Include/Packet32.h \
    Include/pcap-bpf.h \
    Include/pcap-namedb.h \
    Include/pcap-stdinc.h \
    Include/pcap.h \
    Include/remote-ext.h \
    Include/Win32-Extensions.h \
    TCPInfo.h

FORMS    += mainwindow.ui

DISTFILES += \
    Lib/Packet.lib \
    Lib/x64/Packet.lib \
    Lib/x64/wpcap.lib \
    Lib/libpacket.a \
    Lib/libwpcap.a \
    Lib/wpcap.lib

DEFINES += WPCAP
DEFINES += HAVE_REMOTE

INCLUDEPATH += Include
LIBS += "-LLib/x64" -lwpcap -lws2_32

