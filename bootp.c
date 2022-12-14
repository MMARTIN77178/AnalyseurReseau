#include "bootp.h"

extern int verbose;
extern int size_payload;
extern int size_packet;

void bootp(const unsigned char *packet){
    struct bootphdr *bootpptr=(struct bootphdr*)packet;
    if(bootpptr->magic_cookie == 63825363){
        dhcp(packet);
    }
    else{
        switch(verbose){
            
        }
    }
}