OBJS   = main.o stackStatic.o
SOURCE = main.c stackStatic.c
HEADER = stackStatic.h
OUT    = a.out
CC     = gcc
FLAGS  = -g -c -Wall
LFLAGS =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

stackStatic.o: stackStatic.c
	$(CC) $(FLAGS) stackStatic.c 

clean:
	rm -f $(OBJS) $(OUT)
