
main: main.o wiringSerial.o
	gcc main.o wiringSerial.o -o main

main.o: main.c  wiringSerial.h
	gcc -c main.c

wiringSerial.o: wiringSerial.c wiringSerial.h
	gcc -c wiringSerial.c 
