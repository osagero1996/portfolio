// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "stackint.h"
#include <map>
#include <string>

class ProgramState
{
public:
	ProgramState(int numLines);
	//StackInt pablo; //stack to hold return lines for GOSUB
	void incrementLine();
	void setVariable(std::string name, int val); //set the variable to its value
	void setToZero();
	void setLine(int line);
	int getProgramState();
	int getVariable(std::string name);
	void printAll(std::ostream &outf);
	int getNumLine();
	void addVariable(std::string name, int num);
	void addVariableVar(std::string name, std::string yep);
	void subVariable(std::string name, int num);
	void subVariableVar(std::string name, std::string yep);
	void multVariable(std::string name, int num);
	void multVariableVar(std::string name, std::string yep);
	void divVariable(std::string name, int num);
	void divVariableVar(std::string name, std::string yep);
	int top();
	void push(int x);
	void pop();
	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.


private:

	int m_numLines;
	int currentLine;
	std::map<std::string, int> *variables; //keeps variable name and values
	StackInt pablo; 
	


};

#endif



