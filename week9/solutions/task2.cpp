#include <iostream>
#include <queue>
#include <algorithm>
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
int sum(TreeNode<T>*& root) {
	if (root == nullptr) {
		return 0;
	}

	int sum = 0;

	queue<TreeNode<T>*> q; 
    q.push(root);

    while (!q.empty()) {

    	int n = q.size();

    	while (n > 0) {
    		TreeNode<T>* curr = q.front(); 
        	q.pop();

        	sum += curr->data;

        	for (int i = 0; i < curr->children.size(); i++) {
        		q.push(curr->children[i]);
        	}
        	n--;
    	}
    }

    return sum;
}

template <typename T>
void print(TreeNode<T>* root) { 
    
    if (root == nullptr) {
        return;
    }
  
    queue<TreeNode<T>*>q; 
    q.push(root); 
 
    while (!q.empty()) { 
        int n = q.size(); 

        while (n > 0) { 

            TreeNode<T>* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            for (int i = 0; i < curr->children.size(); i++) {
                q.push(curr->children[i]);
            }
            n--; 
        } 
  
        cout << endl; 
    } 
} 


int main() {

	return 0;
}