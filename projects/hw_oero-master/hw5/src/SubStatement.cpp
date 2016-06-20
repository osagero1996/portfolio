#include "../lib/SubStatement.h"

using namespace std;

SubStatement::SubStatement(std::string name, int num, const int param)
{
	variableName = name;
	number = num;
	x = param;
}

SubStatement::SubStatement(std::string name, std::string sub, const int param)
{
	variableName = name;
	variableSub = sub;
	x = param;
}

SubStatement::~SubStatement()
{
	
}

void SubStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(x == 1)
	{
		state->subVariable(variableName, number);
	}
	else
	{
		state->subVariableVar(variableName, variableSub);
	}


	state->incrementLine();
}