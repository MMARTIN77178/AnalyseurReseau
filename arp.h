#ifndef ARP_H_INCLUDED
#define ARP_H_INCLUDED
/*
struct arp_hdr {
    uint16_t hw_type;
    unsigned short int pro_type;
    unsigned char hw_len;
    unsigned char pro_len;
    unsigned short int op;
    unsigned char sha[6];
    unsigned char spa[4];
    unsigned char tha[5];
    unsigned char tpa[4];
} __attribute__ ((__packed__));
*/

char *arp_hwtype(uint16_t hwtype);

char *arp_prot(uint16_t pro);

char *arp_opcode(uint16_t opcode);

char *get_ip_addr(uint8_t *ip);

#endif // ARP_H_INCLUDED
