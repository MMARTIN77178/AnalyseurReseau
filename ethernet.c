#include "bootp.h"
#include <string.h>

extern int verbose;

char * get_mac_addr(u_char *mac_addr){
    char *mac = malloc(18);
    sprintf(mac, "%02x:%02x:%02x:%02x:%02x:%02x", mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    return mac;
}

void ethernet(u_char *user_args, const struct pcap_pkthdr* packet_header, const u_char *packet){
    struct ether_header *ethptr; 
    ethptr = (struct ether_header*)packet;
    const u_char *net_pckt=(const unsigned char *)packet+14;

    char *ethdst=get_mac_addr(ethptr->ether_dhost);
    char *ethsrc=get_mac_addr(ethptr->ether_shost);

    if((strcmp(ethdst, "00:00:00:00:00") == 0) && strcmp(ethdst, "00:00:00:00:00") == 0){
        printf("Ethernet || ");
    }
    else{
        printf("Ethernet || src : %s || dest : %s || ", ethsrc, ethdst);
    }

    switch(ntohs(ethptr->ether_type)){
        case ETHERTYPE_IP:
            printf(BLEUCLAIR "IPv4\n" NORMAL);
            ipv4(net_pckt);
            break;
        case ETHERTYPE_IPV6:
            printf(BLEUCLAIR "IPv6\n" NORMAL);
            //ipv6(net_pckt, verbose);
            break;
        case ETHERTYPE_ARP:
            printf(BLEUCLAIR "ARP\n" NORMAL);
            //arp(net_pckt, packet_header->caplen, verbose);
            break;
        default:
            printf(BLEUCLAIR "%d\n" NORMAL, ntohs(ethptr->ether_type));
            break;
    }
}

void ipv4(const unsigned char* net_pckt){
    struct ip *iptr=(struct ip*)net_pckt;
    if(verbose>=2){
        printf("\tIPv4 || src: %s || dst: %s \n", inet_ntoa(iptr->ip_src), inet_ntoa(iptr->ip_dst));
    }
    if(verbose==3){
        printf(BLEU "\t\tHeader length : %d (%d bytes)\n" NORMAL, iptr->ip_hl, iptr->ip_hl*4);
        printf(BLEU "\t\tVersion : %d\n" NORMAL, iptr->ip_v);
        printf(BLEU "\t\tType of service : %d\n" NORMAL, iptr->ip_tos);
        printf(BLEU "\t\tTotal length : %d\n" NORMAL, ntohs(iptr->ip_len));
        printf(BLEU "\t\tIdentification : 0x%x\n" NORMAL, ntohs(iptr->ip_id));
        printf(BLEU "\t\tFragment offset : 0x%x\n" NORMAL, ntohs(iptr->ip_off));
        printf(BLEU "\t\tTime to live : %d\n" NORMAL, iptr->ip_ttl);
        printf(BLEU "\t\tChecksum : 0x%x\n" NORMAL, ntohs(iptr->ip_sum));
        printf(BLEU "\t\tSource address : %s\n" NORMAL, inet_ntoa(iptr->ip_src));
        printf(BLEU "\t\tDestination address : %s\n" NORMAL, inet_ntoa(iptr->ip_dst));
    }
    switch(iptr->ip_p){
        case IPPROTO_TCP:
            if (verbose==1){
                printf("Application : TCP\n");
            }
            tcp(net_pckt+iptr->ip_hl*4);
            break;
        /*
        case IPPROTO_UDP:
            printf(BLEUCLAIR "\t\tUDP\n" NORMAL);
            udp(net_pckt+iptr->ip_hl*4);
            break;
        case IPPROTO_ICMP:
            printf(BLEUCLAIR "\t\tICMP\n" NORMAL);
            icmp(net_pckt+iptr->ip_hl*4);
            break;
        */
        default:
            break;
    }
}