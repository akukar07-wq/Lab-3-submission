#include "card_list.h"
#include <iostream>
#include <string>
using namespace std;
void playGame(Card_List& alice, Card_List& bob) {
    bool foundMatch = true;
  
    while (foundMatch) {
        foundMatch = false;
        auto it = alice.begin();
        while (it != alice.end()) {
            if (bob.contains(*it)) {
                cout << "Alice picked matching card " << *it << endl;
                bob.remove(*it);
                alice.remove(*it);
                foundMatch = true;
                break;
            } else {
                ++it;
            }
        }
  
        if (!foundMatch) break;
        foundMatch = false;
        auto rev = bob.rbegin();
        while (rev != bob.rend()) {
            if (alice.contains(*rev)) {
                cout << "Bob picked matching card " << *rev << endl;
                alice.remove(*rev);
                bob.remove(*rev);
                foundMatch = true;
                break;
            } else {
                ++rev;
            }

        }
    }
  }

Card_List::Card_List()
{
    root = nullptr;
}
Card_List::Card_List(Card c)
{
    Node* n = new Node();
    n->data = c;
    root = n;
}
Card_List::~Card_List() {
    deleteTree(root);
}

void Card_List::deleteTree(Node* n) {
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}
void Card_List::insert(Card c)
{
    if(root == nullptr){
        root = new Node();
        root->data = c;
        return;
    }
     insertNode(c, root);
}
void Card_List::insertNode(Card c, Node* n)
{
    if (c < n->data)
    {
        if (n->left == nullptr)
        {
            n->left = new Node();
            n->left->data = c;
        }
        else
        {
            insertNode(c, n->left);
        }
    }
    else
    {
        if (n->right == nullptr)
        {
            n->right = new Node();
            n->right->data = c;
        }
        else
        {
            insertNode(c, n->right);
        }
    }
}
Card_List::Node* Card_List::getSuccessorNode(Card c) const
{
    Node* n = getNodeFor(c, root);
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
        if(c>curr->data)
        {
            curr = curr->right; 
        }
        else if (c < curr->data)
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
Card_List::Node* Card_List::getNodeFor(Card value, Node* n) const
{
    if(n == nullptr)
    {
        return NULL;
    }
    if(n->data == value)
    {
        return n;
    }
    else if(n->data<value)
    {
        return getNodeFor(value, n->right);
    } 
    else
    {
        return getNodeFor(value, n->left);
    }  
}
bool Card_List::contains(Card c)
{
    if(getNodeFor(c, root) == nullptr)
    {
        return false;
    }
    return true;
}
bool Card_List::remove(Card c)
{
    Node* p = nullptr;
    Node* n = root;
    while (n && !(n->data == c))
    {
        p = n;
        if (c < n->data)
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
        Node* x = getSuccessorNode(c);
        Card i = x->data;
        remove(i);
        n->data = i;
        return true;
    }
    return false;
}
void Card_List::printList()
{
    printNode(root);
}
void Card_List::printNode(Node* n) const
{
    if(n == nullptr)
    {
        return;
    }
    printNode(n->left);
    cout<<n->data<<endl;
    printNode(n->right);

}


  










