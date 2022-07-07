// reference: https://adtinfo.org

#ifndef BST_HPP
#define BST_HPP

#include <string>
#include <memory>



//  MARK: - prototype
namespace ft {

template <class T> struct bst_node;
template <class T, class Compare, class Allocator> class bst;

}   // namespace ft

namespace LMI {

template <class T>
std::string debugDescription(const ft::bst_node<T>& node);

template <class T, class Compare, class Allocator>
std::string debugDescription(const ft::bst<T, Compare, Allocator>& bst);

}   // namespace LMI



namespace ft {

//  MARK: - bst_node
template <class T>
struct bst_node {
public:
    typedef T           value_type;

    enum link_index {
        LI_LEFT,
        LI_RIGHT,
        LI_PARENT,
    };  // enum link

    bst_node*   link[3];
    value_type  value;

    bst_node(void): value() { bzero(this->link, sizeof(bst_node*) * 3); }
    bst_node(const value_type& value): value(value) { bzero(this->link, sizeof(bst_node*) * 3); }

    void transform_up() {
        int direction;

        bst_node* const parent = this->link[LI_PARENT];

        if (!(parent != NULL))
            return;

        bst_node* const grandParent = parent->link[LI_PARENT];

        this->link[LI_PARENT] = grandParent;
        if (grandParent != NULL) {
            direction = grandParent->link[LI_RIGHT] == parent;
            grandParent->link[direction] = this;
        }

        direction = parent->link[LI_RIGHT] == this;
        bst_node* const child = this->link[!direction];
        parent->link[direction] = child;
        if (child != NULL)
            child->link[LI_PARENT] = parent;

        this->link[!direction] = parent;
        parent->link[LI_PARENT] = this;
    }

    std::string debugDescription(void) const {
        std::string description;

        std::ostringstream oss;

        description += "{";
        description += "\"value\":";
        description += LMI::debugDescription(this->value);
        description += ",";
        description += "\"link[ft::bst_node<T>::LI_LEFT]\":";
        bst_node* const leftChild = this->link[ft::bst_node<T>::LI_LEFT];
        if (leftChild == NULL)
            description += LMI::debugDescription(leftChild);
        else
            description += LMI::debugDescription(*leftChild);
        description += ",";
        description += "\"link[ft::bst_node<T>::LI_RIGHT]\":";
        bst_node* const rightChild = this->link[ft::bst_node<T>::LI_RIGHT];
        if (rightChild == NULL)
            description += LMI::debugDescription(rightChild);
        else
            description += LMI::debugDescription(*rightChild);
        description += "}";

        return description;
    }
};  // struct bst_node



//  MARK: - bst
template <class T, class Compare = std::less<T>, class Allocator = std::allocator<bst_node<T> > >
class bst {
public:
    typedef T                       value_type;
    typedef bst_node<value_type>    node_type;
    typedef Compare                 value_compare;
    typedef Allocator               allocator_type;

private:
    allocator_type  allocator_;
    value_compare   value_compare_;
    node_type*      root_;
    std::size_t     node_count_;

public:
    bst(const value_compare& compare = value_compare(), const allocator_type& allocator = allocator_type())
    : allocator_(allocator), value_compare_(compare), root_(NULL), node_count_() {
    }

    node_type* search(const T& value) {
        node_type* p;

        for (p = this->root_; p != NULL;)
            if (this->value_compare_(value, p->value_)) p = p->link[node_type::LI_LEFT];
            else if (this->value_compare_(p->value_, value)) p = p->link[node_type::LI_RIGHT];
            else return p;

        return NULL;
    }

    node_type* insert(const T& value) {
        node_type* o;
        node_type* p;
        int direction;

        for (o = NULL, p = root_; p != NULL; o = p, p = p->link[direction])
            if (value_compare_(value, p->value)) direction = node_type::LI_LEFT;
            else if (value_compare_(p->value, value)) direction = node_type::LI_RIGHT;
            else return p;

        node_type* new_node = allocator_.allocate(1);
        allocator_.construct(new_node, node_type(value));

        if (o != NULL) {
            o->link[direction] = new_node;
            new_node->link[bst_node<T>::LI_PARENT] = o;
        }
        else root_ = new_node;

        ++node_count_;

        return new_node;
    }

    void root_insert(const T& value) {
        node_type* new_node = insert(value);
        while (new_node->link[bst_node<T>::LI_PARENT] != NULL)
            new_node->transform_up();
        root_ = new_node;
    }

    std::string debugDescription(void) const {
        std::string description;

        description += "{";
        description += "\"root_\":";
        if (root_ == NULL)
            description += LMI::debugDescription(root_);
        else
            description += LMI::debugDescription(*root_);
        description += ",";
        description += "\"node_count_\":";
        description += LMI::debugDescription(node_count_);
        description += "}";

        return description;
    }
};  // class bst

}   // namespace ft



//  MARK: - LMI::debugDescription() shadowing
namespace LMI {

template <class T>
std::string debugDescription(const ft::bst_node<T>& node) {
    return node.debugDescription();
}

template <class T, class Compare, class Allocator>
std::string debugDescription(const ft::bst<T, Compare, Allocator>& bst) {
    return bst.debugDescription();
}

}   // namespace LMI

#endif  // BST_HPP
