SRC_DIR = src
INC_DIR = inc

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
DOC_DIR = $(BUILD_DIR)/doc

PROGRAM = $(BIN_DIR)/lab5

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -I$(INC_DIR)

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEP_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC_FILES))

all: $(PROGRAM)

$(PROGRAM): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEP_FILES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(PROGRAM)

doc:
	doxygen Doxyfile

exe: all
	@$(PROGRAM)