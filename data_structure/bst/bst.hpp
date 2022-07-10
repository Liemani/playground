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

    enum Direction {
        D_LEFT,
        D_RIGHT,
        D_PARENT,
    };  // enum Direction

    bst_node*   link_[3];
    value_type  value_;

    bst_node(void): value_() { bzero(this->link_, sizeof(bst_node*) * 3); }
    bst_node(const value_type& value): value_(value) { bzero(this->link_, sizeof(bst_node*) * 3); }

    bst_node*& parent() { return this->link_[D_PARENT]; }
    bst_node*& leftChild() { return this->link_[D_LEFT]; }
    bst_node*& rightChild() { return this->link_[D_RIGHT]; }
    const bst_node* parent() const { return this->link_[D_PARENT]; }
    const bst_node* leftChild() const { return this->link_[D_LEFT]; }
    const bst_node* rightChild() const { return this->link_[D_RIGHT]; }

    void transform_up() {
        int direction;

        bst_node* const parent = this->parent();

        if (!(parent != NULL))
            return;

        bst_node* const grandParent = parent->parent();

        this->parent() = grandParent;
        if (grandParent != NULL) {
            direction = grandParent->rightChild() == parent;
            grandParent->link_[direction] = this;
        }

        direction = parent->rightChild() == this;
        bst_node* const child = this->link_[!direction];
        parent->link_[direction] = child;
        if (child != NULL)
            child->parent() = parent;

        this->link_[!direction] = parent;
        parent->parent() = this;
    }

    template <class UnaryFunction>
    void traverse(UnaryFunction action) {
        bst_node* leftChild = this->leftChild();
        bst_node* rightChild = this->rightChild();
        if (leftChild != NULL)
            this->leftChild()->traverse(action);
        action(value_);
        if (rightChild != NULL)
            this->rightChild()->traverse(action);
    }

    std::string debugDescription(void) const {
        std::string description;

        std::ostringstream oss;

        description += "{";
        description += "\"value_\":";
        description += LMI::debugDescription(this->value_);
        description += ",";
        description += "\"leftChild()\":";
        const bst_node* const leftChild = this->leftChild();
        if (leftChild == NULL)
            description += LMI::debugDescription(leftChild);
        else
            description += LMI::debugDescription(*leftChild);
        description += ",";
        description += "\"rightChild()\":";
        const bst_node* const rightChild = this->rightChild();
        if (rightChild == NULL)
            description += LMI::debugDescription(rightChild);
        else
            description += LMI::debugDescription(*rightChild);
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
        node_type* searchingNode = this->root_;
        while (searchingNode != NULL) {
            if (this->value_compare_(value, searchingNode->value_))
                searchingNode = searchingNode->leftChild();
            else if (this->value_compare_(searchingNode->value_, value))
                searchingNode = searchingNode->rightChild();
            else
                return searchingNode;
        }

        return NULL;
    }

    const node_type* search(const T& value) const {
        node_type* searchingNode = this->root_;
        while (searchingNode != NULL) {
            if (this->value_compare_(value, searchingNode->value_))
                searchingNode = searchingNode->leftChild();
            else if (this->value_compare_(searchingNode->value_, value))
                searchingNode = searchingNode->rightChild();
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

        node_type*& rightChild = removingNode->rightChild();
        node_type*& leftChild = removingNode->leftChild();
        if (rightChild == NULL) {
            replaceNode = leftChild;
            makeLinkToChild(parent, direction, replaceNode);
        }
        else if (rightChild->leftChild() == NULL) {
            replaceNode = rightChild;
            makeLinkToChild(replaceNode, node_type::D_LEFT, leftChild);
            makeLinkToChild(parent, direction, replaceNode);
        }
        else {
            node_type* leftestOfRightSubtree;
            leftestOfRightSubtree = rightChild->leftChild();
            node_type*& leftestNode = leftestOfRightSubtree;
            while (leftestNode->leftChild() != NULL)
                leftestNode = leftestNode->leftChild();
            makeLinkToChild(
                    leftestOfRightSubtree->parent(),
                    node_type::D_LEFT,
                    leftestOfRightSubtree->rightChild()
                    );

            replaceNode = leftestOfRightSubtree;
            makeLinkToChild(replaceNode, node_type::D_LEFT, removingNode->leftChild());
            makeLinkToChild(replaceNode, node_type::D_RIGHT, removingNode->rightChild());
            makeLinkToChild(parent, direction, replaceNode);
        }

        if (parent == NULL)
            this->root_ = replaceNode;

        allocator_.destroy(removingNode);
        allocator_.deallocate(removingNode, 1);

        --node_count_;
    }

    template <class UnaryFunction>
    void walk(UnaryFunction action) {
        if (root_ == NULL)
            return;

        root_->traverse(action);
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
