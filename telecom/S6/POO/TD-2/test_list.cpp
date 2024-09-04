#include <iostream>
#include <list>
#include <string>

/**
 * @brief Fetches a list of strings from user input, until "end" is given.
 * @return A list of strings
 */
auto fetch() {
    std::list<std::string> l;
    std::string s;

    printf("\nWrite a word:");
    do {
        std::cin >> s;
        if (s.compare("end"))
            l.push_back(s);
        printf("\nWrite a word:");
    } while (s.compare("end"));

    return l;
}

void print(const std::list<std::string>& l) {
    std::list<std::string>::const_iterator ptr;
    for (ptr = l.begin(); ptr != l.end(); ptr++)
        std::cout << *ptr << std::endl;
}

auto operator+(const std::list<std::string>& l1, const std::list<std::string>& l2) {
    auto res = l1;
    std::list<std::string>::const_iterator ptr;
    for (ptr = l2.begin(); ptr != l2.end(); ptr++)
        res.push_back(*ptr);
    return res;
}

void insert(std::list<std::string>& l, const std::string& s) {

    std::list<std::string>::iterator ptr;
    for (ptr = l.begin(); s.compare(*ptr) > 0 && ptr != l.end(); ptr++)
        ;
    l.emplace(ptr, s);
}

auto fetch2() {
    std::list<std::string> l;
    std::string s;

    printf("\nWrite a word:");
    do {
        std::cin >> s;
        if (s.compare("end"))
            insert(l, s);
        printf("\nWrite a word:");
    } while (s.compare("end"));

    return l;
}

auto invert(const std::list<std::string>& l) {
    std::list<std::string> res;
    std::list<std::string>::const_iterator ptr;
    for (ptr = l.end(); ptr != l.begin(); ptr--)
        res.push_back(*ptr);
    return res;
}

int main() {
    std::list<std::string> l;
    std::list<std::string> l2 = {"fuck", "whoever", "asked", "do-while"};
    l = fetch();
    print(l);
    printf("\n");
    std::list<std::string> l3 = l + l2;
    print(l3);
    printf("\n");
    std::list<std::string> l4 = l;
    l4.insert(l4.end(), l2.begin(), l2.end());
    print(l4);
    printf("\n");
    l4.sort();
    print(l4);
    printf("\n");

    insert(l4, "sane");
    print(l4);

    std::list<std::string> m = fetch2();
    print(m);
    printf("\n");

    m = invert(m);
    print(m);

    return 0;
}
