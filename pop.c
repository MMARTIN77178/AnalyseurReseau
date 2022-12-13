#include "bootp.h"
#include <ctype.h>

extern int verbose;
extern int size_payload;
extern int size_packet;

void pop_response(const unsigned char *packet){
    int i=0;
    if(packet[0]=='+' && packet[1]=='O' && packet[2]=='K'){
        printf(YELLOW "\t\t\t\t\t\tresponse indicator: +OK\n" NORMAL);
        printf(YELLOW "\t\t\t\t\t\tresponse description: " NORMAL);
        i=4;
        while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
            printf(YELLOW "%c" NORMAL, packet[i]);
            i++;
        }
        printf("\n");
    }
    else{
        printf(YELLOW "\t\t\t\t\t\tData fragment\n" NORMAL);
    }
    
}

void pop_request(const unsigned char *packet){
    int i=0;
    int j=0;
    while(i<size_payload-1){
        printf("\t\t\t\t\t");
        while(j<size_payload-1 && packet[j]!='\r' && packet[j+1]!='\n'){
            printf(YELLOW "%c" NORMAL, packet[j]);
            j++;
        }
        if(packet[j]=='\r' && packet[j+1]=='\n'){
            printf(YELLOW "\\r\\n\n" NORMAL);
            j+=2;
        }
        while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
            printf(YELLOW "\t\t\t\t\t\trequest indicator: " NORMAL);
            while(i<size_payload && packet[i]!=' '){
                printf(YELLOW "%c" NORMAL, packet[i]);
                i++;
            }
            i++;
            if(i<size_payload-1){
                printf(YELLOW "\n\t\t\t\t\t\trequest parameter: " NORMAL);
                while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                    printf(YELLOW "%c" NORMAL, packet[i]);
                    i++;
                }
                printf("\n");
            }
            i++;
        }
    }
}

void pop(const unsigned char *packet, bool is_response){
    if(size_payload==0){
        return;
    }
    switch(verbose){
        case 1:
            if(size_payload>0){
                printf("Protocol : POP3 || Total Length : %d || \n", size_packet);
            }
            if(is_response){
                printf("S:");
                if(size_payload>=4 && packet[0]=='+' && packet[1]=='O' && packet[2]=='K'){
                    printf("+OK");
                    int i=4;
                    while (i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                        printf("%c", packet[i]);
                        i++;
                    }
                printf("\n");
                }
                else{
                    printf("Data fragment, size: %d bytes\n", size_payload);
                }
            }
            else{
                printf("C:");
                int i=0;
                while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                    printf("%c", packet[i]);
                    i++;
                }
                printf("\n");
            }
            break;
        case 2:
            if(is_response){
                printf(YELLOW "\t\t\t\tPost Office Protocol, Response\n" NORMAL);
            }
            else{
                printf(YELLOW "\t\t\t\tPost Office Protocol, Command\n" NORMAL);
            }
            break;
        case 3:
            printf(YELLOW "\t\t\t\tPost Office Protocol\n" NORMAL);
            if(size_payload==0){
                printf(YELLOW "No more data\n" NORMAL);
            }
            if(is_response && size_payload>=4){
                pop_response(packet);
            }
            else if(!is_response && size_payload>=5){
                pop_request(packet);
            }
            break;
        default:
            break;
    }
}