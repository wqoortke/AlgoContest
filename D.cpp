#include <iostream>
#include <string>
#include <map>

std::string rev(std::string r) {
    std::string out;
    for (int i = r.size() - 1; i >= 0; i--) {
        out += r[i];
    }
    return out;
}


int main() {
    std::map<char, int> m;
    std::string s;
    std::string r;
    int n;
    std::cin >> n;
    std::cin >> s;
    for (const char i : s) {
        m[i] += 1;
    }
    for (auto& p : m) {
        if (p.second > 1) {
            for (int j = 0; j < (p.second / 2); j++) {
                r += p.first;
            }
            p.second -= 2 * (p.second / 2);
        }
    }
    int counter = 0;
    for (auto p : m) {
        if (p.second == 1) {
            r += p.first;
            counter += 1;
            break;
        }
    }
    bool b = counter != 1;
    r += rev(r.substr(0, r.size() - 1 + b));
    std::cout << r;
    return 0;
}
