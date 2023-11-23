CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=-lcjson

OBJS := json-writer.o json-reader.o json-array-writer.o json-array-reader.o json-writer2.o json-array-reader-sys.o json-array-writer-sys.o

BINS := json-writer.out json-reader.out json-array-writer.out json-array-reader.out json-writer2.out json-array-reader-sys.out json-array-writer-sys.out

all: $(BINS)

#json-writer.out: json-writer.o
#	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

#json-reader.out: json-reader.o
#	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

#json-array-writer.out: json-array-writer.o
#	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

#json-array-reader.out: json-array-reader.o
#	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

#json-writer2.out: json-writer.o
#	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.out : %.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINS) *.json
