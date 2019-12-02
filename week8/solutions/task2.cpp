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
int calculateHeight(Node<T>* root) {
    if (!root) {
        return 0;
    }

    return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}

template <typename T>
bool isBalanced(Node<T>* root) { 
 
    if (root == nullptr) {
        return true;
    } 
  
    int leftTreeHeight = calculateHeight(root->left);
    int rightTreeHeight = calculateHeight(root->right);
  
    return (abs(leftTreeHeight - rightTreeHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right));
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

	cout << "is balanced: tree1 -> " << boolalpha << isBalanced(tree1) << endl;
	cout << "is balanced: tree2 -> " << boolalpha << isBalanced(tree2) << endl;

	return 0;
}