CC = gcc
CFLAGS = -Wall -g -lm -lpcap
EXEC  = telnet
HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(EXEC)

telnet: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
	rm -f *.gch
	rm -f *.a
	rm -f .[a-Z]*
