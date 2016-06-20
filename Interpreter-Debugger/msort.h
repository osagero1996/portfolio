#ifndef MERGE_SORT_INCLUDED
#define MERGE_SORT_INCLUDED

#include <vector>
#include <string>

struct AlphaStrComp {
    bool operator()(const std::string& lhs, const std::string& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs < rhs; 
    }
  };

struct AlphaStrCompRev{
    bool operator()(const std::string& lhs, const std::string& rhs)
    {
        return lhs > rhs;
    }
};

struct NumberSortAscending{
    bool operator()(const int& first, const int& second)
    {
        return first < second;
    }

};

struct NumberSortDescending{
    bool operator()(const int& first, const int& second)
    {
        return first > second;
    }
};

template <class T, class Comparator>
void merge(std::vector<T>& myArray, int l, int m, int r, Comparator comp)
{
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    T *L = new T[n1];
    //std::vector<T> L;
    //std::vector<T> R;

    T *R = new T[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = myArray[l + i];
    for (j = 0; j < n2; j++)
        R[j] = myArray[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (comp(L[i], R[j]) )
        {
            myArray[k] = L[i];
            i++;
        }
        else
        {
            myArray[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        myArray[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        myArray[k] = R[j];
        j++;
        k++;
    }
}


template <class T, class Comparator>
 void helper(std::vector<T>& myArray, int left, int right, Comparator comp)
 {

    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for
        // large l and h
        int middle = left+(right-left)/2;
 
        // Sort first and second halves
        helper(myArray, left, middle, comp);
        helper(myArray, middle+1, right, comp);
 
        merge(myArray, left, middle, right, comp);
    }

}

 template <class T, class Comparator>
 void mergeSort (std::vector<T>& myArray, Comparator comp)
 {

 	//call a helper function that breaks down the array to singular components
 	//merge function takes a comparator object

 	helper(myArray, 0, myArray.size() - 1, comp);



 }

 #endif