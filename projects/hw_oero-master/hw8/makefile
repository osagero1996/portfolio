SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
PRO_FOR = Problem4
PRO_FIV = prob5
CXX = g++
CPPFLAGS = -g -Wall


all: $(BIN_DIR)/.dirstamp  $(BIN_DIR)/test $(BIN_DIR)/hashtest $(BIN_DIR)/zipf

$(BIN_DIR)/zipf: $(BIN_DIR)/splaytree.o $(BIN_DIR)/hashtable.o zipf.cpp
	$(CXX) $(CPPFLAGS) $(BIN_DIR)/splaytree.o  $(BIN_DIR)/hashtable.o zipf.cpp -o $(BIN_DIR)/zipf

$(BIN_DIR)/test:  $(BIN_DIR)/splaytree.o test.cpp
	$(CXX) $(CPPFLAGS) $(BIN_DIR)/splaytree.o test.cpp -o $(BIN_DIR)/test

$(BIN_DIR)/hashtest: $(BIN_DIR)/hashtable.o hashtest.cpp
	$(CXX) $(CPPFLAGS) $(BIN_DIR)/hashtable.o hashtest.cpp -o $(BIN_DIR)/hashtest

$(BIN_DIR)/splaytree.o: $(SRC_DIR)/splaytree.cpp $(LIB_DIR)/splaytree.h $(LIB_DIR)/bst.h $(LIB_DIR)/Maps.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/splaytree.cpp -o $(BIN_DIR)/splaytree.o 

$(BIN_DIR)/hashtable.o: $(SRC_DIR)/hashtable.cpp $(LIB_DIR)/hashtable.h $(PRO_FIV)/Map.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/hashtable.cpp -o $(BIN_DIR)/hashtable.o




.PHONY: clean

clean:
	rm -rf $(BIN_DIR)



$(BIN_DIR)/.dirstamp: 
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp