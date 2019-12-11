#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template <typename T>
struct Node {

  T data;
  Node<T> *left, *right;

  Node (const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr) : data(_data),left(_left),right(_right) {}
};

int toInteger(string str) {
  	int number = 0;

  	for (int i = 0; i < str.size(); i++) {
    	number = number * 10 + (str[i] - '0');
  	}

  return number;
}

template <typename T>
int calculateFormula(Node<T>* root) {

	if (root->left == nullptr && root->right == nullptr) {
		return toInteger(root->data);
	}

	if (root->data == "+") {
    	return calculateFormula(root->left) + calculateFormula(root->right);
  	}

  	if (root->data == "-") {
    	return calculateFormula(root->left) - calculateFormula(root->right);
  	}

  	if (root->data == "*") {
    	return calculateFormula(root->left) * calculateFormula(root->right);
  	}
}


int main() {

	Node<string>* mathTree = new Node<string>("*");
	mathTree->left = new Node<string>("-");
	mathTree->right = new Node<string>("+");
	mathTree->left->left = new Node<string>("22");
	mathTree->left->right = new Node<string>("2");
	mathTree->right->left = new Node<string>("3");
	mathTree->right->right = new Node<string>("5");

	cout << calculateFormula(mathTree) << endl;
	return 0;
}