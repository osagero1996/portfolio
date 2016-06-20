#include "../lib/ReturnStatement.h"

ReturnStatement::ReturnStatement()
{

}

ReturnStatement::~ReturnStatement()
{

}


void ReturnStatement::execute(ProgramState *state, std::ostream &outf)
{
	state->setLine(state->top());
	state->pop();
} 