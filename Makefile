CC = gcc
CFLAGS = -Wall -Wextra

SRCS = ipc.c main.c time.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o time
