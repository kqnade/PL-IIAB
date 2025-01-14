CC = gcc
CFLAGS = 
LDFLAGS =
# Target programs
TARGET1 = pendraw
TARGET2 = pdcl
# Source files
SRC1 = pendraw.c
SRC2 = pdcl.c
# Libraries
LIBS = -lncurses
# Default target to build both programs
all: $(TARGET1) $(TARGET2)
# Rule for building pendraw
$(TARGET1): $(SRC1)
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET1) $(LIBS)
# Rule for building pdcl
$(TARGET2): $(SRC2)
	$(CC) $(CFLAGS) $(SRC2) -o $(TARGET2)
# Clean up object and binary files
clean:
	rm -f $(TARGET1) $(TARGET2)
# PHONY targets
.PHONY: all clean
