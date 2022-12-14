#include "bootp.h"

extern int size_payload;
extern int verbose;
extern int size_packet;

void smtp_command(const unsigned char *packet){
    int j=0;
    bool fin_ligne=false;
    while(size_payload-j>1){  
        int k=j;
        printf(YELLOW "\t\t\t\t\tCommand Line: " NORMAL);
        while(size_payload-1>k && fin_ligne==false){
            if(packet[k]=='\r' && packet[k+1]=='\n'){
                printf(YELLOW"\\r\\n\n" NORMAL);
                fin_ligne=true;
                k++;
                int l=j;
                printf(YELLOW "\t\t\t\t\t\tCommand: " NORMAL);
                while(l<size_payload && packet[l]!=' '){
                    printf(YELLOW "%c" NORMAL, packet[l]);
                    l++;
                }
            }
            else{
                printf(YELLOW "%c" NORMAL, packet[k]);
            }
            k++; 
        }
        fin_ligne=false;
        j=k;
    }
}

void smtp_response(const unsigned char *packet){
    printf(YELLOW "\t\t\t\t\tResponse: " NORMAL);
    const char *payload = (const char *) packet;
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
    bool response_code = false;
    int code_int = 100*(packet[0] - '0') + 10*(packet[1] - '0') + packet[2] - '0';
    printf(YELLOW "\t\t\t\t\t\tResponse code: (%d) " NORMAL, code_int);
    switch(code_int){
        case 101:
            printf(YELLOW "cannot open SMTP stream\n"NORMAL);
            response_code = true;
            break;
        case 111:
            printf(YELLOW "Refused connection or unable to open SMTP stream\n"NORMAL);
            response_code = true;
            break;
        case 211:
            printf(YELLOW "System status, or system help reply\n"NORMAL);
            response_code = true;
            break;
        case 214:
            printf(YELLOW "Help message\n"NORMAL);
            response_code = true;
            break;
        case 220:
            printf(YELLOW "<domain> Service ready\n"NORMAL);
            response_code = true;
            break;
        case 221:
            if(size_payload >= 9 && payload[4]=='2' && payload[6]=='0' && payload[8]=='0'){
                printf(YELLOW "2.0.0 Goodbye\n"NORMAL);
                response_code = true;
            }
            else{
                printf(YELLOW "Service closing transmission channel\n"NORMAL);
                response_code = true;
            }
            break;
        case 235:
            printf(YELLOW "2.7.0 Authentication successful\n"NORMAL);
            response_code = true;
            break;
        case 240:
            printf(YELLOW "Requested mail action okay, completed\n"NORMAL);
            response_code = true;
            break;
        case 250:
            printf(YELLOW "Requested mail action okay, completed\n"NORMAL);
            response_code = true;
            break;
        case 251:
            printf(YELLOW "User not local; will forward to <forward-path>\n"NORMAL);
            response_code = true;
            break;
        case 252:
            printf(YELLOW "Cannot VRFY user, but will accept message and attempt delivery\n"NORMAL);
            response_code = true;
            break;
        case 334:
            printf(YELLOW "(Server challenge - the text part contains the Base64-encoded challenge)\n"NORMAL);
            response_code = true;
            break;
        case 354:
            printf(YELLOW "Start mail input; end with <CRLF>.<CRLF>\n"NORMAL);
            response_code = true;
            break;
        case 421:
            printf(YELLOW "Service not available, closing transmission channel\n"NORMAL);
            response_code = true;
            break;
        case 432:
            printf(YELLOW "4.7.12 A password transition is needed\n"NORMAL);
            response_code = true;
            break;
        case 450:
            printf(YELLOW "Requested mail action not taken: mailbox unavailable\n"NORMAL);
            response_code = true;
            break;
        case 451:
            if(size_payload >=9 && payload[4]=='4' && payload[6]=='4' && payload[8]=='1'){
                printf(YELLOW "4.4.1 IMAP Server unavailable\n"NORMAL);
                response_code = true;
            }
            else{
                printf(YELLOW "Requested action aborted: local error in processing\n"NORMAL);
                response_code = true;
            }
            break;
        case 452:
            printf(YELLOW " 4.7.0 Requested action not taken: insufficient system storage\n"NORMAL);
            response_code = true;
            break;
        case 500:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='5' && payload[8]=='6'){
                printf(YELLOW "5.5.6 Authentication Exchange line is too long\n"NORMAL);
                response_code = true;
            }
            else{
                printf(YELLOW "Syntax error, command unrecognized\n"NORMAL);
                response_code = true;
            }
            break;
        case 501:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='5' && payload[8]=='2'){
                printf(YELLOW "5.5.2 Cannot Base64-decode Client responses\n"NORMAL);
                response_code = true;
            }
            else if(size_payload >= 9 && payload[4]=='5' && payload[6]=='7' && payload[8]=='0'){
                printf(YELLOW "5.7.0 Client initiated Authentication Exchange\n"NORMAL);
                response_code = true;
            }
            else{
                printf(YELLOW "Syntax error in parameters or arguments\n"NORMAL);
                response_code = true;
            }
            break;
        case 502:
            printf(YELLOW "Command not implemented\n"NORMAL);
            response_code = true;
            break;
        case 503:
            printf(YELLOW "Bad sequence of commands\n"NORMAL);
            response_code = true;
            break;
        case 504:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='5' && payload[8]=='4'){
                printf(YELLOW "5.5.4 Unrecognized authentication type\n"NORMAL);
                response_code = true;
            }
            else{
                printf(YELLOW "Command parameter not implemented\n"NORMAL);
                response_code = true;
            }
            break;
        case 521:
            printf(YELLOW "Server does not accept mail (see RFC1846)\n"NORMAL);
            response_code = true;
            break;
        case 523:
            printf(YELLOW "Encryption needed\n"NORMAL);
            response_code = true;
            break;
        case 530:
            printf(YELLOW "5.7.0 Authentication required\n"NORMAL);
            response_code = true;
            break;
        case 534:
            printf(YELLOW "5.7.9 Authentication mechanism is too weak\n"NORMAL);
            response_code = true;
            break;
        case 535:
            printf(YELLOW "5.7.8 Authentication credentials invalid\n"NORMAL);
            response_code = true;
            break;
        case 538:
            printf(YELLOW "5.7.11 Encryption required for requested authentication mechanism\n"NORMAL);
            response_code = true;
            break;
        case 550:
            printf(YELLOW "Requested action not taken: mailbox unavailable\n"NORMAL);
            response_code = true;
            break;
        case 551:
            printf(YELLOW "User not local; please try <forward-path>\n"NORMAL);
            response_code = true;
            break;
        case 552:
            printf("Requested mail action aborted: exceeded storage allocation\n"NORMAL);
            response_code = true;
            break;
        case 553:
            printf(YELLOW "Requested action not taken: mailbox name not allowed\n"NORMAL);
            response_code = true;
            break;
        case 554:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='3' && payload[8]=='4'){
                printf(YELLOW "5.3.4 Message too big for system\n"NORMAL);
                response_code = true;
            }
            else{
                printf(YELLOW "Transaction failed\n"NORMAL);
                response_code = true;
            }
            break;
        case 556:
            printf(YELLOW "Domain does not accept mail\n"NORMAL);
            response_code = true;
            break;
        default:
            printf(YELLOW "Unknown response code\n"NORMAL);
            break;
    }    
    int j=0;
    bool fin_ligne=false;
    if(response_code==true){
        while(size_payload-j>4){  
            int k=j;    
            if ((100*(packet[k] - '0') + 10*(packet[k+1] - '0') + packet[k+2] - '0')==code_int){
                k+=4;
                printf(YELLOW "\t\t\t\t\t\tResponse parameter: " NORMAL);
                while(size_payload-1>k && fin_ligne==false){
                    if(packet[k]=='\r' && packet[k+1]=='\n'){
                        printf("\n");
                        fin_ligne=true;
                        k++;
                    }
                    else{
                        printf(YELLOW "%c" NORMAL, packet[k]);
                    }
                    k++;
                }
                fin_ligne=false;
            }
            j=k;
  	    }
    }
}

void smtp(const unsigned char *packet, bool is_response){
    switch(verbose){
        case 1:
            if(size_payload>0){
                printf(YELLOW "Protocol : SMTP || Total Length : %d || \n" NORMAL, size_packet);
            }
            if(is_response){
                printf("S:");
            }
            else{
                printf("C:");
            }
            int i=0;
            while (i<size_payload-1 && packet[i]!='\r' && packet[i+1]!='\n'){
                printf("%c", packet[i]);
                i++;
            }
            printf("\n");
            break;
        case 2:
            if(is_response){
                printf(YELLOW "\t\t\t\tSimple Mail Transfer Protocol, Response\n" NORMAL);
            }
            else{
                printf(YELLOW "\t\t\t\tSimple Mail Transfer Protocol, Command\n" NORMAL);
            }
            break;
        case 3:
            printf(YELLOW "\t\t\t\tSimple Mail Transfer Protocol\n" NORMAL);
            if(verbose == 3){
                if(size_payload==0){
                    printf(YELLOW "No more data\n" NORMAL);
                }
                if(is_response && size_payload>=7){
                    smtp_response(packet);
                }
                else if(!is_response){
                    smtp_command(packet);
                }
            }
            break;
        default:
            break;
    }
}
