#include "pcap.h"
#include <stdlib.h>
#include <time.h>

#include "bootp.h"
#include "color.h"

int n;

void print_packet_info(struct pcap_pkthdr packet_header) {
    printf("Packet capture length: %d\n", packet_header.caplen);
    printf("Packet total length %d\n", packet_header.len);
}

void print_packet(u_char *user_args, const u_char *packet, struct pcap_pkthdr packet_header){
    (void)user_args;
    (void)packet;
    printf("==== Got a %d byte packet ====\n", packet_header.len);
}



int main()
{
    char errbuf[PCAP_ERRBUF_SIZE] = {0};
    pcap_t *handle;
    
    const u_char *packet;
    struct pcap_pkthdr packet_header;

    struct bpf_program fp;
    bpf_u_int32 net; //mask;
    const char *filter_exp;

    char *device = "eth0";
    handle = pcap_open_live(device, BUFSIZ,1,10000,errbuf);
    if(handle == NULL){                                      // << Passes since value is NULL (typically zero).
        perror("ERROR: while opening pcap device");
        exit(1);
    }
    printf("ok\n");
    packet = pcap_next(handle, &packet_header);
    if (packet == NULL) {
        printf("No packet found.\n");
        return 2;
    }

    printf("ok\n");
    print_packet_info(packet_header);
    printf("ok\n");
    return 0;

      if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n",
        filter_exp, pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  /* apply the compiled filter */
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n",
        filter_exp, pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  pcap_loop(handle, 0, print_packet, NULL);
}

