#include "../lib/MultStatement.h"

using namespace std;

MultStatement::MultStatement(std::string name, int num, const int param)
{
	variableName = name;
	number = num;
	x = param;
}

MultStatement::MultStatement(std::string name, std::string mult, const int param)
{
	variableName = name;
	variableMult = mult;
	x = param;
}

MultStatement::~MultStatement()
{
	
}

void MultStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(x == 1)
	{
		state->multVariable(variableName, number);
	}
	else
	{
		state->multVariableVar(variableName, variableMult);
	}


	state->incrementLine();
}