#include "bootp.h"
#include <ctype.h>

extern int verbose;
extern int size_payload;
extern int size_packet;

void imap(const unsigned char *packet, bool is_response){
    if(size_payload==0){
        return;
    }
    switch(verbose){
        case 1:
            if(size_payload>0){
                printf("Protocol : IMAP || Total Length : %d || ", size_packet);
            }
            if(is_response){
                printf("Response: ");
                int i=0;
                int nb_ligne=0;
                //On affiche uniquement la ligne ayant un tag
                if(packet[0]=='*'){
                    while(i<size_payload-2 && packet[i]!='\r' && packet[i+1]!='\n' && packet[i+2]=='*'){
                        if(packet[i]!='\r' && packet[i+1]!='\n'){
                            nb_ligne++;
                        }
                        i++;
                    }
                    if(nb_ligne==1){
                        i=0;
                    }
                    if(i<size_payload-1){
                        while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                            printf("%c" , packet[i]);
                            i++;
                        }
                    }
                }
                else{
                    while (i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                        printf("%c", packet[i]);
                        i++;
                    }
                }
                printf("\n");
            }
            else{
                printf("Request : ");
                int i=0;
                //On affiche uniquement la ligne ayant un tag
                if(packet[0]=='*'){
                    while(i<size_payload-2 && packet[i]!='\r' && packet[i+1]!='\n' && packet[i+2]=='*'){
                        i++;
                    }
                    if(i<size_payload-1){
                        while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                            printf(YELLOW"%c" NORMAL, packet[i]);
                            i++;
                        }
                    }
                }
                else{
                    while (i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                        printf("%c", packet[i]);
                        i++;
                    }
                }
                printf("\n");
            }
            break;
        case 2:
            if(is_response){
                printf(YELLOW "\t\t\t\tInternet Message Access Protocol, Response\n" NORMAL);
            }
            else{
                printf(YELLOW "\t\t\t\tInternet Message Access Protocol, Request\n" NORMAL);
            }
            break;
        case 3:
            printf(YELLOW "\t\t\t\tInternet Message Access Protocol\n" NORMAL);
            if(size_payload==0){
                printf(YELLOW "No more data\n" NORMAL);
            }
            else{
                int i=0;
                while(i<size_payload-1){
                    printf(YELLOW "\t\t\t\t\t Line : " NORMAL);
                    while(i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                        printf(YELLOW"%c" NORMAL, packet[i]);
                        i++;
                    }
                    if(packet[i]=='\r' && packet[i+1]=='\n'){
                        printf("\n");
                    }
                    i++;
                }
            }
            break;
    }
}