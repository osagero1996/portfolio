#include "heap.h"
#include <string>
#include <iostream>

using namespace std;


int main(){

  
  cout << "Enter d: ";
  int num;
  cin >> num;
  MinHeap<string> test(num);

  test.add("p", 9);
  test.add("p", 1);
  test.add("a", 0);
  test.add("l", 10);
  test.add("e", 4);

  

  /*
  
  test.add("orange", 5);
  test.add("mango", 7);
  test.add("grapefruit", 9);
  test.add("kiwi", 11);
  test.add("lemon", 13);
  test.add("lulu", 12);
*/
  test.print();

  test.remove();

  cout << "post removal" << endl;

  test.print();

/*
  
  test.print();

  test.add("apple", 2);

  cout << "Current smallest priority: " << test.peek() << endl;

  while(!test.isEmpty()){
    test.remove();
  }
  if(test.isEmpty()){
    cout << "The Heap is Empty" << endl;
  }else{
    cout << "Something went wrong" << endl;
  }

  test.add("I", 0);
  test.add("Will", 1);
  test.add("succeed", 2);

  test.print();
  */

  return 0;
}









