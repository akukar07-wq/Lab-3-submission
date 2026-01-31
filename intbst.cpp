// intbst.cpp
// Implements class IntBST
// Akul, 1/29/25

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(n == nullptr)
    {
        return;
    }
    clear(n->left);
    clear(n->right); 
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if(root == nullptr)
    {
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)

bool IntBST::insert(int value, Node *n) {

    if (value == n->info) {
        return false;
    }
    if (value < n->info) 
    {
        if (n->left == nullptr)
        {
            n->left = new Node(value);
            return true;
        }
        return insert(value, n->left);
    } 
    else 
    {
        if (n->right == nullptr) 
        {
            n->right = new Node(value);
            return true;
        }
        return insert(value, n->right);
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if(n == nullptr)
    {
        return;
    }
    cout<<n->info<<" ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(n == nullptr)
    {
        return;
    }
    printInOrder(n->left);
    cout<<n->info<<" ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if(n == nullptr)
    {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout<<n->info<<" ";
    
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n == nullptr)
    {
        return 0;
    }
    return n->info+sum(n->left)+sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n == nullptr)
    {
        return 0;
    }
    return 1+count(n->left)+count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n == nullptr)
    {
        return NULL;
    }
    if(n->info == value)
    {
        return n;
    }
    if(n->info<value)
    {
        return getNodeFor(value, n->right);
    } 
    if(n->info>value)
    {
        return getNodeFor(value, n->left);
    }  
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root) == NULL)
    {
        return false;
    }
    return true;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if(n == nullptr)
    {
        return NULL;
    }
    if (n->left != nullptr)
    {
        Node* curr = n->left;
        while (curr->right != nullptr)
        {
            curr = curr->right;
        }
        return curr;
    }
    Node* pre = nullptr;
    Node* curr = root;
    while(curr)
    {
        if(value>curr->info)
        {
            pre = curr;
            curr = curr->right; 
        }
        else if (value < curr->info)
        {
            curr = curr->left;
        }
        else
        {
            break;
        }
    }
    return pre;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* n = getPredecessorNode(value);
    if(n == nullptr)
    {
        return 0;
    }
    return n->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if(n == nullptr)
    {
        return NULL;
    }
    if (n->right != nullptr)
    {
        Node* curr = n->right;
        while (curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }
    Node* succ = nullptr;
    Node* curr = root;
    while(curr)
    {
        if(value>curr->info)
        {
            curr = curr->right; 
        }
        else if (value < curr->info)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            break;
        }
    }
    return succ;
    
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* n = getSuccessorNode(value);
    if(n == nullptr)
    {
        return 0;
    }
    return n->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* p = nullptr;
    Node* n = root;
    while (n && n->info != value)
    {
        p = n;
        if (value < n->info)
            n = n->left;
        else
            n = n->right;
    }
    if(n == nullptr)
    {
        return false;
    }
    if(n->right == nullptr)
    {
        if(p == nullptr)
        {
            root = n->left;
            delete n;
            return true;
        }
        else
        {
            if(n == p->right)
            {
                p->right = n->left;
                delete n;
            }
            if(n == p->left)
            {
                p->left = n->left;
                delete n;
            }
            return true;
        }


    }
    else if(n->left == nullptr)
    {
        if(p == nullptr)
        {
            root = n->right;
            delete n;
            return true;
        }
        else
        {
            if(n == p->right)
            {
                p->right = n->right;
                delete n;
            }
            if(n == p->left)
            {
                p->left = n->right;
                delete n;
            }
            return true;
        }

    }
    else
    {
        Node* x = getSuccessorNode(value);
        int i = x->info;
        remove(i);
        n->info = i;
        return true;
    }
    return false;
}
