#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"


class GosubStatement: public Statement
{
public:

	GosubStatement(int line);
	~GosubStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
	
private:
	int lines;
};

#endif