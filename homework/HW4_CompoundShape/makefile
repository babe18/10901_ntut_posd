.PHONY: clean run mkdir

SRC = src/triangle.h src/ellipse.h src/rectangle.h src/two_dimensional_coordinate.h src/compound_shape.h src/shape.h src/shape.cpp
TEST = test/ut_triangle.h test/ut_ellipse.h test/ut_rectangle.h test/ut_compound_shape.h

all: clean mkdir hw hw4
hw4: test/ut_main.cpp $(SRC) $(TEST)
		g++ -std=c++11 -Wfatal-errors test/ut_main.cpp obj/shape.o -o bin/ut_main -lgtest -lpthread
hw: src/shape.cpp $(SRC) $(TEST)
	  g++ -std=c++11 -Wfatal-errors -c src/shape.cpp -o obj/shape.o -lgtest -lpthread
clean:
		rm -f bin/* rm -f obj/*
run:
		bin/ut_main
mkdir:
		mkdir -p bin
		mkdir -p obj
