#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) {
    std::cout << "argc: " << argc << std::endl;

    for (int i = 0; i < argc; ++i) {
      printf("[%d] %s\n", i, argv[i]);
    }

    return 0;
}
