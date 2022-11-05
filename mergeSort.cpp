#include <iostream>
using namespace std;
void merge(int *arrays, int const left, int const mid, int const right){
    auto const leftarr = mid - left + 1;
    auto const rightarr = right - mid;

    int *leftArray = new int[leftarr], *rightArray = new int[rightarr];

    for (auto i = 0; i < leftarr; i++)
        leftArray[i] = arrays[left + i];
    for (auto j = 0; j < rightarr; j++)
        rightArray[j] = arrays[mid + 1 + j];

    int indexOfSubArrayOne= 0, indexOfSubArrayTwo = 0, indexOfMergedArray = left;
    while (indexOfSubArrayOne < leftarr && indexOfSubArrayTwo < rightarr) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arrays[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arrays[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < leftarr) {
        arrays[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < rightarr) {
        arrays[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}