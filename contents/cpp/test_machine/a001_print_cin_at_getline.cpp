#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    std::string token;

    while (getline(cin, token))
        cout << token << endl << endl;

    if (cin.eof())
        cout << "cin.eof() is true." << endl;
    if (cin.fail())
        cout << "cin.fail() is true." << endl;
    if (cin.bad())
        cout << "cin.bad() is true." << endl;
    if (cin.good())
        cout << "cin.good() is true." << endl;

    return 0;
}
