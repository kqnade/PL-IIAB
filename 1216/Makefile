CC = cc
CFLAGS = -Wall -c
LDFLAGS = -lncursesw
TARGET = ttt
SRCS = board.c game.c main.c
OBJS = $(SRCS:.c=.o)
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) $<
clean:
	rm -f $(OBJS) $(TARGET)
.PHONY: all clean

