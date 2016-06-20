#include "llistint.h"
#include <cstdlib>
#include <stdexcept>
#include <iostream>

using namespace std;

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
 

  //if loc is greater than size or less than 0, just return
  if(loc > size() || loc < 0)
  {
    cerr << "Invaild Location Fam" << endl;
    return;
  }

  //inserting into a list when it is empty
  if(empty())
  {
    Item *temp = new Item;
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;
    head_ = temp;
    tail_ = temp;
    size_++;
    return;
  }

  //inserting to the beginning of the list
  if(loc == 0)
  {
    Item *temp = new Item;
    temp->val = val;
    temp->prev = NULL;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    size_++;
    return; 
  }

  //inserting into the end of the list
  if(loc == size())
  {
    Item *temp = new Item;
    temp->val = val;
    temp->prev = tail_;
    temp->next = NULL;
    tail_->next = temp;
    tail_ = temp;
    size_++;
    return;

  }


  //inserting into the middle of the list
  Item *temp = new Item;
  Item *old = getNodeAt(loc);
  temp->val = val;
  temp->prev = old->prev;
  old->prev->next = temp;
  old->prev = temp;
  temp->next = old;
  size_++;


  return;



}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  //if the location is invalid
  if(loc < 0 || loc >= size())
  {
    cerr << "Invalid input fam" << endl;
    return;
  }

  //if the list is empty
  if(size() == 0)
  {
    cerr << "the list is empty" << endl;
    return;
  }



  //remove from the front of the list

  if(loc == 0)
  {
    Item *temp = head_;
    head_->next->prev = NULL;
    head_ = head_->next;
    delete temp;
    size_--;
    return;

  }

  //if there is only one in the list
  if(size_ == 1)
  {
    Item* temp = getNodeAt(0);
    head_ = NULL;
    tail_ = NULL;
    delete temp;
    size_--;
    return;
  }

  //removing from the list at the end
  if(loc == size()-1)
  {
    Item *temp = tail_;
    tail_->prev->next = NULL;
    tail_ = tail_->prev;
    delete temp;
    size_--;
    return;

  }

  //removing from the middle of the list
  Item *temp = getNodeAt(loc);
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;
  size_--;
  return;



}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{ 
  if(loc == 0)
  {
    return head_;
  }

  if(loc == size_-1)
  {
    return tail_;
  }

  if(loc < 0 || loc >= size_)
  {
    return NULL;
  }


  Item *temp = head_;
  for(int i = 0; i < loc; i++)
  {
    temp = temp->next;
  }
 
  return temp;


}
