#include "../lib/IfStatement.h"

IfStatement::IfStatement(std::string name, std::string comp, int x, int y)
{
	var = name;
	comper = comp;
	first = x;
	last = y;
}

IfStatement::~IfStatement()
{}

void IfStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(last < 0 || last > state->getNumLine())
		{
			outf << "Illegal jump restriction" << std::endl;
			state->setToZero();
			return;
		}

		if(comper == ">")
		{
			if(state->getVariable(var) > first)
			{
				
				state->setLine(last);
			}
			else
			{
				state->incrementLine();
			}
		}
		else if(comper == "<")
		{
			if(state->getVariable(var) < first)
			{
				state->setLine(last);
			}
			else
			{
				state->incrementLine();
			}
		}
		else if(comper == "=")
		{
			if(state->getVariable(var) == first)
			{
				state->setLine(last);
			}
			else{
				state->incrementLine();
			}
		}
		else if(comper == ">=")
		{
			if(state->getVariable(var) >= first)
			{
				state->setLine(last);
			}
			else
			{
				state->incrementLine();
			}
		}
		else if(comper == "<=")
		{
			if(state->getVariable(var) <= first)
			{
				state->setLine(last);
			}
			else{
				state->incrementLine();
			}
		}
		else if(comper == "<>")
		{
			if(state->getVariable(var) != first)
			{
				state->setLine(last);
			}
			else
			{
				state->incrementLine();
			}
		}
		else
		{
			state->incrementLine();
		}
}