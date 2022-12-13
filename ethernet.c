#include "bootp.h"
#include <string.h>

extern int verbose;
extern int size_payload;
char mac_addr_str[18];
int size_packet=0;

char src[INET6_ADDRSTRLEN];
char dst[INET6_ADDRSTRLEN];

char * get_mac_addr(u_char *mac_addr){
    sprintf(mac_addr_str, "%02x:%02x:%02x:%02x:%02x:%02x", mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);    
    return mac_addr_str;
}

void ethernet(u_char *user_args, const struct pcap_pkthdr* packet_header, const u_char *packet){
    struct ether_header *ethptr; 
    ethptr = (struct ether_header*)packet;
    const u_char *net_pckt=(const unsigned char *)packet+14;

    char *ethdst=get_mac_addr(ethptr->ether_dhost);
    char *ethsrc=get_mac_addr(ethptr->ether_shost);
    //idée : implémenter fonction pour récupérer Organizationally Unique Identifier
    switch(verbose){
        case 1:
            break;
        case 2:
            printf("Ethernet || src: %s || dst: %s\n", ethsrc, ethdst);
            break;
        case 3:
            printf("Ethernet || src: %s || dst: %s ||\n", ethsrc, ethdst);
            printf("\tSource : %s\n", ethsrc);
            printf("\tDestination : %s\n", ethdst);
            printf("\tType : 0x0%x\n", ntohs(ethptr->ether_type));
            break;
    }
    switch(ntohs(ethptr->ether_type)){
        case ETHERTYPE_IP:
            ipv4(net_pckt);
            break;
        case ETHERTYPE_IPV6:
            ipv6(net_pckt);
            break;
        case ETHERTYPE_ARP:
            arp(net_pckt);
            break;
        case ETHERTYPE_REVARP:
            break;
        case ETHERTYPE_VLAN:
            break;
        case ETHERTYPE_LOOPBACK:
            break;
        case ETHERTYPE_PUP:
            break;
        case ETHERTYPE_SPRITE:
            break;
        case ETHERTYPE_IPX:
            break;
        case ETHERTYPE_AT:
            break;
        case ETHERTYPE_AARP:
            break;
        default:
            break;
    }
}

void ipv4(const unsigned char* net_pckt){
    struct ip *ipptr=(struct ip*)net_pckt;
    size_payload=ntohs(ipptr->ip_len)-ipptr->ip_hl*4;
    size_packet=ntohs(ipptr->ip_len)+14;
    switch(verbose){
        case 1:
            printf("src: %s || dst: %s || ", inet_ntoa(ipptr->ip_src), inet_ntoa(ipptr->ip_dst));
            if(size_payload==0){
                printf("Protocol : IPv4 || Total Length : %d\n", size_packet);
            }
            break;
        case 2:
            printf(BLEU "\tIPv4 || src: %s || dst: %s\n", inet_ntoa(ipptr->ip_src), inet_ntoa(ipptr->ip_dst));
            break;
        case 3:
            printf(BLEU "\tIPv4 || src: %s || dst: %s\n", inet_ntoa(ipptr->ip_src), inet_ntoa(ipptr->ip_dst));
            printf(BLEU "\t\tHeader length : %d (%d bytes)\n" NORMAL, ipptr->ip_hl, ipptr->ip_hl*4);
            printf(BLEU "\t\tVersion : %d\n" NORMAL, ipptr->ip_v);
            printf(BLEU "\t\tType of service : %d\n" NORMAL, ipptr->ip_tos);
            printf(BLEU "\t\tTotal length : %d\n" NORMAL, ntohs(ipptr->ip_len));
            printf(BLEU "\t\tIdentification : 0x%x\n" NORMAL, ntohs(ipptr->ip_id));
            printf(BLEU "\t\tFragment offset : 0x%x\n" NORMAL, ntohs(ipptr->ip_off));
            printf(BLEU "\t\tTime to live : %d\n" NORMAL, ipptr->ip_ttl);
            printf(BLEU "\t\tChecksum : 0x%x\n" NORMAL, ntohs(ipptr->ip_sum));
            printf(BLEU "\t\tSource address : %s\n" NORMAL, inet_ntoa(ipptr->ip_src));
            printf(BLEU "\t\tDestination address : %s\n" NORMAL, inet_ntoa(ipptr->ip_dst));
            break;
    }
    switch(ipptr->ip_p){
        case IPPROTO_TCP:
            tcp(net_pckt+ipptr->ip_hl*4);
            break;        
        case IPPROTO_UDP:
            udp(net_pckt+ipptr->ip_hl*4);
            break;
         /*
        case IPPROTO_ICMP:
            printf(BLEUCLAIR "\t\tICMP\n" NORMAL);
            icmp(net_pckt+iptr->ip_hl*4);
            break;
        */
        default:
            if(verbose==1){
                printf("Protocol : IPv4 || Total Length : %d\n", size_packet);
            }
            break;
    }
}

void ipv6(const unsigned char* net_pckt){
    struct ip6_hdr *ip6ptr=(struct ip6_hdr*)net_pckt;
    size_packet=ntohs(ip6ptr->ip6_plen)+54;
    size_payload=ntohs(ip6ptr->ip6_plen);
    switch(verbose){
        case 1:
            printf("src: %s || dst: %s || ", inet_ntop(AF_INET6, &ip6ptr->ip6_src, src, INET6_ADDRSTRLEN), inet_ntop(AF_INET6, &ip6ptr->ip6_dst, dst, INET6_ADDRSTRLEN));
            if(size_payload==0){
                printf("Protocol : IPv6 || Total Length : %d\n", size_packet);
            }
            break;
        case 2:
            printf(BLEU "\tIPv6 || src: %s || dst: %s \n" NORMAL, inet_ntop(AF_INET6, &ip6ptr->ip6_src, src, INET6_ADDRSTRLEN), inet_ntop(AF_INET6, &ip6ptr->ip6_dst, dst, INET6_ADDRSTRLEN));
            break;
        case 3:
            printf(BLEU "\tIPv6 || src: %s || dst: %s \n" NORMAL, src, dst);
            printf(BLEU "\t\tVersion : %d\n" NORMAL, ip6ptr->ip6_vfc>>4);
            printf(BLEU "\t\tTraffic class : 0x%x\n" NORMAL, ip6ptr->ip6_flow>>20);
            printf(BLEU "\t\tPayload length : %d\n" NORMAL, ntohs(ip6ptr->ip6_plen));
            printf(BLEU "\t\tNext header : %d\n" NORMAL, ip6ptr->ip6_nxt);
            printf(BLEU "\t\tHop limit : %d\n" NORMAL, ip6ptr->ip6_hlim);
            printf(BLEU "\t\tSource address : %s\n" NORMAL, src);
            printf(BLEU "\t\tDestination address : %s\n" NORMAL, dst);
            break;
    }
    switch(ip6ptr->ip6_nxt){
        case IPPROTO_TCP:
            tcp(net_pckt+40);
            break;
        
        case IPPROTO_UDP:
            udp(net_pckt+40);
            break;
        case IPPROTO_HOPOPTS:
            printf("Protocol : IPv6\n");
            //A faire
            /*
            if (verbose==1 && net_packet+){
                printf("Protocol : ICMPv6\n");
            }
            */
            break;
       default:
            if(verbose==1){
                printf("Protocol : IPv6\n");
            }
            break;
    }
}