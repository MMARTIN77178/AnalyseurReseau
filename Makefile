OBJS	= main.o ethernet.o tcp.o arp.o udp.o http.o dns.o ftp.o smtp.o telnet.o pop.o imap.o
SOURCE	= main.c ethernet.c tcp.c arp.c udp.c http.c dns.c ftp.c smtp.c	telnet.c pop.c imap.c
HEADER	= bootp.h arp.h dns.h
OUT		= analyseur
LFLAGS	= -lpcap
CFLAGS	= -Wall -g -Wextra
CC		= gcc


all: analyseur

analyseur: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)