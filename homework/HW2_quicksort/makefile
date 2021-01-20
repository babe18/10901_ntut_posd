.PHONY: dirs clean

SRC = src/triangle.h src/ellipse.h src/shape.h src/sort.h src/rectangle.h src/two_dimensional_coordinate.h
TEST = test/ut_sort.h test/ut_triangle.h test/ut_ellipse.h test/ut_rectangle.h

all: dirs ut_main

ut_main: test/ut_main.cpp $(SRC) $(TEST)
				g++ test/ut_main.cpp -o bin/ut_main -lgtest -lpthread -Wfatal-errors

clean:
	rm -f bin/*
dirs:
	mkdir -p bin
