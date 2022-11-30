OBJS	= main.o ethernet.o
SOURCE	= main.c ethernet.c
HEADER	= bootp.h
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