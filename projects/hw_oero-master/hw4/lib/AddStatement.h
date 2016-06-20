#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class AddStatement : public Statement 
{
public:
	AddStatement(std::string name, int num, const int param);
	AddStatement(std::string name, std::string addend, const int param);
	virtual void execute(ProgramState * state, std::ostream &outf);
	~AddStatement();

private:
	std::string variableName; 
	std::string variableAdd;
	int number;
	int x;
};

#endif 