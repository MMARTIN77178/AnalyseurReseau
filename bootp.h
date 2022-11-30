#ifndef BOOTP_H
#define BOOTP_H

#include <net/ethernet.h>
#include <netinet/ip.h>
#include <stdio.h>
#include "pcap.h"
#include <stdlib.h>
#include <time.h>

#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define SOULIGNE "\033[04m"
#define NORMAL "\033[00m"

/** Protocole Ethernet **/
void ethernet(u_char *user_args, const struct pcap_pkthdr* packet_header, const u_char *packet);

/** Protocole IPv4 **/
void ipv4(const unsigned char*);

#endif