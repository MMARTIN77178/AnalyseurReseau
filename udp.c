#include "bootp.h"

extern int verbose;
extern int size_payload;

void udp(const unsigned char *ippacket){
    size_payload=size_payload-8;
    struct udphdr *udpptr;
    udpptr = (struct udphdr*)ippacket;
    if(verbose>=2){
        printf(ROUGE "\t\tUDP || src : %d || dest : %d \n" NORMAL, ntohs(udpptr->source), ntohs(udpptr->dest));
    }
    if(verbose==3){
        printf(ROUGE "\t\t\tSource port : %d\n" NORMAL, ntohs(udpptr->source));
        printf(ROUGE "\t\t\tDestination port : %d\n" NORMAL, ntohs(udpptr->dest));
        printf(ROUGE "\t\t\tLength : %d\n" NORMAL, ntohs(udpptr->len));
        printf(ROUGE "\t\t\tChecksum : 0x%x\n" NORMAL, ntohs(udpptr->check));
    }
    switch(ntohs(udpptr->source)){
        case 80:
            http(ippacket+8);
            break;
        default:
            break;
    }
    return;
}