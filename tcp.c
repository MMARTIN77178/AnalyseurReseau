#include "bootp.h"

extern int verbose;

void print_tcp_flags(u_char flags){
    if(flags & 0x01){
        printf(ROUGE "FIN | " NORMAL);
    }
    if(flags & 0x02){
        printf(ROUGE "SYN | " NORMAL);
    }
    if(flags & 0x04){
        printf(ROUGE "RST | " NORMAL);
    }
    if(flags & 0x08){
        printf(ROUGE "PSH | " NORMAL);
    }
    if(flags & 0x10){
        printf(ROUGE "ACK | " NORMAL);
    }
    if(flags & 0x20){
        printf(ROUGE "URG | " NORMAL);
    }
    if(flags & 0x40){
        printf(ROUGE "ECE | " NORMAL);
    }
    if(flags & 0x80){
        printf(ROUGE "CWR | " NORMAL);
    }
}


//a faire : traiter le flag avec le 0xXXX 
void tcp(const unsigned char *ippacket){
    struct tcphdr *tcpptr=(struct tcphdr*)ippacket;

    if(verbose>=2){
        printf(ROUGE "\t\tTCP || src port : %d || dst port : %d || seq : %.4x ||  ack : %d || len : %d\n" NORMAL,
         ntohs(tcpptr->th_sport), ntohs(tcpptr->th_dport), ntohl(tcpptr->th_seq), ntohl(tcpptr->th_ack), tcpptr->th_off*4);
    }
    if(verbose==3){
        printf(ROUGE "\t\t\tSource port : %d\n" NORMAL, ntohs(tcpptr->th_sport));
        printf(ROUGE "\t\t\tDestination port : %d\n" NORMAL, ntohs(tcpptr->th_dport));
        printf(ROUGE "\t\t\tSequence number : %u\n" NORMAL, ntohl(tcpptr->th_seq));
        printf(ROUGE "\t\t\tAcknowledgement number : %u\n" NORMAL, ntohl(tcpptr->th_ack));
        printf(ROUGE "\t\t\tHeader Length : %d (%d bytes)\n" NORMAL, (unsigned int)tcpptr->doff, (unsigned int)tcpptr->doff*4);
        printf(ROUGE "\t\t\tFlags : " NORMAL);
        print_tcp_flags(tcpptr->th_flags);
        printf("\n");
        printf(ROUGE "\t\t\t\t.... ..%d. .... :  Urgent (%s)\n" NORMAL, (unsigned int)tcpptr->urg, SET((unsigned int)tcpptr->urg));
        printf(ROUGE "\t\t\t\t.... ...%d .... :  Acknowledgement (%s)\n" NORMAL, (unsigned int)tcpptr->ack, SET((unsigned int)tcpptr->ack));
        printf(ROUGE "\t\t\t\t.... .... %d... :  Push (%s)\n" NORMAL, (unsigned int)tcpptr->psh, SET((unsigned int)tcpptr->psh));
        printf(ROUGE "\t\t\t\t.... .... .%d.. :  Reset (%s)\n" NORMAL, (unsigned int)tcpptr->rst, SET((unsigned int)tcpptr->rst));
        printf(ROUGE "\t\t\t\t.... .... ..%d. :  Synchronize (%s)\n" NORMAL, (unsigned int)tcpptr->syn, SET((unsigned int)tcpptr->syn));
        printf(ROUGE "\t\t\t\t.... .... ...%d :  Finish (%s)\n" NORMAL, (unsigned int)tcpptr->fin, SET((unsigned int)tcpptr->fin));
        printf(ROUGE "\t\t\tWindow : %d\n" NORMAL, ntohs(tcpptr->window));
        printf(ROUGE "\t\t\tChecksum : 0x%x\n" NORMAL, ntohs(tcpptr->check));
        printf(ROUGE "\t\t\tUrgent pointer : %d\n" NORMAL, ntohs(tcpptr->urg_ptr));
    }
    switch(ntohs(tcpptr->th_sport)){
        case 53:
            dns(ippacket+tcpptr->th_off*4);
            break;
        /*
        case 67:
            bootp(ippacket+tcpptr->th_off*4);
            break;
        */
        default:
            break;
    }
}