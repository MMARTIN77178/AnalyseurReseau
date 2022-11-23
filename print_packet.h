#include <stdio.h>
#include <pcap.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);