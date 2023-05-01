#define TRAVERSE_ITERATIVE5
#define BST_NODE_COPY_RECURSIVE
#define BST_NODE_COPY_ITERATIVE4

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

#define GROUND013
#ifdef GROUND013
int main(void) {
    cout << "[rebalence() test]" << endl;

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
    bst.rebalence();
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    return 0;
}
#endif

#ifdef GROUND012
int main(void) {
    cout << "[transformTreeToVine() test]" << endl;

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
    bst.transformTreeToVine();
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(bst));

    return 0;
}
#endif

#ifdef GROUND011
int main(void) {
    cout << "[bst_node_copy_iterative() test]" << endl;

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

    ft::bst_node<int> dst;
    ft::bst_node_copy_iterative(&dst, bst.getRoot());
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(dst));

    return 0;
}
#endif

#ifdef GROUND010
int main(void) {
    cout << "[bst_node_copy_recursive() test]" << endl;

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

    ft::bst_node<int> dst;
    bst_node_copy_recursive(dst, *bst.getRoot());
    LMI::JSONDescriber::describe(cout, LMI::debugDescription(dst));

    return 0;
}
#endif

#ifdef GROUND009
int main(void) {
    cout << "[bst_traverser test]" << endl;

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

    ft::bst<int>::traverser trav;
    int* item;
    for (item = bst.begin_traverser(trav); item != NULL; item = trav.next_item())
        cout << *item << endl;
    for (item = trav.previous_item(); item != NULL; item = trav.previous_item())
        cout << *item << endl;

    return 0;
}
#endif

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
