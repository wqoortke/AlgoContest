#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


std::vector<int> selectionSort(std::vector<int> v) {
    int jval, max = v[0];
    int maxIndex = 0;
    for (int i = 1, j = 0; j < v.size();) {
        if (i < v.size() and v[i] > max) {
            max = v[i];
            maxIndex = i;
        }
        if (i >= v.size()) {
            if (maxIndex != j) {
                jval = v[j];
                v[j] = v[maxIndex];
                v[maxIndex] = jval;
                max = 0;
            }
            j++;
            max = v[j];
            maxIndex = j;
            i = j;
        }
        i++;
    }
    return v;
}

int main() {
    std::string inp;
    std::ifstream f;
    std::vector<int> arr;
    f.open("input.txt");
    if (!f.is_open()) {
        return 1;
    }
    while (getline(f, inp))
    {
        std::istringstream iss(inp);
        int num;
        while (iss >> num) {
            arr.push_back(num);
        }
    }
    f.close();
    if (arr.size() == 1) {
        std::cout << arr[0];
        return 0;
    }
    arr = selectionSort(arr);
    for (auto e : arr) {
        std::cout << e << ' ';
    }

    return 0;
}
