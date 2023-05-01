#include <exception>

int throwingFunction(int x) {
    if (x >= 0) return 1;
    else throw std::exception();
    return 0;
}

int main(void) {
    try {
        throwingFunction(-1);
    } catch (std::exception& e) {
        return -2;
    }

    return 0;
}
