#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"
#define EMPTY_TREE 1
#define NON_EXISTENT 2

class BSTree{
    private:
        Node *root;
        std::string traverse(Node *n);

    public:
        BSTree();
        std::string get_debug_string();
        int rsearch(int value);
        int rsearch(int value, Node *p);
        void insert(int value);
        void insert(int value, Node *previous, Node* current);

        int countChildren(Node *p);
        Node* search(int value);
        Node* previousNode(int value);
        Node* largestValue(Node *x);
        Node* notNull(Node *x);
        void deletion(int value);

        int leaves();
        int leaves(Node* n);

        int height();
        int height(Node *n);

        int sumLevel(int level);
        int sumOfChildren(Node *n);
};