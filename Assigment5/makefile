.PHONY: clean run mkdir

SRC = src/triangle.h src/ellipse.h src/rectangle.h src/two_dimensional_coordinate.h \
			src/compound_shape.h src/shape.h src/shape.cpp src/iterator.h src/iterator.h \
			src/null_iterator.h src/shape_iterator.h src/utility.h
TEST = test/ut_triangle.h test/ut_ellipse.h test/ut_rectangle.h test/ut_compound_shape.h \
			 test/ut_iterator.h test/ut_utility.h

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



# .PHONY: dirs clean run
#
# all : clean dirs ut_main shape
#
# ut_main: test/ut_ellipse.h test/ut_rectangle.h test/ut_triangle.h test/ut_compound_shape.h src/shape.cpp src/compound_shape.h src/ellipse.h src/rectangle.h src/shape.h src/triangle.h src/two_dimensional_coordinate.h
# 	   g++ -std=c++11 -Wfatal-errors -g test/ut_main.cpp -o bin/ut_main -lgtest -lpthread
# shape: src/shape.cpp test/ut_ellipse.h test/ut_rectangle.h test/ut_triangle.h test/ut_compound_shape.h src/shape.cpp src/compound_shape.h src/ellipse.h src/rectangle.h src/shape.h src/triangle.h src/two_dimensional_coordinate.h
# 		 g++ -std=c++11 -Wfatal-errors -c src/shape.cpp -o obj/shape.o -lgtest -lpthread
#
# dirs:
# 	mkdir -p bin
# 	mkdir -p obj
# clean:
# 	rm -f bin/* rm -f obj/*
