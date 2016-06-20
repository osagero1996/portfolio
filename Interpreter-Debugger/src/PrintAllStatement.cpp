#include "../lib/PrintAllStatement.h"
using namespace std; 

PrintAllStatement::PrintAllStatement()
{

}

PrintAllStatement::~PrintAllStatement()
{}

void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
	state->printAll(outf);
	state->incrementLine();
}