#include "../lib/hashtable.h"
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <cctype>



HashTable::HashTable()
{
	//initialize important variables
	initialize();
}

HashTable::~HashTable()
{

}

void HashTable::add(const std::string& word, int startAt)
{
	std::string lowercase;
	for(unsigned int i = 0; i < word.size(); i++)
	{
		lowercase += std::tolower(word[i]);
	}

	// std::cout << "lowercase: " << lowercase << std::endl;

	hash(lowercase, startAt);
	// std::cout << "variable: " << word << std::endl;
	
	//checks load factor to see if it is above 0.5
	checkLoadFactor();

	// clears w vector after each add
	clearWVector();

}

void HashTable::reportAll(std::ostream& output)
{
	for(int i = 0; i < sizeVector[sizeCounter-1]; i++)
	{
		//check if something exists in this spot
		//
		if(table[i].second != 0)
		{
			output << table[i].first << " " << table[i].second << std::endl;
		}
	}

}

void HashTable::initialize()
{
	table = new std::pair<std::string, int> [11];
	sizeCounter = 1;
	elementCounter = 0;
	createSizeVector();
	createMultipleVector();
	createHashVector();
	
}

void HashTable::hash(std::string word, int startAt)
{
	//if the word is bigger than eight
	//then pass it into hash helper function

	if(!biggerThanEight(word))
		hashHelper(word, startAt);
	else
	{
		std::string lol;
		//reverse the string then pass it in to biggerWord function
		for(int i = word.size()-1; i >= 0; i--)
		{
			lol += word[i];
		}

		biggerWord(lol, startAt);
	}

	//mod function return the index to where word mapped to
	int index = modFunction();
	// std::cout << "index: " << index << std::endl;

	//check if the spot is empty
	//and increment element count
	if( table[index].second == 0)
	{
		table[index].first = word;
		table[index].second = startAt;
		elementCounter++;

	}
	//check if the word already exists
	else if(table[index].second != 0 && table[index].first == word )
	{
		//
		table[index].second += 1;
	}
	// if spot is taken and  word hasnt been added yet
	else
	{
		// std::cout << "Probing..." << std::endl;

		bool found = false;
		int x = 1;

		while(!found)
		{
			int probe = (index + int( pow(x, 2) ) ) % sizeVector[sizeCounter-1];

			if(table[probe].first == word)
			{
				table[probe].second++;
				// std::cout << "new index is: " << probe << std::endl;
				found = true;
			}

			if( table[probe].second == 0)
			{
				table[probe].first = word;
				table[probe].second = startAt;
				elementCounter++;
				found = true;			
				// std::cout << "new index is: " << probe << std::endl;
			}

			x++;
		}
	}

}

void HashTable::hashHelper(std::string word, int startAt)
{
	long long hash = 0;
	int damn = 0;
	int x = multipleVector.size()-1;

	std::vector<int> sum;

	for(unsigned int i = 0; i < word.size(); i++)
	{
		damn = word[i];

		sum.push_back(damn);
	}

	for( int i = sum.size()-1; i >= 0; i--)
	{

		hash += sum[i] * multipleVector[x];
		x--;
	}

	//std::cout << "hash is: " << hash << std::endl;

	//double check this please
	//have the juice
	while(hash != 0)
	{
		w.push_back(hash%40961);

		hash = hash / 40961;
	}
	//make mod function here
	

}

void HashTable::biggerWord(std::string word, int startAt)
{
	std::string lol;
	std::string temp;

	//
	if(biggerThanEight(word) )
	{

		for(int i =0; i < 8; i++)
		{
			lol += word[i];
		}

		for(int i = lol.size()-1; i >= 0; i--)
		{
			temp+= lol[i];
		}

		hashHelper(temp, startAt);

		word.erase(0, 8);
		biggerWord(word, startAt);
	}
	else
	{

		for(int i = word.size()-1; i >= 0; i--)
		{
			temp+= word[i];
		}	

		hashHelper(temp, startAt);

	}


	

}



int HashTable::modFunction()
{
	long long hash = 0;
	int x = 0;

	for(unsigned int i = 0; i < w.size(); i++)
	{
		hash += w[i] * hashVector[x];

		x++;
	}

	



	int index =  hash % sizeVector[sizeCounter-1];

	return index;

}




void HashTable::createMultipleVector()
{
	multipleVector.push_back(pow(128,7));
	multipleVector.push_back(pow(128,6));
	multipleVector.push_back(pow(128,5));
	multipleVector.push_back(pow(128,4));
	multipleVector.push_back(pow(128,3));
	multipleVector.push_back(pow(128,2));
	multipleVector.push_back(pow(128,1));
	multipleVector.push_back(1);

}

void HashTable::checkLoadFactor()
{
	loadFactor = elementCounter / sizeVector[sizeCounter-1];
	// std::cout << "loadfactor: " << loadFactor << std::endl;
	// std::cout << "elementCounter: " << elementCounter << std::endl;
	// std::cout << "size: " << sizeVector[sizeCounter-1] << std::endl;
	// std::cout << std::endl;

	if(loadFactor > 0.5)
	{
		resize();
	}
}


void HashTable::resize()
{
	// std::cout << "Resizing..." << std::endl;
	std::pair<std::string, int> * temp = table;



	elementCounter = 0.0;
	loadFactor = 0.0;

	table = new std::pair<std::string, int> [sizeVector[sizeCounter]];


	
	sizeCounter++;

	for(int i = 0; i < sizeVector[sizeCounter-2]; i++)
	{
		if(temp[i].second != 0)
		{
			add(temp[i].first, temp[i].second);
		}
	}

	// std::cout << "All done..." << std::endl;

}

bool HashTable::biggerThanEight(std::string word)
{
	if(word.size() > 8)
		return true;
	else 
		return false; 
}

void HashTable::clearWVector()
{
	while(!w.empty())
	{
		w.pop_back();
	}
}

void HashTable::createSizeVector()
{
	sizeVector.push_back(11);
	sizeVector.push_back(23);
	sizeVector.push_back(41);
	sizeVector.push_back(83);
	sizeVector.push_back(163);
	sizeVector.push_back(331);
	sizeVector.push_back(641);
	sizeVector.push_back(1283);
	sizeVector.push_back(2579);
	sizeVector.push_back(5147);
	sizeVector.push_back(10243);
	sizeVector.push_back(20483);
	sizeVector.push_back(40961);

}

void HashTable::createHashVector()
{
	hashVector.push_back(5552);
	hashVector.push_back(24019);
	hashVector.push_back(33514);
	hashVector.push_back(36216);
	hashVector.push_back(19250);
	hashVector.push_back(36642);
	hashVector.push_back(27779);
	hashVector.push_back(22339);
	hashVector.push_back(10174);
	hashVector.push_back(2623);
	hashVector.push_back(16351);
	hashVector.push_back(38074);
	hashVector.push_back(36706);
	hashVector.push_back(34394);
	
}