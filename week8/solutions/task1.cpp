#include <iostream>
#include <climits>
using namespace std;

template <typename T>
struct Node {

  T data;
  Node<T> *left, *right;

  Node (const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr) : data(_data),left(_left),right(_right) {}
};


template <typename T>
bool isOrdered(Node<T>* root) { 
 
    return isOrderedTreeHelper(root, INT_MIN, INT_MAX);
} 

template <typename T>
bool isOrderedTreeHelper(Node<T>* node, int min, int max) { 
  

    if (node == nullptr) {
    	return true;
    } 

    if (node->data < min || node->data > max) {
    	return false;
    }
  
    return isOrderedTreeHelper(node->left, min, node->data - 1) &&
    		isOrderedTreeHelper(node->right, node->data + 1, max);
} 

int main() {

	Node<int>* tree1 = new Node<int>(1); 
    tree1->left = new Node<int>(2); 
    tree1->right = new Node<int>(3); 
    tree1->left->left = new Node<int>(4); 
    tree1->left->right = new Node<int>(5); 

	Node<int>* tree2 = new Node<int>(4); 
    tree2->left = new Node<int>(-2);  
    tree2->right = new Node<int>(6); 
    tree2->right->left = new Node<int>(5);
    tree2->right->right = new Node<int>(8);
    tree2->right->right->right = new Node<int>(20);

	cout << "is ordered: tree1 -> " << boolalpha << isOrdered(tree1) << endl;
	cout << "is ordered: tree2 -> " << boolalpha << isOrdered(tree2) << endl;

	return 0;
}