CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := get-ip.o sock-server.o sock-client.o

BINS := get-ip.out sock-server.out sock-client.out

all: $(BINS)

get-ip.out: get-ip.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

sock-server.out: sock-server.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

sock-client.out: sock-client.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
