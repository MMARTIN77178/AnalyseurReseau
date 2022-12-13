#include "bootp.h"

extern int verbose;
extern int size_payload;
extern int size_packet;

void udp(const unsigned char *ippacket){
    size_payload=size_payload-8;
    struct udphdr *udpptr;
    udpptr = (struct udphdr*)ippacket;
    switch(verbose){
        case 1:
            if(size_payload==0){
                printf("Protocol : UDP || Total Length : %d || Info : Bad length for UDP packet\n", size_packet);
            }
            break;
        case 2:
            printf(ROUGE "\t\tUDP || src port : %d || dest port : %d \n" NORMAL, ntohs(udpptr->source), ntohs(udpptr->dest));
            break;
        case 3:
            printf(ROUGE "\t\tUDP || src : %d || dest : %d \n" NORMAL, ntohs(udpptr->source), ntohs(udpptr->dest));
            printf(ROUGE "\t\t\tSource port : %d\n" NORMAL, ntohs(udpptr->source));
            printf(ROUGE "\t\t\tDestination port : %d\n" NORMAL, ntohs(udpptr->dest));
            printf(ROUGE "\t\t\tLength : %d\n" NORMAL, ntohs(udpptr->len));
            printf(ROUGE "\t\t\tChecksum : 0x%x\n" NORMAL, ntohs(udpptr->check));
            printf(ROUGE "\t\t\tUDP Payload : %d\n" NORMAL, size_payload);
            break;
    }
    int prot_trouve=2;
    switch(ntohs(udpptr->source)){
        case 80:
            http(ippacket+8);
            break;
        default:
            prot_trouve--;
            break;
    }
    switch(ntohs(udpptr->dest)){
        case 80:
            http(ippacket+8);
            break;
        default:
            prot_trouve--;
            break;
    }
    if(prot_trouve==0 && verbose ==1){
        printf("Protocol : UDP || Total Length : %d || Info : Unknown protocol\n", size_packet);
    }
    return;
}