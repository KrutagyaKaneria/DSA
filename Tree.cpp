#include <iostream>
using namespace std;
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Recursive function to build tree from preorder traversal
Node* buildTree(int preorder[], int& idx, int length) {
    idx++;
    if (idx >= length || preorder[idx] == -1) {
        return nullptr;
    }
    

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx, length);
    root->right = buildTree(preorder, idx, length);
    return root;
}

// Preorder traversal print
// void postorderTraversal(Node* root) {
//     if (root == nullptr)
//         return;
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
//     cout << root->data << " ";
// };

void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
};

// void intorderTraversal(Node* root) {
//     if (root == nullptr)
//         return;
//     preorderTraversal(root->left);
//     cout << root->data << " ";
//     preorderTraversal(root->right);
// };

void levelorder(Node* root){
    queue<Node*> q;
    
    q.push(root);
    
    int maxValue = root->data;
    
    while(q.size() > 0){
        
        Node* current = q.front();
        q.pop();
        
        
        if (current->data > maxValue) {
            maxValue = current->data;
        }
        
        cout << current->data << " ";
        
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
    cout << maxValue << endl;
    cout << endl;
};

int main() {
    int preorder[] = {1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,-1,6,10,-1,-1,-1};

    int idx = -1;
    int length = sizeof(preorder) / sizeof(preorder[0]);

    Node* root = buildTree(preorder, idx, length);

    cout << "Preorder Traversal: ";
    // preorderTraversal(root);
    levelorder(root);
    return 0;
}