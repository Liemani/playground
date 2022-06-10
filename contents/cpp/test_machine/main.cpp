#include <string>
#include <iostream>

int main() {
    std::string name = "hi";
    char buf1[] = { 'a', 'b', 'c', '\0' };
    char buf2[] = { 'd', '\0', 'e', 'f' };

    std::string name1 = name + buf1;
    std::string name2 = name + buf2;

    std::cout << name1 << std::endl;
    std::cout << name2 << std::endl;

    return 0;
}
