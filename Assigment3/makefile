.PHONY: dirs clean

CC = g++
SRC = src/rectangle.h src/triangle.h src/ellipse.h src/two_dimensional_coordinate.h src/sort.h src/terminal.h
TEST = test/ut_rectangle.h test/ut_triangle.h test/ut_ellipse.h test/ut_sort.h test/ut_terminal.h
BIN = ./bin
OBJ = ./obj
LIB = -lgtest -lpthread
CFLAGS = -std=c++11

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	$(CC) $(CFLAGS) -o $(BIN)/ut_main test/ut_main.cpp $(LIB)

dirs:
	mkdir -p $(OBJ) $(BIN)
	
clean:
	rm -rf $(BIN) $(OBJ)
