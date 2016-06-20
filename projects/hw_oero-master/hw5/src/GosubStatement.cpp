#include "../lib/GosubStatement.h"

GosubStatement::GosubStatement(int line)
{
	lines = line;
}

GosubStatement::~GosubStatement()
{}

void GosubStatement::execute(ProgramState *state, std::ostream &outf)
{
	if(lines < 0 || lines > state->getNumLine())
	{
		outf << "Illegal jump restriction" << std::endl;
		state->setToZero();
		return;
	}

	state->push(state->getProgramState() + 1);

	state->setLine(lines);

}