CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=-lrt -lpthread

OBJS := shmem-writer.o shmem-reader.o

BINS := shmem-writer.out shmem-reader.out

all: $(BINS)

shmem-writer.out: shmem-writer.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

shmem-reader.out: shmem-reader.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
