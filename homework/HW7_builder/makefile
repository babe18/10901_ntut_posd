.PHONY: clean run mkdir

SRC = src/triangle.h src/ellipse.h src/rectangle.h src/two_dimensional_coordinate.h src/compound_shape.h src/shape.h src/shape.cpp src/shape_iterator.h src/iterator.h src/null_iterator.h src/utility.h src/visitor.h src/area_visitor.h src/info_visitor.h src/shape_builder.h src/scanner.h src/shape_parser.h
TEST = test/ut_triangle.h test/ut_ellipse.h test/ut_rectangle.h test/ut_compound_shape.h test/ut_iterator.h test/ut_utility.h test/ut_visitor.h test/ut_shape_builder.h test/ut_scanner.h test/ut_shape_parser.h

all: clean mkdir hw hw6
hw6: test/ut_main.cpp $(SRC) $(TEST)
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
