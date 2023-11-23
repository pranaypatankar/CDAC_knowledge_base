CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := catch-ctrlc.o strsignal.o forking_signals.o 

BINS := catch-ctrlc.out strsignal.out forking_signals.out

all: $(BINS)

strsignal.out: strsignal.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

catch-ctrlc.out: catch-ctrlc.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

forking_signals.out: forking_signals.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
