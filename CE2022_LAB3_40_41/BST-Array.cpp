#include "BinarySearchTree.h"
#include <iostream>

#define MAX_SIZE 16

class BSTArray : public BinarySearchTree {
private:
    int BST[MAX_SIZE];
    
    int leftChild(int index) {
        return 2 * index + 1;
    }
    
    int rightChild(int index) {
        return 2 * index + 2;
    }
    
    void initializeTree() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            BST[i] = -1; 
        }
    }
    
public:
    BSTArray() {
        initializeTree();
    }
    
    bool isEmpty() override {
        return BST[0] == -1;
    }
    
    void addBST(int value) override {
        if (isEmpty()) {
            BST[0] = value;
            return;
        }
        
        int index = 0;
        while (index < MAX_SIZE && BST[index] != -1) {
            if (value < BST[index]) {
                index = leftChild(index);
            } else {
                index = rightChild(index);
            }
        }
        
        if (index < MAX_SIZE) {
            BST[index] = value;
        } else {
            std::cerr << "Tree is full. Cannot add value " << value << std::endl;
        }
    }
    
    void removeBST(int keyToDelete) override {
        int index = 0;
        while (index < MAX_SIZE && BST[index] != keyToDelete) {
            if (keyToDelete < BST[index]) {
                index = leftChild(index);
            } else {
                index = rightChild(index);
            }
        }

        // Not Found
        if (index >= MAX_SIZE) {
            std::cout << "Value " << keyToDelete << " not found in the BST." << std::endl;
            return;
        }

        // Found 

        // Case 1: Zero Child
        if (BST[leftChild(index)] == -1 && BST[rightChild(index)] == -1) {
            BST[index] = -1;
        }

        // Case 2: One Child
        if (BST[leftChild(index)] == -1 && BST[rightChild(index)] != -1){
            BST[index] = BST[rightChild(index)];
            BST[rightChild(index)] = -1;
        } 
        if (BST[rightChild(index)] == -1 && BST[leftChild(index)] != -1){
            BST[index] = BST[leftChild(index)];
            BST[leftChild(index)] = -1;
        }

        // Case 3: Two Children
        if (BST[leftChild(index)] != -1 && BST[rightChild(index)] != -1){
            int successorIndex = rightChild(index);
            // finding the inorder successor (leftmost child of the right subtree) or we can find the inorder predecessor (rightmost child of the left subtree)
            while ( BST[leftChild(successorIndex)] != -1 ) {
                if (leftChild(successorIndex)>MAX_SIZE){
                    break;
                }
                successorIndex = leftChild(successorIndex);
            }
            BST[index] = BST[successorIndex];
            BST[successorIndex] = -1;
        }

    }
    
    bool searchBST(int targetKey) override {
        int index = 0;
        while (index < MAX_SIZE && BST[index] != -1) {
            if (BST[index] == targetKey) {
                return true;
            } else if (targetKey < BST[index]) {
                index = leftChild(index);
            } else {
                index = rightChild(index);
            }
        }
        return false;
    }
    
    void printTree() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (BST[i] != -1) {
                std::cout << BST[i] << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    BSTArray bst;
    std::cout << std::endl;
    std::cout << "Initial state of the BST:\n";
    bst.printTree();
    std::cout << "Is the BST empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nAdding values to the BST: 10, 5, 15, 3, 7, 12, 18, 6, 9, 25\n";
    bst.addBST(10);
    bst.addBST(5);
    bst.addBST(15);
    bst.addBST(3);
    bst.addBST(7);
    bst.addBST(12);
    bst.addBST(18);
    bst.addBST(6);
    bst.addBST(9);
    bst.addBST(25);
    
    std::cout << "State of the BST after additions:\n";
    bst.printTree();
    
    std::cout << "\nSearching for values are in the BST:\n";
    int searchValues[] = {7, 20, 10, 23};
    for (int value : searchValues) {
        std::cout << value << " is in the BST: " << (bst.searchBST(value) ? "true" : "false") << std::endl;
    }
    
    std::cout << "\nRemoving value 3 having 0 Child.\n";
    bst.removeBST(3);
    std::cout << "State of the BST after removal:\n";
    bst.printTree();
    
    std::cout << "\nRemoving value 18 having 1 Child.\n";
    bst.removeBST(18);
    std::cout << "State of the BST after removal:\n";
    bst.printTree();

    std::cout << "\nRemoving value 7 having 2 Child.\n";
    bst.removeBST(7);
    std::cout << "State of the BST after removal:\n";
    bst.printTree();
    
    return 0;
}