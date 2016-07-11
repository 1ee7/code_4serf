
main: main.o wiringSerial.o task1_mavdata.o init.o task2_videodata.o config.o 
	gcc  $^ -o $@

main.o: main.c 
	gcc -c $^

wiringSerial.o: wiringSerial.c wiringSerial.h
	gcc -c $^

init.o: init.c init.h global.h
	gcc -c $^

task1_mavdata.o: task1_mavdata.c task1_mavdata.h
	gcc -c $^

task2_videodata.o: task2_videodata.c task2_videodata.h
	gcc -c $^

config.o: config.c
	gcc -c $^


clean:
	@echo "cleanning project"
	rm  -rf main *.o *.gch
	@echo "clean completed"
