#include "bootp.h"

extern int verbose;

void ethernet(u_char *user_args, const struct pcap_pkthdr* packet_header, const u_char *packet){
    struct ether_header *ethptr; 
    ethptr = (struct ether_header*)packet;
    const u_char *net_pckt=(const unsigned char *)packet+14;

    printf("Trame Ethernet\n");
    switch(ntohs(ethptr->ether_type)){
        case ETHERTYPE_IP:
            printf(BLEUCLAIR "Type : IPv4\n" NORMAL);
            ipv4(net_pckt);
            break;
        case ETHERTYPE_IPV6:
            printf(BLEUCLAIR "Type : IPv6\n" NORMAL);
            //ipv6(net_pckt, verbose);
            break;
        case ETHERTYPE_ARP:
            printf(BLEUCLAIR "Type : ARP\n" NORMAL);
            //arp(net_pckt, packet_header->caplen, verbose);
            break;
        default:
            printf(BLEUCLAIR "Type : %d\n" NORMAL, ntohs(ethptr->ether_type));
            break;
    }
}

void ipv4(const unsigned char* net_pckt){
    struct ip *iptr=(struct ip*)net_pckt;

    if(verbose>1){
        printf(ROUGE "\t*** IPv4 ***\n" NORMAL);
        printf(BLEU "Header length : %d (%d bytes)\n" NORMAL, iptr->ip_hl, iptr->ip_hl*4);
    }
}