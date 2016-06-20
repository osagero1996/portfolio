#ifndef hashtable_h
#define hashtable_h



#include <iostream>
#include <string>
#include "../prob5/Map.h"
#include <vector>


class HashTable: public Map
{
public:

	HashTable();
	~HashTable();
	virtual void add(const std::string& word, int startAt = 1);
	virtual void reportAll(std::ostream& output);


protected:
	void resize();
	void hash(std::string word, int startAt);
	void checkLoadFactor();
	void createSizeVector();
	void createMultipleVector();
	void createHashVector();
	void hashHelper(std::string word, int startAt);
	void initialize();
	int modFunction();
	void clearWVector();
	void biggerWord(std::string word, int startAt);
	std::pair<std::string, int> *table;
	std::vector<int> sizeVector;
	std::vector<long long> hashVector;
	int sizeCounter;
	double elementCounter;
	int hashCounter;
	double loadFactor;
	std::vector<long long> w;
	bool biggerThanEight(std::string word);

	std::vector<long long> multipleVector;

	


};

#endif