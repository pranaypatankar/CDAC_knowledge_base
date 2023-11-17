CC=gcc
CFLAGS=-g -ggdb3 -Wall -fPIC
LDFLAGS=-lfind_tan -I./ -L./ -lm
AR=ar
RANLIB=ranlib

OBJS = find_tan.o
DYNAMIC_LIB_PATH=$(PWD)
DYNAMIC_LIB = $(DYNAMIC_LIB_PATH)/libfind_tan.so

all: a.out

a.out:	main.o $(DYNAMIC_LIB) 
	$(CC) $< $(CFLAGS) $(LDFLAGS) -Wl,-rpath=$(DYNAMIC_LIB_PATH) -o a.out
	@#echo "********* Run export LD_LIBRARY_PATH=${DYNAMIC_LIB_PATH}:/lib now *********"

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNAMIC_LIB): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

clean:
	rm -rf a.out *.o $(DYNAMIC_LIB)
