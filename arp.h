#ifndef ARP_H_INCLUDED
#define ARP_H_INCLUDED

#define HARDWARETYPE_ETHERNET 0x0001
#define HARDWARETYPE_EXP_ETHERNET 0x0002

struct arp_hdr {
    uint8_t hw_type;
    unsigned short int pro_type;
    unsigned char hw_len;
    unsigned char pro_len;
    unsigned short int op;
    unsigned char sha[6];
    unsigned char spa[4];
    unsigned char tha[5];
    unsigned char tpa[4];
} __attribute__ ((__packed__));

char *arp_hwtype(uint16_t hwtype);



#endif // ARP_H_INCLUDED