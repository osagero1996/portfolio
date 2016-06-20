#include "../lib/ProgramState.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;


ProgramState::ProgramState(int numLines)
{
	m_numLines = numLines;
	currentLine = 1;
	variables = new std::map<std::string, int>();
}

int ProgramState::getNumLine()
{
	return m_numLines;
}

void ProgramState::incrementLine()
{
	if(currentLine <= m_numLines)
		currentLine++;
}

void ProgramState::setVariable(std::string name, int val)
{
	//if variable doesn't exist
	if(variables->find(name) == variables->end())
	{
		variables->insert(std::make_pair(name, val));
	}
	else
	{
		//if it exists, just update variable
		variables->find(name)->second = val;
	}
	
}

void ProgramState::setToZero()
{
	currentLine = 0;
}

int ProgramState::getProgramState()
{
	return currentLine;
}

int ProgramState::getVariable(std::string name)
{
	if(variables->find(name) == variables->end())
	{
		return 0;
	}
	else
	{
		return variables->find(name)->second;
	}
	
}

void ProgramState::setLine(int line)
{
	currentLine = line;
}

void ProgramState::printAll(std::ostream &outf)
{
	std::map<std::string, int>::iterator it;
	for(it = variables->begin(); it != variables->end(); ++it)
	{
		outf << it->first << " " << it->second << endl;
	}
}

void ProgramState::addVariable(std::string name, int num)
{
	variables->find(name)->second += num;
	
}

void ProgramState::addVariableVar(std::string name, std::string yep)
{
	variables->find(name)->second += variables->find(yep)->second;
}

void ProgramState::subVariable(std::string name, int num)
{
	variables->find(name)->second -= num;

}
void ProgramState::subVariableVar(std::string name, std::string yep)
{
	variables->find(name)->second -= variables->find(yep)->second;
}

void ProgramState::multVariable(std::string name, int num)
{


	variables->find(name)->second *= num;
}

void ProgramState::multVariableVar(std::string name, std::string yep)
{
	
	variables->find(name)->second *= variables->find(yep)->second;

}

void ProgramState::divVariable(std::string name, int num)
{
	variables->find(name)->second /= num;
}

void ProgramState::divVariableVar(std::string name, std::string yep)
{
	variables->find(name)->second /= variables->find(yep)->second;
}

void ProgramState::push(int x)
{
	pablo.push(x);
}

int ProgramState::top()
{
	return pablo.top();
}

void ProgramState::pop()
{
	pablo.pop();
}

