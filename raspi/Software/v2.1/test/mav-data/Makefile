# Compilation
CFLAGS= -o
CC=gcc $(CFLAGS)
# Headers
HEAD=server.h

# binary folder
DIR=/home/pi/raspi/test/mav-data/
# source folder
BIN=$(DIR)bin/
SRC=$(DIR)src/*.c 


all: main

main:
	$(CC) main  $(SRC)

rebuild: clean all

clean:
	@echo "cleanning project"
	rm  -rf main *.o
	@echo "clean completed"
