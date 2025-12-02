CC = gcc
CFLAGS = -Wall -Wextra -O2 -Isrc

SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))

build/crox: $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

run: build/crox
	./build/crox

clean:
	rm -rf build

