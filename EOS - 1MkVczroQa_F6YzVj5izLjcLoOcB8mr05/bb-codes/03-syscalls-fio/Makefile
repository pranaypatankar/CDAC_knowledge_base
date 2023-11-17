CC=gcc
CFLAGS=-g -ggdb3 -Wno-unused-variable #-Wall
LDFLAGS=

OBJS := syscalls-copy.o clib-copy.o io-clib.o perror-strerror.o

BINS := syscalls-copy.out clib-copy.out io-clib.out perror-strerror.out

all: $(BINS)

syscalls-copy.out: syscalls-copy.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

clib-copy.out: clib-copy.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

io-clib.out: io-clib.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

perror-strerror.out: perror-strerror.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
