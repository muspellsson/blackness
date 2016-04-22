CXX=g++
CURSES_INC=.
WARNINGS=-g -O -Wall -Weffc++ -pedantic  \
-pedantic-errors -Wextra -Waggregate-return -Wcast-align \
-Wcast-qual -Wconversion \
-Wdisabled-optimization \
-Wfloat-equal -Wformat=2 \
-Wformat-nonliteral -Wformat-security  \
-Wformat-y2k \
-Wimport  -Winit-self  -Winline \
-Winvalid-pch   \
-Wlong-long \
-Wmissing-field-initializers -Wmissing-format-attribute   \
-Wmissing-include-dirs -Wmissing-noreturn \
-Wpacked  -Wpadded -Wpointer-arith \
-Wredundant-decls \
-Wshadow -Wstack-protector \
-Wstrict-aliasing=2 -Wswitch-default \
-Wswitch-enum \
-Wunreachable-code -Wunused \
-Wunused-parameter \
-Wvariadic-macros \
-Wwrite-strings
CXXFLAGS=-std=c++11 -I$(CURSES_INC) $(WARNINGS)
LDFLAGS=-L$(CURSES_LIB) -static-libstdc++ -lcurses

OBJ=map.o player.o screen.o terrain.o window.o main.o

all: $(OBJ)
	g++ $(OBJ) $(LDFLAGS) -o blackness

clean:
	rm -f *.o
	rm -f *.exe