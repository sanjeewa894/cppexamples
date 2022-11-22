/**
 * @copyright Copyright (c) by Versatile Ag.
 *            All rights reserved.
 *  Author: skumara@versatile-ag.com
*/
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>

template <typename T>
class BinarySearch {
  public:
    BinarySearch (T A[], int size);
    ~BinarySearch();
    T searchValue (const T &a);
    void printArray();

  private:
    T *array;
    int asize = 0;

    int valueSearch (T A[], const T &a, int left, int right);
};

template class BinarySearch<float>;
template class BinarySearch<int>;

#endif // BINARYSEARCH_H
