#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> v, std::vector<int> u) {
    std::vector<int> r;
    for (int i = 0, j = 0; r.size() < v.size() + u.size();) {
        if (i < v.size()) {
            if (v[i] < u[j]) {
                r.push_back(v[i]);
                i++;
            }
        }
        if (j < u.size()) {
            if (v[i] >= u[j]) {
                r.push_back(u[j]);
                j++;
            }
        }
        if (i >= v.size() and j < u.size()) {
            r.push_back(u[j]);
            j++;
        }
        if (j >= u.size() and i < v.size()) {
            r.push_back(v[i]);
            i++;
        }
    }
    return r;
}

std::vector<int> mergeSort(std::vector<int> v, std::vector<int> u) {
    if (u.empty() or u.size() == 0) {
        return mergeSort({v.begin(), v.end() - v.size() / 2}, {v.end() - v.size() / 2, v.end()});
    }
    if (v.size() == 1 and u.size() == 1) {
        std::vector<int> a {u[0], v[0]};
        std::vector<int> b {v[0], u[0]};
        return v[0] > u[0] ? a : b;
    }
    if ((v.size() == 1 or u.size() == 1)) {
        return v.size() != 1 ? merge(mergeSort({v.begin(), v.end() - v.size() / 2}, {v.end() - v.size() / 2, v.end()}), u) : merge(mergeSort({u.begin(), u.end() - u.size() / 2}, {u.end() - u.size() / 2, u.end()}), v);
    }
    return merge(mergeSort({v.begin(), v.end() - v.size() / 2}, {v.end() - v.size() / 2, v.end()}), mergeSort({u.begin(), u.end() - u.size() / 2}, {u.end() - u.size() / 2, u.end()}));
}

void printVector(std::vector<int> arr) {
    for (auto e : arr) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}


int main() {
    int n, t;
    std::cin >> n;
    std::vector<int> arr1 = {};
    std::vector<int> arr2 = {};
    int i = 0;
    while (i < n) {
        std::cin >> t;
        arr1.push_back(t);
        i++;
    }
    printVector(mergeSort(arr1, arr2));
}
