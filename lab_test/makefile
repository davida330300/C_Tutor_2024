TARGET = test_example
SRC = example.c test_example.c
OBJ = $(SRC:.c=.o)

CFLAGS = -std=c11 -Wall -Wextra -pedantic
LDFLAGS = -lcheck -lm -lpthread -lrt -lsubunit

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
