#include "bootp.h"

extern int verbose;

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
        case;
    }
    return type;
}



void arp(const unsigned char* net_pckt){
    struct ether_arp *arpptr=(struct ether_arp*)net_pckt;
    if(verbose>=2){
        //printf("\tARP || src: %s || dst: %s \n", arpptr->ar_sha, arpptr->ar_tha);
    }
    if(verbose==3){
        printf(BLEU "\t\tHardware type : %s\n" NORMAL, arp_hwtype(ntohs(arpptr->ea_hdr.ar_hrd)));
        printf(BLEU "\t\tProtocol type : %d\n" NORMAL, arpptr->ea_hdr.ar_pro);
        printf(BLEU "\t\tHardware address length : %d\n" NORMAL, arpptr->ea_hdr.ar_hln);
        printf(BLEU "\t\tProtocol address length : %d\n" NORMAL, arpptr->ea_hdr.ar_pln);
        printf(BLEU "\t\tOperation : %d\n" NORMAL, arpptr->ea_hdr.ar_op);
        printf(BLEU "\t\tSender hardware address : %s\n" NORMAL, arpptr->arp_sha);
        printf(BLEU "\t\tSender protocol address : %s\n" NORMAL, arpptr->arp_spa);
        printf(BLEU "\t\tTarget hardware address : %s\n" NORMAL, arpptr->arp_tha);
        printf(BLEU "\t\tTarget protocol address : %s\n" NORMAL, arpptr->arp_tpa);
    }
}