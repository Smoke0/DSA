#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int x){
        data = x;
        left = right = nullptr;
    }
}Node;

/// recursively insert node in binary tree
Node* insertNode(Node* &root,int x){
    if(!root){
        root = new Node(x);
        return root;
    }
    else{
        if( x < root->data ){
            root->left = insertNode(root->left,x);
        }
        else{
            root->right = insertNode(root->right,x);
        }
        return root;
    }

}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/// gfg verified return min val in BST go left as much you can
int minValue(Node* root){
    if(!root)
        return -1;
    if(root->left == NULL)
        return root->data;
    return minValue(root->left);
}


int main(){
    Node* root = nullptr;
    insertNode(root,2);
    insertNode(root,1);
    insertNode(root,3);
    insertNode(root,4);
    inorder(root);
    return 0;
}
