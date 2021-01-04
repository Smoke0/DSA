#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
/// insert given node in binary tree.
void insertInBST(node* &root,int x){
    if(!root){
        root = new node(x);
        return;
    }
    else{
        if(root->data >= x)
            insertInBST(root->left,x);
        else
            insertInBST(root->right,x);
    }
}
/// prints node in a given range iterating in inorder fashion
void printKeysInGivenRange(node* root,int k1,int k2){
    if(!root)
        return;
    printKeysInGivenRange(root->left,k1,k2);
    if(root->data <=k2 && root->data >=k1)
        cout << root->data << " ";
    printKeysInGivenRange(root->right,k1,k2);
}
int main(){
    return 0;
}

