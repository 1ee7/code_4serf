
main: main.o wiringSerial.o task1_mavdata.o init.o task2_videodata.o 
	gcc  main.o wiringSerial.o task1_mavdata.o init.o task2_videodata.o  -o main

main.o: main.c 
	gcc -c main.c

wiringSerial.o: wiringSerial.c wiringSerial.h
	gcc -c wiringSerial.c wiringSerial.h

init.o: init.c init.h
	gcc -c init.c init.h

task1_mavdata.o: task1_mavdata.c task1_mavdata.h global.h
	gcc -c task1_mavdata.c task1_mavdata.h

task2_videodata.o: task2_videodata.c task2_videodata.h global.h
	gcc -c task2_videodata.c task2_videodata.h

clean:
	@echo "cleanning project"
	rm  -rf main *.o *.gch
	@echo "clean completed"
