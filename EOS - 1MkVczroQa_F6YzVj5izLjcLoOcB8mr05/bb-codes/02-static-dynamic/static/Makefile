CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=-lm
AR=ar
RANLIB=ranlib

OBJS = find_tan.o
STATIC_LIB = find_tan.a

all: a.out

a.out:	main.o $(STATIC_LIB)  
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -static -o a.out

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJS)
	$(AR) rc $@ $^
	$(RANLIB) $@

clean:
	rm -rf a.out *.o $(STATIC_LIB)
