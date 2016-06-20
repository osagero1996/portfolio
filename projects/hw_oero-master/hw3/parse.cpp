#include "stackint.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char*argv[])
{
	//open and close parantheses
	// plus, multiply, shift right and shift left
	//does have to be const
	//need counter for parantheses to make sure the match
	// or it is considered an error
	const int open = -1;
	const int close = -2;
	const int plus = -3;
	const int mult = -4;
	const int shiftRight = -5;
	const int shiftLeft = -6;


	if (argc != 2)
	{
		cout << "Input a filename" << endl;
		return 1;
	}


	ifstream infile(argv[1]);
	stringstream ss;
	string line;
	while(getline(infile, line))
	{
		StackInt pablo; //declare a new stack
		bool malformed = false; //check if line is malformed
		int openp = 0; //keep track of open parantheses
		int closep = 0; //keep track of closed parantheses
		int total = 0; //keep track of total from line
		

		
		// if the first char is any of these then it must be malformed
			if(line[0] == ')')
			{
				malformed = true;

			}

			if(line[0] == '*'){
				malformed = true;

			}

			if(line[0] == '+'){
				malformed = true;

			}

			if(line[0] >= 48 && line[0] <= 57)//if first thing on the line is a number
			{
				malformed = true;
				
			}
			
		// loop checks to see if an invalid character follows after a char

		for(unsigned int i = 0; i < line.length(); i++)
		{
			char c = line[i];
			if(c == '(' || c == '+' || c == '*')
			{
				//check if next is an operator
				//or closed parentheses
				if(i != line.length() -1)
				{
					if(line[i+1] == ')' || line[i+1] == '+' || line[i+1] == '*')
					{
						malformed = true;
					}
				}

				if(c == '(')
				{
					openp++; //keep tabs on open parentheses
				}
			}
		

			if(c == ')')
			{
				if(i != line.length() -1)
				{
					if(line[i+1] == '(' || line[i+1] == '>' || line[i+1] == '<' 
						|| (line[i+1] >= 48 && line[i+1] == 57) )
					{
						malformed = true;
					}
				}

				closep++; //keep track of closed parentheses
			}


			if(c == '<' || c == '>')
			{
				if(i != line.length()-1)
				{
					if(line[i+1] == '+' || line[i+1] == '*' || line[i+1] ==  ')')
					{
						malformed = true;
					}
				}
			}

		}
			// if last character is not a closed parentheses
			if(line[line.length()-1] != ')')
			{
				malformed = true;
			}

			//if closed parentheses does not match the number of open
			// it is malformed
			if(closep != openp)
			{
				malformed = true;
			}

			if(malformed == true)
			{
				cout << "Malformed" << endl;
			}

		ss << line;
		
			char a;
		if(malformed == false)
		{
			while(ss >> a)
			{
				if(a == '(')
				{
					pablo.push(open);
				}

				if(a == '+')
				{
					pablo.push(plus);
				}

				if(a == '*')
				{
					pablo.push(mult);
				}


				if(a == '<')
				{
					pablo.push(shiftLeft);
				}

				if(a == '>')
				{
					pablo.push(shiftRight);
				}

				if(a >= 48 && a <= 57)
				{
					int b = 0;
					b = a-48;
					pablo.push(b);
					
				}

				if(a == ')')
				{
					pablo.push(close);
				}

			}
		}



		





	}
	

}
