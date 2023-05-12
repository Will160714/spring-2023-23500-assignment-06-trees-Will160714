#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
    root = nullptr;
}

// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
    std::string a,b,c;
  
    if(n==nullptr)
        return "";
    
    else{
        a = traverse(n->getLeft());
        b = std::to_string(n->getData());
        c = traverse(n->getRight());
        return a + ", " + b+ ", " + c; 
    }
}

std::string BSTree::get_debug_string(){
  return traverse(root);
}

int BSTree::rsearch(int value){
    return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p){
    if(p == nullptr)
        throw NON_EXISTENT;
    if(p -> getData() == value)
        return value;
    
    if(p -> getData() > value)
        rsearch(value, p -> getLeft());
    else
        rsearch(value, p -> getRight());

}

void BSTree::insert(int value){
    Node* tmp = nullptr;
    return insert(value, tmp, root);
}

void BSTree::insert(int value, Node *previous, Node* current){
    if(current == nullptr){
        Node* tmp = new Node(value);
        if(previous == nullptr)
            root = tmp;
        else if(previous -> getData() == value)
            return;
        else if(previous -> getData() > value)
            previous -> setLeft(tmp);
        else
            previous -> setRight(tmp);
    }
    else{
        if(current -> getData() == value)
            return;
        else if(current -> getData() > value)
            insert(value, current, current -> getLeft());
        else
            insert(value, current, current -> getRight());
    }
}


Node* BSTree::search(int value){
    Node *current = root;

    while (current != nullptr){
        int node_val = current->getData();
        if (value == node_val)
            return current;
        else if (value < node_val)
            current = current->getLeft();
        else 
            current = current->getRight();
    }

    return nullptr;
}

Node* BSTree::previousNode(int value){
    Node *trailer = nullptr;
    Node *current = root;

    while (current != nullptr){
        int node_val = current->getData();
        if (value == node_val)
            return trailer;
        else if (value < node_val){
            trailer = current;
            current = current->getLeft();
        }
        else{
            trailer = current;
            current = current->getRight();
        }
    }

    return nullptr;
}


int BSTree::countChildren(Node *p){
    int count = 0;
    if(p -> getRight() != nullptr)
        count++;
    if(p -> getLeft() != nullptr)
        count++;
    return count;
}

Node* BSTree::largestValue(Node *x){
    Node* trailer = nullptr;
    Node* header = x -> getLeft();
    if(header == nullptr)
        return nullptr;
    Node *NodeOfLargest = header;

    int largest = header -> getData();
    while(header != nullptr){
        if(header -> getData() > largest){
            largest = header -> getData();
            NodeOfLargest = header;
        }
        trailer = header;
        header = header -> getRight();
    }
    return NodeOfLargest;
}

Node* BSTree::notNull(Node *x){
    if(x -> getRight() != nullptr)
        return x -> getRight();
    return x -> getLeft();
}

void BSTree::deletion(int value){
    Node* NodeToDelete = search(value);
    if(NodeToDelete == nullptr)
        throw NON_EXISTENT;
    int children = countChildren(NodeToDelete);
    Node* previous = previousNode(value);

    if(children < 2){
        if(previous == nullptr){
            Node *tmp = nullptr;
            if(children == 1)
                tmp = notNull(NodeToDelete);
            
            delete NodeToDelete;
            root = tmp;
        }
        
        else{
            Node *replacement = nullptr;
            if(children == 1)
                replacement = notNull(NodeToDelete);
            
            if(previous -> getRight() == NodeToDelete)
                previous -> setRight(replacement);
            else
                previous -> setLeft(replacement);
            
            delete NodeToDelete;    
        }
    }

    else{
        if(previous == nullptr){
            Node* newRoot = NodeToDelete -> getLeft();
            newRoot -> setRight(NodeToDelete -> getRight());
            delete NodeToDelete;
            root = newRoot;
        }
        
        else{
            Node* largest = largestValue(NodeToDelete);
            Node* previousOfLargest = previousNode(largest -> getData());
            
            if(previousOfLargest -> getRight() == largest)
                previousOfLargest -> setRight(nullptr);
            else
                previousOfLargest -> setLeft(nullptr);

            largest -> setRight(NodeToDelete -> getRight());
            largest -> setLeft(NodeToDelete -> getLeft());

            if(previous -> getRight() == NodeToDelete)
                previous -> setRight(largest);
            else
                previous -> setLeft(largest);
            
            delete NodeToDelete;
        }
    }
}

int BSTree::leaves(){
    return leaves(root);
}

int BSTree::leaves(Node* n){
    if(n == nullptr)
        return 0;

    return countChildren(n) + leaves(n -> getRight()) + leaves(n -> getLeft());
}

int BSTree::height(){
    return height(root);
}

int BSTree::height(Node *n){
    if(n == nullptr)
        return 0;
    
    int left = 1 + height(n -> getRight());
    int right = 1 + height(n -> getLeft());

    if(right > left)
        return right;
    return left;
}

//Root is 1
int BSTree::sumLevel(int level){
    if(root == nullptr || level < 0)
        return 0;

    if(level == 1)
        return root -> getData();
    
    Node *preLeft = root;
    Node *preRight = root;
    
    for(int x = 1; x < level - 1; x++){
        if(preLeft != nullptr)
            preLeft = preLeft -> getLeft();
        if(preRight != nullptr)
            preRight = preRight -> getRight();
    }

    if(preLeft == preRight)
        return sumOfChildren(preLeft);
    return sumOfChildren(preLeft) + sumOfChildren(preRight);
}

int BSTree::sumOfChildren(Node *n){
    if(n == nullptr)
        return 0;
    
    int sum = 0;

    if(n -> getRight() != nullptr)
        sum += n -> getRight() -> getData();

    if(n -> getLeft() != nullptr)
        sum += n -> getLeft() -> getData();

    return sum;
}