all: build/bubble
.PHONY: all
build:
	@echo "building directory $@"
	mkdir -p $@

build/bubble: bubble.c print.c | build
	$(CC) -o $@ bubble.c print.c -Wall -Wextra -pedantic -std=c17
