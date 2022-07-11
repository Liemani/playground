#define TRAVERSE_ITERATIVE5

#include <iostream>
#include "LMI.hpp"
#include "bst.hpp"

using std::cout;
using std::endl;

/*  template
#ifdef GROUND139
int main(void) {

    return 0;
}
#endif

*/

#define GROUND006
#ifdef GROUND008
int main(void) {
    cout << "[copy constructor test]" << endl;

    ft::bst<int> bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(9);
    bst.insert(8);
    bst.insert(6);
    bst.insert(7);

    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    ft::bst<int> bst2(bst);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst2));

    return 0;
}
#endif

#ifdef GROUND007
int main(void) {
    cout << "[const_iterator test]" << endl;

    ft::bst<int> bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(9);
    bst.insert(8);
    bst.insert(6);
    bst.insert(7);

    ft::bst_iterator iterator = bst.begin();
    while (iterator != bst.end()) {
        cout << "value: " << *iterator << endl;
        ++iterator;
    }


    return 0;
}
#endif

#ifdef GROUND006
int main(void) {
    cout << "[iterator test]" << endl;

    ft::bst<int> bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(9);
    bst.insert(8);
    bst.insert(6);
    bst.insert(7);

    ft::bst<int>::iterator iterator = bst.begin();
    while (iterator != bst.end()) {
        cout << "value: " << *iterator << endl;
        ++iterator;
    }


    return 0;
}
#endif

#ifdef GROUND005
template <class T>
void printNodeValue(T value) {
    cout << "value: " << value << endl;
}

int main(void) {
    cout << "[traverse_iterative test]" << endl;

    ft::bst<int> bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(9);
    bst.insert(8);
    bst.insert(6);
    bst.insert(7);

    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    bst.walk_iterative(printNodeValue<int>);

    return 0;
}
#endif

#ifdef GROUND004
template <class T>
void printNodeValue(T value) {
    cout << "value: " << value << endl;
}

int main(void) {
    cout << "[traverse_recursive test]" << endl;

    ft::bst<int> bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(9);
    bst.insert(8);
    bst.insert(6);
    bst.insert(7);

    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    bst.walk_recursive(printNodeValue<int>);

    return 0;
}
#endif

#ifdef GROUND003
int main(void) {
    cout << "[remove test]" << endl;

    ft::bst<int> bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(9);
    bst.insert(8);
    bst.insert(6);
    bst.insert(7);

    bst.remove(8);
    bst.remove(2);
    bst.remove(5);

    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    return 0;
}
#endif

#ifdef GROUND002
int main(void) {
    cout << "[insert test]" << endl;

    ft::bst<int> bst;
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    bst.insert(1);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    return 0;
}
#endif

#ifdef GROUND001
int main(void) {
    cout << "[root_insert tset]" << endl;
    ft::bst<int> bst;

    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(6);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    bst.root_insert(4);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    return 0;
}
#endif

#ifdef GROUND000
int main(void) {
    ft::bst<int> bst;

    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    bst.insert(1);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    bst.insert(2);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    bst.insert(0);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    return 0;
}
#endif
