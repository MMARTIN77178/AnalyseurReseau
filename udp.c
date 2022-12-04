#include "bootp.h"

extern int verbose;

void udp(const unsigned char *ippacket){
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
    return;
}