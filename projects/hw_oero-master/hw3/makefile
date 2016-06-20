SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall
GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread



all: $(BIN_DIR)/.dirstamp main $(BIN_DIR)/hw3

parse: parse.cpp $(BIN_DIR)/stackint.o $(BIN_DIR)/llistint.o
	$(CXX) $(CPPFLAGS) parse.cpp stackint.cpp llistint.cpp $(BIN_DIR)/stackint.o $(BIN_DIR)/llistint.o -o $(BIN_DIR)/parse

$(BIN_DIR)/stackint.o: stackint.h stackint.cpp
	$(CXX) $(CPPFLAGS) -c stackint.cpp -o $(BIN_DIR)/stackint.o

$(BIN_DIR)/llistint.o: llistint.h llistint.cpp
	$(CXX) $(CPPFLAGS) -c llistint.cpp -o $(BIN_DIR)/llistint.o

llisttest: llisttest.cpp $(BIN_DIR)/llistint.o
	$(CXX) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp: 
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

target: dependencies
	command (compile something)



