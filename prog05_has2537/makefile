
# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.
#g++ -std=c++11 -o UTPod  UTPodDriver.cpp UTPod.cpp Song.cpp

final: UTPodDriver.o UTPod.o Song.o
	g++ -o UTPod UTPodDriver.o UTPod.o Song.o
driver: UTPodDriver.cpp UTPod.h Song.h
	g++ -c UTPodDriver.cpp
UtPod.o: UTPod.cpp UTPod.h Song.h
	g++ -c UTPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp