# Makefile

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = my_program

# Source files
SRCS = main.c cal.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation step
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)
