CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := unnamed-pipe.o fifo-writer.o fifo-reader.o

BINS := unnamed-pipe.out fifo-writer.out fifo-reader.out

all: $(BINS)

unnamed-pipe.out: unnamed-pipe.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

fifo-writer.out: fifo-writer.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

fifo-reader.out: fifo-reader.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
