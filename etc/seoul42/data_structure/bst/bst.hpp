// reference: https://adtinfo.org

#ifndef BST_HPP
#define BST_HPP

#include <string>
#include <memory>
#include <iterator>
#include "LMI.hpp"



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

    bst_node*       link_[3];
    value_type      value_;

    bst_node(void): value_() { bzero(link_, sizeof(bst_node*) * 3); }
    bst_node(const value_type& value): value_(value) { bzero(link_, sizeof(bst_node*) * 3); }
    bst_node(const bst_node& rhs): value_(rhs.value_) {}

//      bst_node& operator=(const bst_node& rhs) {
//          new bst_node(rhs->value_);
//      }

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
        description += "\"address\":";
        description += LMI::debugDescription(this);
        description += ",";
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

#ifdef BST_NODE_CLONE_RECURSIVE1
template <class T>
bst_node<T>* bst_node_clone_recursive(const bst_node<T>* const node) {
    if (node == NULL)
        return NULL;

    bst_node<T>* clone = new bst_node<T>(node->value_);

    clone->left() = bst_node<T>_clone_recursive(node->left());
    clone->right() = bst_node<T>_clone_recursive(node->right());

    return clone;
}
#endif  // BST_NODE_CLONE_RECURSIVE1

#ifdef BST_NODE_CLONE_RECURSIVE2
template <class T>
bst_node<T>* bst_node_clone_recursive(const bst_node<T>* node) {
    bst_node<T>* clone = new bst_node<T>(node->value_);

    if (node->left() == NULL)
        clone->left() = NULL;
    else
        clone->left() = bst_node_clone_recursive(clone->left());

    if (node->right() == NULL)
        clone->right() = NULL;
    else
        clone->right() = bst_node_clone_recursive(clone->right());

    return clone;
}
#endif  // BST_NODE_CLONE_RECURSIVE2

#ifdef BST_NODE_COPY_RECURSIVE
template <class T>
void bst_node_copy_recursive(bst_node<T>& dst, const bst_node<T>& src) {
    dst.value_ = src.value_;

    if (src.left() != NULL) {
        dst.left() = std::allocator<bst_node<T> >().allocate(1);
        bst_node_copy_recursive(*dst.left(), *src.left());
    }
    else
        dst.left() = NULL;

    if (src.right() != NULL) {
        dst.right() = std::allocator<bst_node<T> >().allocate(1);
        bst_node_copy_recursive(*dst.right(), *src.right());
    }
    else
        dst.right() = NULL;
}
#endif  // BST_NODE_COPY_RECURSIVE

#ifdef BST_NODE_COPY_ITERATIVE1
template <class T>
void bst_node_copy_iterative(bst_node<T>* dst, const bst_node<T>* src) {
    if (dst == NULL)
        return;

start:
    if (src != NULL) {
        dst->value_ = src->value_;

        if (src->left() != NULL) {
            dst->left() = std::allocator<bst_node<T> >().allocate(1);
            bst_node_copy_iterative(dst->left(), src->left());
        }
        else
            dst->left() = NULL;

        if (src->right() != NULL) {
            dst->right() = std::allocator<bst_node<T> >().allocate(1);
            dst = dst->right();
            src = src->right();
            goto start;
        }
        else
            dst->right() = NULL;
    }
}
#endif  // BST_NODE_COPY_ITERATIVE1

#ifdef BST_NODE_COPY_ITERATIVE2
template <class T>
void bst_node_copy_iterative(bst_node<T>* dst, const bst_node<T>* src) {
    if (dst == NULL)
        return;

    while (src != NULL) {
        dst->value_ = src->value_;

        if (src->left() != NULL) {
            dst->left() = std::allocator<bst_node<T> >().allocate(1);
            bst_node_copy_iterative(dst->left(), src->left());
        }
        else
            dst->left() = NULL;

        if (src->right() != NULL) {
            dst->right() = std::allocator<bst_node<T> >().allocate(1);
            dst = dst->right();
            src = src->right();
        }
        else {
            dst->right() = NULL;
            break;
        }
    }
}
#endif  // BST_NODE_COPY_ITERATIVE2

#ifdef BST_NODE_COPY_ITERATIVE3
template <class T>
void bst_node_copy_iterative(bst_node<T>* dst, const bst_node<T>* src) {
    if (dst == NULL)
        return;

    bst_node<T>* dst_stack[bst_node<T>::MAX_HEIGHT];
    const bst_node<T>* src_stack[bst_node<T>::MAX_HEIGHT];
    std::size_t height = 0;

start:
    while (src != NULL) {
        dst->value_ = src->value_;

        if (src->left() != NULL) {
            dst->left() = std::allocator<bst_node<T> >().allocate(1);
            dst_stack[height] = dst;
            src_stack[height] = src;
            ++height;
            dst = dst->left();
            src = src->left();
            goto start;
        }
        else
            dst->left() = NULL;
resume:
        if (src->right() != NULL) {
            dst->right() = std::allocator<bst_node<T> >().allocate(1);
            dst = dst->right();
            src = src->right();
        }
        else {
            dst->right() = NULL;
            break;
        }
    }
    if (height > 0) {
        --height;
        dst = dst_stack[height];
        src = src_stack[height];
        goto resume;
    }
}
#endif  // BST_NODE_COPY_ITERATIVE3

#ifdef BST_NODE_COPY_ITERATIVE4
template <class T>
void bst_node_copy_iterative(bst_node<T>* dst, const bst_node<T>* src) {
    if (dst == NULL)
        return;

    bst_node<T>* dst_stack[bst_node<T>::MAX_HEIGHT];
    const bst_node<T>* src_stack[bst_node<T>::MAX_HEIGHT];
    std::size_t height = 0;

start:
    while (src != NULL) {
        dst->value_ = src->value_;

        if (src->left() != NULL) {
            dst->left() = std::allocator<bst_node<T> >().allocate(1);
            dst_stack[height] = dst;
            src_stack[height] = src;
            ++height;
            dst = dst->left();
            src = src->left();
            goto start;
        }
        else {
            dst->left() = NULL;
            goto middle;
        }
    }
endwhile:
    if (height > 0) {
        --height;
        dst = dst_stack[height];
        src = src_stack[height];
middle:
        if (src->right() != NULL) {
            dst->right() = std::allocator<bst_node<T> >().allocate(1);
            dst = dst->right();
            src = src->right();
            goto start;
        }
        else {
            dst->right() = NULL;
            goto endwhile;
        }
    }
}
#endif  // BST_NODE_COPY_ITERATIVE4

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
#endif  // TRAVERSE_ITERATIVE4

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
#endif  // TRAVERSE_ITERATIVE5

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



//  MARK: - bst_traverser
template <class T>
class bst_traverser {
private:
    typedef T           node_value_type;
    typedef bst_node<T> node_type;

    node_type*          root_;
    node_type*          node_;
    node_type*          stack_[node_type::MAX_HEIGHT];
    std::size_t         height_;

    node_type* get_value_node() {
        if (node_ == NULL) {
            if (height_ == 0)
                return root_ != NULL ? root_->max() : NULL;
            else
                return stack_[height_ - 1]->left()->max();
        }
        return node_->parent();
    }

public:
    bst_traverser()
    : root_(NULL)
    , node_(NULL)
    , height_(0) {
    }

    bst_traverser(node_type* root)
    : root_(root)
    , node_(root_)
    , height_(0) {
    }

    bool operator==(const bst_traverser& rhs) {
        return node_ == rhs.node_ && height_ == rhs.height_;
    }

    bool operator!=(const bst_traverser& rhs) {
        return !(*this == rhs);
    }

    T& operator*() {
        return node_->value_;
    }

    T* next_item() {
        while (node_ != NULL) {
            stack_[height_++] = node_;
            node_ = node_->left();
        }

        if (height_ == 0)
            return NULL;

        node_ = stack_[--height_];
        T* value_ptr = &node_->value_;
        node_ = node_->right();

        return value_ptr;
    }

    T* previous_item() {
        if (node_ == NULL) {
            node_ = this->get_value_node();
            if (node_ == NULL)
                return NULL;
        }
        else {
            if (node_ == root_)
                return NULL;
            node_ = node_->parent();
        }

        T* value_ptr = &node_->value_;

        if (node_->left() != NULL) {
            stack_[height_++] = node_;
            node_ = node_->left()->max()->right();
        }
        else if (node_ == root_) {
            return NULL;
        }
        else {
            while (height_ > 0 && stack_[height_ - 1]->left() == node_)
                node_ = stack_[--height_];
        }

        return value_ptr;
    }

    std::string debugDescription(void) const {
        std::string description;

        description += "{";
        description += "\"node_\":";
        if (node_ == NULL)
            description += LMI::debugDescription(node_);
        else
            description += LMI::debugDescription(*node_);
        description += ",";
        description += "\"height_\":";
        description += LMI::debugDescription(height_);
        description += "}";

        return description;
    }
};  // class bst_traverser



//  MARK: - bst
template <class T, class Compare = std::less<T>, class Allocator = std::allocator<bst_node<T> > >
class bst {
public:
    typedef T                       value_type;
    typedef bst_node<value_type>    node_type;
    typedef Compare                 value_compare;
    typedef Allocator               allocator_type;
    typedef bst_traverser<T>        traverser;
    typedef const bst_traverser<T>  const_traverser;
    typedef bst_iterator<T>         iterator;
    typedef bst_iterator<const T>   const_iterator;

private:
    node_type*      root_;
    node_type*      begin_node_;
    node_type*      end_node_;
    allocator_type  allocator_;
    value_compare   value_compare_;
    std::size_t     node_count_;

    bst& operator=(const bst& rhs);

public:
    bst(const value_compare& compare = value_compare(), const allocator_type& allocator = allocator_type())
    : root_(NULL)
    , begin_node_(NULL)
    , end_node_(NULL)
    , allocator_(allocator)
    , value_compare_(compare)
    , node_count_() {
    }

    const node_type* getRoot() const { return this->root_; }

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
            if (parent == begin_node_ && direction == node_type::D_LEFT)
                begin_node_ = new_node;
        }
        else {
            root_ = new_node;
            begin_node_ = new_node;
        }

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
            root_ = replaceNode;

        if (removingNode == begin_node_)
            begin_node_ = root_->min();

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

    T* begin_traverser(traverser& trav) {
        trav = traverser(root_);
        return trav.next_item();
    }

    T* end_traverser() {
        return NULL;
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

    void transformTreeToVine() {
        if (root_ == NULL)
            return;

        node_type* node = root_;
        while (true) {
            while (node->right() != NULL) {
                node = node->right();
                node->transform_up();
            }
            if (node->left() != NULL)
                node = node->left();
            else
                break;
        }

        while (node->parent() != NULL)
            node = node->parent();
        root_ = node;
    }

    void rebalence() {
        if (root_ == NULL)
            return;

        this->transformTreeToVine();
        std::size_t vineNodeCount = node_count_;

        std::size_t blackNodeCount = vineNodeCount;
        std::size_t rotatedBlackNodeCount = 0;

        while (blackNodeCount >= 3) {
            node_type* node = root_;
            node = node->left();
            node->transform_up();
            root_ = node;

            blackNodeCount /= 2;
            rotatedBlackNodeCount = 1;

            while (rotatedBlackNodeCount < blackNodeCount) {
                node = node->left()->left();
                node->transform_up();
                ++rotatedBlackNodeCount;
            }
        }
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
