.PHONY: directories clean

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_ellipse.h test/ut_rectangle.h test/ut_triangle.h src/two_dimensional_coordinate.h src/ellipse.h src/rectangle.h src/shape.h src/triangle.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/*.h src/*.cpp test/*.h test/*.cpp
