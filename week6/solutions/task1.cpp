#include <iostream>
using namespace std;

int COUNT = 5;

template <typename T>
struct Node {

  T data;
  Node<T> *left, *right;

  Node (const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr) : data(_data),left(_left),right(_right) {}
};


template <typename T>
Node<T>* treeFromArray(T* arr, int size) {
	if (size == 0) {
		return nullptr;
	}

	int mid = size / 2;
	Node<T>* node = new Node<T>(arr[mid]);

	node->left = treeFromArray(arr, mid);
	node->right = treeFromArray(arr + mid + 1, size - mid - 1);

	return node;
}

template <typename T>
void printTree(Node<T>* root) {
	if (root == nullptr) {
		return;
	}

	cout << root->data << " ";

	printTree(root->left);
	printTree(root->right);
}


int main () {

	return 0;
}