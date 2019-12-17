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
void mirror(TreeNode<T>*& root) {
    if (root == nullptr) {
        return;
    }

    int n = root->children.size(); 

    if (n < 2) {
        return;
    }

    for (int i = 0; i < n; i++) {
        mirror(root->children[i]);
    }

    reverse(root->children.begin(), root->children.end());
}

int main() {

    return 0;
}