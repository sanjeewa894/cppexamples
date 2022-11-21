#include <iostream>
#include <cstring>

// Function to print an array
template <typename T>
void printArray(T A[], int start, int end)
{
    for (auto i = start; i < end; i++)
        std::cout << A[i] << " ";

    std::cout << std::endl;
}
 
template <typename T>
void mergeInPlace(T array[], int left, int mid, int right) {
    //no need to sort if end of first array and begining of 2nd array are sorted
    if (array[mid]<=array[mid+1])
        return;
    
    int i = left, j = mid+1; // Initial index of second sub-array

    while (i <= mid && j<=right) {
        if (array[i] > array[j]) {
            int value = array[j];
            //int index = j;
            // Shift all the elements to right by 1 from i.
            // while (index != i) {
            //     array[index] = array[index - 1];
            //     --index;
            // }

            int diff = (j - i)* sizeof(T); //number of bytes to copy      
            std::memmove(array + i + 1, array + i, diff);

            array[i] = value;
            ++i;
            ++mid;
            ++j;
        }
        else {
            ++i;
        }
    }
}

/*
* merger array in divide and conquer manner
*/
template <typename T>
void mergeSort(T array[], int start, int end)
{
    if (start >= end)
        return; // Returns recursively

    auto mid = start + (end - start) / 2; //get mid point
    mergeSort(array, start, mid); //sort left
    mergeSort(array, mid + 1, end); //sort right 
    mergeInPlace(array, start, mid, end); //merge sorted arrays
}



void testMergeSort() {
    //int arr[] = { 12, 11, 13, 5, 6, 7,2, 134,213,234,23452,12332,23441,133,5,554,65,34,6,42,87 };
    int arr[] = { 12, 11, 13, 5, 6, 7,3 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";

    printArray(arr, 0,arr_size);

   mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nSorted array is \n";
    printArray(arr,0, arr_size);

}