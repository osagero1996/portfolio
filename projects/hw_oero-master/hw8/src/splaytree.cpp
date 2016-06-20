#include "../lib/splaytree.h"
#include <string>
#include <iostream>
#include <cctype>


SplayTree::SplayTree()
{
	this->root = NULL;
}

SplayTree::~SplayTree()
{
	//this->deleteAll(root);
}


void SplayTree::add(const std::string& word)
{

	//account for upper and lower of same word!
	std::string lol;

	for(unsigned int i =0; i < word.size(); i++)
	{
		lol += std::tolower(word[i]);
	}

	// word = lol;

	Node<std::string,int>* temp = this->internalFind(lol);


	//if word is not in the tree then insert it
	if(temp == NULL)
	{
		this->insert(lol, 1);
		splay(this->internalFind(lol));
	}
	else
	{
		//if word exists, then increase count by 1
		temp->setValue(temp->getValue() + 1);
		splay(temp);
	}

	// std::cout  << "the root is: " << this->root->getKey() << std::endl;
}

void SplayTree::reportAll(std::ostream& output)
{
	
	BinarySearchTree<std::string,int>::iterator it(this->begin());

	for(it = this->begin(); it != this->end(); ++it) {
		output << it->first << " " << it->second << std::endl;

	}
	

}

void SplayTree::splay(Node<std::string,int>* curr)
{
	//is curr already is the root
	if( isRoot(curr) )
		return;


	//if currs parent is the root
	if(isParentRoot(curr)  && isLeftChild(curr))
	{
		//do case 3
		rotateRight(curr->getParent());
		// splay(curr);
		
	}
	else if(isParentRoot(curr) && !isLeftChild(curr))
	{
		rotateLeft(curr->getParent());
		// splay(curr);

		//do case three but left rotation
	}

	//Left Left case
	else if(isLeftChild(curr) && isLeftChild(curr->getParent()))
	{
		//do two right rotations
		rotateRight(curr->getParent()->getParent());
		rotateRight(curr->getParent());
		splay(curr);

	}

	//right right case
	else if(!isLeftChild(curr) && !isLeftChild(curr->getParent()))
	{
		//two left rotations
		rotateLeft(curr->getParent()->getParent());
		rotateLeft(curr->getParent());
		splay(curr);

	}

	//right left case
	else if(isLeftChild(curr) && !isLeftChild(curr->getParent()))
	{
		//one right rotation and then one left rotation
		rotateRight(curr->getParent());
		rotateLeft(curr->getParent());
		splay(curr);

	}
	//left right case
	else if(!isLeftChild(curr) && isLeftChild(curr->getParent()) )
	{
		rotateLeft(curr->getParent());
		rotateRight(curr->getParent());
		splay(curr);
		//one left rotation and then one right rotation
	}
	else
	{
		return;
	}

}


void SplayTree::rotateLeft(Node<std::string,int>* p)
{
	//when reassigning pointers, check if nodes have parents and children


  Node<std::string,int>* x  = p->getRight();
  p->setRight(x->getLeft());
  
  if(x->getLeft() != NULL)
  	x->getLeft()->setParent(p);

  x->setLeft(p);

  if(p->getParent() != NULL )
  {
  	if(isLeftChild(p))
  	{
  		p->getParent()->setLeft(x);
  	}
  	else
  	{
  		p->getParent()->setRight(x);
  	}
  }

  x->setParent(p->getParent());
  p->setParent(x);

  if(x->getParent() == NULL)
  	this->root = x;

 
}

void SplayTree::rotateRight(Node<std::string,int>* p)
{
	//have different cases for right rotations such as if b's left child is null
	//also start from the newly inserted node to work with rotations
  Node<std::string,int>* x = p->getLeft();
  p->setLeft(x->getRight());

  //if x is right child isnt null, then set the parent to p 
  if(x->getRight() != NULL)
  	x->getRight()->setParent(p);

  x->setRight(p);

  //if p parent is not NULL, then change the parents pointer to the new child
  if(p->getParent() != NULL )
  {
  	if(isLeftChild(p))
  	{
  		p->getParent()->setLeft(x);
  	}
  	else
  	{
  		p->getParent()->setRight(x);
  	}
  }

  x->setParent(p->getParent());
  p->setParent(x);



  if(x->getParent() == NULL)
  	this->root = x;

 

}

bool SplayTree::isLeftChild(Node<std::string,int>* curr)
{
	if(curr->getParent()->getLeft() == curr)
		return true;
	else
		return false;

}

bool SplayTree::isParentRoot(Node<std::string,int>* curr)
{
	if(curr->getParent()->getParent() == NULL)
		return true;
	else
		return false;
}

bool SplayTree::isRoot(Node<std::string,int>* curr)
{
	if(curr->getParent() == NULL)
		return true;
	else 
		return false;
}