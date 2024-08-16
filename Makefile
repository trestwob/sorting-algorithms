BIN = bin
SRC_DIR = src
INC = include

CFLAGS = -Iinclude -Wall -Wextra -pedantic -std=c17

SRC= main.c $(SRC_DIR)/print.c $(SRC_DIR)/bubble.c $(SRC_DIR)/array.c $(SRC_DIR)/merge.c $(SRC_DIR)/quick.c

OBJ= $(SRC:.c=.o)

TARGET = $(BIN)/main

all: $(TARGET)

.PHONY: all

$(BIN):
	mkdir -p $(BIN)

$(TARGET): $(BIN) $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)%.c | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: clean
