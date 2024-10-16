#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <iomanip>


void printArr(int* arr, int length) {
    for (int x = 0 ; x < length; x++) {
        std::cout << arr[x] << " ";
    }
    std::cout << '\n';
}

int* heapify(int* arr, int length, int i = 0) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, length, largest);
    }
    return arr;
}

int* heapsort(int* arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i);}
    for (int i = len - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return arr;
}

int main() {
    int n, t;
    std::cin >> n;
    int* arr = new int[100000];
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        arr[i] = t;
    }
    heapsort(arr, n); 
    printArr(arr, n); 
    return 0;
}
