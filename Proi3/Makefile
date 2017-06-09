all: program

program: main.o Position.o Rocket.o MyDefRocket.o OpponentRocket.o MyAttRocket.o Launcher.o Menu.o Test.o
	g++ -o program main.o Position.o Rocket.o MyDefRocket.o OpponentRocket.o MyAttRocket.o Launcher.o Menu.o Test.o

main.o: main.cpp Position.h Rocket.h MyDefRocket.h OpponentRocket.h MyAttRocket.h Launcher.h Menu.h Test.h
	g++ -c main.cpp

Position.o: Position.cpp Position.h
	g++ -c Position.cpp

Rocket.o: Rocket.cpp Rocket.h 
	g++ -c Rocket.cpp

MyDefRocket.o: MyDefRocket.cpp MyDefRocket.h Rocket.h Position.h
	g++ -c MyDefRocket.cpp

MyAttRocket.o: MyAttRocket.cpp MyAttRocket.h Rocket.h Position.h
	g++ -c MyAttRocket.cpp

OpponentRocket.o: OpponentRocket.cpp OpponentRocket.h Rocket.h Position.h
	g++ -c OpponentRocket.cpp

Launcher.o: Launcher.cpp Launcher.h Position.h Rocket.h MyDefRocket.h OpponentRocket.h MyAttRocket.h
	g++ -c Launcher.cpp

Menu.o: Menu.cpp Menu.h Launcher.h Position.h Rocket.h MyDefRocket.h OpponentRocket.h MyAttRocket.h
	g++ -c Menu.cpp

Test.o: Test.cpp Test.h Launcher.h Position.h Rocket.h MyDefRocket.h OpponentRocket.h MyAttRocket.h
	g++ -c Test.cpp

clean:
	rm -rf *o program
