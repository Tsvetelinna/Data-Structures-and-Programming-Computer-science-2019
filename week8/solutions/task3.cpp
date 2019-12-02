#include <iostream>
using namespace std;

template <typename T>
struct Node {

  T data;
  Node<T> *left, *right;

  Node (const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr) : data(_data),left(_left),right(_right) {}
};

template <typename T>
bool containsWord(Node<T>* root, string word, int index) {
	if (root == nullptr) {
		return false;
	}

  	return containsWordhelper(root, word, index) || containsWord(root->left, word, index) || containsWord(root->right, word, index);
}

template <typename T>
bool containsWordhelper(Node<T>* root, string word, int index) {

	if (root == nullptr) {
		return (index == word.size());
	}

	if (index == word.size()) {
		return true;
	}

  return root->data == word[index] && (containsWordhelper(root->left, word, index + 1) || containsWordhelper(root->right, word, index + 1));
}

int main() {

	Node<char>* charTree = new Node<char>('c');
	charTree->left = new Node<char>('a');
	charTree->right = new Node<char>('v');
	charTree->left->left = new Node<char>('m');
	charTree->left->right = new Node<char>('t');

	cout << "contains cash: " << containsWord(charTree, "cash", 0) << endl;
	cout << "contains cat: " << containsWord(charTree, "cat", 0) << endl;

	return 0;
}