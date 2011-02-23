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

#include <stdint.h>

/* Pcap file format:
   http://wiki.wireshark.org/Development/LibpcapFileFormat
*/
class PcapFile {
  public:
    enum {
        PCAP_MAGIC_NUMBER       = 0xA1B2C3D4,
        PCAP_MAGIC_SWAPPED      = 0xD4C3B2A1,
        MAC_ETHER_TYPE_IPV4     = 0x0800,
        IP_HEADER_VERSION_IPv4  = 4,
        IP_PROTOCOL_TCP         = 6,
        IP_PROTOCOL_UDP         = 17,
    };

    /* Pcap file header */
    struct PcapHeader {
        uint32_t    magic_number;   /* magic number */
        uint16_t    version_major;  /* major version number */
        uint16_t    version_minor;  /* minor version number */
        int32_t     thiszone;       /* GMT to local correction */
        uint32_t    sigfigs;        /* accuracy of timestamps */
        uint32_t    snaplen;        /* max length of captured packets, in octets */
        uint32_t    network;        /* data link type */
    };

    /* Pcap packet header */
    struct PcapPacket {
        uint32_t    ts_sec;         /* timestamp seconds */
        uint32_t    ts_usec;        /* timestamp microseconds */
        uint32_t    incl_len;       /* number of octets of packet saved in file */
        uint32_t    orig_len;       /* actual length of packet */
    };

    /* 6 byte MAC */
    struct MacAdress {
        uint8_t     byte1;
        uint8_t     byte2;
        uint8_t     byte3;
        uint8_t     byte4;
        uint8_t     byte5;
        uint8_t     byte6;
    };

    /* MAC header */
    struct MacHeader {
        MacAdress   dmac;           /* Destination MAC */
        MacAdress   smac;           /* Source MAC */
        uint16_t    ether_type;     /* Ether type */
    };

    /* IPv4 header */
    struct IPv4Header {
        uint8_t     ver_ihl;        /* Version (4 bits) + Internet header length (4 bits) */
        uint8_t     tos;            /* Type of service */
        uint16_t    tlen;           /* Total length */
        uint16_t    identification; /* Identification */
        uint16_t    flags_fo;       /* Flags (3 bits) + Fragment offset (13 bits) */
        uint8_t     ttl;            /* Time to live */
        uint8_t     proto;          /* Protocol */
        uint16_t    csum;           /* Header checksum */
        uint32_t    saddr;          /* Source address */
        uint32_t    daddr;          /* Destination address */
    };

    /* UDP header */
    struct UdpHeader {
        uint16_t    sport;          /* Source port */
        uint16_t    dport;          /* Destination port */
        uint16_t    len;            /* Length of header and encapsulated data */
        uint16_t    csum;           /* Checksum of the pseudo header */
    };

    /* TCP header */
    struct TcpHeader {
        uint16_t    sport;          /* Source port */
        uint16_t    dport;          /* Destination port */
        uint32_t    seqnum;         /* Sequence number */
        uint32_t    acknum;         /* Acknowledgment number */
        uint16_t    control;        /* Data offset (4 bits) + ECN (3 bits) + Contol (6 bits) */
        uint16_t    window;         /* Sender window size */
        uint16_t    csum;           /* Checksum of the pseudo header */
        uint16_t    urgent;         /* Urgent sequence number */
    };

  private:
    FILE           *fp;
    bool            byteSwap_flag;
    PcapHeader      header;
    PcapPacket      packet;
    MacHeader       mac;
    IPv4Header      ipv4;
    UdpHeader       udp;
    TcpHeader       tcp;
    uint8_t        *pcapData;       /* pointer to pcap packet data */
    uint8_t        *datagram;       /* pointer to ip datagram */
    uint16_t        datagram_len;   /* number of bytes in datagram */

  public:
    PcapFile();
    ~PcapFile();

    void     clear();
    bool     open(const char *filename);
    void     close();
    bool     readPacket();
    void     printPacket();
    void     printFileHeader();
    void    *getPacketData();
    uint16_t getPacketLength();
    uint8_t  getIPv4HeaderVersion();
    uint8_t  getIPv4HeaderLength();
    uint8_t  getTcpHeaderLength();
    uint8_t  getUdpHeaderLength();
    uint16_t getSourcePort();
    uint16_t getDestinationPort();
    uint32_t getSourceIpAddress();
    uint32_t getDestinationIpAddress();

  protected:
    void     clearHeader();
    void     clearPacket();
    void     clearMac();
    void     clearIPv4();
    void     clearTcp();
    void     clearUdp();
    bool     readFileHeader();

  public:
    static uint16_t swap16(uint16_t n);
    static uint32_t swap32(uint32_t n);
};
