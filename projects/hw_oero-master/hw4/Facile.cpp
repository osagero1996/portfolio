// Facile.cpp
#include "lib/Statement.h"
#include "lib/LetStatement.h"
#include "lib/ProgramState.h"
#include "lib/EndStatement.h"
#include "lib/PrintStatement.h"
#include "lib/PrintAllStatement.h"
#include "lib/AddStatement.h"
#include "lib/SubStatement.h"
#include "lib/MultStatement.h"
#include "lib/DivStatement.h"
#include "lib/GotoStatement.h"
#include "lib/IfStatement.h"
#include "lib/GosubStatement.h"
#include "lib/ReturnStatement.h" 
#include "lib/stackint.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);

		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(std::string line)
{
	Statement * statement;	
	stringstream ss;
	stringstream aa;
	string type;
	string var;
	string carrie;
	string comp;
	int x;
	int y;
	int val;
	const int a = 1;
	const int b = 2;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	if(type == "END" || type == ".")
	{
		statement = new EndStatement();
	}

	if(type == "PRINT")
	{
		ss >> var;
		statement = new PrintStatement(var);
	}

	if(type == "PRINTALL")
	{
		statement = new PrintAllStatement();
	}

	if(type == "ADD")
	{

		ss >> var;
		ss >> carrie;

	

		if(carrie[0] >= 48 && carrie[0] <= 57)
		{
			aa << carrie;
			aa >> val;
			statement = new AddStatement(var, val, a);

		}
		else
		{
			statement = new AddStatement(var, carrie, b);
		}


	}

	if(type == "SUB")
	{
		ss >> var;
		ss >> carrie;
		if(carrie[0] >= 48 && carrie[0] <= 57)
		{
			aa << carrie;
			aa >> val;
			statement = new SubStatement(var, val, a);

		}
		else
		{
			statement = new SubStatement(var, carrie, b);
		}
	}

	if(type == "MULT")
	{
		ss >> var;
		ss >> carrie;

		if(carrie[0] >= 48 && carrie[0] <= 57)
		{
			aa << carrie;
			aa >> val;
			statement = new MultStatement(var, val, a);
		}
		else
		{
			statement = new MultStatement(var, carrie, b);
		}

	}

	if(type == "DIV")
	{
		ss >> var;
		ss >> carrie;

		if(carrie[0] >= 48 && carrie[0] <= 57)
		{
			aa << carrie;
			aa >> val;
			statement = new DivStatement(var, val, a);
		}
		else
		{
			statement = new DivStatement(var, carrie, b);
		}

	}

	if(type == "GOTO")
	{
		ss >> val;
		statement = new GotoStatement(val);
	}

	if (type == "IF")
	{
		ss >> var;
		ss >> comp;
		ss >> x;
		ss >> carrie;
		ss >> y;


		statement = new IfStatement(var, comp, x, y);
	}

	if(type == "GOSUB")
	{
		ss >> val;

		statement = new GosubStatement(val);
	}

	
	if(type == "RETURN")
	{
		statement = new ReturnStatement();
	}
	



		
	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );
	//since index 0 = NULL, # of lines is = program.size() 
	ProgramState *state = new ProgramState(program.size());

	// while command isnt NULL keep going
	
	while(program[state->getProgramState()] != NULL)
	{
		program[state->getProgramState()]->execute(state, outf);
	}

	program.erase(program.begin(), program.end());
/*


	for(unsigned int i = 0; i <p rogram.size(); i++)
	{
		delete program[i];
	}

	delete state;
	*/
	
	// Incomplete;  TODO:  Finish this function!
}

