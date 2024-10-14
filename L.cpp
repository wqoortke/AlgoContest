#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>

std::string solution(std::string r, std::string s) {
    std::string out;
    std::unordered_set<char> l;
    bool wasInserted = false;
    for (const char e : r) {
        for (int i = 0; i < s.length(); i++) {
            if (l.count(e) == 0) {
                if (s[i] == e) {
                    out += e;
                    wasInserted = true;
                }
            }
        }
        if (wasInserted)
            l.insert(e);
    }
    return out;
}

int main() {
    std::string r, s;
    std::cin >> r >> s;
    std::cout << solution(r, s);
}
