#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Node {

  T data;
  Node<T> *left, *right;

  Node (const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr) : data(_data),left(_left),right(_right) {}
};

template <typename T>
void insertBinaryTree(Node<T>* root, T value) { 
    queue<Node<T>*> q; 
    q.push(root); 
    Node<T>* temp;
 
    while (!q.empty()) { 

        temp = q.front(); 
        q.pop(); 
  
        if (temp->left == nullptr) { 
            temp->left = new Node<T>(value); 
            break; 
        } 

        else {
            q.push(temp->left); 
        }
  
        if (temp->right == nullptr) { 
            temp->right = new Node<T>(value); 
            break; 
        } 

        else {
            q.push(temp->right); 
        }
    } 
} 


int main() {

	return 0;
}