CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := flock-writer.o flock-reader.o 

BINS := flock-writer.out flock-reader.out

all: $(BINS)

flock-writer.out: flock-writer.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

flock-reader.out: flock-reader.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
