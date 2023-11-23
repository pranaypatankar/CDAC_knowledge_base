CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := variadic-1.o

BINS := variadic-1.out

all: $(BINS)

variadic-1.out: variadic-1.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) *.json
