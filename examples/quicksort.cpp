/**
 * @copyright Copyright (c) by Versatile Ag.
 *            All rights reserved.
 *  Author: skumara@versatile-ag.com
*/
#include <iostream>

void printArray (int arry[], int size) {
  for (int i = 0; i < size; i++)
    std::cout << arry[i] << " ";
  std::cout << std::endl;
}

int doPartition (int arry[], int start, int end) {
  int pivot = arry[end]; //pivot value as end of the element in the array
  int i = start; //starting
  //loop to end of the array
  for (int j = start; j < end; j++) {
    //if element is lower than the pivot, swap the value from the front
    if (arry[j] < pivot) {
      int temp = arry[j];
      arry[j] = arry[i];
      arry[i] = temp;
      ++i;
    }
  }
  //move end of element to first larger value form the front of the array
  int tmp = arry[end];
  arry[end] = arry[i];
  arry[i] = tmp;
  //return the pivot swap position
  return i;
}

/*
 * Pivot select end of the array
 */
void quicksortEnd (int arry[], int start, int end) {
  if (start < end) {
    int index = doPartition (arry, start, end); //take middle as pivot
    quicksortEnd (arry, start, index - 1);
    quicksortEnd (arry, index + 1, end);
  }
}


/*
 * Using middle value
 */
void quicksortMiddle (int arry[], int start, int end) {
  if (start < end) {
    int idex = (start + end) / 2;
    int pivot = arry[idex];
    int i = start;
    int k = end;
    while (i <= k) {
      while (arry[i]  < pivot)
        i++; //iterate until element from the start is less than pivot
      while (arry[k] > pivot)
        k--; //iterate until element from the end is greater than pivot
      //swap if found min & max values disparity to pivot
      if (i <= k) {
        int temp = arry[i];
        arry[i] = arry[k];
        arry[k] = temp;
        i++;
        k--;
      }
    }
    if (start < k)
      quicksortMiddle (arry, start, k);
    if (i < end)
      quicksortMiddle (arry, i, end);
  }
}


int main() {
  int arry[] = {5, 3, 6, 8, 2, 5, 7, 1};
  std::cout << "Before sort" << std::endl;
  printArray (arry, sizeof (arry) / sizeof (arry[0]));
  quicksortEnd (arry, 0, (sizeof (arry) / sizeof (arry[0]) - 1));
  std::cout << "After sort" << std::endl;
  printArray (arry, sizeof (arry) / sizeof (arry[0]));
  //////********************////////
  int arry2[] = {5, 3, 6, 8, 2, 5, 7, 1};
  std::cout << "pivot select from the middle" << std::endl;
  std::cout << "Before sort" << std::endl;
  printArray (arry2, sizeof (arry2) / sizeof (arry2[0]));
  quicksortEnd (arry2, 0, (sizeof (arry2) / sizeof (arry2[0]) - 1));
  std::cout << "After sort" << std::endl;
  printArray (arry, sizeof (arry2) / sizeof (arry2[0]));
  return 0;
}
