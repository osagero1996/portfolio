
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


template <typename T>
  class MinHeap {
     public:
       MinHeap (int d)
       {
          mary = d;
          size = 0;
       }
       /* Constructor that builds a d-ary Min Heap
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

       ~MinHeap ()
       {

       }

       void add (T item, int priority)
       {
          priorityVector.push_back(make_pair(item, priority));
          BubbleUp(priorityVector.size()-1);
          size++;
         /* adds the item to the heap, with the given priority. */
       }

       const T & peek () const
       {
          return priorityVector[0].first;
         /* returns the element with smallest priority. */
       }

       void remove ()
       {

        swap(priorityVector[0], priorityVector[priorityVector.size()-1]);
        size--;
        priorityVector.erase(priorityVector.end());
        trickleDown(0);
         /* removes the element with smallest priority. */
       }

       bool isEmpty ()
       {
              if(size == 0)
                return true;
                else
                  return false;
         /* returns true iff there are no elements on the heap. */
       }

       void print()
       {
          for(unsigned int i = 0; i < priorityVector.size(); i++)
          {
            cout << priorityVector[i].first << endl;
          }

       }


   private:


      std::vector< pair<T, int> > priorityVector;
       int mary;
      int size;

      int getParent(int index)
      {
        return (index-1)/ mary;
      }

      void BubbleUp(int pos)
      {
        if(pos > 0 && priorityVector[pos].second < priorityVector[getParent(pos)].second)
        {
          /*
          int tempPriority = priorityVector[getParent(pos)].second;
          T temp = priorityVector[getParent(pos)].first;

          priorityVector[getParent(pos)].second = priorityVector[pos].second;
          priorityVector[getParent(pos)].first = priorityVector[pos].first;

          priorityVector[pos].second = tempPriority;
          priorityVector[pos].first = temp;
        */

          swap(priorityVector[getParent(pos)], priorityVector[pos]);
          BubbleUp(getParent(pos));
        } 
        
      }

      void trickleDown(int pos)
      {
        int child = (mary*pos) + 1;

        if(child >= priorityVector.size()-1)
        {
          return;
        }
        int newChild = child;

        if(child < priorityVector.size())
        {

          for(int i = 1; i < mary; i++)
          {
            if(child+i < priorityVector.size() )
            {
              if(priorityVector[child].second > priorityVector[child+i].second)
              {
                newChild = child + i;
              }
            }
          }


          if(priorityVector[newChild].second < priorityVector[pos].second)
          {
            swap(priorityVector[newChild], priorityVector[pos]);
            trickleDown(newChild);
          }
            }
     
      }
      // whatever you need to naturally store things.
      // You may also add helper functions here.
  };


