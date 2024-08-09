CC=gcc

CFLAGS=-Wall -Wextra -O2

TARGET=bomb

all: $(TARGET)

$(TARGET): bomb.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean