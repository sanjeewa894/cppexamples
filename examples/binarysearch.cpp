/**
 * @copyright Copyright (c) by Versatile Ag.
 *            All rights reserved.
 *  Author: skumara@versatile-ag.com
*/
#include "binarysearch.h"

template <typename T> BinarySearch<T>::BinarySearch (T A[], int size) {
  array = new T[size];
  asize = size;
  for (int i = 0; i < asize; i++)
    array[i] = A[i];
}

template <typename T> BinarySearch<T>::~BinarySearch() {
  delete[] array;
}

template <typename T> int BinarySearch<T>::valueSearch (T A[], const T &a, int left, int right) {
  if (left <= right) {
    int mid = (left + right) / 2;
    if (a == A[mid])
      return mid;
    else if (a < A[mid])
      return valueSearch (A, a, left, mid - 1);
    else if (a > A[mid])
      return valueSearch (A, a, mid + 1, right);
  }
  return -1;
}

template <typename T> T BinarySearch<T>::searchValue (const T &a) {
  //search variable and return matching variable
  int result = valueSearch (array, a, 0, asize);
  if (result >= 0)
    std::cout << "Search value " << array[result] << " is in the array at " << result << std::endl;
  else
    std::cout << "Search value does not present in the array." << std::endl;
  return (T)1;
}



template <typename T> void BinarySearch<T>::printArray() {
  for (int i = 0; i < asize; i++)
    std::cout << " " << * (array + i);
  std::cout << std::endl;
}
