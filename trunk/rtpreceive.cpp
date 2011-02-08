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
#include <conio.h>
#include <winsock2.h>


#define VERSION_STR  "V1.0"

#define MAX_BUFFER_LEN      (16384)

#define RTP_MAX_CSCR_COUNT  (16)


struct RtpPacket {
    char            version;
    char            padding;
    char            extension;
    char            cscr_count;
    char            marker;
    short           payload_type;
    int             sequence_number;
    unsigned int    time_stamp;
    unsigned int    ssrc;
    unsigned int    cscr[RTP_MAX_CSCR_COUNT];
    const void     *payload_data;
};


int parse_rtp(RtpPacket *rtp, const void *data, int len) {
    int rc = -1;
    if (len >= (3 * 4)) {
        int i = 0;
        unsigned char byte = 0;
        const unsigned char *buf =
            static_cast <const unsigned char *> (data);
        byte = buf[i++];
        rtp->version      = (byte & 0xC0) >> 6;
        rtp->padding      = (byte & 0x20) >> 5;
        rtp->extension    = (byte & 0x10) >> 4;
        rtp->cscr_count   = (byte & 0x0F) >> 0;
        byte = buf[i++];
        rtp->marker       = (byte & 0x80) >> 7;
        rtp->payload_type = (byte & 0x7F) >> 0;
        rtp->sequence_number = (buf[i] << 8) | (buf[i+1] << 0);
        i += 2;
        rtp->time_stamp =
            (buf[i] << 24) | (buf[i+1] << 16) | (buf[i+2] << 8) | (buf[i+3]);
        i += 4;
        rtp->ssrc =
            (buf[i] << 24) | (buf[i+1] << 16) | (buf[i+2] << 8) | (buf[i+3]);
        i += 4;
        int n = rtp->cscr_count;
        if (n < 0) {
            n = 0;
        }
        if (n > RTP_MAX_CSCR_COUNT) {
            n = RTP_MAX_CSCR_COUNT;
        }
        for (int j = 0; j < n; j++) {
            rtp->cscr[j] =
                (buf[i] << 24) | (buf[i+1] << 16) | (buf[i+2] << 8) | (buf[i+3]);
            i += 4;
        }
        rtp->payload_data = &buf[i];

        rc = i;
    }

    return rc;
}


void print_rtp(const RtpPacket *rtp) {
    printf("RTP: ver%2d; pad%2d; ext%2d; cc%2d; mark%2d; pt%4d; seq %6d; ts %6u; ssrc %6u\n",
        rtp->version,
        rtp->padding,
        rtp->extension,
        rtp->cscr_count,
        rtp->marker,
        rtp->payload_type,
        rtp->sequence_number,
        rtp->time_stamp,
        rtp->ssrc);
}


// main app
int main(int argc, char **argv) {
    int rc = EXIT_SUCCESS;

    printf("\nRTP receive %s\n", VERSION_STR);
    printf("    Project web site: http://code.google.com/p/rtpreceive/\n\n");

    // check command line
    char *basename = NULL;
    if (argc != 2) {
        basename = strrchr(argv[0], '/');
        if (basename == NULL) {
            basename = strrchr(argv[0], '\\');
        }
        if (basename == NULL) {
            basename = argv[0];
        } else {
            basename++;
        }
        printf("Usage:   %s port\n", basename);
        printf("         port on which to receive RTP data\n");
        rc = EXIT_FAILURE;
    } else {
        unsigned short port = 0;
        sscanf(argv[1], "%hu", &port);

        // initialize windows socket library
        WORD wVersionRequested = MAKEWORD(2, 2);            // version 2.2
        WSADATA wsaData;
        int err = WSAStartup(wVersionRequested, &wsaData);  // requires wsock32.lib
        if (err != 0) {
            fprintf(stderr, "WSAStartup failure\n");
        } else {

            // open socket
            SOCKET soc = INVALID_SOCKET;
            soc = socket(PF_INET, SOCK_DGRAM, 0);
            if (soc == INVALID_SOCKET) {
                fprintf(stderr, "Socket creation failed\n");
                rc = EXIT_FAILURE;
            } else {

                // bind to local receive port
                sockaddr_in config;
                memset(&config, 0, sizeof(config));
                config.sin_family      = AF_INET;
                config.sin_addr.s_addr = htonl(INADDR_ANY);
                config.sin_port        = htons(port);
                if (bind(soc, (sockaddr *) &config, sizeof(config)) == SOCKET_ERROR) {
                    fprintf(stderr, "Socket bind failed\n");
                    rc = EXIT_FAILURE;
                } else {
                    printf("Listening on port %hu ...\n", port);

                    // receive data
                    char *buffer = new char[MAX_BUFFER_LEN];
                    RtpPacket rtp;
                    bool flag = true;
                    while (flag) {
                        int n = recv(soc, buffer, MAX_BUFFER_LEN, 0);
                        if (n > 0) {
                            parse_rtp(&rtp, buffer, n);
                            print_rtp(&rtp);
                        }
                        if (_kbhit()) {
                            _getch();
                            flag = false;
                        }
                    }
                }

                // close socket
                shutdown(soc, SD_SEND);
                closesocket(soc);
            }
        }
    }

    return rc;
}
