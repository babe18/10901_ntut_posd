.PHONY: clean run mkdir

SRC = src/triangle.h src/ellipse.h src/shape.h src/sort.h src/rectangle.h src/two_dimensional_coordinate.h src/terminal.h
TEST = test/ut_sort.h test/ut_triangle.h test/ut_ellipse.h test/ut_rectangle.h test/ut_terminal.h

all: clean mkdir hw3 geo execute
hw3: test/ut_main.cpp $(SRC) $(TEST)
		g++ -std=c++11 -Wfatal-errors test/ut_main.cpp -o bin/ut_main  -lgtest -lpthread

geo: src/main.cpp $(SRC) $(TEST)
		g++ -std=c++11 -Wfatal-errors src/main.cpp -o bin/geo  -lgtest -lpthread

execute:
		bin/geo input.txt output.txt area inc

clean:
		rm -f bin/* rm -f output.txt
run:
		bin/ut_main
mkdir:
		mkdir -p bin
