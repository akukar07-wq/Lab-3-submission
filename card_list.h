// card_list.h
// Author: Akul Karnataki
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <iostream>
#include <string>
#include <vector>
#include "card.h"


using namespace std;


class Card_List
{
    private:
    struct Node
    {
        Card data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    
    
    void insertNode(Card c, Node* n); 
    Node* getSuccessorNode(Card card) const;
    Node* getNodeFor(Card value, Node* n) const;   
    void printNode(Node* n) const;
    Node* root;
    mutable vector<Node*> nodes;
    public:

        Card_List();
        Card_List(Card c);
        ~Card_List();
        void deleteTree(Node* n);
        void insert(Card c);
        bool remove(Card c);
        bool contains(Card c);
        void printList();

        class reverseIterator {
            private:
                const vector<Node*>& vec; 
                size_t i;                
            public:
                reverseIterator(const vector<Node*>& v, size_t start = 0) : vec(v), i(start) {}
                reverseIterator& operator++() { i--; return *this; }     
                reverseIterator operator++(int) { reverseIterator tmp = *this; --(*this); return tmp; }
                reverseIterator& operator--() { i++; return *this; }   
                reverseIterator operator--(int) { reverseIterator tmp = *this; ++(*this); return tmp; }
                Card operator*() const { return vec[i]->data; }
                bool operator==(const reverseIterator& other) const { return i == other.i; }
                bool operator!=(const reverseIterator& other) const { return i != other.i; }
                friend class Card_List;
        };
        class Iterator {
            private:
                const vector<Node*>& vec; 
                size_t i;                
            public:
                Iterator(const vector<Node*>& v, size_t start = 0) : vec(v), i(start) {}
                Iterator& operator++() { i++; return *this; }     
                Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
                Iterator& operator--() { i--; return *this; }   
                Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
                Card operator*() const { return vec[i]->data; }
                bool operator==(const Iterator& other) const { return i == other.i; }
                bool operator!=(const Iterator& other) const { return i != other.i; }
                friend class Card_List;
        };
        void sortForward(Node* node, vector<Node*>& list) const {
    
            if (!node) return;
            sortForward(node->left, list);
            list.push_back(node);
            sortForward(node->right, list);
        }

    Iterator begin() const
    {
       nodes.clear(); 
        sortForward(root, nodes);
        return Iterator(nodes, 0);
    }
    Iterator end() const
    {
        nodes.clear();
        sortForward(root, nodes);
        return Iterator(nodes, nodes.size());
    }
    reverseIterator rbegin() const
    {
        nodes.clear();
        sortForward(root, nodes);
        return reverseIterator(nodes, nodes.size()-1); 
    }
    reverseIterator rend() const{
        nodes.clear();
        sortForward(root, nodes);
        return reverseIterator(nodes, -1); 
    }
    
};
void playGame(Card_List& alice, Card_List& bob);


        
        


    



#endif
