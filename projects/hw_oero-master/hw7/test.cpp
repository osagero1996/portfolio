  // .cpp
  
#include "bst.h"
#include "avlbst.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	BinarySearchTree<string,int> a;
	a.insert("n1", 0);
	a.insert("n2", 1);
	a.insert("n3", 11);
	a.insert("n4", 100);
	a.insert("n5", 21);
	a.insert("n6", 41);
	a.insert("n7", 44);
	a.insert("n8", 8);
	a.insert("n9", 1);	
	cout << "print" << endl;
	a.print();
	cout << "iterator" << endl;

	BinarySearchTree<string,int>::iterator it(a.begin());

	for(it = a.begin(); it != a.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}

	return 1;
}