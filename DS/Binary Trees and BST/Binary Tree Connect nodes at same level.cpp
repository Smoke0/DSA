/// gfg verified. leet code verified

/// this is a special question in which we connect nodes at same level and print them too.
/// this connecting nodes at same level might have some advantage
#include<iostream>
#include<queue>

using namespace std;
/// nextRight pointer is used for connecting to next node right to current node.
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* nextRight;
}Node;

Node* createNode(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    return temp;
}
/// we basically modified the BFS to do the deed.
/// we have a previous pointer whose nextRight pointer will be used for connecting to current node.
void connectNodeAtSameLevel(Node* root){
    if(!root)
        return;
    Node* temp;
    Node* prev = NULL;
    queue<Node*> q;
    int count = 1;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        /// for very first node of level we keep previous null to indicate that node is first so nothing will connect
        /// to first node.
        if(prev)
            prev->nextRight = temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        prev = temp;
        count--;
        if(!count){
            count = q.size();
            /// after one level we reset prev to null.
            prev = NULL;
        }
    }
}
/// prints the tree whose node are connected level wise.
void printConnectedTree(Node* root){
    Node* temp = root;
    Node* temp2;
    while(temp){
            temp2 = temp;
        while(temp2){
            cout<< temp2->data << " ";
            temp2 = temp2->nextRight;
        }
        cout << "\n";
        temp = temp->left;
    }
}
int main(){
    Node* root = createNode(1);
    Node* a = createNode(2);
    Node* b = createNode(3);
    Node* c = createNode(4);
    Node* d = createNode(5);
    Node* e = createNode(6);
    Node* f = createNode(7);
    Node* g = createNode(8);
    Node* h = createNode(9);
    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;
    c->left = g;
    e->left =  h;
    connectNodeAtSameLevel(root);
    printConnectedTree(root);
    return 0;
}
