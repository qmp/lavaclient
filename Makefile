SRC = ui/ui.c
OBJ = $(SRC:.c=.o)
MAIN_BIN = lavaclient
bin/$(MAIN_BIN): src/ui/ui.o
	cp src/ui/ui.o bin/$(MAIN_BIN)

%.o: %.c %.h
	gcc -o $*.o $*.c -lncurses

clean:
	-rm -f bin/$(MAIN_BIN) src/$(OBJ)
