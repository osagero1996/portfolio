#include "../lib/ReturnStatement.h"
#include <iostream>

ReturnStatement::ReturnStatement()
{

}

ReturnStatement::~ReturnStatement()
{

}


void ReturnStatement::execute(ProgramState *state, std::ostream &outf)
{
	
	if(state->empty())
	{
		outf << "Error: Nothing to return to" << std::endl;
		state->setToZero();
		return;
	}
	
	state->setLine(state->top());
	state->pop();
} 