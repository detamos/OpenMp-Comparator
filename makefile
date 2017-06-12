CC = gcc
CFLAGS = -c -Wall -std=gnu99 -I
LFLAGS = -Wall -std=gnu99 -I
OFLAGS = -fopenmp

DFLAGS = -g -Wextra -Werror

RM = rm 
RFLAGS = -r -f

INCLUDES = ./include/

SRCS1 = ./src/mergeSort/mergeSort.c ./src/mergeSort/main.c 
OBJS1 = $(SRCS1:.c=.o)
SRCS2 = ./src/fibonacci/fibonacci.c ./src/fibonacci/main.c
OBJS2 = $(SRCS2:.c=.o)


all : clean-objects  mergeSort fibonacci

clean: clean-objects
	$(RM) ./bin/*

clean-objects:
	$(RM) $(RFLAGS) ./src/mergeSort/*.o
	$(RM) $(RFLAGS) ./src/fibonacci/*.o

mergeSort: $(OBJS1)
	$(CC) $(LFLAGS) $(INCLUDES) $(OBJS1) -o ./bin/mergeSort -lm
fibonacci: $(OBJS2)
	$(CC) $(LFLAGS) $(INCLUDES) $(OBJS2) -o ./bin/fibonacci -lm
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@