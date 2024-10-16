#include <iostream>
#include <vector>

int getMin(std::vector<int> v) {
    int min = v[0];
    for (auto e : v) {
        if (e < min) {
            min = e;
        }
    }
    return min;
}

int getMax(std::vector<int> v) {
    int max = v[0];
    for (auto e : v) {
        if (e > max) {
            max = e;
        }
    }
    return max;
}

std::vector<int> countSort(std::vector<int> v) {
    int shift = getMin(v);
    int max = getMax(v);
    int length = max - shift + 1;
    std::vector<int> cArr(length, 0);
    for (int i = 0; i < v.size(); i++) {
        cArr[v[i] - shift] += 1;}
    for (int i = 1 ; i < length ; i++) {
        cArr[i] += cArr[i - 1];}
    std::vector<int> result(v.size(), 0);
    for (int i = v.size() - 1; i >= 0; i--) {
        result[cArr[v[i] - shift] - 1] = v[i];
        cArr[v[i] - shift] -= 1;
    }
    return result;
}


int main() {
    int n, t;
    std::vector<int> v;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> t;
        v.push_back(t);
    }
    v = countSort(v);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    return 0;
}
