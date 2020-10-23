SRCMODULES = object.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -g -Wall
CPATH = ./object
VPATH = object 

CC=clang

%.o: %.c %.h %.r
	$(CC) $(CFLAGS) -c $< -o $@

main: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o main liboopc.a

lib:
	ar -rcs liboopc.a $(OBJMODULES)
