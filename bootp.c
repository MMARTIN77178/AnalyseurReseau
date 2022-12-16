#include "bootp.h"

extern int verbose;
extern int size_payload;
extern int size_packet;

char mac_address[18];

int pos; //position dans les options dhcp

void bootp_message_type(int bootp_op){
    switch(bootp_op){
        case 1:
            printf("Boot Request");
            break;
        case 2:
            printf("Boot Reply");
            break;
        default:
            printf("Unknown");
            break;
    }
    return;
}

char *bootp_hwtype(uint8_t hwtype){
    char *type;
    switch (hwtype) {
        case ARPHRD_NETROM:
            type = "NET/ROM";
            break;
        case ARPHRD_ETHER:
            type="Ethernet";
            break;
        case ARPHRD_EETHER:
            type="Experimental Ethernet";
            break;
        case ARPHRD_AX25:
            type="AX.25 Level 2";
            break;
        case ARPHRD_PRONET:
            type="PROnet token ring";
            break;
        case ARPHRD_CHAOS:
            type="Chaosnet";
            break;
        case ARPHRD_IEEE802:
            type="IEEE 802.2 Ethernet/TR/TB";
            break;
        case ARPHRD_ARCNET:
            type="ARCnet";
            break;
        case ARPHRD_APPLETLK:
            type="APPLEtalk";
            break;
        case ARPHRD_DLCI:
            type="Frame Relay DLCI";
            break;
        case ARPHRD_ATM:
            type="ATM";
            break;
        case ARPHRD_METRICOM:
            type="Metricom STRIP (new IANA id)";
            break;
        case ARPHRD_EUI64:
            type="EUI-64";
            break;
        case ARPHRD_IEEE1394:
            type="IEEE 1394 IPv4 - RFC 2734";
            break;
        case ARPHRD_INFINIBAND:
            type="InfiniBand";
            break;
        default:
            type="Autre";
            break;
    }
    return type;
}



void dhcp_option(const unsigned char *packet){
    if(verbose == 3){
        switch(packet[0]){
            case 1:
                printf(YELLOW "\t\t\t\t\tOption : (1) Subnet Mask  (%d.%d.%d.%d)\n" NORMAL, packet[2], packet[3], packet[4], packet[5]);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tSubnet Mask : %d.%d.%d.%d\n" NORMAL, packet[2], packet[3], packet[4], packet[5]);
                pos+=packet[1]+2;
                break;
            case 3:
                printf(YELLOW "\t\t\t\t\tOption : (3) Router\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tRouter : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 4:
                printf(YELLOW "\t\t\t\t\tOption : (4) Time Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tTime Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 5:
                printf(YELLOW "\t\t\t\t\tOption : (5) Name Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tName Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 6:
                printf(YELLOW "\t\t\t\t\tOption : (6) Domain Name Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tDomain Name Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 7:
                printf(YELLOW "\t\t\t\t\tOption : (7) Log Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tLog Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 8:
                printf(YELLOW "\t\t\t\t\tOption : (8) Cookie Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tCookie Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 9:
                printf(YELLOW "\t\t\t\t\tOption : (9) LPR Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tLPR Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 10:
                printf(YELLOW "\t\t\t\t\tOption : (10) Impress Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tImpress Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 11:
                printf(YELLOW "\t\t\t\t\tOption : (11) Resource Location Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "\t\t\t\t\t\tRLP Server : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 12 :
                printf(YELLOW "\t\t\t\t\tOption : (12) Host Name\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tHost Name : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 13:
                printf(YELLOW "\t\t\t\t\tOption : (13) Boot File Size\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tBoot File Size : %d\n" NORMAL, packet[2]<<8 | packet[3]);
                pos+=packet[1]+2;
                break;
            case 14:
                printf(YELLOW "\t\t\t\t\tOption : (14) Merit Dump File\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tMerit Dump File : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 15:
                printf(YELLOW "\t\t\t\t\tOption : (15) Domain Name\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tDomain Name : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 16:
                printf(YELLOW "\t\t\t\t\tOption : (16) Swap Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tSwap Server : %d.%d.%d.%d\n" NORMAL, packet[2], packet[3], packet[4], packet[5]);
                pos+=packet[1]+2;
                break;
            case 17:
                printf(YELLOW "\t\t\t\t\tOption : (17) Root Path\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tRoot Path : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 18:
                printf(YELLOW "\t\t\t\t\tOption : (18) Extensions Path\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tExtensions Path : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 19:
                printf(YELLOW "\t\t\t\t\tOption : (19) IP Forwarding\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tIP Forwarding : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 20:
                printf(YELLOW "\t\t\t\t\tOption : (20) Non-Local Source Routing\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNon-Local Source Routing : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 21:
                printf(YELLOW "\t\t\t\t\tOption : (21) Policy Filter\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tPolicy Filter : " NORMAL);
                for(int j=2; j<packet[1]; j+=8){
                    printf(YELLOW "\t\t\t\t\t\tPolicy Filter : " NORMAL);
                    printf(YELLOW "\t\t\t\t\t\t\tAdress : %d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                    printf(YELLOW "\t\t\t\t\t\t\tMask : %d.%d.%d.%d\n" NORMAL, packet[j+4], packet[j+5], packet[j+6], packet[j+7]);
                }
                pos+=packet[1]+2;
                break;
            case 22:
                printf(YELLOW "\t\t\t\t\tOption : (22) Maximum Datagram Reassembly Size\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tMaximum Datagram Reassembly Size : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]*256+packet[3]);
                pos+=packet[1]+2;
                break;
            case 23:
                printf(YELLOW "\t\t\t\t\tOption : (23) Default IP Time-to-live\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tDefault IP Time-to-live : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]);
                pos+=packet[1]+2;
                break;
            case 24:
                printf(YELLOW "\t\t\t\t\tOption : (24) Path MTU Aging Timeout\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tPath MTU Aging Timeout : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]*256+packet[3]);
                pos+=packet[1]+2;
                break;
            case 25:
                printf(YELLOW "\t\t\t\t\tOption : (25) Path MTU Plateau Table\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tPath MTU Plateau Table : " NORMAL);
                for(int j=2; j<packet[1]; j+=2){
                    printf(YELLOW "%d\n" NORMAL, packet[j+2]*256+packet[j+3]);
                }
                pos+=packet[1]+2;
                break;    
            case 26:
                printf(YELLOW "\t\t\t\t\tOption : (26) Interface MTU\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tInterface MTU : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]*256+packet[3]);
                pos+=packet[1]+2;
                break;
            case 27:
                printf(YELLOW "\t\t\t\t\tOption : (27) All Subnets are Local\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tAll Subnets are Local : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 28:
                printf(YELLOW "\t\t\t\t\tOption : (28) Broadcast Address\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tBroadcast Address : " NORMAL);
                printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[2], packet[3], packet[4], packet[5]);
                pos+=packet[1]+2;
                break;
            case 29:
                printf(YELLOW "\t\t\t\t\tOption : (29) Perform Mask Discovery\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tPerform Mask Discovery : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 30:
                printf(YELLOW "\t\t\t\t\tOption : (30) Mask Supplier\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tMask Supplier : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 31:
                printf(YELLOW "\t\t\t\t\tOption : (31) Perform Router Discovery\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tPerform Router Discovery : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 32:
                printf(YELLOW "\t\t\t\t\tOption : (32) Router Solicitation Address\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tRouter Solicitation Address : " NORMAL);
                printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[2], packet[3], packet[4], packet[5]);
                pos+=packet[1]+2;
                break;
            case 33:
                printf(YELLOW "\t\t\t\t\tOption : (33) Static Route\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tStatic Route : " NORMAL);
                for(int j=2; j<packet[1]; j+=8){
                    printf(YELLOW "%d.%d.%d.%d/%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3], packet[j+4], packet[j+5], packet[j+6], packet[j+7]);
                }
                pos+=packet[1]+2;
                break;
            case 34:
                printf(YELLOW "\t\t\t\t\tOption : (34) Trailer Encapsulation\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tTrailer Encapsulation : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 35:
                printf(YELLOW "\t\t\t\t\tOption : (35) ARP Cache Timeout\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tARP Cache Timeout : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]*256+packet[2]);
                pos+=packet[1]+2;
                break;
            case 36:   
                printf(YELLOW "\t\t\t\t\tOption : (36) Ethernet Encapsulation\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tEthernet Encapsulation : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 37:
                printf(YELLOW "\t\t\t\t\tOption : (37) TCP Default TTL\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tTCP Default TTL : %d\n" NORMAL, packet[2]);
                pos+=packet[1]+2;
                break;
            case 38:
                printf(YELLOW "\t\t\t\t\tOption : (38) TCP Keepalive Interval\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tTCP Keepalive Interval : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]<<24 | packet[3]<<16 | packet[4]<<8 | packet[5]);
                pos+=packet[1]+2;
                break;
            case 39:
                printf(YELLOW "\t\t\t\t\tOption : (39) TCP Keepalive Garbage\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tTCP Keepalive Garbage : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "Disabled\n" NORMAL);
                }
                else{
                    printf(YELLOW "Enabled\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 40:
                printf(YELLOW "\t\t\t\t\tOption : (40) Network Information Service Domain\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetwork Information Service Domain : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf(YELLOW "\n" NORMAL);
                pos+=packet[1]+2;
                break;
            case 41:
                printf(YELLOW "\t\t\t\t\tOption : (41) Network Information Servers\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetwork Information Servers : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 42:
                printf(YELLOW "\t\t\t\t\tOption : (42) Network Time Protocol Servers\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetwork Time Protocol Servers : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 43:
                printf(YELLOW "\t\t\t\t\tOption : (43) Vendor Specific Information\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tVendor Specific Information : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf(YELLOW "\n" NORMAL);
                pos+=packet[1]+2;
                break;
            case 44:
                printf(YELLOW "\t\t\t\t\tOption : (44) NetBIOS over TCP/IP Name Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetBIOS over TCP/IP Name Server : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 45:
                printf(YELLOW "\t\t\t\t\tOption : (45) NetBIOS over TCP/IP Datagram Distribution Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetBIOS over TCP/IP Datagram Distribution Server : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 46:
                printf(YELLOW "\t\t\t\t\tOption : (46) NetBIOS over TCP/IP Node Type\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetBIOS over TCP/IP Node Type : " NORMAL);
                if(packet[2] == 0){
                    printf(YELLOW "B-node\n" NORMAL);
                }
                else if(packet[2] == 1){
                    printf(YELLOW "P-node\n" NORMAL);
                }
                else if(packet[2] == 2){
                    printf(YELLOW "M-node\n" NORMAL);
                }
                else if(packet[2] == 4){
                    printf(YELLOW "H-node\n" NORMAL);
                }
                else{
                    printf(YELLOW "Unknown\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 47:
                printf(YELLOW "\t\t\t\t\tOption : (47) NetBIOS over TCP/IP Scope\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tNetBIOS over TCP/IP Scope : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf(YELLOW "\n" NORMAL);
                pos+=packet[1]+2;
                break;
            case 48:
                printf(YELLOW "\t\t\t\t\tOption : (48) X Window System Font Server\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tX Window System Font Server : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 49:
                printf(YELLOW "\t\t\t\t\tOption : (49) X Window System Display Manager\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tX Window System Display Manager : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 50:
                printf(YELLOW "\t\t\t\t\tOption : (50) Requested IP Address\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tRequested IP Address : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%d.%d.%d.%d\n" NORMAL, packet[j], packet[j+1], packet[j+2], packet[j+3]);
                }
                pos+=packet[1]+2;
                break;
            case 51:
                printf(YELLOW "\t\t\t\t\tOption : (51) IP Address Lease Time\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tIP Address Lease Time : " NORMAL);
                printf(YELLOW "%d s\n" NORMAL, (packet[2]<<24) + (packet[3]<<16) + (packet[4]<<8) + packet[5]);

                pos+=packet[1]+2;
                break;
            case 52:
                printf(YELLOW "\t\t\t\t\tOption : (52) Option Overload\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tOption Overload : " NORMAL);
                if(packet[2] == 1){
                    printf(YELLOW "File\n" NORMAL);
                }
                else if(packet[2] == 2){
                    printf(YELLOW "Sname\n" NORMAL);
                }
                else if(packet[2] == 3){
                    printf(YELLOW "Both\n" NORMAL);
                }
                else{
                    printf(YELLOW "Unknown\n" NORMAL);
                }
                pos+=packet[1]+2;
                break;
            case 53:
                printf(YELLOW "\t\t\t\t\tOption : (53) DHCP Message Type\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tDHCP Message Type : " NORMAL);
                switch(packet[2]){
                    case 1:
                        printf(YELLOW "Discover\n" NORMAL);
                        break;
                    case 2:
                        printf(YELLOW "Offer\n" NORMAL);
                        break;
                    case 3:
                        printf(YELLOW "Request\n" NORMAL);
                        break;
                    case 4:
                        printf(YELLOW "Decline\n" NORMAL);
                        break;
                    case 5:
                        printf(YELLOW "Ack\n" NORMAL);
                        break;
                    case 6:
                        printf(YELLOW "Nak\n" NORMAL);
                        break;
                    case 7:
                        printf(YELLOW "Release\n" NORMAL);
                        break;
                    case 8:
                        printf(YELLOW "Inform\n" NORMAL);
                        break;
                    default:
                        printf(YELLOW "Unknown\n" NORMAL);
                        break;
                }
                pos+=packet[1]+2;
                break;
            case 54:
                printf(YELLOW "\t\t\t\t\tOption : (54) Server Identifier\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tServer Identifier : " NORMAL);
                for(int j=2; j<packet[1]; j+=4){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf(YELLOW "\n" NORMAL);
                pos+=packet[1]+2;
                break;
            case 55:
                printf(YELLOW "\t\t\t\t\tOption : (55) Parameter Request List\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tParameter Request List : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%d || " NORMAL, packet[j]);
                }
                printf(YELLOW "\n" NORMAL);
                pos+=packet[1]+2;
                break;
            case 56:
                printf(YELLOW "\t\t\t\t\tOption : (56) Message\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tMessage : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf(YELLOW "\n" NORMAL);
                pos+=packet[1]+2;
                break;
            case 57:
                printf(YELLOW "\t\t\t\t\tOption : (57) Maximum DHCP Message Size\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tMaximum DHCP Message Size : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, (int)packet[2]);
                pos+=packet[1]+2;
                break;
            case 58:
                printf(YELLOW "\t\t\t\t\tOption : (58) Renewal Time Value\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tRenewal Time Value : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]<<24 | packet[3]<<16 | packet[4]<<8 | packet[5]);
                pos+=packet[1]+2;
                break;
            case 59:
                printf(YELLOW "\t\t\t\t\tOption : (59) Rebinding Time Value\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tRebinding Time Value : " NORMAL);
                printf(YELLOW "%d\n" NORMAL, packet[2]<<24 | packet[3]<<16 | packet[4]<<8 | packet[5]);
                pos+=packet[1]+2;
                break;
            case 60:
                printf(YELLOW "\t\t\t\t\tOption : (60) Vendor Class Identifier\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tVendor Class Identifier : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 61:
                printf(YELLOW "\t\t\t\t\tOption : (61) Client Identifier\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\t\tType : %d\n"NORMAL,(int)packet[2]);
                printf(YELLOW "\t\t\t\t\t\tClient Identifier : " NORMAL);
                for(int j=3; j<packet[1]+2; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 66:
                printf(YELLOW "\t\t\t\t\tOption : (66) TFTP Server Name\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tTFTP Server Name : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 67:
                printf(YELLOW "\t\t\t\t\tOption : (67) Boot File Name\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tBoot File Name : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
            case 255:
                printf(YELLOW "\t\t\t\t\tOption : (255) End\n" NORMAL);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                pos+=packet[1]+2;
                break;
            default:
                printf(YELLOW "\t\t\t\t\tOption : (%d) Unrecognized\n" NORMAL, packet[0]);
                printf(YELLOW "\t\t\t\t\t\tLength : %d\n" NORMAL, packet[1]);
                printf(YELLOW "\t\t\t\t\t\tValue : " NORMAL);
                for(int j=2; j<packet[1]; j++){
                    printf(YELLOW "%c" NORMAL, packet[j]);
                }
                printf("\n");
                pos+=packet[1]+2;
                break;
        }
    }
    else{
        if(packet[0] == 53){
            printf("DHCP ");
            switch(packet[2]){
                    case 1:
                        printf( "Discover || " );
                        break;
                    case 2:
                        printf( "Offer || " );
                        break;
                    case 3:
                        printf( "Request || " );
                        break;
                    case 4:
                        printf( "Decline || " );
                        break;
                    case 5:
                        printf( "Ack || " );
                        break;
                    case 6:
                        printf( "Nak || " );
                        break;
                    case 7:
                        printf( "Release || " );
                        break;
                    case 8:
                        printf( "Inform || " );
                        break;
                    default:
                        printf( "Unknown || " );
                        break;
            }      
        }
        pos+=packet[1]+2;
    }
    return;



}



void bootp(const unsigned char *packet){
    struct bootphdr *bootpptr=(struct bootphdr*)packet; 
    switch(verbose){
        case 1:
            printf("Protocol: ");
            if(ntohl(bootpptr->bootp_magic) == 0x63825363){
                printf("DHCP || Total Lenght : %d || ", size_packet);
                pos=sizeof(struct bootphdr);
                while(packet[pos]!=0xff){
                    dhcp_option(packet+pos);
                }
                printf("Transaction ID : 0x%08x\n", ntohl(bootpptr->bootp_id));
           }
            else{
                printf("BOOTP || Total Lenght : %d || Bootp Message Type : ", size_packet);
                bootp_message_type(bootpptr->bootp_op);
                printf("\n");
            }
            break;
        case 2:
            if(ntohl(bootpptr->bootp_magic) == 0x63825363){
                printf(YELLOW "\t\t\t\tDynamic Host Configuration Protocol\n" NORMAL);
            }
            else{
                printf(YELLOW "\t\t\t\tBOOTP || Bootp Message Type : " );
                bootp_message_type(bootpptr->bootp_op);
                printf("\n" NORMAL); 
            }
            break;
        case 3:
            if(ntohl(bootpptr->bootp_magic) == 0x63825363){
                printf(YELLOW "\t\t\t\tDynamic Host Configuration Protocol\n" NORMAL);
            }
            else{
                printf(YELLOW "\t\t\t\tBOOTP || Bootp Message Type : ");
                bootp_message_type((int)bootpptr->bootp_op);
                printf("\n"); 
            }
            printf(YELLOW "\t\t\t\t\tHardware Type : %s" NORMAL, bootp_hwtype(bootpptr->bootp_htype));
            printf("\n");
            printf(YELLOW "\t\t\t\t\tHardware Address Length : %d\n" NORMAL, bootpptr->bootp_hlen);
            printf(YELLOW "\t\t\t\t\tHops : %d\n" NORMAL, bootpptr->bootp_hops);
            printf(YELLOW "\t\t\t\t\tTransaction ID : 0x%08x\n" NORMAL, ntohl(bootpptr->bootp_id));
            printf(YELLOW "\t\t\t\t\tSeconds elapsed : %d\n" NORMAL, ntohs(bootpptr->bootp_secs));
            printf(YELLOW "\t\t\t\t\tBootp Flags : 0x%d\n" NORMAL, (unsigned int)bootpptr->bootp_flags);
            printf(YELLOW "\t\t\t\t\t\t%d... .... .... .... = Broadcast flag : %s\n" NORMAL, bootpptr->bootp_flags, (bootpptr->bootp_flags & 0x8000) ? "Broadcast" : "Unicast");
            printf(YELLOW "\t\t\t\t\t\t.000 0000 0000 0000 = Reserved flags : 0\n" NORMAL); //pas réussi à faire la conversion au vue d ela structure
            printf(YELLOW "\t\t\t\t\tClient IP address : %s\n" NORMAL, inet_ntoa(bootpptr->ciaddr));
            printf(YELLOW "\t\t\t\t\tYour IP address : %s\n" NORMAL, inet_ntoa(bootpptr->yiaddr));
            printf(YELLOW "\t\t\t\t\tNext server IP address : %s\n" NORMAL, inet_ntoa(bootpptr->siaddr));
            printf(YELLOW "\t\t\t\t\tRelay agent IP address : %s\n" NORMAL, inet_ntoa(bootpptr->giaddr));
            printf(YELLOW "\t\t\t\t\tClient hardware address : %s\n" NORMAL, get_mac_addr(bootpptr->bootp_chaddr));
            
            if(ntohl(bootpptr->bootp_magic) == 0x63825363){
                printf(YELLOW "\t\t\t\t\tServer name option : " NORMAL);
                printf(YELLOW "overloaded by DHCP options\n" NORMAL);
                printf(YELLOW "\t\t\t\t\tBoot file name option : " NORMAL);
                printf(YELLOW "overloaded by DHCP options\n" NORMAL);
                printf(YELLOW "\t\t\t\t\tMagic cookie : DHCP (0x63585363)\n" NORMAL);
                pos=sizeof(struct bootphdr);
                while(packet[pos]!=0xff){
                    dhcp_option(packet+pos);
                }
            }
            else{
                printf(YELLOW "\t\t\t\t\tServer name option : %s\n" NORMAL, bootpptr->bootp_sname);
                printf(YELLOW "\t\t\t\t\tBoot file name option : %s\n" NORMAL, bootpptr->bootp_file);
                printf(YELLOW "\t\t\t\t\tMagic cookie : 0x%d\n" NORMAL, bootpptr->bootp_magic);
            }
            
    }
}