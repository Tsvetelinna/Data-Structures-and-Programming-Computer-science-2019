#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct TreeNode {    
    T data;
    vector<TreeNode*> children;
};

template <typename T>
TreeNode<T>* newNode(T data) { 
    TreeNode<T>* temp = new TreeNode<T>; 
    temp->data = data; 
    return temp; 
} 

template <typename T>
void insert(TreeNode<T>*& root, T key) { 

	if (root == nullptr) {
		root = newNode(key);
		return;
	}

    queue<TreeNode<T>*> q; 
    q.push(root); 
 
    while (!q.empty()) { 

        TreeNode<T>* curr = q.front(); 
        q.pop(); 
  
        if (curr->children.empty()) { 
            (curr->children).push_back(newNode(key));
            break; 
        } 

        else {
        	for (int i = 0; i < curr->children.size(); i++) {
            	q.push(curr->children[i]); 
        	}
        }
    } 
} 

int main() {

    return 0;
}