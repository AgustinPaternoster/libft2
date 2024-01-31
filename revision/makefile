CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES := $(wildcard *.c)
BINARY = app

$(BINARY) : $(CFILES)
		$(CC) $(CFLAGS) -o $@ $^

clean:
		rm -f $(BINARY)