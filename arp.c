#include "bootp.h"

extern int verbose;
char ip_str[16];

char *arp_hwtype(uint16_t hwtype){
    char *type;
    switch (hwtype) {
        case ARPHRD_NETROM:
            type = "NET/ROM";
            break;
        case ARPHRD_ETHER:
            type="Ethernet";
            break;
        case ARPHRD_EETHER:
            type="Experimental Ethernet";
            break;
        case ARPHRD_AX25:
            type="AX.25 Level 2";
            break;
        case ARPHRD_PRONET:
            type="PROnet token ring";
            break;
        case ARPHRD_CHAOS:
            type="Chaosnet";
            break;
        case ARPHRD_IEEE802:
            type="IEEE 802.2 Ethernet/TR/TB";
            break;
        case ARPHRD_ARCNET:
            type="ARCnet";
            break;
        case ARPHRD_APPLETLK:
            type="APPLEtalk";
            break;
        case ARPHRD_DLCI:
            type="Frame Relay DLCI";
            break;
        case ARPHRD_ATM:
            type="ATM";
            break;
        case ARPHRD_METRICOM:
            type="Metricom STRIP (new IANA id)";
            break;
        case ARPHRD_EUI64:
            type="EUI-64";
            break;
        case ARPHRD_IEEE1394:
            type="IEEE 1394 IPv4 - RFC 2734";
            break;
        case ARPHRD_INFINIBAND:
            type="InfiniBand";
            break;
        default:
            type="Autre";
            break;
    }
    return type;
}

char *arp_prot(uint16_t pro){
    char *protocole;
    switch (pro) {
        case ETHERTYPE_IP:
            protocole = "IPv4";
            break;
        case ETHERTYPE_IPV6:
            protocole = "IPv6";
            break;
        default:
            protocole = "Autre";
            break;
    }
    return protocole;
}

char *arp_opcode(uint16_t opcode){
    char *op;
    switch (opcode) {
        case ARPOP_REQUEST:
            op = "Request";
            break;
        case ARPOP_REPLY:
            op = "Reply";
            break;
        case ARPOP_RREQUEST:
            op = "RARP Request";
            break;
        case ARPOP_RREPLY:
            op = "RARP Reply";
            break;
        case ARPOP_InREQUEST:
            op = "InARP Request";
            break;
        case ARPOP_InREPLY:
            op = "InARP Reply";
            break;
        case ARPOP_NAK:
            op = "NAK";
            break;
        default:
            op = "Autre";
            break;
    }
    return op;
}

char *get_ip_addr_arp(uint8_t *ip){
    sprintf(ip_str, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    return ip_str;
}   



void arp(const unsigned char* net_pckt){
    struct ether_arp *arpptr=(struct ether_arp*)net_pckt;
    switch(verbose){
        case 1:
            printf("Source : %s || Destination : Broadcast || Protocol : ARP || Length : 60 || ", get_mac_addr(arpptr->arp_sha));
            switch(ntohs(arpptr->ea_hdr.ar_op)){
                case ARPOP_REQUEST:
                    printf("Who has %s ? Tell %s\n", get_ip_addr_arp(arpptr->arp_tpa), get_ip_addr_arp(arpptr->arp_spa));
                    break;
                case ARPOP_REPLY:
                    printf("%s is at %s\n", get_ip_addr_arp(arpptr->arp_spa), get_mac_addr(arpptr->arp_sha));
                    break;
                case ARPOP_RREQUEST:
                    printf("Who is %s ? Tell %s\n", get_mac_addr(arpptr->arp_tha), get_mac_addr(arpptr->arp_sha));
                    break;
                case ARPOP_RREPLY:
                    printf("%s is at %s\n", get_mac_addr(arpptr->arp_tha), get_mac_addr(arpptr->arp_sha));
                    break;
            }
            break;
        case 2:
            printf(BLEU "\tARP || src: %s || (%s)\n" NORMAL, get_mac_addr(arpptr->arp_sha), arp_opcode(ntohs(arpptr->ea_hdr.ar_op)));
            break;
        case 3:
            printf(BLEU "\tARP || src: %s || (%s)\n" NORMAL, get_mac_addr(arpptr->arp_sha), arp_opcode(ntohs(arpptr->ea_hdr.ar_op)));
            printf(BLEU "\t\tHardware type : %s\n" NORMAL, arp_hwtype(ntohs(arpptr->ea_hdr.ar_hrd)));
            printf(BLEU "\t\tProtocol type : %s\n" NORMAL, arp_prot(ntohs(arpptr->ea_hdr.ar_pro)));
            printf(BLEU "\t\tHardware address length : %d\n" NORMAL, arpptr->ea_hdr.ar_hln);
            printf(BLEU "\t\tProtocol address length : %d\n" NORMAL, arpptr->ea_hdr.ar_pln);
            printf(BLEU "\t\tOperation : %s, (%d)\n" NORMAL, arp_opcode(ntohs(arpptr->ea_hdr.ar_op)), ntohs(arpptr->ea_hdr.ar_op));
            printf(BLEU "\t\tSender hardware address : %s\n" NORMAL, get_mac_addr(arpptr->arp_sha));
            printf(BLEU "\t\tSender protocol address : %s\n" NORMAL, get_ip_addr_arp(arpptr->arp_spa));
            printf(BLEU "\t\tTarget hardware address : %s\n" NORMAL, get_mac_addr(arpptr->arp_tha));
            printf(BLEU "\t\tTarget protocol address : %s\n" NORMAL, get_ip_addr_arp(arpptr->arp_tpa));
            break;
    }
}