#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "../lib/stackint.h"

using namespace std;

StackInt::StackInt()
{

}

StackInt::~StackInt()
{

}
/**
   * Returns true if the stack is empty, false otherwise
   */

bool StackInt::empty() const
{
	if(list.size() == 0)
		return true;
  else
    return false;
}

 /**
   * Pushes a new value, val, onto the top of the stack
   */
void StackInt::push(const int& val)
{
	list.insert(list.size(), val);
}

/**
   * Returns the top value on the stack
   */
int const &  StackInt::top() const
  {
  	return list.get(list.size()-1);
  	
  }

void StackInt::pop()
{
	list.remove(list.size()-1);
}