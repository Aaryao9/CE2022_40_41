#include<iostream>
#include <random>
#include<chrono>
#include "InsertionSort.cpp"
#include "QuickSort.cpp"

void printArray(int arr[], int n) {   
    for (int i = 0; i < n; i++) {  
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::cout << "INSERTION SORT\n";
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Unsorted array:   ";
    printArray(arr, size);
    insertionSort(arr, size);
    std::cout << "Sorted array:     ";
    printArray(arr, size);

    int n = 10000;
    std::cout << "Runtime for insertion sort sorting an array A[] having " << n << " elements :  \n";
    int *array = new int[n];  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000);
    for (int i = 0; i < n; i++) {
        array[i] = dis(gen);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(array, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "Runtime: " << runtime.count() << " seconds" << std::endl; 

    /////////////////////////////////////////////////////////////////////////////////////

    std::cout << "QUICK SORT\n";
    int arr1[] = {15, 7, 11, 19, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Unsorted array:   ";
    printArray(arr1, size1);
    quickSort(arr1, 0, size1 - 1);
    std::cout << "Sorted array:     ";
    printArray(arr1, size1);

    std::cout << "Runtime for quick sort sorting an array A[] having " << n << " elements :  \n";
    int *array1 = new int[n];  
    array1 = array;
    
    auto startQS = std::chrono::high_resolution_clock::now();
    quickSort(array1, 0, n - 1);
    auto endQS = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtimeQS = endQS - startQS;
    std::cout << "Runtime: " << runtimeQS.count() << " seconds" << std::endl; 



    return 0;
    
}