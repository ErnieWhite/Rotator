CLFAGS = -Wall -Wextra -mwindows -g
CC = gcc
TARGET = monitor_info.exe
SRC = main.C

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
