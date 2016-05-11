

main: main.o wiringSerial.o udpinit.o
	gcc main.o wiringSerial.o udpinit.o mavlinkParse.h -o main

main.o: main.c 
	gcc -c main.c

wiringSerial.o: wiringSerial.c
	gcc -c wiringSerial.c 

udpinit.o: udpinit.c
	gcc -c udpinit.c



clean:
	@echo "cleanning project"
	rm  -rf main *.o
	@echo "clean completed"
