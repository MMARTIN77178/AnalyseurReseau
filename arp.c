#include "bootp.h"

extern int verbose;

char *arp_hwtype(uint8_t hwtype){
    char *type;
    switch (hwtype) {
        case HARDWARETYPE_ETHERNET:
            type="Ethernet";
        case HARDWARETYPE_EXP_ETHERNET:
            type="Experimental Ethernet";
        default:
            type="Unknown";
    }
    return type;
}

struct arp_hdr_build()//a faire

void arp(const unsigned char* net_pckt){
    struct arp_hdr *arpptr=(struct arp_hdr*)net_pckt;
    char src[INET_ADDRSTRLEN];
    char dst[INET_ADDRSTRLEN];
    if(verbose>=2){
        //printf("\tARP || src: %s || dst: %s \n", inet_ntoa(arpptr->ar_spa), inet_ntoa(arpptr->ar_tha));
    }
    if(verbose==3){
        printf(BLEU "\t\tHardware type : %s, (%d)\n" NORMAL, arp_hwtype(arpptr->hw_type), arpptr->hw_type);
        printf(BLEU "\t\tProtocol type : %d\n" NORMAL, arpptr->pro_type);
        printf(BLEU "\t\tHardware address length : %d\n" NORMAL, arpptr->hw_len);
        printf(BLEU "\t\tProtocol address length : %d\n" NORMAL, arpptr->pro_len);
        printf(BLEU "\t\tOperation : %d\n" NORMAL, arpptr->op);
        printf(BLEU "\t\tSender hardware address : %s\n" NORMAL, arpptr->sha);
        //printf(BLEU "\t\tSender protocol address : %s\n" NORMAL, inet_ntoa(arpptr->ar_spa));
        //printf(BLEU "\t\tTarget hardware address : %s\n" NORMAL, inet_ntoa(arpptr->ar_tha));
        printf(BLEU "\t\tTarget protocol address : %s\n" NORMAL, arpptr->tpa);
    }
}