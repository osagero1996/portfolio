#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
	public:
	MultStatement(std::string name, int num, const int param);
	MultStatement(std::string name, std::string mult, const int param);
	~MultStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);

private:
	std::string variableName; 
	std::string variableMult;
	int number;
	int x;
};

#endif