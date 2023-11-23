x86_CC=gcc
ARM_CC=arm-linux-gnueabihf-gcc 

BINS := a.out.x86 a.out.arm

all: $(BINS)

a.out.x86: a.c
	$(x86_CC) -Wall -g -ggdb3 $< -o $@

a.out.arm: a.c
	$(ARM_CC) -Wall -g -ggdb3 $< -o $@

clean:
	rm -rf $(BINS)

