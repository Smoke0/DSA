#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left,*right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};
/// this fn determines wether tree is height balanced or not and also 
/// return value too.
pair<int,bool> isHeightBalancedOptimised(node *root)
{
    /// base case  if root is null tree is balanced and it's height is zero.
    if(!root){
        return make_pair(0,true);
    }
    /// first thing is height and second one is whether tree is balanced.
    pair<int,bool> p,left,right;
    left = isHeightBalancedOptimised(root->left);
    right = isHeightBalancedOptimised(root->right);
    /// height of tree is gonna be the max of height of left and right plus one.
    p.first = max(left.first,right.first) + 1;
    /// and tree will be balanced if both left and right subtree is balanced
    /// and the absolute difference b/w there height is less than one.
    if(left.second && right.second && (abs(left.first-right.first)<=1) )
        p.second = 1;
    /// else tree is unbalanced
    else
        p.second = 0;
    return p;
}
/// it's a class that implements the tree iterator of inorder traversal

class TreeIterator
{
    stack<Node*> s; bool flag = 0;
public:
    TreeIterator(Node *root){
        s.push(root);
    }

    /** @return the next node in inrder traversal */
    int next(){
        Node *temp = s.top();
        Node* key;
        /// dealing with left part.
        if(!flag){
            while(!flag && temp->left){
                s.push(temp->left);
                temp = temp->left;

            }
            flag = 1;
        }
        key = s.top();
        s.pop();
        if(key->right){
            s.push(key->right);
            flag = 0;
        }
        return key->data;
    }

    /** @return whether we have  next node or not */
    bool hasNext(){
        return !(s.empty());
    }
};
/// create tree using in and post order traversals
node* createTreeUsingInAndPost(int *in, int *post,int left,int right,int &k){
    if(left>right)
        return NULL;
    int key = post[k--];
    node* root =  new node(key);
    /// find the position of root in in order.
    int index;
    for(int i=left;i<=right;i++){
        if(in[i]==key){
            index = i;
            break;
        }
    }
    root->right = createTreeUsingInAndPost(in,post,index+1,right,k);
    root->left = createTreeUsingInAndPost(in,post,left,index-1,k);
    return root;
}
/// pass k = 0
node* createTreeUsingInAndPre(int *in, int *pre,int left,int right,int &k){
    if(left>right)
        return NULL;
    int key = pre[k++];
    node* root =  new node(key);
    /// find the position of root in in order.
    int index;
    for(int i=left;i<=right;i++){
        if(in[i]==key){
            index = i;
            break;
        }
    }
    root->left = createTreeUsingInAndPre(in,pre,left,index-1,k);
    root->right = createTreeUsingInAndPre(in,pre,index+1,right,k);
    return root;
}
void preOrder(node* root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void levelOrder(node* root){
    queue<node*> q; node* temp;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        temp = q.front(); q.pop();
        if(!temp){
            if(!q.empty()){
                q.push(NULL);
                cout << "\n";
            }
        }
        else{
            cout << temp->data <<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
int main() {

    int t,n;
    int in[100],post[100];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> in[i];
        for(int i=0;i<n;i++)
            cin >> post[i];
        int k = n-1;
        node* root = createTreeUsingInAndPost(in,post,0,n-1,k);
        preOrder(root);
        cout << "\n";
    }

	return 0;
}
