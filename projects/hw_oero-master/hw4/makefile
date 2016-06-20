SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall


all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/Facile


$(BIN_DIR)/Facile: $(BIN_DIR)/LetStatement.o $(BIN_DIR)/ReturnStatement.o $(BIN_DIR)/stackint.o $(BIN_DIR)/llistint.o $(BIN_DIR)/GosubStatement.o $(BIN_DIR)/IfStatement.o $(BIN_DIR)/GotoStatement.o $(BIN_DIR)/DivStatement.o $(BIN_DIR)/MultStatement.o $(BIN_DIR)/SubStatement.o $(BIN_DIR)/ProgramState.o $(BIN_DIR)/AddStatement.o $(BIN_DIR)/PrintAllStatement.o $(BIN_DIR)/EndStatement.o $(BIN_DIR)/PrintStatement.o
	$(CXX) $(CPPFLAGS) $(BIN_DIR)/LetStatement.o $(BIN_DIR)/ReturnStatement.o $(BIN_DIR)/stackint.o $(BIN_DIR)/llistint.o $(BIN_DIR)/GosubStatement.o $(BIN_DIR)/IfStatement.o $(BIN_DIR)/GotoStatement.o $(BIN_DIR)/DivStatement.o $(BIN_DIR)/MultStatement.o $(BIN_DIR)/SubStatement.o $(BIN_DIR)/AddStatement.o $(BIN_DIR)/PrintAllStatement.o $(BIN_DIR)/ProgramState.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/EndStatement.o Facile.cpp -o $(BIN_DIR)/Facile

$(BIN_DIR)/LetStatement.o: $(SRC_DIR)/LetStatement.cpp $(LIB_DIR)/LetStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/LetStatement.cpp -o $(BIN_DIR)/LetStatement.o 

$(BIN_DIR)/ProgramState.o: $(SRC_DIR)/ProgramState.cpp $(LIB_DIR)/ProgramState.h 
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/ProgramState.cpp -o $(BIN_DIR)/ProgramState.o

$(BIN_DIR)/EndStatement.o: $(SRC_DIR)/EndStatement.cpp $(LIB_DIR)/EndStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/EndStatement.cpp -o $(BIN_DIR)/EndStatement.o

$(BIN_DIR)/PrintStatement.o: $(SRC_DIR)/PrintStatement.cpp $(LIB_DIR)/PrintStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/PrintStatement.cpp -o $(BIN_DIR)/PrintStatement.o

$(BIN_DIR)/PrintAllStatement.o: $(SRC_DIR)/PrintAllStatement.cpp $(LIB_DIR)/PrintAllStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/PrintAllStatement.cpp -o $(BIN_DIR)/PrintAllStatement.o

$(BIN_DIR)/AddStatement.o: $(SRC_DIR)/AddStatement.cpp $(LIB_DIR)/AddStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/AddStatement.cpp -o $(BIN_DIR)/AddStatement.o

$(BIN_DIR)/SubStatement.o: $(SRC_DIR)/SubStatement.cpp $(LIB_DIR)/SubStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/SubStatement.cpp -o $(BIN_DIR)/SubStatement.o

$(BIN_DIR)/MultStatement.o: $(SRC_DIR)/MultStatement.cpp $(LIB_DIR)/MultStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/MultStatement.cpp -o $(BIN_DIR)/MultStatement.o

$(BIN_DIR)/DivStatement.o: $(SRC_DIR)/DivStatement.cpp $(LIB_DIR)/DivStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/DivStatement.cpp -o $(BIN_DIR)/DivStatement.o 	

$(BIN_DIR)/GotoStatement.o: $(SRC_DIR)/GotoStatement.cpp $(LIB_DIR)/GotoStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/GotoStatement.cpp -o $(BIN_DIR)/GotoStatement.o 

$(BIN_DIR)/IfStatement.o: $(SRC_DIR)/IfStatement.cpp $(LIB_DIR)/IfStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/IfStatement.cpp -o $(BIN_DIR)/IfStatement.o 

$(BIN_DIR)/GosubStatement.o: $(SRC_DIR)/GosubStatement.cpp $(LIB_DIR)/GosubStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/GosubStatement.cpp -o $(BIN_DIR)/GosubStatement.o

$(BIN_DIR)/stackint.o: $(SRC_DIR)/stackint.cpp $(LIB_DIR)/stackint.h 
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/stackint.cpp -o $(BIN_DIR)/stackint.o 

$(BIN_DIR)/llistint.o: $(SRC_DIR)/llistint.cpp $(LIB_DIR)/llistint.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/llistint.cpp -o $(BIN_DIR)/llistint.o

$(BIN_DIR)/ReturnStatement.o: $(SRC_DIR)/ReturnStatement.cpp $(LIB_DIR)/ReturnStatement.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/ReturnStatement.cpp -o $(BIN_DIR)/ReturnStatement.o








# target: is the thing we want to make.
# dependencies are all of the things that need to exist or if they have been changed, we have to recompile
# system commands: are the things we want to do once we have all of the dependencies set. 
# <target>: <dependencies>:
#	<system commands>

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)


$(BIN_DIR)/.dirstamp: 
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp


target: dependencies
	command (compile something)
