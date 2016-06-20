#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class DivStatement: public Statement
{
	public:
	DivStatement(std::string name, int num, const int param);
	DivStatement(std::string name, std::string dive, const int param);
	virtual void execute(ProgramState * state, std::ostream &outf);
	~DivStatement();

private:
	std::string variableName; 
	std::string variableDiv;
	int number;
	int x;
};

#endif