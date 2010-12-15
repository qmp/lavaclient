SRC = ui/ui.c
OBJ = $(SRC:.c=.o)
MAIN_BIN = lavaclient
bin/$(MAIN_BIN): src/ui/ui.o bin
	cp src/ui/ui.o bin/$(MAIN_BIN)

bin:
	mkdir -p bin

%.o: %.c %.h
	gcc -o $*.o $*.c -lncurses

clean:
	-rm -f bin/$(MAIN_BIN) src/$(OBJ)
