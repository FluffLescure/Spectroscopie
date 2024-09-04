#include <iostream>
#include <sstream>
#include <string>

std::string fetch(std::string msg) {
    std::string input;
    std::cout << msg << std::endl;
    getline(std::cin, input);
    return input;
}

int main() {
    std::istringstream stream(fetch("Write me a letter..."));
    std::string word;
    for (int i = 0; stream >> word; i++) {
        stream.str().substr(0, word.length());
        printf("%d. %s\n", i, word);
    }

    return 0;
}