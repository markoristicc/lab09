// intbst.cpp
// Implements class IntBST
// MARKO RISTIC 3/8/2020

#include "intbst.h"
#include <iostream>
using namespace std;

// constructor sets up empty tree
intbst::intbst() : root(0) { }

// destructor deletes all nodes
intbst::~intbst() {
    clear(root);
}

// recursive helper for destructor
void intbst::clear(Node *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
bool intbst::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool intbst::insert(int value, Node *n) {
    if (value == n->info)
        return false;
    if (value < n->info) {
        if (n->left)
            return insert(value, n->left);
        else {
            n->left = new Node(value);
            return true;
        }
    }
    else {
        if (n->right)
            return insert(value, n->right);
        else {
            n->right = new Node(value);
            return true;
        }
    }
}

// print tree data pre-order
void intbst::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void intbst::printPreOrder(Node *n) const {
    if (n) {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void intbst::printInOrder() const {
    printInOrder(root);
}
void intbst::printInOrder(Node *n) const {
    if(n){
	    printInOrder(n->left);
	    cout << n->info << " ";
	    printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void intbst::printPostOrder() const {
    printPostOrder(root);
}
void intbst::printPostOrder(Node *n) const {
    if(n){
	    printPostOrder(n->left);
	    printPostOrder(n->right);
	    cout << n->info << " ";
    }
}

// return sum of values in tree
int intbst::sum() const {
    return sum(root);
}

// recursive helper for sum
int intbst::sum(Node *n) const {
   if(n){
	if(n->right == NULL)
	    return n->info;
   	 else return n->info + sum(n->left) + sum(n->right);
   }
   else return 0;
}

// return count of values
int intbst::count() const {
    return count(root);
}

// recursive helper for count
int intbst::count(Node *n) const {
    if(n){
	if(n->right == NULL)
	    return 1;
    	else return 1 + count(n->left) + count(n->right);
    }
    else return 0;
}

// returns true if value is in the tree; false if not
bool intbst::contains(int value) const {
    return contains(value, root);	    
}
bool intbst::contains(int value, Node *n) const {
    if(n == NULL)
	    return false;
    else if(n->info == value)
	    return true;
    else if(n->info > value)
	    return contains(value, n->left);
    else if(n->info < value)
	    return contains(value, n->right);
}

// implement optional challenge methods below
