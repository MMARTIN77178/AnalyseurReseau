#include "bootp.h"

extern int verbose;
extern int size_payload;

void http(const unsigned char *packet){
    printf(YELLOW "\t\t\t\tHyperText Transfer Protocol\n" NORMAL);
    printf(YELLOW "Payload size : %d\n" NORMAL, size_payload);
    if(size_payload==0){
        printf(YELLOW "No more data\n" NORMAL);
    }
    else{
        int cnt=0;
         for(int i = 0; i < size_payload; i++) {
            if(cnt==0){
                printf(YELLOW "\t" NORMAL);
            }
            if(packet[i] == '\r' && packet[i+1] == '\n'){
                printf(YELLOW "\n" NORMAL);
                cnt=0;
                i++;
            }
            else{
                printf("%c", packet[i]);
                cnt++;
            }
  		}
    }

}