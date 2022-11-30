#include "bootp.h"

extern int verbose;

void tcp(const unsigned char *ippacket){
    struct tcphdr *tcpptr=(struct tcphdr*)ippacket;
        if(verbose>=2){
            printf(ROUGE "\tTCP || src port : %d || dst port : %d || seq : %d ||  ack : %d || len : %d\n" NORMAL, ntohs(tcpptr->th_sport), ntohs(tcpptr->th_dport), ntohl(tcpptr->th_seq), ntohl(tcpptr->th_ack), tcpptr->th_off*4);
        }
        if(verbose==3){
            printf(ROUGE "\t\t\tSource port : %d\n" NORMAL, ntohs(tcpptr->th_sport));
            printf(ROUGE "\t\t\tDestination port : %d\n" NORMAL, ntohs(tcpptr->th_dport));
            printf(ROUGE "\t\t\tSequence number : %d\n" NORMAL, ntohl(tcpptr->th_seq));
            printf(ROUGE "\t\t\tAcknowledgement number : %d\n" NORMAL, ntohl(tcpptr->th_ack));
            printf(ROUGE "\t\t\tData offset : %d (%d bytes)\n" NORMAL, tcpptr->doff, tcpptr->doff*4);
            printf(ROUGE "\t\t\tReserved : %d\n" NORMAL, tcpptr->th_x2);
            printf(ROUGE "\t\t\tFlags : %d\n" NORMAL, tcpptr->th_flags);
            printf(ROUGE "\t\t\tWindow : %d\n" NORMAL, ntohs(tcpptr->th_win));
            printf(ROUGE "\t\t\tChecksum : 0x%x\n" NORMAL, ntohs(tcpptr->th_sum));
            printf(ROUGE "\t\t\tUrgent pointer : %d\n" NORMAL, ntohs(tcpptr->th_urp));
    }
}