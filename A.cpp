#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>


int main() {
    std::string inp;
    std::ifstream f;
    std::vector<std::pair<int,std::string> > data;
    f.open("input.txt");
    if (!f.is_open()) {
        return 1;
    }
    while (getline(f, inp))
    {
        std::pair<int,std::string> p = std::make_pair(std::stoi(inp.substr(0, inp.find_first_of(' '))), inp.substr(inp.find_first_of(' '), inp.length()));
        data.push_back(p);
    }
    f.close();
    for (int i = 9; i < 12; i++) {
        for (int j = 0; j < data.size(); j++) {
            if (data[j].first == i) {
                std::cout << data[j].first << data[j].second << '\n';
            }
        }
    }
}
