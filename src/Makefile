

main: main.o wiringSerial.o
	gcc main.o wiringSerial.o -o main

main.o: main.c 
	gcc -c main.c

wiringSerial.o: wiringSerial.c
	gcc -c wiringSerial.c 


clean:
	@echo "cleanning project"
	rm main *.o
	@echo "clean completed"