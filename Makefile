CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/memory_pool.c

TEST = test/test_memory_pool.c

TARGET = mp

all:
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean all
