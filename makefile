CPPS := $(shell find . -name "*.cpp")

all: run

build:
	clang++ -Isrc/ $(CPPS) -o out/idasm

run: build
	./out/idasm test/test.id test/test 
