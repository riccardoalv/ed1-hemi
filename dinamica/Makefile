OBJS   = main.o  stackDynamic.o
SOURCE = main.c  stackDynamic.c
HEADER =  stackDynamic.h
OUT    = a.out
CC     = gcc
FLAGS  = -g -c -Wall
LFLAGS =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

stackDynamic.o: stackDynamic.c
	$(CC) $(FLAGS) stackDynamic.c 

clean:
	rm -f $(OBJS) $(OUT)
