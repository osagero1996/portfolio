#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GotoStatement: public Statement
{
public:
	GotoStatement(int line);
	~GotoStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);


private:
	int linenum;


};

#endif