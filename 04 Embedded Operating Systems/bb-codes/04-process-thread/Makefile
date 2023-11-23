CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := forking.o process-env.o 

BINS := forking.out process-env.out

all: $(BINS)

forking.out: forking.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

process-env.out: process-env.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
	make -C exec clean
	make -C flock clean
	make -C shmem clean
	make -C threads clean
	make -C signals clean
	make -C pipes clean
	make -C message-queues clean
	make -C sockets clean
