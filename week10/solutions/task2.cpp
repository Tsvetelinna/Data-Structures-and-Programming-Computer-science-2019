#include <iostream>
using namespace std;

template <typename T>
struct Node {

  T data;
  Node<T> *left, *right;

  Node (const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr) : data(_data),left(_left),right(_right) {}
};


template <typename T>
T min(Node<T>* root){
    while(root->left != nullptr){
        root = root->left;
    }

    return root->data;

}

template <typename T>
void deleteOrderedTree(Node<T>*& root, T value) { 
   if (root == nullptr) {
        return;
   }

   if (value < root->data) {
        deleteOrderedTree(root->left, value);
   }

    if (value > root->data) {
        deleteOrderedTree(root->right, value);
   }

   if (value == root->data) {

        if (root->left == nullptr && root->right == nullptr) {
            Node<T>* temp = root;
            root = nullptr;
            delete temp;
            return;
        }

        if (root->left == nullptr) {
            Node<T>* temp = root;
            root = root->left;
            delete temp;
            return;
        }


        if (root->right == nullptr) {
            Node<T>* temp = root;
            root = root->right;
            delete temp;
            return;
        }

        T minElem = min(root->right);
        root->data = minElem;

        deleteOrderedTree(root->right, minElem);
   }
} 

int main() {
	
	return 0;
}