CXX=g++
CURSES_INC=.
CXXFLAGS=-std=c++11 -I$(CURSES_INC)
LDFLAGS=-L$(CURSES_LIB) -static-libstdc++ -lcurses

OBJ=player.o screen.o main.o

all: $(OBJ)
	g++ $(OBJ) $(LDFLAGS) -o blackness

clean:
	rm *.o
	rm *.exe