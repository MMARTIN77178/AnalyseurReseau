#include "bootp.h"
#include <string.h>

extern int verbose;
extern int size_payload;

void ftp_request(const unsigned char* data)
{
    const char *payload = (const char *) data;
    int test = 0;
    
    printf(YELLOW "\t\t\t\t\t\t\tRequest command:\n" NORMAL);

    if (strstr(payload, "USER") != NULL)
	{
		printf("USER ");
        test = 1;
	}
    if (strstr(payload, "PASS") != NULL)
	{
		printf("PASS ");
        test = 1;
	}
    if (strstr(payload, "ACCT") != NULL)
	{
		printf("ACCT ");
        test = 1;
    }
    if (strstr(payload, "CWD") != NULL)
	{
		printf("CWD ");
        test = 1;
	}
    if (strstr(payload, "CDUP") != NULL)
	{
		printf("CDUP ");
        test = 1;
	}
    if (strstr(payload, "QUIT") != NULL)
	{
		printf("QUIT ");
        test = 1;
	}
    if (strstr(payload, "PORT") != NULL)
	{
		printf("PORT ");
        test = 1;
	}
    if (strstr(payload, "PASV") != NULL)
	{
		printf("PASV ");
        test = 1;
	} 
    if (strstr(payload, "TYPE") != NULL)
	{
		printf("TYPE ");
        test = 1;
	} 
    if (strstr(payload, "RETR") != NULL)
	{
		printf("RETR ");
        test = 1;
	} 
    if (strstr(payload, "STOR") != NULL)
	{
		printf("STOR ");
        test = 1;
	} 
    if (strstr(payload, "APPE") != NULL)
	{
		printf("APPE ");
        test = 1;
	} 
    if (strstr(payload, "REST") != NULL)
	{
		printf("REST ");
        test = 1;
	} 
    if (strstr(payload, "RNFR") != NULL)
	{
		printf("RNFR ");
        test = 1;
	} 
    if (strstr(payload, "RNTO") != NULL)
	{
		printf("RNTO ");
        test = 1;
	}
    if (strstr(payload, "ABOR") != NULL)
	{
		printf("ABOR ");
        test = 1;
	}
    if (strstr(payload, "DELE") != NULL)
	{
		printf("DELE ");
        test = 1;
	}
    if (strstr(payload, "RMD") != NULL)
	{
		printf("RMD ");
        test = 1;
	}
    if (strstr(payload, "MKD") != NULL)
	{
		printf("MKD ");
        test = 1;
	}
    if (strstr(payload, "PWD") != NULL)
	{
		printf("PWD ");
        test = 1;
	}
    if (strstr(payload, "LIST") != NULL)
	{
		printf("LIST ");
        test = 1;
	}
    if (strstr(payload, "SITE") != NULL)
	{
		printf("SITE ");
        test = 1;
	}
    if (strstr(payload, "SYST") != NULL)
	{
		printf("SYST ");
        test = 1;
	}
    if (strstr(payload, "STAT") != NULL)
	{
		printf("STAT ");
        test = 1;
	}
    if (strstr(payload, "HELP") != NULL)
	{
		printf("HELP ");
        test = 1;
	}
    if (strstr(payload, "NOOP") != NULL)
	{
		printf("NOOP ");
        test = 1;
	}

    if (!test)
    {
        printf("none\n");
        return;
    }
    printf("\n");
    return;
    
}

void ftp_response(const unsigned char *packet){
    const char *payload = (const char *) packet;
    char code[3];
    snprintf(code, 3+1, "%.3s", payload);
    int code_int = atoi(code);
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
    int i=0;
    printf(YELLOW "\t\t\t\t\t\tResponse message: "NORMAL);
    while(i<strlen(payload)-4 && cnt!=0){
        if(packet[i+4] == '\r' && packet[i+5] == '\n'){ //+4 pour ne pas noter le code
                cnt=0;
                i++;
        }
        else{
            printf(YELLOW "%c" NORMAL, packet[i+4]);
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
    printf(YELLOW "\t\t\t\t\tPayload size : %d\n" NORMAL, size_payload);
    if(size_payload==0){
        printf(YELLOW "\t\t\t\t\tNo more data\n" NORMAL);
    }
    else{
        int cnt=0;
        for(int i = 0; i < size_payload; i++) {
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
        if(is_response){
            ftp_response(packet);
        }
        else{
            ftp_request(packet);
        }
    }
}
