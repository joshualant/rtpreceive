/*
 * Copyright (c) 2011, Jim Hollinger
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Jim Hollinger nor the names of its contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include <stdio.h>
#include <memory.h>

#if !defined (WIN32)
#  include <sys/socket.h>
#  include <netinet/in.h>
#else
#  include <winsock.h>
#endif

#include "pcapfile.h"


PcapFile::PcapFile() {
    fp              = NULL;
    pcapData        = NULL;
    datagram        = NULL;
    datagram_len    = 0;
    clear();
}


PcapFile::~PcapFile() {
    if (fp != NULL) {
        this->close();
    }
    if (pcapData   != NULL) {
        delete []pcapData;
        pcapData    = NULL;
    }
    datagram        = NULL;
    datagram_len    = 0;
}


void PcapFile::clear() {
    if (fp != NULL) {
        this->close();
    }
    if (pcapData != NULL) {
        delete []pcapData;
        pcapData = NULL;
    }
    datagram        = NULL;
    datagram_len    = 0;
    byteSwap_flag = false;
    clearHeader();
    clearPacket();
    clearMac();
    clearIPv4();
    clearTcp();
    clearUdp();
}


void PcapFile::clearHeader() {
    memset(&header, 0, sizeof(header));
}


void PcapFile::clearPacket() {
    memset(&packet, 0, sizeof(packet));
}


void PcapFile::clearMac() {
    memset(&mac, 0, sizeof(mac));
}


void PcapFile::clearIPv4() {
    memset(&ipv4, 0, sizeof(ipv4));
}


void PcapFile::clearTcp() {
    memset(&tcp, 0, sizeof(tcp));
}


void PcapFile::clearUdp() {
    memset(&udp, 0, sizeof(udp));
}


bool PcapFile::open(const char *filename) {
    bool flag = false;

    if (fp != NULL) {
        this->close();
    }
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "PcapFile.open: Could not open \"%s\"\n", filename);
    } else {
        if (readFileHeader()) {
            printf("PcapFile.open \"%s\" V%hu.%hu%s\n",
                filename,
                header.version_major,
                header.version_minor,
                (byteSwap_flag) ? ", byte swapped" : "");
            if (header.version_major == 2) {
                flag = true;
            } else {
                fprintf(stderr,
                    "PcapFile.open: Only major version 2 supported\n");
            }
        } else {
            fprintf(stderr,
            "PcapFile.open: \"%s\", but it does not appear to be a pcap file\n",
                filename);
            printFileHeader();
        }
        if (pcapData != NULL) {
            delete []pcapData;
            pcapData = NULL;
        }
        pcapData = new uint8_t[header.snaplen];
        if (pcapData == NULL) {
            fprintf(stderr,
                "PcapFile.open: Could not create %u byte buffer\n",
                header.snaplen);
            flag = false;
        }
    }

    return flag;
}


void PcapFile::close() {
    if (fp != NULL) {
        fclose(fp);
        fp = NULL;
    }
}


bool PcapFile::readFileHeader() {
    bool flag = false;

    if (fp != NULL) {
        size_t n = fread(&header, 1, sizeof(header), fp);
        if (n == sizeof(header)) {
            switch (header.magic_number) {

            case PCAP_MAGIC_NUMBER:
                byteSwap_flag = false;
                flag = true;
                break;

            case PCAP_MAGIC_SWAPPED:
                byteSwap_flag = true;
                flag = true;
                break;

            default:
                break;
            }
            if (flag) {
                if (byteSwap_flag) {
                    header.magic_number  = swap32(header.magic_number);
                    header.version_major = swap16(header.version_major);
                    header.version_minor = swap16(header.version_minor);
                    header.thiszone      = swap32(header.thiszone);
                    header.sigfigs       = swap32(header.sigfigs);
                    header.snaplen       = swap32(header.snaplen);
                    header.network       = swap32(header.network);
                }
            }
        }
    }

    return flag;
}


void PcapFile::printFileHeader() {
    printf("PcapFile.header magic: 0x%08X ver: %hu.%hu zone: %d sigfigs: %u snaplen: %u network: %u\n",
        header.magic_number,
        header.version_major,
        header.version_minor,
        header.thiszone,
        header.sigfigs,
        header.snaplen,
        header.network);
}


bool PcapFile::readPacket() {
    bool flag = false;

    if (fp != NULL) {
        size_t n = fread(&packet, 1, sizeof(packet), fp);
        if (n == sizeof(packet)) {
            if (byteSwap_flag) {
                packet.ts_sec   = swap32(packet.ts_sec);
                packet.ts_usec  = swap32(packet.ts_usec);
                packet.incl_len = swap32(packet.incl_len);
                packet.orig_len = swap32(packet.orig_len);
            }
            if ((packet.incl_len > 0) && (packet.incl_len <= header.snaplen)) {
                if (pcapData != NULL) {
                    n = fread(pcapData, 1, packet.incl_len, fp);
                    if (n == packet.incl_len) {
                        flag = true;
                        clearMac();
                        clearIPv4();
                        clearTcp();
                        clearUdp();
                        if (n >= sizeof(mac)) {
                            memcpy(&mac, pcapData, sizeof (mac));
                            mac.ether_type = ntohs(mac.ether_type);
                            if (mac.ether_type == MAC_ETHER_TYPE_IPV4) {
                                if (n >= (sizeof(mac) + sizeof(ipv4))) {
                                    memcpy(&ipv4, &pcapData[sizeof(mac)], sizeof(ipv4));
                                    ipv4.tlen  = ntohs(ipv4.tlen);
                                    ipv4.identification = ntohs(ipv4.identification);
                                    ipv4.flags_fo = ntohs(ipv4.flags_fo);
                                    ipv4.csum  = ntohs(ipv4.csum);
                                    ipv4.saddr = ntohl(ipv4.saddr);
                                    ipv4.daddr = ntohl(ipv4.daddr);
                                    datagram = &pcapData[sizeof(mac) + getIPv4HeaderLength()];
                                    datagram_len = ipv4.tlen - getIPv4HeaderLength();
                                    if (getIPv4HeaderVersion() == IP_HEADER_VERSION_IPv4) {
                                        if (ipv4.proto == IP_PROTOCOL_TCP) {
                                            memcpy(&tcp, datagram, sizeof(tcp));
                                            tcp.sport   = ntohs(tcp.sport);
                                            tcp.dport   = ntohs(tcp.dport);
                                            tcp.seqnum  = ntohl(tcp.seqnum);
                                            tcp.acknum  = ntohl(tcp.acknum);
                                            tcp.control = ntohs(tcp.control);
                                            tcp.window  = ntohs(tcp.window);
                                            tcp.csum    = ntohs(tcp.csum);
                                            tcp.urgent  = ntohs(tcp.urgent);
                                            datagram   += getTcpHeaderLength();
                                            datagram_len = datagram_len - getTcpHeaderLength();
                                        } else if (ipv4.proto == IP_PROTOCOL_UDP) {
                                            memcpy(&udp, datagram, sizeof(udp));
                                            udp.sport   = ntohs(udp.sport);
                                            udp.dport   = ntohs(udp.dport);
                                            udp.len     = ntohs(udp.len);
                                            udp.csum    = ntohs(udp.csum);
                                            datagram   += getUdpHeaderLength();
                                            datagram_len = udp.len - getUdpHeaderLength();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return flag;
}


void PcapFile::printPacket() {
    printf("PcapFile.packet timestamp: %u.%06u sec  len: %u/%u\n",
        packet.ts_sec,
        packet.ts_usec,
        packet.incl_len,
        packet.orig_len);
}


void *PcapFile::getPacketData() {
    return datagram;
}


uint16_t PcapFile::getPacketLength() {
    return datagram_len;
}


uint8_t PcapFile::getIPv4HeaderVersion() {
    return (ipv4.ver_ihl & 0xF0) >> 4;
}


uint8_t PcapFile::getIPv4HeaderLength() {
    return (ipv4.ver_ihl & 0x0F) * 4;
}


uint8_t PcapFile::getTcpHeaderLength() {
    return static_cast <uint8_t> ((tcp.control & 0xF000) >> 12) * 4;
}


uint8_t PcapFile::getUdpHeaderLength() {
    return sizeof(udp);
}


uint16_t PcapFile::getSourcePort() {
    uint16_t port = 0;

    if (mac.ether_type == MAC_ETHER_TYPE_IPV4) {
        if (getIPv4HeaderVersion() == IP_HEADER_VERSION_IPv4) {
            if (ipv4.proto == IP_PROTOCOL_TCP) {
                port = tcp.sport;
            } else if (ipv4.proto == IP_PROTOCOL_UDP) {
                port = udp.sport;
            }
        }
    }

    return port;
}


uint16_t PcapFile::getDestinationPort() {
    uint16_t port = 0;

    if (mac.ether_type == MAC_ETHER_TYPE_IPV4) {
        if (getIPv4HeaderVersion() == IP_HEADER_VERSION_IPv4) {
            if (ipv4.proto == IP_PROTOCOL_TCP) {
                port = tcp.dport;
            } else if (ipv4.proto == IP_PROTOCOL_UDP) {
                port = udp.dport;
            }
        }
    }

    return port;
}


uint32_t PcapFile::getSourceIpAddress() {
    uint32_t addr = INADDR_NONE;

    if (mac.ether_type == MAC_ETHER_TYPE_IPV4) {
        if (getIPv4HeaderVersion() == IP_HEADER_VERSION_IPv4) {
            addr = ipv4.saddr;
        }
    }

    return addr;
}


uint32_t PcapFile::getDestinationIpAddress() {
    uint32_t addr = INADDR_NONE;

    if (mac.ether_type == MAC_ETHER_TYPE_IPV4) {
        if (getIPv4HeaderVersion() == IP_HEADER_VERSION_IPv4) {
            addr = ipv4.daddr;
        }
    }

    return addr;
}


uint16_t PcapFile::swap16(uint16_t n) {
    return ((n & 0xFF00) >> 8) | ((n & 0x00FF) << 8);
}


uint32_t PcapFile::swap32(uint32_t n) {
    return ((n & 0xFF000000) >> 24) | ((n & 0x00FF0000) >>  8) |
           ((n & 0x0000FF00) <<  8) | ((n & 0x000000FF) << 24);
}
