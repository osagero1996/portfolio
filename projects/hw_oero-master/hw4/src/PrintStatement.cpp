 // PrintStatement.cpp:
#include "../lib/PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << state->getVariable(m_variableName) << std::endl;
	state->incrementLine();
}


