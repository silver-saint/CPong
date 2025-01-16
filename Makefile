# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Project name and files
TARGET = $(BIN_DIR)/sdl2_app
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Ensure necessary directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Default target: build the application
all: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile C source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rebuild the project from scratch
rebuild: clean all
# Debug target to run with gdb
debug: $(TARGET)
	@echo "Running in gdb..."
	@SDL_DEBUG=1 SDL_VIDEODRIVER=x11 gdb attach 6466  -ex lay next  --args $(TARGET)

.PHONY: all clean rebuild debug
