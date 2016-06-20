#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class ReturnStatement: public Statement
{
	public:
		ReturnStatement();
		~ReturnStatement();
		void virtual execute(ProgramState * state, std::ostream &outf);
};

#endif