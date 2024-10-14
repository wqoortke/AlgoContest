#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

void deleteArr(int* arr, int length ){
    for (int i = 0; i < length ; i++) {
        arr[i] = '\0';
    }
}

int* removePrintMax(int* arr, int length) {
    int max = 0, ind = 0;
    int* arr2 = new int[200000];
    for (int i = length - 1; i >= length / 2; i--) {
        if (arr[i] > max) {
            max = arr[i];
            ind = i;
        }
    }
    std::cout << max << '\n';
    for (int i = 0; i < length; i++) {
        if (i < ind) {
            arr2[i] = arr[i];
        } else if (i > ind) {
            arr2[i - 1] = arr[i];
        }
    }
    deleteArr(arr, length);
    return arr2;
}

int* heapify(int* arr, int length, int start = 0) {
    int swap;
    for (int i = length / 2; i >= 0 and i < length; i--) {
        if (arr[i] != 0 and arr[2*i + 1] != 0 and arr[i] > arr[2*i + 1]) {
            swap = arr[2*i + 1];
            arr[2*i + 1] = arr[i];
            arr[i] = swap;
        }
        if (arr[i] != 0 and arr[2*i + 2] != 0 and arr[i] > arr[2*i + 2]) {
            swap = arr[2*i + 2];
            arr[2*i + 2] = arr[i];
            arr[i] = swap;
        }
    }
    return arr;
}

void printHeapTree(int* arr, int length, int index = 0, int indent = 0) {
    if (index >= length) return;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (right < length) printHeapTree(arr, length, right, indent + 4);
    std::cout << std::setw(indent) << "" << arr[index] << std::endl;
    if (left < length) printHeapTree(arr, length, left, indent + 4);
}

void printArr(int* arr, int length) {
    for (int x = 0 ; x < length; x++) {
        std::cout << arr[x] << " ";
    }
    std::cout << '\n';
}

void solution(int* arr, int length) {
    std::string in;
    std::ifstream f;
    f.open("input.txt");
    if (!f.is_open()) {
        return;
    }
    while (getline(f, in))
    {
        if (in == "EXTRACT") {
            if (length == 0)
                std::cout << "CANNOT\n";
            else
                arr = removePrintMax(arr, length);
                length--;
        } else if (in == "CLEAR") {
            deleteArr(arr, length);
            int* arr = new int[200000];
            length = 0;

        } else {
            int d = in.find_first_of(' ');
            std::string op = in.substr(0, d);
            std::string val = in.substr(d, in.length());
            int value = std::stoi( val );
            if (op == "ADD") {
                arr[length] = value;
                length++;
                heapify(arr, length);
            }
        }
    }
    f.close();
}


int main() {
    int* ptr = new int[200000];
    int length = 0;
    solution(ptr, length);
}
