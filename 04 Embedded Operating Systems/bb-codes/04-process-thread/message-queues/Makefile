CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=-lrt

OBJS := mq-writer.o mq-reader.o
 
BINS := mq-writer.out mq-reader.out

all: $(BINS)

mq-writer.out: mq-writer.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

mq-reader.out: mq-reader.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
