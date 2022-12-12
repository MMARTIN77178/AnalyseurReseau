#ifndef BOOTP_H
#define BOOTP_H

#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip6.h>
#include <netinet/ether.h>
#include "dns.h"
#include <stdio.h>
#include "pcap.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define SOULIGNE "\033[04m"
#define NORMAL "\033[00m"
#define YELLOW "\033[00;33m"

#define SET(x) (x==1?"set":"not set")



char * get_mac_addr(u_char *mac_addr);

/** Protocole Ethernet **/
void ethernet(u_char *user_args, const struct pcap_pkthdr* packet_header, const u_char *packet);

/** Protocole IPv4 **/
void ipv4(const unsigned char*);

/** Protocole IPv6**/
void ipv6(const unsigned char*);

/** Protocole ARP **/
void arp(const unsigned char*);

void print_tcp_flags(u_char);

/** Protocole TCP*/
void tcp(const unsigned char*);

/** Protocole UDP **/
void udp(const unsigned char *);

void http(const unsigned char *);

void ftp(const unsigned char *, bool);

void ftp_request(const unsigned char *);

void ftp_response(const unsigned char *);

void smtp(const unsigned char *, bool);

void smtp_request(const unsigned char *);

void smtp_response(const unsigned char *);

void telnet(const unsigned char *);

void pop(const unsigned char *, bool);
#endif