SRCMODULES = object.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -g -Wall -I./ -Iobject
CPATH = ./object
VPATH = object 

%.o: %.c %.h %.r
	$(CC) $(CFLAGS) -c $< -o $@

main: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o main
