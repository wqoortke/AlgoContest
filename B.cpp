#include <iostream>

int main() {
    int n, m, e;
    int* shirts = new int[100000];
    int* pants = new int[100000];
    std::cin >> n;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> e;
        shirts[i] = e;
    }
    std::cin >> m;
    for (int j = 0 ; j < m ; j++) {
        std::cin >> e;
        pants[j] = e;
    }
    int perfectShirt = 0, perfectPants = 0;
    int maxDelta = std::abs(shirts[0] - pants[0]);
    int i = 0, j = 0;
    while (i < n and j < m) {
        if (std::abs(shirts[i] - pants[j]) < maxDelta) {
            maxDelta = std::abs(shirts[i] - pants[j]);
            perfectShirt = i;
            perfectPants = j;
        }
        if (shirts[i] < pants[j]) {
            i++;
        } else if (pants[j] <= shirts[i]) {
            j++;
        }
    }
    std::cout << shirts[perfectShirt] << ' ' << pants[perfectPants];
}
