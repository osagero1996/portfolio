#include "lib/splaytree.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	SplayTree a;

	a.add("hello");
	a.add("car");
	a.add("lol");
	a.add("mama");
	a.add("hello");
	a.add("hello");



	a.reportAll(cout);

	return 1;
}