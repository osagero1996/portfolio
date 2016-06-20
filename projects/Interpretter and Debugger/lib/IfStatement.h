#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class IfStatement: public Statement
{
public:
	virtual ~IfStatement();

	IfStatement(std::string name, std::string comp, int x, int y);
	virtual void execute(ProgramState * state, std::ostream &outf);


private:
	std::string var;
	std::string comper;
	int first;
	int last;

};

#endif