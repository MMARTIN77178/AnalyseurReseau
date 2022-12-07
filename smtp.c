#include "bootp.h"

extern int size_payload;
extern int verbose;

void smtp_command(const unsigned char *packet){
    return;
}

void smtp_response(const unsigned char *packet){
    printf(YELLOW "\t\t\t\t\tResponse: " NORMAL);
    const char *payload = (const char *) packet;
    int a=0;
    int i=0;
    int cnt=1;
    while(i < size_payload-1 && cnt != 0) {
            if(packet[i] == '\r' && packet[i+1] == '\n'){
                printf(YELLOW "\\r\\n\n" NORMAL);
                i++;
                a+=2;
                cnt=0;
            }
            else{
                printf(YELLOW "%c" NORMAL, packet[i]);
                a++;
            }
            i++;
  	}
    bool response_code = false;
    int code_int = 100*(packet[0] - '0') + 10*(packet[1] - '0') + packet[2] - '0';
    printf(YELLOW "\t\t\t\t\t\tResponse code: (%d) " NORMAL, code_int);
    switch(code_int){
        case 211:
            printf("System status, or system help reply\n");
            response_code = true;
            break;
        case 214:
            printf("Help message\n");
            response_code = true;
            break;
        case 220:
            printf("<domain> Service ready\n");
            response_code = true;
            break;
        case 221:
            if(size_payload >= 9 && payload[4]=='2' && payload[6]=='0' && payload[8]=='0'){
                printf("2.0.0 Goodbye");
                response_code = true;
            }
            else{
                printf("Service closing transmission channel\n");
                response_code = true;
            }
            break;
        case 235:
            printf("2.7.0 Authentication successful\n");
            response_code = true;
            break;
        case 240:
            printf("Requested mail action okay, completed\n");
            response_code = true;
            break;
        case 250:
            printf("Requested mail action okay, completed\n");
            response_code = true;
            break;
        case 251:
            printf("User not local; will forward to <forward-path>\n");
            response_code = true;
            break;
        case 252:
            printf("Cannot VRFY user, but will accept message and attempt delivery\n");
            response_code = true;
            break;
        case 334:
            printf("(Server challenge - the text part contains the Base64-encoded challenge)\n");
            response_code = true;
            break;
        case 354:
            printf("Start mail input; end with <CRLF>.<CRLF>\n");
            response_code = true;
            break;
        case 421:
            printf("Service not available, closing transmission channel\n");
            response_code = true;
            break;
        case 432:
            printf("4.7.12 A password transition is needed\n");
            response_code = true;
            break;
        case 450:
            printf("Requested mail action not taken: mailbox unavailable\n");
            response_code = true;
            break;
        case 451:
            if(size_payload >=9 && payload[4]=='4' && payload[6]=='4' && payload[8]=='1'){
                printf("4.4.1 IMAP Server unavailable");
                response_code = true;
            }
            else{
                printf("Requested action aborted: local error in processing\n");
                response_code = true;
            }
            break;
        case 452:
            printf(" 4.7.0 Requested action not taken: insufficient system storage\n");
            response_code = true;
            break;
        case 500:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='5' && payload[8]=='6'){
                printf("5.5.6 Authentication Exchange line is too long\n");
                response_code = true;
            }
            else{
                printf("Syntax error, command unrecognized\n");
                response_code = true;
            }
            break;
        case 501:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='5' && payload[8]=='2'){
                printf("5.5.2 Cannot Base64-decode Client responses\n");
                response_code = true;
            }
            else if(size_payload >= 9 && payload[4]=='5' && payload[6]=='7' && payload[8]=='0'){
                printf("5.7.0 Client initiated Authentication Exchange\n");
                response_code = true;
            }
            else{
                printf("Syntax error in parameters or arguments\n");
                response_code = true;
            }
            break;
        case 502:
            printf("Command not implemented\n");
            response_code = true;
            break;
        case 503:
            printf("Bad sequence of commands\n");
            response_code = true;
            break;
        case 504:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='5' && payload[8]=='4'){
                printf("5.5.4 Unrecognized authentication type\n");
                response_code = true;
            }
            else{
                printf("Command parameter not implemented\n");
                response_code = true;
            }
            break;
        case 521:
            printf("Server does not accept mail (see RFC1846)\n");
            response_code = true;
            break;
        case 523:
            printf("Encryption needed\n");
            response_code = true;
            break;
        case 530:
            printf("5.7.0 Authentication required\n");
            response_code = true;
            break;
        case 534:
            printf("5.7.9 Authentication mechanism is too weak\n");
            response_code = true;
            break;
        case 535:
            printf("5.7.8 Authentication credentials invalid\n");
            response_code = true;
            break;
        case 538:
            printf("5.7.11 Encryption required for requested authentication mechanism\n");
            response_code = true;
            break;
        case 550:
            printf("Requested action not taken: mailbox unavailable\n");
            response_code = true;
            break;
        case 551:
            printf("User not local; please try <forward-path>\n");
            response_code = true;
            break;
        case 552:
            printf("Requested mail action aborted: exceeded storage allocation\n");
            response_code = true;
            break;
        case 553:
            printf("Requested action not taken: mailbox name not allowed\n");
            response_code = true;
            break;
        case 554:
            if(size_payload >= 9 && payload[4]=='5' && payload[6]=='3' && payload[8]=='4'){
                printf("5.3.4 Message too big for system\n");
                response_code = true;
            }
            else{
                printf("Transaction failed\n");
                response_code = true;
            }
            break;
        case 556:
            printf("Domain does not accept mail\n");
            response_code = true;
            break;
        default:
            printf("Unknown response code\n");
            break;
    }    
    printf("\n");
    if (size_payload-a-3>0){
        printf(YELLOW "\t\t\t\t\t\tResponse parameter : " );
        for(int i = a; i < size_payload-1; i++) {
            if(packet[i] == '\r' && packet[i+1] == '\n'){
                if(i+3 < size_payload && )
                printf(YELLOW "\n\t\t\t\t\t\tResponse parameter : " );
                i++;
                break;
            else{
                printf(YELLOW "%c" NORMAL, packet[i]);
            }
        }
        printf("\n");
    }
}

void smtp(const unsigned char *packet, bool is_response){
    if(size_payload==0){
        return;
    }
    printf(YELLOW "\t\t\t\tSimple Mail Transfer Protocol\n" NORMAL);
    if(verbose == 3){
        if(size_payload==0){
            printf(YELLOW "\t\t\t\t\tNo more data\n" NORMAL);
        }
        if(is_response && size_payload>=7){
                smtp_response(packet);
        }
        else if(!is_response && size_payload>=8){
                smtp_command(packet);
        }
    }
}
