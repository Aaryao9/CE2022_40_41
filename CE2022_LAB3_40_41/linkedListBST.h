#include "BinarySearchTree.h"

class Node {
    public:
        int key;
        Node* leftChild;
        Node* rightChild;
        Node* parent;
        Node() {}
        Node(int d) : key(d), leftChild(nullptr), rightChild(nullptr) {}
        Node(int d, Node *leftChild, Node *rightChild) : key(d),leftChild(leftChild), rightChild(rightChild) {}
};

class LinkedBST : public BinarySearchTree {
    private:
        Node *root;
    public:
        LinkedBST();
        ~LinkedBST();
        bool isEmpty();
        void addBST(int data);
        void removeBST(int keyToDelete);
        bool searchBST(int targetKey);
};