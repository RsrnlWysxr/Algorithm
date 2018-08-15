#include <iostream>
#include "Sort.h"
#include <string>
using namespace std;

int main()
{
    int N = 1000000;
//    auto arr1 = SortAlgorithm::generateRandomArray(N,0,100);
    auto arr1 = SortAlgorithm::generateNearlyOrderedArray(N,100);
    auto arr2 = SortAlgorithm::copyIntArray(arr1,N);
    auto arr3 = SortAlgorithm::copyIntArray(arr1,N);
//    SortAlgorithm::testSort("Selection Sort",SortAlgorithm::selectionSort,arr1,N);
//    SortAlgorithm::testSort("Insertion Sort1",SortAlgorithm::insertionSort,arr1,N);
//    SortAlgorithm::testSort("Insertion Sort2",SortAlgorithm::insertionSort2,arr1,N);
    SortAlgorithm::testSort("Merge Sort",SortAlgorithm::mergeSort,arr1,N);
//    SortAlgorithm::testSort("Quick Sort",SortAlgorithm::quickSort,arr2,N);
    SortAlgorithm::testSort("Quick Sort3",SortAlgorithm::quickSort3,arr2,N);
    SortAlgorithm::testSort("heap Sort",SortAlgorithm::heapSort,arr3,N);
    delete[] arr1;
    delete[] arr2;
    return 0;
}