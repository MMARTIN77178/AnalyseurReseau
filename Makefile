OBJS	= main.o ethernet.o tcp.o arp.o
SOURCE	= main.c ethernet.c tcp.c arp.c
HEADER	= bootp.h arp.h
OUT		= analyseur
LFLAGS	= -lpcap
CFLAGS	= -Wall -g -Wextra

all: analyseur

analyseur: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)