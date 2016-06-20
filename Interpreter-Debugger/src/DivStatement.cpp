#include "../lib/DivStatement.h"

using namespace std;

DivStatement::DivStatement(std::string name, int num, const int param)
{
	variableName = name;
	number = num;
	x = param;
}

DivStatement::DivStatement(std::string name, std::string dive, const int param)
{
	variableName = name;
	variableDiv = dive;
	x = param;
}

DivStatement::~DivStatement()
{
	
}

void DivStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(x == 1)
	{
		if(state->getVariable(variableName) == 0 || number == 0)
		{
			state->setToZero();
			outf << "Divide by zero exception" << std::endl;
			return;
		}

		state->divVariable(variableName, number);
	}
	else
	{
		if(state->getVariable(variableName) == 0 || state->getVariable(variableDiv) == 0)
		{
			state->setToZero();
			outf << "Divide by zero exception" << std::endl;
			return;
		}

		state->divVariableVar(variableName, variableDiv);
	}


	state->incrementLine();
}