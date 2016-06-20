#include "../lib/GotoStatement.h"


GotoStatement::GotoStatement(int lines)
{
	linenum = lines;
}

GotoStatement::~GotoStatement()
{}

void GotoStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(linenum > state->getNumLine() || linenum < 0)
	{
		outf << "Illegal Jump Restriction" << std::endl;
		state->setToZero();
		return;
	}

	state->setLine(linenum);

}