#include <iostream>
using namespace std;

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
int calculateHeight(Node<T>* root) {
	if (!root) {
		return 0;
	}

	return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}

template <typename T>
void printLevelOrder(Node<T>* root) {  

    int height = calculateHeight(root);  

    for (int i = 1; i <= height; i++) {
        printGivenLevel(root, i);
        cout << endl;  
    } 
}  
  
template <typename T>
void printGivenLevel(Node<T>* root, int level) {  

    if (root == NULL) {
        return;  
    }

    if (level == 1) {
        cout << root->data << " ";  
    }

    else if (level > 1) {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

template <typename T>
T accumulate(T (*op)(T, T), T initValue, const Node<T>* node) {
	if (node != nullptr) {
		return op(op(accumulate(op, initValue, node->left), node->data), accumulate(op, initValue, node->right));
	}

	return initValue;
}

int sum(int x, int y) {
	return x + y;
}

int product(int x, int y) {
	return x * y;
}

int main () {
	int size = 6;

	int arr[size] = {1, 2, 3, 4, 5, 6};

	Node<int>* root = treeFromArray(arr, size);

	printLevelOrder(root);
	
	cout << "sum: " << accumulate(sum, 0, root) << endl;
	cout << "product: " << accumulate(product, 1, root) << endl;

	return 0;
}