#ifndef ARP_H_INCLUDED
#define ARP_H_INCLUDED

char *arp_hwtype(uint16_t hwtype);

char *arp_prot(uint16_t pro);

char *arp_opcode(uint16_t opcode);

char *get_ip_addr_arp(uint8_t *ip);

#endif // ARP_H_INCLUDED
