 /*
 * avlbst.h
 *
 * Date        Author    Notes
 * =====================================================
 * 2014-04-14  Kempe     Initial version
 * 2015-04-06  Redekopp  Updated formatting and removed
 *                         KeyExistsException
 * 2016-03-31  Cote      Modify for AVL Trees
 */
#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"
#include <algorithm>
#include <stdlib.h>


template <class KeyType, class ValueType>
class AVLNode : public Node<KeyType, ValueType>
{
public:
  AVLNode (KeyType k, ValueType v, AVLNode<KeyType, ValueType> *p)
    : Node<KeyType, ValueType> (k, v, p)
    { height = 0; }
  
  virtual ~AVLNode () {}
  
  int getHeight () const
    { return height; }
  
  void setHeight (int h)
    { height = h; }
  
  virtual AVLNode<KeyType, ValueType> *getParent () const
    { return (AVLNode<KeyType,ValueType>*) this->_parent; }
  
  virtual AVLNode<KeyType, ValueType> *getLeft () const
    { return (AVLNode<KeyType,ValueType>*) this->_left; }
  
  virtual AVLNode<KeyType, ValueType> *getRight () const
    { return (AVLNode<KeyType,ValueType>*) this->_right; }
  
 protected:
  int height;
};

/* -----------------------------------------------------
 * AVL Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class AVLTree : public BinarySearchTree<KeyType, ValueType>
{

public:
  void insert (const std::pair<const KeyType, ValueType>& new_item)
  {
    
    try{

        if(this->internalFind(new_item.first) != NULL)
          throw 10;

        if(this->root == NULL)
      {
        AVLNode<KeyType,ValueType>* temp = new AVLNode<KeyType,ValueType>(new_item.first, new_item.second, NULL);
        this->root = static_cast<Node<KeyType,ValueType>*>(temp);
        
        //set the height of root node to 1;
        static_cast<AVLNode<KeyType,ValueType>*>(this->root)->setHeight(1);
      }
      else
      {
        //AVLNode<KeyType,ValueType>* curr = 
        insertHelper(new_item.first, new_item.second, static_cast<AVLNode<KeyType,ValueType>*>(this->root)); 
        //fixHeight(curr);   
        //rotationHelper(curr, curr);  
      }
    
    }
    catch (int e)
    {
      std::cout << "Key already exists in the tree" << std::endl;
    }
    

  }

  void printHeights () 
  { 
    printHeightHelper(static_cast<AVLNode<KeyType,ValueType>*>(this->root));
    std::cout << "\n";
  }

  void printHeightHelper (AVLNode<KeyType, ValueType> *r) 
  {
    if (r != NULL)
      { 
  std::cout << "[";
  printHeightHelper (r->getLeft());
  std::cout << " (" << r->getKey() << ", " << r->getValue() << ", " << r->getHeight() << ") ";
  printHeightHelper (r->getRight());
  std::cout << "]";
      }
  }



  /* This one is yours to implement.
     It should insert the (key, value) pair to the tree, 
     making sure that it remains a valid AVL Tree.
     If the key is already in the tree, you should throw an exception. */
   
   /*  
  void delete (const KeyType &toRemove)
  {}
  */

  /* Implement this as well.  It should remove the (key, value) pair from
   * the tree which corresponds to the input parameter.
   * If the key is not in the tree, you should throw an exception.
   */
protected:

AVLNode<KeyType, ValueType>* nodeFixer;  


void rotationHelper(AVLNode<KeyType, ValueType>* curr)
{
  int balance = balanceChecker(curr);


   if (balance > 1 && curr->getLeft()->getLeft()->getKey() < curr->getLeft()->getKey())
         rotateRight(curr);
 
    // Right Right Case
    if (balance < -1 && curr->getRight()->getRight()->getKey() > curr->getRight()->getKey())
         rotateLeft(curr);
 
    // Left Right Case
    if (balance > 1 && curr->getLeft()->getLeft()->getKey() > curr->getLeft()->getKey())
    {
        curr->setLeft(rotateLeft(curr->getLeft() ) );
        rotateRight(curr);
    }
 
    // Right Left Case
    if (balance < -1 && curr->getRight()->getRight()->getKey() < curr->getRight()->getKey())
    {
        curr->setRight(rotateRight(curr->getRight()) );
        rotateRight(curr);
    }

    if(curr->getParent() == NULL)
      return;
 
    rotationHelper(curr->getParent());
    /* return the (unchanged) node pointer */

}



AVLNode<KeyType,ValueType>* rotateLeft(AVLNode<KeyType,ValueType>* a)
{
  AVLNode<KeyType,ValueType>* b = a->getRight();
  a->setRight(b->getLeft());
  b->setLeft(a);

  a->setHeight(std::max(a->getLeft()->getHeight(), a->getRight()->getHeight()) + 1);
  b->setHeight(std::max(b->getLeft()->getHeight(), b->getLeft()->getHeight())+1);

  return b;
}

AVLNode<KeyType,ValueType>* rotateRight(AVLNode<KeyType,ValueType>* b)
{
  AVLNode<KeyType,ValueType>* a = b->getRight();
  b->setLeft(a->getRight());
  a->setRight(b);

  b->setHeight(std::max(b->getLeft()->getHeight(), b->getLeft()->getHeight())+1);
  a->setHeight(std::max(a->getLeft()->getHeight(), a->getRight()->getHeight()) + 1);

/*
 
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
*/
  return a;
}

//recursively adjust the height starting from the newly inserted node
void fixHeight(AVLNode<KeyType, ValueType>* node)
{

  //std::cout << "root is: " << static_cast<AVLNode<KeyType,ValueType>*>(this->root)->getHeight() << std::endl;
  
  if(node->getParent() == NULL)
  {
    
    return;
  }


  if(node->getParent() == static_cast<AVLNode<KeyType,ValueType>*>(this->root))
  {
    static_cast<AVLNode<KeyType,ValueType>*>(this->root)->setHeight(std::max(fixHeightLeft(node), fixHeightRight(node)) + 1);
    return;  
  }

  node->getParent()->setHeight(std::max(fixHeightLeft(node), fixHeightRight(node)) + 1 );
  //std::cout << node->getHeight() << std::endl;
 
  if(node->getParent() == static_cast<AVLNode<KeyType,ValueType>*>(this->root))
    fixHeight(static_cast<AVLNode<KeyType,ValueType>*>(this->root));

  fixHeight(node->getParent());

}

//returns the height of the left child of parent
int fixHeightLeft(AVLNode<KeyType, ValueType>* &node)
{
  if(node->getParent()->getLeft() == NULL)
    return 0;

  return node->getParent()->getLeft()->getHeight();
}

// returns the height of the right child of the parent
int fixHeightRight(AVLNode<KeyType, ValueType>* &node)
{
  if(node->getParent()->getRight() == NULL)
    return 0;

  return node->getParent()->getRight()->getHeight();
}

//you need to check if node children is NULL
int balanceChecker(AVLNode<KeyType,ValueType>* node)
{
  return grabLeftHeight(node) - grabRightHeight(node);
}

int grabLeftHeight(AVLNode<KeyType,ValueType>* node)
{
  if(node->getLeft() == NULL)
    return 0;

  return node->getLeft()->getHeight();
}

int grabRightHeight(AVLNode<KeyType,ValueType>* node)
{
  if(node->getRight() == NULL)
    return 0;

  return node->getRight()->getHeight();
  
}



  void insertHelper(KeyType k, ValueType v, AVLNode<KeyType,ValueType>* root)
  {
    if(k <= root->getKey())
    {

      if(root->getLeft() != NULL)
        {
          insertHelper(k, v, root->getLeft());
          return;
        }
        else
        {
          AVLNode<KeyType,ValueType>* temp = new AVLNode<KeyType,ValueType>(k, v, root);
          temp->setHeight(1);
          root->setLeft(temp);
          nodeFixer = temp;
          //std::cout << "hello " << std::endl;
          fixHeight(temp);
          rotationHelper(temp);
          //return temp;
        }
    }
    else
    {
      if(root->getRight() != NULL)
      {
        insertHelper(k, v, root->getRight());
        return;
      }
      else
      {
        AVLNode<KeyType,ValueType>* temp = new AVLNode<KeyType,ValueType>(k, v, root);
        temp->setHeight(1);
        root->setRight(temp);
        nodeFixer = temp;
        //std::cout << "hello1 " << std::endl;
        fixHeight(temp);
        rotationHelper(temp);
        //return temp;
      }
    }

    //fixHeight(nodeFixer);

    //return root;
}





};

#endif
