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

#include "rtppacket.h"


RtpPacket::RtpPacket() {
    clear();
}


RtpPacket::~RtpPacket() {
    ;
}


void RtpPacket::clear() {
    version         = 0;
    padding         = 0;
    extension       = 0;
    cscr_count      = 0;
    marker          = 0;
    payload_type    = 0;
    sequence_number = 0;
    timestamp       = 0;
    ssrc            = 0;
    for (int i = 0; i < RTP_MAX_CSCR_COUNT; i++) {
        cscr[i] = 0;
    }
    payload_data = NULL;
}


int RtpPacket::parse(const void *data, int len) {
    int rc = -1;

    if ((data != NULL) && (len >= (3 * 4))) {
        int i = 0;
        unsigned char byte = 0;
        const unsigned char *buf = static_cast <const unsigned char *>(data);
        byte = buf[i++];
        version         = (byte & 0xC0) >> 6;
        padding         = (byte & 0x20) >> 5;
        extension       = (byte & 0x10) >> 4;
        cscr_count      = (byte & 0x0F) >> 0;
        byte = buf[i++];
        marker          = (byte & 0x80) >> 7;
        payload_type    = (byte & 0x7F) >> 0;
        sequence_number = (buf[i] << 8) | (buf[i+1] << 0);
        i += 2;
        timestamp =
            (buf[i] << 24) | (buf[i+1] << 16) | (buf[i+2] << 8) | (buf[i+3]);
        i += 4;
        ssrc =
            (buf[i] << 24) | (buf[i+1] << 16) | (buf[i+2] << 8) | (buf[i+3]);
        i += 4;
        int n = cscr_count;
        if (n < 0) {
            n = 0;
        }
        if (n > RTP_MAX_CSCR_COUNT) {
            n = RTP_MAX_CSCR_COUNT;
        }
        for (int j = 0; j < n; j++) {
            cscr[j] =
               (buf[i] << 24) | (buf[i+1] << 16) | (buf[i+2] << 8) | (buf[i+3]);
            i += 4;
        }
        payload_data = &buf[i];

        rc = i;
    }

    return rc;
}


int RtpPacket::store(void *data, int len) {
    int rc = -1;

    if ((data != NULL) && (len >= (3 * 4))) {
        int i = 0;
        unsigned char byte = 0;
        unsigned char *buf = static_cast <unsigned char *>(data);

        byte = 0;
        byte |= (version        << 6) & 0xC0;
        byte |= (padding        << 5) & 0x20;
        byte |= (extension      << 4) & 0x10;
        byte |= (cscr_count     << 0) & 0x0F;
        buf[i++] = byte;

        byte = 0;
        byte |= (marker         << 7) & 0x80;
        byte |= (payload_type   << 0) & 0x7F;
        buf[i++] = byte;

        buf[i++] = static_cast <unsigned char>((sequence_number & 0xFF00) >> 8);
        buf[i++] = static_cast <unsigned char>((sequence_number & 0x00FF) >> 0);

        buf[i++] = static_cast <unsigned char>((timestamp & 0xFF000000) >> 24);
        buf[i++] = static_cast <unsigned char>((timestamp & 0x00FF0000) >> 16);
        buf[i++] = static_cast <unsigned char>((timestamp & 0x0000FF00) >>  8);
        buf[i++] = static_cast <unsigned char>((timestamp & 0x000000FF) >>  0);

        buf[i++] = static_cast <unsigned char>((ssrc & 0xFF000000) >> 24);
        buf[i++] = static_cast <unsigned char>((ssrc & 0x00FF0000) >> 16);
        buf[i++] = static_cast <unsigned char>((ssrc & 0x0000FF00) >>  8);
        buf[i++] = static_cast <unsigned char>((ssrc & 0x000000FF) >>  0);

        int n = cscr_count;
        if (n < 0) {
            n = 0;
        }
        if (n > RTP_MAX_CSCR_COUNT) {
            n = RTP_MAX_CSCR_COUNT;
        }
        for (int j = 0; j < n; j++) {
           buf[i++] = static_cast <unsigned char>((cscr[j] & 0xFF000000) >> 24);
           buf[i++] = static_cast <unsigned char>((cscr[j] & 0x00FF0000) >> 16);
           buf[i++] = static_cast <unsigned char>((cscr[j] & 0x0000FF00) >>  8);
           buf[i++] = static_cast <unsigned char>((cscr[j] & 0x000000FF) >>  0);
        }

        rc = i;
    }
    
    return rc;
}


int RtpPacket::print() {
    return fprint(stdout);
}


int RtpPacket::fprint(FILE *fp) {
    int rc = -1;

    if (fp != NULL) {
        rc = 0;
        rc += fprintf(fp, "RTP: ver%2d; pad%2d; ext%2d; cc%2d; mark%2d; pt%4d",
            version,
            padding,
            extension,
            cscr_count,
            marker,
            payload_type);
        rc += fprintf(fp, "; seq %6hu; ts %6u; ssrc %6u\n",
            sequence_number,
            timestamp,
            ssrc);
    }

    return rc;
}

bool RtpPacket::checkOrder(const RtpPacket *prev) {
    bool inOrder_flag = true;

    unsigned short delta = sequence_number - prev->sequence_number;
    if (delta > 32767) {
        printf("RTP out of order: sequence number %5hu came after %5hu\n",
            sequence_number, prev->sequence_number);
        inOrder_flag = false;
    } else if (delta != 1) {
        int num_dropped = delta - 1;
        printf("RTP dropped %2d packet%s sequence number %5hu came after %5hu\n",
            num_dropped,
            (num_dropped == 1) ? ": " : "s:",
            sequence_number, prev->sequence_number);
        inOrder_flag = false;
    }

    return inOrder_flag;
}
