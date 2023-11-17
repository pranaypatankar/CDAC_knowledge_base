CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=

OBJS := execl.o execlp.o execle.o execv.o execvp.o execve.o 

BINS := execl.out execlp.out execle.out execv.out execvp.out execve.out 

all: $(BINS)

execl.out: execl.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

execlp.out: execlp.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

execle.out: execle.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

execv.out: execv.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

execvp.out: execvp.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

execve.out: execve.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) file.*
