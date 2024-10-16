#include <iostream>
#include <fstream>


int main() {
    std::string inp;
    std::ifstream f;
    f.open("input.txt");
    if (!f.is_open()) {
        return 1;
    }
    while (getline(f, inp))
    {


    }
    f.close();
}
