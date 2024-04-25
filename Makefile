# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Output executable names for each part
TARGET1 = lab13_part1
TARGET2 = lab13_part2

# Source files for each target
SRCS1 = lab13_part1.c
SRCS2 = lab13_part2.c

# Default target (build both parts)
all: $(TARGET1) $(TARGET2)

# Build target for part 1
$(TARGET1): $(SRCS1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SRCS1)

# Build target for part 2
$(TARGET2): $(SRCS2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SRCS2)

# Clean target to remove executables
clean:
	rm -f $(TARGET1) $(TARGET2)

# Additional targets
.PHONY: all clean
