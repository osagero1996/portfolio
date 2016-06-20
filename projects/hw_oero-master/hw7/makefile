
all: test2 test

test2: test2.cpp avlbst.h bst.h
	g++ -g -Wall $< -o $@

test: test.cpp bst.h
	g++ -g -Wall $< -o $@



.PHONY: clean

clean:
	rm -rf test2
	rm -rf test