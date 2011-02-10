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

/* Example output:

RTP receive V1.0
    Project web site: http://code.google.com/p/rtpreceive/

Listening on port 1234 ...
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29283; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29284; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29285; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29286; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29287; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29288; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29289; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29290; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29291; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29292; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29293; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29294; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29295; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29296; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29297; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29298; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29299; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29300; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29301; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29302; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29303; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29304; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29305; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29306; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29307; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29308; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29309; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29310; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29311; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29312; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29313; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29314; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29315; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29316; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29317; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29318; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29319; ts 3827707364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29320; ts 3827710364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29321; ts 3827710364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29322; ts 3827710364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29323; ts 3827713364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29324; ts 3827713364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29325; ts 3827713364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29326; ts 3827716364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29327; ts 3827716364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29328; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29329; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29330; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29331; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29332; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29333; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29334; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29335; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29336; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29337; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29338; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29339; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29340; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29341; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29342; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29343; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29344; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29345; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29346; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29347; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29348; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29349; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29350; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29351; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29352; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29353; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29354; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29355; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29356; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29357; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29358; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29359; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29360; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29361; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29362; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29363; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29364; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29365; ts 3827719364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29366; ts 3827722364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29367; ts 3827722364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29368; ts 3827722364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29369; ts 3827725364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29370; ts 3827725364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29371; ts 3827728364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29372; ts 3827728364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29373; ts 3827731364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29374; ts 3827731364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29375; ts 3827734364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29376; ts 3827734364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29377; ts 3827737364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29378; ts 3827737364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29379; ts 3827740364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29380; ts 3827740364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 0; pt  96; seq  29381; ts 3827743364; ssrc 1262133036
RTP: ver 2; pad 0; ext 0; cc 0; mark 1; pt  96; seq  29382; ts 3827743364; ssrc 1262133036
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined (WIN32)
#  include <conio.h>
#  include <winsock2.h>
#  define CLOSE(soc)        closesocket(soc)
#else
#  include <unistd.h>
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  define SOCKET            int
#  define INVALID_SOCKET    (-1)
#  define SOCKET_ERROR      (-1)
#  define SD_RECEIVE        SHUT_RD
#  define SD_SEND           SHUT_WR
#  define CLOSE(soc)        close(soc)
#endif

#include "rtppacket.h"


#define VERSION_STR  "V1.0"

#define MAX_BUFFER_LEN      (16384)


bool zeroTimestamp_flag = true;


// open input socket for listening
SOCKET open_input(unsigned short port, sockaddr *addr, int addrlen) {

    // create socket
    SOCKET soc = INVALID_SOCKET;
    soc = socket(PF_INET, SOCK_DGRAM, 0);
    if (soc == INVALID_SOCKET) {
        fprintf(stderr, "Input socket creation failed\n");
    } else {

        // bind to local receive port
        memset(addr, 0, addrlen);
        sockaddr_in *config = reinterpret_cast<sockaddr_in *>(addr);
        config->sin_family      = AF_INET;
        config->sin_addr.s_addr = htonl(INADDR_ANY);  // listen to anyone
        config->sin_port        = htons(port);
        if (bind(soc, addr, addrlen) == SOCKET_ERROR) {
            shutdown(soc, SD_RECEIVE);
            fprintf(stderr, "Input socket bind to %hu failed\n", port);
            CLOSE(soc);
            soc = INVALID_SOCKET;
        } else {
            printf("Listening on port %hu\n", port);
        }
    }

    return soc;
}


// open output socket for loopback retransmission
SOCKET open_output(unsigned short port, sockaddr *addr, int addrlen) {

    // create socket
    SOCKET soc = INVALID_SOCKET;
    soc = socket(PF_INET, SOCK_DGRAM, 0);
    if (soc == INVALID_SOCKET) {
        fprintf(stderr, "Output socket creation failed\n");
    } else {

        // configure for loopback retransmission
        memset(addr, 0, addrlen);
        sockaddr_in *config = reinterpret_cast<sockaddr_in *>(addr);
        config->sin_family      = AF_INET;
        config->sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // retransmit on loopback
        config->sin_port        = htons(port);
        printf("Retransmitting on loopback port %hu\n", port);
    }

    return soc;
}


// main app
int main(int argc, char * const argv[]) {
    int rc = EXIT_SUCCESS;

    printf("\nRTP receive %s\n", VERSION_STR);
    printf("    Project web site: http://code.google.com/p/rtpreceive/\n\n");

    // check command line
    char *basename = NULL;
    if ((argc != 2) && (argc != 3)) {
        basename = strrchr(argv[0], '/');
        if (basename == NULL) {
            basename = strrchr(argv[0], '\\');
        }
        if (basename == NULL) {
            basename = argv[0];
        } else {
            basename++;
        }
        printf("Usage:   %s in_port [out_port]\n", basename);
        printf("         in_port  on which to receive RTP data\n");
        printf("         out_port on which to retransmit RTP data (optional)\n");
        rc = EXIT_FAILURE;
    } else {
        unsigned short in_port  = 0;
        unsigned short out_port = 0;
        sscanf(argv[1], "%hu", &in_port);
        if (argc >= 3) {
            sscanf(argv[2], "%hu", &out_port);
        }

        // initialize windows socket library
#if defined (WIN32)
        WORD wVersionRequested = MAKEWORD(2, 2);            // version 2.2
        WSADATA wsaData;
        int err = WSAStartup(wVersionRequested, &wsaData);  // requires wsock32.lib
        if (err != 0) {
            fprintf(stderr, "WSAStartup failure\n");
            exit(EXIT_FAILURE);
        }
#endif  // WIN32

        // open sockets
        SOCKET in_soc  = INVALID_SOCKET;
        SOCKET out_soc = INVALID_SOCKET;
        sockaddr addr;
        int addrlen = sizeof(addr);
        in_soc = open_input(in_port, &addr, addrlen);
        if (out_port != 0) {
            out_soc = open_output(out_port, &addr, addrlen);
        }
        if ((in_soc == INVALID_SOCKET) ||
            ((out_soc == INVALID_SOCKET) && (out_port != 0))) {
            rc = EXIT_FAILURE;
        } else {

            // receive data
            char *buffer = new char[MAX_BUFFER_LEN];
            int rtp_pool_num = 0;
            RtpPacket rtp_pool[2];
            RtpPacket *rtp = &rtp_pool[rtp_pool_num];
            RtpPacket *rtp_prev = rtp;
            bool firstTime_flag = true;
            bool flag = true;
            while (flag) {
                int n = recv(in_soc, buffer, MAX_BUFFER_LEN, 0);
                if (n > 0) {
                    rtp->parse(buffer, n);
//                        rtp->print();
                    if (!firstTime_flag) {
                        rtp->checkOrder(rtp_prev);
                    }

                    // retransmit
                    if (out_soc != INVALID_SOCKET) {
                        if (zeroTimestamp_flag) {
                            rtp->timestamp = 0;
                        }
                        rtp->store(buffer, n);
                        int m = sendto(out_soc, buffer, n, 0, &addr, addrlen);
                        if (m != n) {
                            fprintf(stderr, "Retransmit failure\n");
                        }
                    }

                    // flip-flop rtp objects
                    rtp_prev = rtp;
                    rtp_pool_num = (rtp_pool_num + 1) % 2;
                    rtp = &rtp_pool[rtp_pool_num];
                }

                // cui
#if defined (WIN32)
                if (_kbhit()) {
                    int c = _getch();
                    if (c == 0x20) {
                        printf("\nPaused, press Esc to exit, Space to single-step, or Enter to resume ...");
                        c = _getch();
                        printf("\n");
                    }
                    switch (c) {

                    case 0x1B:  // escape
                        flag = false;
                        break;

                    case 0x20:  // space
                        _ungetch(c);
                        break;

                    case 't':
                        zeroTimestamp_flag = true;
                        printf("Setting retransmit timestamp to zero\n");
                        break;

                    case 'T':
                        zeroTimestamp_flag = false;
                        printf("Not setting retransmit timestamp to zero\n");
                        break;

                    default:
                        break;
                    }
                }
#endif  // WIN32
                firstTime_flag = false;
            }
            delete []buffer;
        }

        // close sockets
        if (out_soc != INVALID_SOCKET) {
            shutdown(out_soc, SD_SEND);
            CLOSE(out_soc);
        }
        if (in_soc != INVALID_SOCKET) {
            shutdown(in_soc, SD_RECEIVE);
            CLOSE(in_soc);
        }
    }

    return rc;
}
