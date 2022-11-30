#include "bootp.h"

void sigint_handler(){
    pcap_breakloop(handle);
    printf("\n Capture stopped by user\n");
}

int verbose=1;

int main(int argc, char *argv[]){
    char errbuf[PCAP_ERRBUF_SIZE] = {0};
    pcap_t *handle;
    
    const u_char *packet;
    struct pcap_pkthdr packet_header;

    char * filter_exp = NULL;
    struct bpf_program filter;
    char *device;
    char* file = NULL;

    bpf_u_int32 mask;
	bpf_u_int32 net;

    signal(SIGINT, sigint_handler);


    while((opt = getopt(argc, argv, "i:o:f:v:")) != -1){
        switch(opt){
            case 'i':
                device = optarg;
                break;
            case 'o':
                file = optarg;
                break;
            case 'f':
                filter_exp = optarg;
                break;
            case 'v':
                if(atoi(optarg) > 0 && atoi(optarg) < 4){
                    verbose = atoi(optarg);
                }
                else{
                    printf("Niveau de verbosité invalide\n
                    -v <1-3> : Niveau de verbosité (1=très concis ; 2=synthétique ; 3=complet)\n
                    la verbosité par défaut va être appliquée, soit le niveau 1\n");
                }
                break;
            default:
                //On pourrait faire une fonction "usage" mais ici la fonction est trop courte pour en faire une.
                printf("Usage: %s [-i device] [-o output] [-f filter] [-v verbose]\n", argv[0]);
                exit(1);
        }
    }
        if(dev == NULL) {
		    dev = pcap_lookupdev(errbuf);
		    if (dev == NULL) {
				fprintf(stderr, "L'interface par défaut n'a pas été trouvée: %s\n", errbuf);
				return -1;
		    }
	    }

        if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
		    fprintf(stderr, "Impossible d'obtenir le Netmask de l'interface %s: %s\n", dev, errbuf);
		    net = 0;
		    mask = 0;
	    }

        if(file==NULL){
            handle = pcap_open_live(device, BUFSIZ,1,0,errbuf);
            if(handle == NULL){
                perror("ERREUR: Impossible d'ouvrir le périphérique pcap\n");
                return -1
            }
            if(filter_exp != NULL){
                if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
                    fprintf(stderr, "Impossible d'analyser le filtre %s: %s\n", filter_exp, pcap_geterr(handle));
                    return -1;
                }
                if (pcap_setfilter(handle, &filter) == -1) {
                    fprintf(stderr, "Impossible d'installer le filtre %s: %s\n", filter_exp, pcap_geterr(handle));
                    return -1;
                }
            }
        }
        else{
            handle = pcap_open_offline(file, errbuf);
            if (handle == NULL) {
                fprintf(stderr, "Impossible d'ouvrir le fichier %s: %s\n", file, errbuf);
                return -1;
            }
        }

        pcap_loop(handle, 0, print_packet, NULL);
        pcap_close(handle);
        return 0;
}