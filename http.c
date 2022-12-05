#include "bootp.h"

extern int verbose;
extern int size_payload;

void http(const unsigned char *packet){
    int i=0;
    printf(YELLOW "\t\t\t\tHyperText Transfer Protocol\n" NORMAL);
    printf(YELLOW "\t\t\t\t\tPayload size : %d\n" NORMAL, size_payload);
    if(size_payload==0){
        printf(YELLOW "\t\t\t\t\tNo more data\n" NORMAL);
    }
    else{
        while(i < size_payload){
  			if(packet[i] != '\0'){
  				printf("%c", packet[i]);
  			}
  			else{
  				printf(".");
  			}
  			i++;
  		}
    }
}