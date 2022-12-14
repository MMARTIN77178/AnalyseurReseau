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
#include <sys/time.h>
#include <time.h>

#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define SOULIGNE "\033[04m"
#define NORMAL "\033[00m"
#define YELLOW "\033[00;33m"

#define SET(x) (x==1?"set":"not set")

#define BOOTP_REQUEST 1
#define BOOTP_REPLY 2
#define BOOTP_

struct bootphdr {
	u_int8_t bootp_op;			/* Opcode du packet */
	u_int8_t bootp_htype;		/*  Hardware type*/
	u_int8_t bootp_hlen;		/* Longueur de l'adresse pour l'hardware */
	u_int8_t bootp_hops;		/* gateway hops */
	u_int32_t bootp_id;			/* transaction ID */
	u_int16_t bootp_secs;		/* temps depuis le debut du bootstrap (en seconde)*/
	u_int16_t bootp_flags;		/* flags */
	struct in_addr ciaddr;		/* client IP address */
	struct in_addr yiaddr;		/* 'your' IP address */
	struct in_addr siaddr;		/* server IP address */
	struct in_addr giaddr;		/* gateway IP address */
	u_char bootp_chaddr[16];	/* adresse hardware du client (optionnel)*/
	u_char bootp_sname[64];		/* server host name (optionnel)*/
	u_char bootp_file[128];		/* boot file name (optionnel)*/
	u_char bootp_vend[64]; 		/* vendor*/
};

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

/** Protocole HTTP **/
void http(const unsigned char *);

/** Protocole FTP**/
void ftp(const unsigned char *, bool);

/** Fonction qui affiche le contenu ftp lors d'une requête **/
void ftp_request(const unsigned char *);

/** Fonction qui affiche le contenu ftp lors d'une réponse **/
void ftp_response(const unsigned char *);

/** Protocole SMTP **/
void smtp(const unsigned char *, bool);

/** Fonction qui affiche le contenu d'une commande SMTP**/
void smtp_command(const unsigned char *);

/** Fonction qui affiche le contenu d'une réponse SMTP**/
void smtp_response(const unsigned char *);

/** Protocole TELNET **/
void telnet(const unsigned char *);

/** Protocole POP **/
void pop(const unsigned char *, bool);

/** Fonction qui affiche le contenu d'une commande POP **/
void pop_request(const unsigned char *);

/** Fonction qui affiche le contenu d'une réponse POP **/
void pop_response(const unsigned char *);

/** Protocole IMAP **/
void imap(const unsigned char *, bool);
#endif