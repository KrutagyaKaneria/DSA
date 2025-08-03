#include <iostream>
using namespace std;
#include <vector>
#include <queue>







class Node{
public:
   int data;
   Node* left;
   Node* right;

   Node(int val){
    data=val;
    left=right=NULL;
   }

};

// BUILD A BINARY TREE 

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left= buildTree(preorder);
    root->right= buildTree(preorder);

    return root;

}

// PREORDER TRAVERSING 

void preOrder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);

}

// INORDER TRAVESING
void InOrder(Node* root){
    if(root == NULL){
        return ;
    }
    
    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);

}

// POSTORDER TRAVESING
void PostOrder(Node* root){
    if(root == NULL){
        return ;
    }
    
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << endl;

}

// LEVELORDER TRAVERSING
void LevelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout << curr->data << "";

        if(curr-> left != NULL){
            q.push(curr->left);
        }
        if(curr-> right != NULL){
            q.push(curr->right);
        }

    }
    cout <<endl;
}

// HEIGHT OF A BINARY TREE

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int lefHt = height(root->left);
    int rightHt = height(root->right);
    return max(lefHt,rightHt) + 1;
}


int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    // preOrder(root);
    // InOrder(root);
    // LevelOrder(root);
    cout << height(root);
    return 0;
}
