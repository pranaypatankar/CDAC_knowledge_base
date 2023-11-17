CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := forking.o 

BINS := forking.out 

all: $(BINS)

forking.out: forking.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
	make -C exec clean
	make -C flock clean
	make -C shmem clean
	make -C threads clean
