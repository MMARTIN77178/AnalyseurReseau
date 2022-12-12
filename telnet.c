#include "bootp.h"

extern int size_payload;
extern int verbose;

void telnet(const unsigned char *packet) {
	int i = 0, j = 1;

	if((verbose == 2 || verbose == 3) && size_payload > 0) {
		printf(YELLOW "\t\t\t\tTELNET\n"NORMAL);
        if(verbose==3){
		    while(i < size_payload) 
		    {
		    	if(packet[i] == 255) {
		    		i++;
		    		j = 1;
		    		printf("\t\t\t\t\t");
		    		while(j) {
		    			switch(packet[i]) {
		    				case 0:
		    					printf(YELLOW "Binary transmission " NORMAL);
		    					break;
		    				case 1:
		    					printf(YELLOW "Echo "NORMAL);
		    					break;
		    				case 2:
		    					printf(YELLOW "Reconnection "NORMAL);
		    					break;
		    				case 3:
		    					printf(YELLOW "Suppress go ahead "NORMAL);
		    					break;
		    				case 4:
		    					printf(YELLOW "Approx message size negotation "NORMAL);
		    					break;
		    				case 5:
		    					printf(YELLOW "Status "NORMAL);
		    					break;
		    				case 6:
		    					printf(YELLOW "Timing mark "NORMAL);
		    					break;
		    				case 7:
		    					printf(YELLOW "Remote controlled transmition and echo"NORMAL);
		    					break;
		    				case 8:
		    					printf(YELLOW "Output line width "NORMAL);
		    					break;
		    				case 9:
		    					printf(YELLOW "Output page size "NORMAL);
		    					break;
		    				case 10:
		    					printf(YELLOW "Output carriage-return disposition "NORMAL);
		    					break;
		    				case 11:
		    					printf(YELLOW "Output horizontal tabstops "NORMAL);
		    					break;
		    				case 12:
		    					printf(YELLOW "Output horizontal tab disposition "NORMAL);
		    					break;
		    				case 13:
		    					printf(YELLOW "Output formfeed disposition "NORMAL);
		    					break;
		    				case 14:
		    					printf(YELLOW "Output vertical tabstops "NORMAL);
		    					break;
		    				case 15:
		    					printf(YELLOW "Output vertical tab disposition "NORMAL);
		    					break;
		    				case 16:
		    					printf(YELLOW "Output linefeed disposition "NORMAL);
		    					break;
		    				case 17:
		    					printf(YELLOW "Extended ASCII "NORMAL);
		    					break;
		    				case 18:
		    					printf(YELLOW "Logout "NORMAL);
		    					break;
		    				case 19:
		    					printf(YELLOW "Byte macro "NORMAL);
		    					break;
		    				case 20:
		    					printf(YELLOW "Data entry terminal "NORMAL);
		    					break;
		    				case 21:
		    					printf(YELLOW "SUPDUP "NORMAL);
		    					break;
		    				case 22:
		    					printf(YELLOW "SUPDUP output "NORMAL);
		    					break;
		    				case 23:
		    					printf(YELLOW "Send location "NORMAL);
		    					break;
		    				case 24:
		    					printf(YELLOW "Terminal type "NORMAL);
		    					break;
		    				case 25:
		    					printf(YELLOW "End of record "NORMAL);
		    					break;
		    				case 26:
		    					printf(YELLOW "TACACS user identification "NORMAL);
		    					break;
		    				case 27:
		    					printf(YELLOW "Output marking"NORMAL);
		    					break;
		    				case 28:
		    					printf(YELLOW "Terminal location number "NORMAL);
		    					break;
		    				case 29:
		    					printf(YELLOW "Telnet 3270 regime "NORMAL);
		    					break;
		    				case 30:
		    					printf(YELLOW "X.3 PAD "NORMAL);
		    					break;
		    				case 31:
		    					printf(YELLOW "Window size "NORMAL);
		    					break;
		    				case 32:
		    					printf(YELLOW "Terminal speed "NORMAL);
		    					break;
		    				case 33:
		    					printf(YELLOW "Remote flow control "NORMAL);
		    					break;
		    				case 34:
		    					printf(YELLOW "Linemode "NORMAL);
		    					break;
		    				case 35:
		    					printf(YELLOW "X display location"NORMAL);
		    					break;
		    				case 36:
		    					printf(YELLOW "Environment variables "NORMAL);
		    					break;
		    				case 39:
		    					printf(YELLOW "New environment options "NORMAL);
		    					break;
		    				case 240:
		    					printf(YELLOW "End of subnegotiation parameters "NORMAL);
		    					break;
		    				case 241:
		    					printf(YELLOW "No operation "NORMAL);
		    					break;
		    				case 242:
		    					printf(YELLOW "Data mark "NORMAL);
		    					break;
		    				case 243:
		    					printf(YELLOW "Break "NORMAL);
		    					break;
		    				case 244:
		    					printf(YELLOW "Suspend "NORMAL);
		    					break;
		    				case 245:
		    					printf(YELLOW "Abort output "NORMAL);
		    					break;
		    				case 246:
		    					printf(YELLOW "Are you there "NORMAL);
		    					break;
		    				case 247:
		    					printf(YELLOW "Erase character "NORMAL);
		    					break;
		    				case 248:
		    					printf(YELLOW "Erase line "NORMAL);
		    					break;
		    				case 249:
		    					printf(YELLOW "Go ahead "NORMAL);
		    					break;
		    				case 250:
		    					printf(YELLOW "Subnegotiation "NORMAL);
		    					break;
		    				case 251:
		    					printf(YELLOW "WILL "NORMAL);
		    					break;
		    				case 252:
		    					printf(YELLOW "WON'T "NORMAL);
		    					break;
		    				case 253:
		    					printf(YELLOW "DO "NORMAL);
		    					break;
		    				case 254:
		    					printf(YELLOW "DON'T "NORMAL);
		    					break;
		    				default:
		    					break;
		    			}

		    			i++;
		    			if(packet[i] == 255 || i >= size_payload) {
		    				j = 0;
		    			}
		    		}
		    	}
		    	else {
		    		if(packet[i-1] == '\n' || packet[i-1] == '\r' || i == 0) {
		    			printf(YELLOW "\t\t\t\t\t Data: " NORMAL);
		    		}
		    		printf(YELLOW "%c" NORMAL, packet[i]);
		    		i++;
		    	}
		    }
            printf("\n");
        }
	}
    else{
        if(verbose==1){
            printf("Telnet data ...\n");
        }
    }
}