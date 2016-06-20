#include "lib/hashtable.h"
#include "lib/splaytree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Enter all command line arguments" << endl;
		return 1;
	}


    SplayTree splay;
    HashTable hash;

	int x = atoi(argv[1]);
	
	//std::string arg1(argv[2]);
	
	ifstream infile(argv[2]);
	string row;

	if(infile.fail())
    {
    	cout <<  "Text file failed to open" << endl;
    	return 1;
    }

    if(x==4)
    {


    	while(getline(infile, row))
    	{
	    	stringstream ss;
	    	ss << row;

	    	string hello;
	    	while(ss >> hello)
	    	{
	    		splay.add(hello);
	    	}
    	}

    	ofstream myfile("splay.txt");

  		// myfile.open ("splay.txt");

    	splay.reportAll(myfile);
    }
    else if(x == 5)
    {

    	while(getline(infile, row))
    	{
	    	stringstream ss;
	    	ss << row;

	    	string hello;
	    	while(ss >> hello)
	    	{
	    		hash.add(hello);
	    	}
    	}

    	ofstream myfile("hash.txt");

    	hash.reportAll(myfile);

    }

    else
    {
    	cout << "Choose 4 for Splay Tree and 5 for Hash." << endl;
    }


    return 1;

}