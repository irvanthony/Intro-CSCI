#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node* parent;
};

class BST{
    private:
        node* createNode(int data);
        node* root;

        /** since root is a private member we need helper functions
         to access root for insertion, searching and printing **/
        node* insertNodeHelper(node*, int);
        bool searchKeyHelper(node*, int);
        void printTreeHelper(node*);
        /**Destructor will call this function to recursively delete all node**/
        void destroyNode(node *root);
    public:
        bool searchKey( int);// function to search a data in the tree
        void insertNode(int);// function to insert a node in the tree.
        void printTree();//function to print the tree
        BST(); // default constructor
        BST(int data); // parameterized constructor
        ~BST();// destructor


};
#endif
