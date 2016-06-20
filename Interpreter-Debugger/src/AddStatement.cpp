#include "../lib/AddStatement.h"

using namespace std;

AddStatement::AddStatement(std::string name, int num, const int param)
{
	variableName = name;
	number = num;
	x = param;
}

AddStatement::AddStatement(std::string name, std::string addend, const int param)
{
	variableName = name;
	variableAdd = addend;
	x = param;
}

AddStatement::~AddStatement()
{
	
}

void AddStatement::execute(ProgramState * state, std::ostream &outf)
{
	
	if(x == 1)
	{
		state->addVariable(variableName, number);
	}
	else
	{
		state->addVariableVar(variableName, variableAdd);
	}


	state->incrementLine();
	
	
}