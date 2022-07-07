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

#define GROUND001
#ifdef GROUND001
int main(void) {
    cout << "[test502]" << endl;

    ft::bst<int> bst;

    bst.insert(1);
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(6);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    cout << endl;

    bst.root_insert(4);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    cout << endl;

    return 0;
}
#endif

#ifdef GROUND000
int main(void) {
    cout << "[test501]" << endl;
    ft::bst<int> bst;

    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    cout << endl;

    bst.insert(1);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    cout << endl;

    bst.insert(2);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    cout << endl;

    bst.insert(0);
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));
    cout << endl;

    return 0;
}
#endif
