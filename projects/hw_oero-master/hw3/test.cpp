#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt list;

  
  
  

  // Insert an item at the head.
  list.insert(0, 3);
  list.insert(1, 9);
  list.insert(2, 8);
  list.insert(3, 7);
  list.insert(4, 6);
  list.insert(5, 5);
  list.insert(6, 2);
/*
A *a1;
// some code to put stuff in a1
A *a2 = new A(a1);
// a2 now contains a copy of a1.
*/
//Order lhs(*this);
  
LListInt usc;
usc = list;

usc = list + usc;



int a = list[1];
cout << a << endl;

  

  for(int i = 0; i < usc.size(); i++)
  {
    cout << usc.get(i) << endl;
  }
  


  // Clean up memory.

}