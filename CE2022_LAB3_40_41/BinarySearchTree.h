#include<iostream>

class BinarySearchTree{
    public:
        BinarySearchTree(){};
        virtual bool isEmpty()=0;
        virtual void addBST(int value)=0;
        virtual void removeBST(int keyToDelete)=0;
        virtual bool searchBST(int targetKey)=0;
        
};