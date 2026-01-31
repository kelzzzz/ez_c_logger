CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
LIB_NAME = libezlogger.a

SRC_DIR = src
INC_DIR = include
OBJ_DIR = dist

SRC = $(SRC_DIR)/ez_logger.c
OBJ = $(OBJ_DIR)/ez_logger.o

all: $(OBJ_DIR) $(LIB_NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME)