#include <iostream>
#include "linkedListBst.h"

using namespace std;

int main() {
    LinkedBST bst;
    
    cout << "Adding nodes to the BST" << endl;
    bst.addBST(10);
    bst.addBST(5);
    bst.addBST(20);
    bst.addBST(15);
    cout<<"Added   10\n\t5\n\t20\n\t15"<<endl;

    cout << "BST after additions:" << endl;
    cout << "Contains 10? " << (bst.searchBST(10) ? "Yes" : "No") << endl;
    cout << "Contains 5? " << (bst.searchBST(5) ? "Yes" : "No") << endl;
    cout << "Contains 20? " << (bst.searchBST(20) ? "Yes" : "No") << endl;
    cout << "Contains 15? " << (bst.searchBST(15) ? "Yes" : "No") << endl;
    cout << "Contains 25? " << (bst.searchBST(25) ? "Yes" : "No") << endl;

    cout << "Removing node 10 from the BST" << endl;
    bst.removeBST(10);

    cout << "BST after deletion:" << endl;
    cout << "Contains 10? " << (bst.searchBST(10) ? "Yes" : "No") << endl;

    return 0;
}

LinkedBST::LinkedBST() : root(nullptr) {}
LinkedBST::~LinkedBST() {
    delete root;
}

bool LinkedBST::isEmpty()
{
    return root == nullptr;
}

void LinkedBST::addBST(int data)
{
    Node *newNode = new Node(data);
    if (isEmpty())
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    Node *parent = nullptr;
    while (temp != nullptr)
    {
        parent = temp;
        if (data < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    if (data < parent->key)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
    newNode->parent = parent;
}

void LinkedBST::removeBST(int keyToDelete)
{
    Node* temp = root;
    Node* parent = nullptr;
    
    // Find the node to delete
    while (temp != nullptr && temp->key != keyToDelete) {
        parent = temp;
        if (keyToDelete < temp->key) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }

    if (temp == nullptr) {
        // not found
        return;
    }

    // Case 1: Node has no children
    if (temp->leftChild == nullptr && temp->rightChild == nullptr) {
        if (parent == nullptr) {
            root = nullptr;
        } else if (parent->leftChild == temp) {
            parent->leftChild = nullptr;
        } else {
            parent->rightChild = nullptr;
        }
        delete temp;
    }
    // Case 2: Node has one child
    else if (temp->leftChild == nullptr) {
        if (parent == nullptr) {
            root = temp->rightChild;
        } else if (parent->leftChild == temp) {
            parent->leftChild = temp->rightChild;
        } else {
            parent->rightChild = temp->rightChild;
        }
        delete temp;
    } else if (temp->rightChild == nullptr) {
        if (parent == nullptr) {
            root = temp->leftChild;
        } else if (parent->leftChild == temp) {
            parent->leftChild = temp->leftChild;
        } else {
            parent->rightChild = temp->leftChild;
        }
        delete temp;
    }
    // Case 3: Node has two children
    else {
        Node* successor = temp->rightChild;
        Node* successorParent = temp;
        while (successor->leftChild != nullptr) {
            successorParent = successor;
            successor = successor->leftChild;
        }

        if (successorParent != temp) {
            successorParent->leftChild = successor->rightChild;
        } else {
            successorParent->rightChild = successor->rightChild;
        }

        temp->key = successor->key;
        delete successor;
    }
    cout<< "Node Deleled" << endl;
}


bool LinkedBST::searchBST(int targetKey)
{
    Node* temp = root;
    while (temp != nullptr) {
        if (targetKey == temp->key) {
            return true;
        } else if (targetKey < temp->key) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    return false;
}