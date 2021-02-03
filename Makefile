CC = cc
CFLAGS = -std=c89 -pedantic -Wall

objects := $(patsubst %.c,%.o,$(wildcard *.c))

all: build run

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

build: $(objects)
	$(CC) $(CFLAGS) -o pcc $^

run:
	./pcc

clean:
	rm *.o pcc
