#include "bootp.h"
#include <ctype.h>

extern int verbose;
extern int size_payload;

void pop(const unsigned char *packet, bool is_response) {
	if(size_payload==0){
        return;
    }
    else{
        const char *payload = (const char *) packet;
        if(verbose==1){
            printf("POP 3");
            switch(is_response){
                case 0:
                    printf("S :");
                    break;
                case 1:
                    printf("C :");
                    break;
            }
        }
        if(verbose>=2){
            printf(YELLOW "\t\t\t\t\t\tPOP 3: " NORMAL);
            int a=4;
            int i=0;
            int cnt=1;
            while(i < size_payload-1 && cnt != 0) {
                    if(packet[i] == '\r' && packet[i+1] == '\n'){
                        printf(YELLOW "\\r\\n\n" NORMAL);
                        i++;
                        cnt=0;
                    }
                    else{
                        printf(YELLOW "%c" NORMAL, packet[i]);
                    }
                    i++;
            }
        }
    }
    
}