#include "bootp.h"
#include <string.h>

extern int verbose;
extern int size_payload;

void ftp_request(const unsigned char* packet)
{
    const char *payload = (const char *) packet;
    char req[4];
    strncpy(req, payload, 4);
    printf(YELLOW "\t\t\t\t\t\tRequest command:" NORMAL);
    if (strcmp(req, "ABOR")==0){
        printf(YELLOW "ABOR\n"NORMAL);
    }
    else if (strcmp(req, "ACCT")==0){
        printf(YELLOW"ACCT\n"NORMAL);
    }
    else if (strcmp(req, "ADAT")==0){
        printf(YELLOW"ADAT\n"NORMAL);
    }
    else if (strcmp(req, "ALLO")==0){
        printf(YELLOW"ALLO\n"NORMAL);
    }
    else if (strcmp(req, "APPE")==0){
        printf(YELLOW"APPE\n"NORMAL);
    }
    else if (strcmp(req, "AUTH")==0){
        printf(YELLOW"AUTH\n"NORMAL);
    }
    else if (strcmp(req, "CCC")==0){
        printf(YELLOW"CCC"NORMAL);
    }
    else if (strcmp(req, "CDUP")==0){
        printf(YELLOW"CDUP\n"NORMAL);
    }
    else if (strcmp(req, "CONF")==0){
        printf(YELLOW"CONF\n"NORMAL);
    }
    else if (strcmp(req, "CWD")==0){
        printf(YELLOW"CWD\n"NORMAL);
    }
    else if (strcmp(req, "DELE")==0){
        printf(YELLOW"DELE\n"NORMAL);
    }
    else if (strcmp(req, "ENC ")==0){
        printf(YELLOW"ENC\n"NORMAL);
    }
    else if (strcmp(req, "EPRT")==0){
        printf(YELLOW"EPRT\n"NORMAL);
    }
    else if (strcmp(req, "EPSV")==0){
        printf(YELLOW"EPSV\n"NORMAL);
    }
    else if (strcmp(req, "FEAT")==0){
        printf(YELLOW"FEAT\n"NORMAL);
    }
    else if (strcmp(req, "LANG")==0){
        printf(YELLOW"LANG\n"NORMAL);
    }
    else if (strcmp(req, "LIST")==0){
        printf(YELLOW"LIST\n"NORMAL);
    }
    else if (strcmp(req, "LPRT")==0){
        printf(YELLOW"LPRT\n"NORMAL);
    }
    else if (strcmp(req, "LPSV")==0){
        printf(YELLOW"LPSV\n"NORMAL);
    }
    else if (strcmp(req, "HELP")==0){
        printf(YELLOW"HELP\n"NORMAL);
    }
    else if (strcmp(req, "LIST")==0){
        printf(YELLOW"LIST\n"NORMAL);
    }
    else if (strcmp(req, "MDTM")==0){
        printf(YELLOW"MDTM\n"NORMAL);
    }
    else if (strcmp(req, "MKD")==0){
        printf(YELLOW"MKD\n"NORMAL);
    }
    else if(strcmp(req, "MLST")==0){
        printf(YELLOW"MLST\n"NORMAL);
    }
    else if (strcmp(req, "MODE")==0){
        printf(YELLOW"MODE\n"NORMAL);
    }
    else if (strcmp(req, "NLST")==0){
        printf(YELLOW"NLST\n"NORMAL);
    }
    else if (strcmp(req, "NOOP")==0){
        printf(YELLOW"NOOP\n"NORMAL);
    }
    else if (strcmp(req, "OPTS")==0){
        printf(YELLOW"OPTS\n"NORMAL);
    }
    else if (strcmp(req, "PASS")==0){
        printf(YELLOW"PASS\n"NORMAL);
    }
    else if (strcmp(req, "PASV")==0){
        printf(YELLOW"PASV\n"NORMAL);
    }
    else if (strcmp(req, "PORT")==0){
        printf(YELLOW"PORT\n"NORMAL);
    }
    else if (strcmp(req, "PROT")==0){
        printf(YELLOW"PROT\n"NORMAL);
    }
    else if (strcmp(req, "PWD")==0){
        printf(YELLOW"PWD\n"NORMAL);
    }
    else if (strcmp(req, "QUIT")==0){
        printf(YELLOW"QUIT\n"NORMAL);
    }
    else if (strcmp(req, "REIN")==0){
        printf(YELLOW"REIN\n"NORMAL);
    }
    else if (strcmp(req, "REST")==0){
        printf(YELLOW"REST\n"NORMAL);
    }
    else if (strcmp(req, "RETR")==0){
        printf(YELLOW"RETR\n"NORMAL);
    }
    else if (strcmp(req, "RMD")==0){
        printf(YELLOW"RMD\n"NORMAL);
    }
    else if (strcmp(req, "RNFR")==0){
        printf(YELLOW"RNFR\n"NORMAL);
    }
    else if (strcmp(req, "RNTO")==0){
        printf(YELLOW"RNTO\n"NORMAL);
    }
    else if (strcmp(req, "SITE")==0){
        printf(YELLOW"SITE\n"NORMAL);
    }
    else if (strcmp(req, "SIZE")==0){
        printf(YELLOW"SIZE\n"NORMAL);
    }
    else if (strcmp(req, "SMNT")==0){
        printf(YELLOW"SMNT\n"NORMAL);
    }
    else if (strcmp(req, "STAT")==0){
        printf(YELLOW"STAT\n"NORMAL);
    }
    else if (strcmp(req, "STOR")==0){
        printf(YELLOW"STOR\n"NORMAL);
    }
    else if (strcmp(req, "STOU")==0){
        printf(YELLOW"STOU\n"NORMAL);
    }
    else if (strcmp(req, "STRU")==0){
        printf(YELLOW"STRU\n"NORMAL);
    }
    else if (strcmp(req, "SYST")==0){
        printf(YELLOW"SYST\n"NORMAL);
    }
    else if (strcmp(req, "TYPE")==0){
        printf(YELLOW"TYPE\n"NORMAL);
    }
    else if (strcmp(req, "USER")==0){
        printf(YELLOW"USER\n"NORMAL);
    }
    else if (strcmp(req, "XCUP")==0){
        printf(YELLOW"XCUP\n"NORMAL);
    }
    else if (strcmp(req, "XMKD")==0){
        printf(YELLOW"XMKD\n"NORMAL);
    }
    else if (strcmp(req, "XPWD")==0){
        printf(YELLOW"XPWD\n"NORMAL);
    }
    else if (strcmp(req, "XRCP")==0){
        printf(YELLOW"XRCP\n"NORMAL);
    }
    else if (strcmp(req, "XRMD")==0){
        printf(YELLOW"XRMD\n"NORMAL);
    }
    else if (strcmp(req, "XRSQ")==0){
        printf(YELLOW"XRSQ\n"NORMAL);
    }
    else if (strcmp(req, "XSEM")==0){
        printf(YELLOW"XSEM\n"NORMAL);
    }
    else if (strcmp(req, "XSEN")==0){
        printf(YELLOW"XSEN\n"NORMAL);
    }
    else{
        printf(YELLOW"Unknown command\n"NORMAL);
    }
    int cnt=0;
    if(size_payload-4>0){
        printf(YELLOW "\t\t\t\t\t\tRequest arg:"NORMAL);
        for(int i = 4; i < size_payload-1; i++) {
            if(packet[i] == '\r' && packet[i+1] == '\n'){
                cnt=0;
                i++;
            }
            else{
                printf(YELLOW "%c" NORMAL, packet[i]);
                cnt++;
            }
        }
        printf(YELLOW "\n" NORMAL);
    }

    return;
    
}

void ftp_response(const unsigned char *packet){
    const char *payload = (const char *) packet;
    
    int code_int = 100*(packet[0] - '0') + 10*(packet[1] - '0') + packet[2] - '0';
    printf(YELLOW "\t\t\t\t\t\tResponse code: (%d) " NORMAL, code_int);
    switch(code_int){
        case 110:
            printf(YELLOW "Restart marker reply.\n"NORMAL);
            break;
        case 120:
            printf(YELLOW "Service ready in nnn minutes.\n"NORMAL);
            break;
        case 125:
            printf(YELLOW "Data connection already open; transfer starting.\n"NORMAL);
            break;
        case 150:
            printf(YELLOW "File status okay; about to open data connection.\n"NORMAL);
            break;
        case 200:
            printf(YELLOW "Command okay.\n"NORMAL);
            break;
        case 202:
            printf(YELLOW "Command not implemented, superfluous at this site.\n"NORMAL);
            break;
        case 211:
            printf(YELLOW "System status, or system help reply.\n"NORMAL);
            break;
        case 212:
            printf(YELLOW "Directory status.\n"NORMAL);
            break;
        case 213:
            printf(YELLOW "File status.\n"NORMAL);
            break;
        case 214:
            printf(YELLOW "Help message.\n"NORMAL);
            break;
        case 215:
            printf(YELLOW "NAME system type.\n"NORMAL);
            break;
        case 220:
            printf(YELLOW "Service ready for new user.\n"NORMAL);
            break;
        case 221:
            printf(YELLOW "Service closing control connection.\n"NORMAL);
            break;
        case 225:
            printf(YELLOW "Data connection open; no transfer in progress.\n"NORMAL);
            break;
        case 226:
            printf(YELLOW "Closing data connection.\n"NORMAL);
            break;
        case 227:
            printf(YELLOW "Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n"NORMAL);
            break;
        case 230:
            printf(YELLOW "User logged in, proceed.\n"NORMAL);
            break;
        case 250:
            printf(YELLOW "Requested file action okay, completed.\n"NORMAL);
            break;
        case 257:
            printf(YELLOW "PATHNAME created.\n"NORMAL);
            break;
        case 331:
            printf(YELLOW "User name okay, need password.\n"NORMAL);
            break;
        case 332:
            printf(YELLOW "Need account for login.\n"NORMAL);
            break;
        case 350:
            printf(YELLOW "Requested file action pending further information.\n"NORMAL);
            break;
        case 421:
            printf(YELLOW "Service not available, closing control connection.\n"NORMAL);
            break;
        case 425:
            printf(YELLOW "Can't open data connection.\n"NORMAL);
            break;
        case 426:
            printf(YELLOW "Connection closed; transfer aborted.\n"NORMAL);
            break;
        case 450:
            printf(YELLOW "Requested file action not taken.\n"NORMAL);
            break;
        case 451:
            printf(YELLOW "Requested action aborted: local error in processing.\n"NORMAL);
            break;
        case 452:
            printf(YELLOW "Requested action not taken.\n"NORMAL);
            break;
        case 500:
            printf(YELLOW "Syntax error, command unrecognized.\n"NORMAL);
            break;
        case 501:
            printf(YELLOW "Syntax error in parameters or arguments.\n"NORMAL);
            break;
        case 502:
            printf(YELLOW "Command not implemented.\n"NORMAL);
            break;
        case 503:
            printf(YELLOW "Bad sequence of commands.\n"NORMAL);
            break;
        case 504:
            printf(YELLOW "Command not implemented for that parameter.\n"NORMAL);
            break;
        case 530:
            printf(YELLOW "Not logged in.\n"NORMAL);
            break;
        case 532:
            printf(YELLOW "Need account for storing files.\n"NORMAL);
            break;
        case 550:
            printf(YELLOW "Requested action not taken.\n"NORMAL);
            break;
        case 551:
            printf(YELLOW "Requested action aborted: page type unknown.\n"NORMAL);
            break;
        case 552:
            printf(YELLOW "Requested file action aborted.\n"NORMAL);
            break;
        case 553:
            printf(YELLOW "Requested action not taken.\n"NORMAL);
            break;
        default:
            printf(YELLOW "Unknown response code.\n"NORMAL);
            break;
    }
    int cnt=0;
    printf(YELLOW "\t\t\t\t\t\tResponse message: "NORMAL);
    for(int i = 4; i < size_payload-1; i++) {
            if(packet[i] == '\r' && packet[i+1] == '\n'){
                cnt=0;
                i++;
            }
            else{
                printf(YELLOW "%c" NORMAL, packet[i]);
                cnt++;
            }
  		}
    printf(YELLOW "\n" NORMAL);

}

void ftp(const unsigned char *packet, bool is_response){
    if(size_payload==0){
        return;
    }
    printf(YELLOW "\t\t\t\tFile Transfer Protocol\n" NORMAL);
    if(verbose == 3){
        printf(YELLOW "\t\t\t\t\tPayload size : %d\n" NORMAL, size_payload);
        if(size_payload==0){
            printf(YELLOW "\t\t\t\t\tNo more data\n" NORMAL);
        }
        else{
            int cnt=0;
            for(int i = 0; i < size_payload-1; i++) {
                if(cnt==0){
                    printf(YELLOW "\t\t\t\t\t" NORMAL);
                }
                if(packet[i] == '\r' && packet[i+1] == '\n'){
                    printf(YELLOW "\\r\\n\n" NORMAL);
                    cnt=0;
                    i++;
                }
                else{
                    printf(YELLOW "%c" NORMAL, packet[i]);
                    cnt++;
                }
  		    }
            if(is_response && size_payload>=7){
                ftp_response(packet);
            }
            else if(!is_response && size_payload>=8){
                ftp_request(packet);
            }
        }
    }
}
