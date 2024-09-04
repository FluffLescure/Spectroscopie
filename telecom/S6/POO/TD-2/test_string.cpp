#include <iostream>
#include <sstream>
#include <string>

std::string fetch(std::string msg) {
    std::string input;
    std::cout << msg << std::endl;
    getline(std::cin, input);
    return input;
}

void count(std::string str) {
    std::istringstream stream(str);
    std::string word;
    int count;

    for (count = 0; stream >> word; count++)
        stream.str().substr(0, word.length());
    printf("There are %d words in your letter.", count);
}

void find(std::string str, std::string find) {
    std::istringstream stream(str);
    std::string word;
    int found, count;

    for (count = 0; stream >> word; word.compare(find) == 0 ? found = count : count++)
        stream.str().substr(0, word.length());

    if (found > count)
        printf("\nWord '%s' not found", find.c_str());
    else
        printf("\nYour word has been found at %d", found);
}

int test_string() {
    std::string str = fetch("Write me a letter...");
    count(str);
    find(str, "notempty");

    return 0;
}