#ifndef splaytree_h
#define splaytree_h

#include <iostream>
#include <string>
#include "Maps.h"
#include "bst.h"


class SplayTree: public Maps, public BinarySearchTree<std::string, int>
{
public:
	SplayTree();
	~SplayTree();
	virtual void add(const std::string& word);
	virtual void reportAll(std::ostream& output);


protected:

bool isRoot(Node<std::string,int>* curr);
void splay(Node<std::string,int>* curr);
bool isLeftChild(Node<std::string,int>* curr);
void rotateRight(Node<std::string,int>* p);
void rotateLeft(Node<std::string,int>* p);

bool isParentRoot(Node<std::string,int>* curr);




};

#endif