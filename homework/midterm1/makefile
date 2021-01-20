.PHONY: clean  
SRC =  src/node.h src/app.h src/folder.h src/iterator.h src/node_iterator.h src/null_iterator.h src/utility.h
TEST = test/ut_app.h test/ut_folder.h test/ut_iterator.h test/ut_utility.h
OBJ = obj/node.o

all:directories bin/ut_main

bin/ut_main: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp obj/node.o -o bin/ut_main -lgtest -lpthread

obj/node.o: src/node.cpp src/node.h
	g++ -std=c++11 -Wfatal-errors -c src/node.cpp -o obj/node.o

directories:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -rf bin
	rm -rf obj

stat:
	wc src/* test/*