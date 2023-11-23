CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=-lpthread

OBJS := threads.o join-detach.o mutex-condvar.o

BINS := threads.out join-detach.out mutex-condvar.out

all: $(BINS)

threads.out: threads.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

join-detach.out: join-detach.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

mutex-condvar.out: mutex-condvar.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
