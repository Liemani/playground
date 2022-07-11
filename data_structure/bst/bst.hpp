// reference: https://adtinfo.org

#ifndef BST_HPP
#define BST_HPP

#include <string>
#include <memory>
#include <iterator>



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

    enum Direction {
        D_LEFT,
        D_RIGHT,
        D_PARENT,
    };  // enum Direction

    static const std::size_t MAX_HEIGHT = 32;

    bst_node*   link_[3];
    value_type  value_;

    bst_node(void): value_() { bzero(link_, sizeof(bst_node*) * 3); }
    bst_node(const value_type& value): value_(value) { bzero(link_, sizeof(bst_node*) * 3); }

    bst_node*& parent() { return link_[D_PARENT]; }
    bst_node*& left() { return link_[D_LEFT]; }
    bst_node*& right() { return link_[D_RIGHT]; }

    const bst_node* parent() const { return link_[D_PARENT]; }
    const bst_node* left() const { return link_[D_LEFT]; }
    const bst_node* right() const { return link_[D_RIGHT]; }

    bool is_left_child() { return this->parent()->left() == this; }

    bst_node* min() {
        bst_node* node = this;
        while (node->left() != NULL)
            node = node->left();
        return node;
    }

    bst_node* max() {
        bst_node* node = this;
        while (node->right() != NULL)
            node = node->right();
        return node;
    }

    bst_node* next() {
        bst_node* node = this;
        if (node->right() != NULL)
            return node->right()->min();
        while (node->parent() != NULL && !node->is_left_child())
            node = node->parent();
        return node->parent();
    }

    bst_node* previous() {
        bst_node* node = this;
        if (node->left() != NULL)
            return node->left()->max();
        while (node->is_left_child())
            node = node->parent();
        return node->parent();
    }

    void transform_up() {
        int direction;

        bst_node* const parent = this->parent();

        if (!(parent != NULL))
            return;

        bst_node* const grandParent = parent->parent();

        this->parent() = grandParent;
        if (grandParent != NULL) {
            direction = grandParent->right() == parent;
            grandParent->link_[direction] = this;
        }

        direction = parent->right() == this;
        bst_node* const child = link_[!direction];
        parent->link_[direction] = child;
        if (child != NULL)
            child->parent() = parent;

        link_[!direction] = parent;
        parent->parent() = this;
    }

    std::string debugDescription(void) const {
        std::string description;

        std::ostringstream oss;

        description += "{";
        description += "\"value_\":";
        description += LMI::debugDescription(this->value_);
        description += ",";
        description += "\"left()\":";
        const bst_node* const left = this->left();
        if (left == NULL)
            description += LMI::debugDescription(left);
        else
            description += LMI::debugDescription(*left);
        description += ",";
        description += "\"right()\":";
        const bst_node* const right = this->right();
        if (right == NULL)
            description += LMI::debugDescription(right);
        else
            description += LMI::debugDescription(*right);
        description += "}";

        return description;
    }
};  // struct bst_node

template <class T>
void makeLinkToChild(bst_node<T>* currentNode, typename bst_node<T>::Direction directionToChild, bst_node<T>* childNode) {
    if (childNode != NULL)
        childNode->parent() = currentNode;
    if (currentNode != NULL)
        currentNode->link_[directionToChild] = childNode;
}

template <class T, class UnaryFunction>
void traverse_recursive(bst_node<T>* node, UnaryFunction action) {
    if (node != NULL) {
        traverse_recursive(node->left(), action);
        action(node->value_);
        traverse_recursive(node->right(), action);
    }
}

#ifdef TRAVERSE_ITERATIVE1
//  tail recursion elimination
template <class T, class UnaryFunction>
void traverse_iterative(bst_node<T>* node, UnaryFunction action) {
start:
    if (node != NULL) {
        traverse_iterative(node->left(), action);
        action(node->value_);
        node = node->right();
        goto start;
    }
}
#endif  // TRAVERSE_ITERATIVE1

#ifdef TRAVERSE_ITERATIVE2
//  goto-to-while conversion
template <class T, class UnaryFunction>
void traverse_iterative(bst_node<T>* node, UnaryFunction action) {
    while (node != NULL) {
        traverse_iterative(node->left(), action);
        action(node->value_);
        node = node->right();
    }
}
#endif  // TRAVERSE_ITERATIVE2

#ifdef TRAVERSE_ITERATIVE3
//  save-and-restore recursion elimination
template <class T, class UnaryFunction>
void traverse_iterative(bst_node<T>* node, UnaryFunction action) {
    bst_node<T>* stack[bst_node<T>::MAX_HEIGHT];
    std::size_t height = 0;

    while (node != NULL) {
        stack[height++] = node;
        node = node->left();
        continue;
resume:
        action(node->value_);
        node = node->right();
    }
    if (height > 0) {
        node = stack[--height];
        goto resume;
    }
}
#endif  // TRAVERSE_ITERATIVE3

#ifdef TRAVERSE_ITERATIVE4
//  eliminate label resume:
template <class T, class UnaryFunction>
void traverse_iterative(bst_node<T>* node, UnaryFunction action) {
    bst_node<T>* stack[bst_node<T>::MAX_HEIGHT];
    std::size_t height = 0;

start:
    while (node != NULL) {
        stack[height++] = node;
        node = node->left();
    }
    if (height > 0) {
        node = stack[--height];
        action(node->value_);
        node = node->right();
        goto start;
    }
}
#endif  // TRAVERSE_ITERATIVE3

#ifdef TRAVERSE_ITERATIVE5
//  eliminate label resume:
template <class T, class UnaryFunction>
void traverse_iterative(bst_node<T>* node, UnaryFunction action) {
    bst_node<T>* stack[bst_node<T>::MAX_HEIGHT];
    std::size_t height = 0;

    while (true) {
        while (node != NULL) {
            stack[height++] = node;
            node = node->left();
        }
        if (height == 0)
            break;
        node = stack[--height];
        action(node->value_);
        node = node->right();
    }
}
#endif  // TRAVERSE_ITERATIVE3

//  #ifdef TRAVERSE_ITERATIVE6
//  //  eliminate label resume:
//  template <class T, class UnaryFunction>
//  void traverse_iterative(bst_node<T>* node, UnaryFunction action) {
//      bst_node<T>* stack[bst_node<T>::MAX_HEIGHT];
//      std::size_t height = 0;
//  
//      while (node != NULL) {
//          stack[height++] = node;
//          node = node->left();
//      }
//      while (height > 0) {
//          node = stack[--height];
//          action(node->value_);
//          node = node->right();
//          while (node != NULL) {
//              stack[height++] = node;
//              node = node->left();
//          }
//      }
//  }
//  #endif  // TRAVERSE_ITERATIVE3



//  MARK: - bst_iterator
template <class T>
class bst_iterator {
private:
    typedef bst_node<T>                     _node_type;

public:
    typedef std::size_t                     difference_type;
    typedef bst_node<T>&                    reference;
    typedef bst_node<T>*                    pointer;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
    _node_type* node_;

public:
    bst_iterator(): node_(NULL) {}
    bst_iterator(_node_type& node): node_(&node) {}

    T& operator*() { return node_->value_; }

    bool operator==(const bst_iterator& rhs) {
        return node_ == rhs.node_;
    }

    bool operator!=(const bst_iterator& rhs) {
        return !(*this == rhs);
    }

    bst_iterator& operator++() {
        node_ = node_->next();
        return *this;
    }

    bst_iterator& operator++(int) {
        bst_iterator temp(*this);
        ++(*this);
        return temp;
    }

    bst_iterator& operator--() {
        node_ = node_->previous();
        return *this;
    }

    bst_iterator& operator--(int) {
        bst_iterator temp(*this);
        --(*this);
        return temp;
    }
};  // bst_iterator



//  MARK: - bst
template <class T, class Compare = std::less<T>, class Allocator = std::allocator<bst_node<T> > >
class bst {
public:
    typedef T                       value_type;
    typedef bst_node<value_type>    node_type;
    typedef Compare                 value_compare;
    typedef Allocator               allocator_type;
    typedef bst_iterator<T>         iterator;
    typedef bst_iterator<const T>   const_iterator;

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
        node_type* searchingNode = this->root_;
        while (searchingNode != NULL) {
            if (this->value_compare_(value, searchingNode->value_))
                searchingNode = searchingNode->left();
            else if (this->value_compare_(searchingNode->value_, value))
                searchingNode = searchingNode->right();
            else
                return searchingNode;
        }

        return NULL;
    }

    const node_type* search(const T& value) const {
        node_type* searchingNode = this->root_;
        while (searchingNode != NULL) {
            if (this->value_compare_(value, searchingNode->value_))
                searchingNode = searchingNode->left();
            else if (this->value_compare_(searchingNode->value_, value))
                searchingNode = searchingNode->right();
            else
                return searchingNode;
        }

        return NULL;
    }

    void searchVector(const T& value, node_type*& parent, typename node_type::Direction& direction, node_type*& searchingNode) {
        searchingNode = this->root_;
        parent = NULL;
        while (searchingNode != NULL) {
            if (this->value_compare_(value, searchingNode->value_))
                direction = node_type::D_LEFT;
            else if (this->value_compare_(searchingNode->value_, value))
                direction = node_type::D_RIGHT;
            else
                break;
            parent = searchingNode;
            searchingNode = searchingNode->link_[direction];
        }
    }

    node_type* insert(const T& value) {
        node_type* searchingNode;
        typename node_type::Direction direction;
        node_type* parent;
        searchVector(value, parent, direction, searchingNode);

        if (searchingNode != NULL)
            return searchingNode;

        node_type* new_node = allocator_.allocate(1);
        allocator_.construct(new_node, node_type(value));

        if (parent != NULL) {
            parent->link_[direction] = new_node;
            new_node->parent() = parent;
        }
        else
            root_ = new_node;

        ++node_count_;

        return new_node;
    }

    void root_insert(const T& value) {
        node_type* new_node = insert(value);
        while (new_node->parent() != NULL)
            new_node->transform_up();
        root_ = new_node;
    }

    void remove(const T& value) {
        node_type* removingNode = this->search(value);
        typename node_type::Direction direction;
        node_type* parent;
        searchVector(value, parent, direction, removingNode);
        node_type* replaceNode;

        if (removingNode == NULL)
            return;

        node_type*& right = removingNode->right();
        node_type*& left = removingNode->left();
        if (right == NULL) {
            replaceNode = left;
            makeLinkToChild(parent, direction, replaceNode);
        }
        else if (right->left() == NULL) {
            replaceNode = right;
            makeLinkToChild(replaceNode, node_type::D_LEFT, left);
            makeLinkToChild(parent, direction, replaceNode);
        }
        else {
            node_type* leftestOfRightSubtree;
            leftestOfRightSubtree = right->left();
            node_type*& leftestNode = leftestOfRightSubtree;
            while (leftestNode->left() != NULL)
                leftestNode = leftestNode->left();
            makeLinkToChild(
                    leftestOfRightSubtree->parent(),
                    node_type::D_LEFT,
                    leftestOfRightSubtree->right()
                    );

            replaceNode = leftestOfRightSubtree;
            makeLinkToChild(replaceNode, node_type::D_LEFT, removingNode->left());
            makeLinkToChild(replaceNode, node_type::D_RIGHT, removingNode->right());
            makeLinkToChild(parent, direction, replaceNode);
        }

        if (parent == NULL)
            this->root_ = replaceNode;

        allocator_.destroy(removingNode);
        allocator_.deallocate(removingNode, 1);

        --node_count_;
    }

    iterator begin() {
        if (root_ == NULL)
            return iterator();
        else
            return iterator(*root_->min());
    }

    iterator end() {
        return iterator();
    }

    template <class UnaryFunction>
    void walk_recursive(UnaryFunction action) {
        if (root_ == NULL)
            return;

        traverse_recursive(root_, action);
    }

    template <class UnaryFunction>
    void walk_iterative(UnaryFunction action) {
        if (root_ == NULL)
            return;

        traverse_iterative(root_, action);
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
