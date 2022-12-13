#include "bootp.h"

extern int verbose;
extern int size_payload;
extern int size_packet;

void http(const unsigned char *packet){
    switch(verbose){
        case 1:
            if(size_payload>0){
                printf("Protocol : HTTP || Total Length : %d ||", size_packet);
                int i=0;
                while(i<size_payload-1 && packet[i] != '\r' && packet[i+1] != '\n'){
                    printf("%c", packet[i]);
                    i++;
                }
                printf("\n");
            }
            break;
        case 2:
            printf(YELLOW "\t\t\t\tHyperText Transfer Protocol\n" NORMAL);
            break;
        case 3:
            printf(YELLOW "\t\t\t\tHyperText Transfer Protocol\n" NORMAL);
            if(size_payload==0){
            printf(YELLOW "No more data\n" NORMAL);
            }
            else{
                int cnt=0;
                for(int i = 0; i < size_payload-1; i++) {
                    if(cnt==0){
                    printf(YELLOW "\t\t\t\t\t" NORMAL);
                    }
                    if(packet[i] == '\r' && packet[i+1] == '\n'){
                        printf(YELLOW "\n" NORMAL);
                        cnt=0;
                        i++;
                    }
                    else{
                        printf(YELLOW "%c" NORMAL, packet[i]);
                        cnt++;
                    }
  		        }
            }
            break;
    }
}