SRC=backend
FILES=$(shell find $(SRC) -name '*.c' | sed 's/^.\///') 
HFILES=$(shell find $(SRC) -name '*.h' | sed 's/^.\///')
OCLEAN=$(shell find $(SRC) -name '*.o' | sed 's/^.\///')
OFILES=./backend/domain-specific/functions.o ./backend/support/logger.o ./backend/domain-specific/notes.o ./backend/support/utils.o ./backend/variables/variable.o ./backend/archivoPrueba.o

%.o: %.c $(HFILES)
	$(CC) -c -o $@ $<

all:$(OFILES)
	$(CC) $(OFILES) -o music

clean:
	rm -rf $(OCLEAN)