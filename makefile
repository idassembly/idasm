CC=g++
CPPFLAGS=-g -O2 -Wall -Wextra -Isrc/include

IDASM=idasm

CPPFILES = $(shell find src -type f -name '*.cpp')

build:
	$(CC) $(CPPFLAGS) $(CPPFILES) -o $(IDASM)
