#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  cout << endl;

  list->insert(0, 10);
  list->insert(1, 9);
  list->insert(2, 8);
  list->insert(3, 7);
  list->insert(4, 6);
  list->insert(5, 5);

  list->insert(0, 11);

  //Inserting at the beginning
  cout << "Inserting at the beginning... ";
  if(list->get(0) == 11)
  {
  	cout << "SUCCESS: 11 is at index 0!" << endl;
  }
  else
  {
  	cout << "FAIL: The number " << list->get(0) << "is there instead!" << endl;
  }

  cout << endl;

  list->insert(6, 4);
  //Inserting at the end
  cout << "Inserting at the end... ";
  if(list->get(6) == 4)
  {
  	cout << "SUCCESS: 4 is at the end!" << endl;
  }
  else
  {
  	cout << "FAIL: The number " << list->get(6) << "is there instead" << endl;
  }

  cout << endl;

  list->insert(4, 20);

  cout << "Inserting in the middle... ";
  if(list->get(4) == 20)
  {
  	cout << "SUCCESS: 20 is in indicated position!" << endl;
  }
  else
  {
  	cout << "FAIL: The number" << list->get(4) << " is there instead" << endl;
  }

  cout << endl;

  list->remove(0); 

  cout << "Removing from the beginning... ";
  if(list->get(0) == 10)
  {
  	cout << "SUCESS!" << endl;
  }
  else
  {
  	cout << "FAIL... " << list->get(0) << endl;
  }

  cout << endl;

  list->remove(7);

  cout << "Removing from the end... ";
  if(list->get(6) == 4)
  {
  	cout << "SUCCESS!" << endl;
  }
  else
  {
  	cout << "FAIL!" << endl;
  }

  cout << endl;

  list->remove(4);
  cout << "Removing from the middle... ";
  if(list->get(4) == 6)
  {
  	cout << "SUCCESS" << endl;
  }
  else
  {
  	cout << "FAIL" << endl;
  }

  list->remove(0);
  list->remove(0);
 list->remove(0);
 list->remove(0);
 list->remove(0);
 
 list->remove(0);
  

  if(list->size() == 0)
  {
  	cout << "Testing for Empty.... SUCCESS" << endl;

  }

  else
  {
  	cout << "FAIL: The size of the list is " << list->size() << endl;
  }

  //cout << list->get(0) << endl;

  /*

  for(int i = 0; i < list->size(); i++)
  {
    cout << list->get(i) << endl;
  }
//*/

}