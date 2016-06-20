#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class SubStatement: public Statement
{
	public:
	SubStatement(std::string name, int num, const int param);
	SubStatement(std::string name, std::string sub, const int param);
	~SubStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);

private:
	std::string variableName; 
	std::string variableSub;
	int number;
	int x;
};

#endif
