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
bool hasElement(Node<T>* root, T element) {  
    if (root == NULL) {
        return false;  
    }

    if (root->data == element) {
    	return true;
    }
   
   return hasElement(root->left, element) || hasElement(root->right, element);
} 


int main () {
	int size = 6;

	int arr[size] = {1, 2, 3, 4, 5, 6};

	Node<int>* root = treeFromArray(arr, size);

	printLevelOrder(root);

	cout << "22: " << boolalpha << hasElement(root, 22) << endl;
	cout << "5: " << boolalpha << hasElement(root, 5) << endl;

	return 0;
}