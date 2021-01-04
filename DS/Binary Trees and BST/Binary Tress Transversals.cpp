#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
    struct treenode* parent;
}TreeNode;

TreeNode* newTreeNode(int item, TreeNode* parent)
{
    TreeNode* temp = new TreeNode;
    temp->data = item;
    temp->left = temp->right = NULL;
    temp->parent = parent;
    return temp;
}

Node* newNode(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/// gfg verified
/// This function is verified works perfectly this is simplest form of DFS transversal.
vector<int> preOrder(Node* root,bool print){
    /// Create an temp node pointer and push root to stack.
    Node* temp;
    vector<int> traversal;
    stack<Node*> s;
    if(!root)
        return traversal;

    s.push(root);

    while( !s.empty() ){
        temp = s.top();
        s.pop();
        /// if left and right elements are present push them into stack.
        /// first right is pushed then left because this makes left subtree process first
        if(temp->right != NULL)
            s.push(temp->right);
        if(temp->left != NULL)
            s.push(temp->left);
        if(print)
            cout<<temp->data <<" ";
        traversal.push_back(temp->data);
    }
    if(print)
        cout<<"\n";

    return traversal;
}
/// gfg verified
/// This function is verified works perfectly.
vector<int> Inorder(Node* root,bool print){

    /// we pushes root into stack.
    Node* temp;
    vector<int> traversal;
    if(!root)
        return traversal;
    bool flag = 1;
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        temp = s.top();
        /// we get to most left leaf of current node.
        /// flag = 0 indicates that the left subtree of current node has been checked.
        if(flag){
            while(temp->left != NULL){
            s.push(temp->left);
            temp = temp->left;
            }
            flag = 0;
        }
        s.pop();
        if(print)
            cout << temp->data << " ";
        traversal.push_back(temp->data);
        /// left subtree has been checked check it's right subtree
        if(temp->right != NULL){
            s.push(temp->right);
            /// if a new node is added then it's left must be checked so flag set to one.
            flag = 1;
        }
    }
    if(print)
        cout << "\n";
}
/// gfg verified
/// this is trickiest of traversals the problem here is that we would visit the root node twice once after traversing left
/// other after traversing right subtree we need to print root after traversing right tree so we use an extra pointer
/// previous to store previously traversed node if previously traversed node was right child of current node then
/// we are sure that we can print and pop root.
vector<int> Postorder(Node* root,bool print){
    /// standard pushing of root.
    Node* temp;
    Node* prev;
    bool flag = 1;
    stack<Node*> s;
    vector<int> traversal;
    if(!root)
        return traversal;

    s.push(root);
    while(!s.empty()){
        temp = s.top();
        /// we get to most left leaf of current node.
        /// flag = 0 indicates that the left subtree of current node has been checked.
        if(flag){
            while(temp->left != NULL){
            s.push(temp->left);
            temp = temp->left;
            }
            flag = 0;
        }
        /// we pop an element either if it's right child is null or right child was previously processed node.
        if(temp->right == NULL || temp->right == prev){
                s.pop();
                prev = temp;
                if(print)
                    cout << temp->data << " ";
                traversal.push_back(temp->data);
        }
        else{
            s.push(temp->right);
            flag = 1;
        }
    }
    if(print)
        cout << "\n";
}
/// gfg verified.
/// this is queue implementation of BFS.
void LevelOrder(Node* root){
    /// just push root node into queue.
    Node* temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        /// if left and right child are present then push them
        /// in BFS we process left child first then right child.
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
        cout<<temp->data <<" ";
    }
    cout<<"\n";

}

void LevelOrderLineByLine(Node* root){
    /// just push root node into queue.
    Node* temp;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp != NULL){
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            cout<<temp->data <<" ";
        }
        else if(!q.empty()){
            cout << "\n";
            q.push(NULL);
        }

    }
    cout<<"\n";
}
/// gfg verified google vertical traversal we are basically doing level order traversal
/// while traversing we add node to it's corresponding level.
void printVerticalTraversal(Node *root){
    if(root==NULL)
        return;
    /// queue for traversing level order wise. we need to keep track of level as well that's why we are using a pair
    queue<pair<Node*,int>> q;
    /// map will have a vector mapped to corresponding level.
    map<int,vector<int>> m;
    Node * temp; int current_level; pair <Node*,int> tp;
    q.push(make_pair(root,0));
    while(!q.empty()){
        tp = q.front(); q.pop();
        temp = tp.first; current_level = tp.second;
        m[current_level].push_back(temp->data);
        if(temp->left)
            q.push(make_pair(temp->left,current_level-1));
        if(temp->right)
            q.push(make_pair(temp->right,current_level+1));
    }
    /// now print the map.
    map<int,vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout << it->second[i] << " ";
        }
        cout << "\n";
    }
}
/// gfg verified leet code verified.
/// this function finds the height of tree here we consider root as being height equal to one.
/// this function finds height by traversing the tree BFS wise as soon as new level is encountered we add one to height
int findHeight(Node* root){
    /// handling corner case.
    if(!root){
        return 0;
    }
    /// level is height of tree count is count of nodes at current level
    /// flag determines whether we have accounted for height of current level or not
    /// flag = 0 means we have not considered height of current node flag = 1 means we have.
    int level = 1,count = 1, flag = 0;
    /// just push root node into queue.
    Node* temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        /// we add one to height if level hasn't been encountered and one of left or right child isn't null.
        if( (temp->left != NULL || temp->right != NULL) && flag == 0 ){
            level++;
            flag = 1;
        }
        /// two if statements below are part of traversal.
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
        /// we decrease count by one as one node of current level has been processed
        count--;
        /// if count is zero that means all nodes of current level has been processed
        /// and we assign count to no of nodes present in queue.
        if(!count){
            count = q.size();
            flag = 0;
        }
    }
    return level;
}
/// gfg leet code verified.
int findHeight_rec(Node *root){
    if(!root)
        return 0;
    return max(findHeight_rec(root->left),findHeight_rec(root->right)) + 1;
}
/// this function return vector of deepest nodes of tree it simply considers all nodes of a level
/// as deepest nodes as long as none has children if any node has children all nodes at that level are rejected
vector<int> findDeepestNodes(Node* root){
    /// handling corner case.
    if(!root){
        cout<<"Tree is Empty\n";
    }
    /// flag here determines whether any node on current level has children or not.
    /// flag = 0 means no node at this level has children yet flag = 1 means nodes have children
    int count = 1, flag = 0;
    vector<int> deepestNodes;
    /// just push root node into queue.
    Node* temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        /// this condition makes flag one if any node has children at this level
        /// the flag will remain zero across whole level as long as none node has children which means
        /// all node at this level are deepest nodes
        if( (temp->left != NULL || temp->right != NULL) && flag == 0 )
            flag = 1;
        /// if flag is zero then this element might be deepest.
        if(!flag)
            deepestNodes.push_back(temp->data);
        /// we clear the vector because flag is one.
        if(deepestNodes.size()!= 0 && flag == 1)
            deepestNodes.clear();

        /// two if statements below are part of traversal.
        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }

        /// we decrease count by one as one node of current level has been processed
        count--;
        /// if count is zero that means all nodes of current level has been processed
        /// and we assign count to no of nodes present in queue.
        if(!count){
            count = q.size();
            flag = 0;
        }
    }
    return deepestNodes;
}
/// counts no of leaves in binary tree
/// super simple while traversing tree just count no of leaves.
int No_of_leaves(Node* root){
    int count = 0;
    Node* temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(!(temp->left || temp->right))
            count++;
        /// if left and right child are present then push them
        /// in BFS we process left child first then right child.
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return count;
}
int diameter_util(Node* root, int* max_ptr){
    /// left stores length of longest path from root to it's left sub tree leaves and similiarly right stores
    /// longest path from right side.
    /// one is added to left and right to accont for root node.
    int left, right;
    if(root){
        left = diameter_util(root->left,max_ptr);
        right = diameter_util(root->right,max_ptr);
        if(*max_ptr < left+right+1)
            *max_ptr = left + right + 1;
        /// the sub tree returns the longest path to it's ansestor node one is added to account for node itself.
        return left>right ? left+1 : right+1;
    }
    else
        return 0;
}
/// return the diameter of tree google diameter if binary tree if you don't know it's not width of tree.
/// we are using recursion here
/// we are basically calculating diameter of every sub tree and updating max accordingly.
/// this method runs at O(n) verified by geeksforgeeks.
int diameter_of_tree(Node* root){
    int max = 0;
    diameter_util(root,&max);
    return max;
}

/// this prints zig zag traversal using BFS traversal and using one stack.
/// in zig zag traversal we are following BFS traversal alternatively in regular and reverse order
/// so for regular we don't use stack and for regular we use stack to reverse the order of nodes.
/// but traversal is made using queue only just like regular BFS.
/// this approach processes node twice once for level order and once for putting in stack.
void levelOrder_zigzagTraversal(Node* root){
    bool flag = 0;
    int count = 1;
    Node* temp;
    queue<Node*> q;
    stack<int> s;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        /// if left and right child are present then push them
        /// in BFS we process left child first then right child.
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
        count--;
        if(flag){
            s.push(temp->data);
        }
        else{
            cout << temp->data << " ";
        }
        if(!count){
            count = q.size();
            flag = !flag;
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
        }
    }
    cout<<"\n";
}
/// In this approach we use two stacks not any queue this way we can perform level order traversal
/// by processing node only once.
void levelOrder_zigzagTraversal_optimized(Node* root){
    stack<Node*> s1,s2; bool flag = false; Node* temp;
    s1.push(root);
    while( !s1.empty() || !s2.empty()){
        /// if flag == true we must be processing s2
        if(flag){
            while(!s2.empty()){
                temp = s2.top(); s2.pop();
                cout << temp->data << " ";
                if(temp->right)
                    s1.push(temp->right);
                if(temp->left)
                    s1.push(temp->left);
            }
            cout << "\n";
            flag = !flag;
        }
    /// if flag == false we must be processing s2
        else{
            while(!s1.empty()){
                temp = s1.top(); s1.pop();
                cout << temp->data << " ";
                if(temp->left)
                    s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);
            }
            cout << "\n";
            flag = !flag;
        }
    }
}
void verticleSumutil(Node* root,int column,map<int,int> &sums){
    if(!root)
        return;
    /// we add nodes value to a corresponding column no or distance value.
    sums[column] +=root->data;
    verticleSumutil(root->left,column-1,sums);
    verticleSumutil(root->right,column+1,sums);
}
/// gfg verified.
/// vertical sum of binary tree is sum of nodes falling on same verticle line a verticle line is constructed
/// using distance from root of tree or sub tree for right child one is added and for left one is subtracted from root
/// distance value. the root of tree has zero distance value and accordingly right and left sub tree values are calculated.
/// now the real problem here is finding sum of nodes with same distance value so we use hash map for mapping a node to
/// a distance value.
void verticleSum(Node* root){
    map<int, int> sums;
    map<int,int> :: iterator i;

    verticleSumutil(root,0,sums);

    for(i = sums.begin(); i!=sums.end();++i){
        cout << i->first << ": " << i->second << "\n";
    }
}
/// this is clumsy approach for generating post order array from given pre and in order traversal
/// the clumsy part is we are trying to put root to it's proper position on before recursion
/// I guess this clumsiness can ber converted to iterative approach.
void PostFromInAndPreOrder_Util(int In[], int Pre[], int* Post,int start_in, int end_in,int start_post,int end_post){
    if(start_post>end_post)
        return;
    static int preIndex = 0;
    int InOrderIndex,root,size_left,size_right;
    root = Pre[preIndex++];
    *(Post+end_post) = root;

    if(start_post==end_post)
        return;
   for(int i=start_in;i<=end_in;i++){
        if(In[i]==root){
        InOrderIndex = i;
        break;
        }
    }
    size_left = InOrderIndex - start_in;
    size_right = end_in - InOrderIndex;

    PostFromInAndPreOrder_Util(In,Pre,Post,start_in,InOrderIndex-1,start_post,size_left+start_post-1);
    PostFromInAndPreOrder_Util(In,Pre,Post,InOrderIndex+1,end_in,size_left+start_post,size_right+size_left+start_post-1);

}
int* PostFromInAndPreOrder(int In[], int Pre[] ,int start, int end){
    int* Post;
    Post = (int*)malloc((end-start+1)*sizeof(int));
    PostFromInAndPreOrder_Util(In,Pre,Post,start,end,start,end);
    return Post;
}
/// this is also and approach to generate post order we are simply visiting nodes in a post order manner and
/// putting them to post order array.
void PostGenerte_Util(int In[], int Pre[],int* Post ,int start, int end){
    /// to avoid infinite loop.
    if(start>end)
        return;
    /// preIndex is the index of element we are processing right now
    /// postIndex stores index where we supposed to input the element in post order traversal
    static int preIndex=0,postIndex=0;
    int inOrderIndex,root;
    root = Pre[preIndex++];
    /// base case.
    if(start==end){
        *(Post+postIndex++) = root;
        return;
    }
    /// this loop searches the position of root element in inorder array.
    for(int i=start;i<=end;i++){
        if(In[i]==root){
        inOrderIndex = i;
        break;
        }
    }
    PostGenerte_Util(In,Pre,Post,start,inOrderIndex-1);
    PostGenerte_Util(In,Pre,Post,inOrderIndex+1,end);
    *(Post+postIndex++) = root;
}
int* PostGenerte(int In[], int Pre[] ,int start, int end){
    int* Post;
    Post = (int*)malloc((end-start+1)*sizeof(int));
    PostGenerte_Util(In,Pre,Post,start,end);
    return Post;
}
/// this function replaces the value of node with sum of it's succesor and predecesor in inorder traversal
/// we basically modified our iterative inorder traversal
/// after popping the node we perform our stuff the basic idea here is that when we are at succesor of previous
/// node then we update value of previous node and as far as predecessor of previous node is concerned we store the
/// value of predecesor in a variable the case of first node which has no predecesor and case of last node which has
/// no succesor is handled seprately.
/// none of the inorder code is commented. this is verified on coding blocks
void replaceNodeAsSumOfInorderPredecesorAndSuccessor(Node* root){
    Node* temp;
    /// points to previous node and used for modifying value of previous node.
    Node* prev_node = NULL;
    /// t is a variable to temp hold the data of previous node
    /// prev predecesor is initialized to zero as very first node has no predecesor.
    int t,prev_predecesor=0;

    bool flag = 1;
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        temp = s.top();
        if(flag){
            while(temp->left != NULL){
            s.push(temp->left);
            temp = temp->left;
            }
            flag = 0;
        }
        s.pop();
        /// this if skips the very first node.
        if(prev_node){
            t = prev_node->data;
            prev_node->data = prev_predecesor + temp->data;
            prev_predecesor = t;
        }
        prev_node = temp;
        if(temp->right != NULL){
            s.push(temp->right);
            flag = 1;
        }
        /// this if processes the last node which has no successor.
        if(s.empty())
            prev_node->data = prev_predecesor;
    }

}
/// gfg verified
Node* binaryTreeToDLL(Node *root){
    Node* temp,*head;
    /// points to previous node whose left will be made null and right
    /// will point to successor of it.
    Node* prev_node = NULL;

    bool flag = 1;
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        temp = s.top();
        if(flag){
            while(temp->left != NULL){
            s.push(temp->left);
            temp = temp->left;
            }
            flag = 0;
        }
        s.pop();
        /// this if skips the very first node.
        if(prev_node){
            prev_node->right = temp; /// make previous node right point to temp.
            temp->left = prev_node;
        }
        /// else we have found the head
        else
            head = temp;

        prev_node = temp;
        if(temp->right != NULL){
            s.push(temp->right);
            flag = 1;
        }
        /// empty stack implies last node
        /// thus we make it's left and right pointer null.
        if(s.empty()){
            prev_node->right =  NULL;
        }

    }
    return head;
}
/// given a perfect binary tree it prints specific level order of tree
/// which is we print nodes level wise but we print most left and right first and then we move one node inwards.
/// this is based on idea in which we treat left and right sub tree seprately we perform standard level order
/// on left one and reverse on right one we print a  node of left and them one node of right.
/// this funcion only works for perfect binary tree.
void perfectBinaryTreeSpecificLevelOrderTraversal(Node* root){
    if(!root)
        return;
    cout << root->data << " ";
    if(!root->left)
        return;

    Node* temp;
    Node* temp_2;
    queue<Node*> left_q,right_q;
    left_q.push(root->left);
    right_q.push(root->right);

    while(!left_q.empty()){
        temp = left_q.front();
        left_q.pop();

        temp_2 = right_q.front();
        right_q.pop();

        if(temp->left){
            left_q.push(temp->left);
            left_q.push(temp->right);

            right_q.push(temp_2->right);
            right_q.push(temp_2->left);
        }
        cout << temp->data << " ";
        cout << temp_2->data << " ";
    }
    cout << "\n";
}
/// this is nothing new we are just reversing alternate level of binary tree
/// we are basically swapping most left with most right and so on.
void reverseAlternatingLevelOfPerfectBinaryTree(Node* root){
    if(!root)
        return;
    /// leave root as is it.
    if(!root->left)
        return;

    Node* temp; Node* temp_2;
    queue<Node*> left_q,right_q;
    bool flag = 1; int t, count = 1;

    left_q.push(root->left);
    right_q.push(root->right);

    while(!left_q.empty()){
        temp = left_q.front();
        left_q.pop();

        temp_2 = right_q.front();
        right_q.pop();

        if(flag){
            t = temp->data;
            temp->data = temp_2->data;
            temp_2->data = t;
        }

        if(temp->left){
            left_q.push(temp->left);
            left_q.push(temp->right);

            right_q.push(temp_2->right);
            right_q.push(temp_2->left);
        }
        /// we decrease count by one as one node of current level has been processed
        count--;
        /// if count is zero that means all nodes of current level has been processed
        /// and we assign count to no of nodes present in queue.
        if(!count){
            count = left_q.size();
            flag = !flag;
        }
    }
}
/// sadly wrong function but nice try.
void BoundryTraversal(Node* root){
    Node* temp;
    Node* special = root;
    bool flag = 1, once = 1;
    stack<Node*> s;
    stack<int> s2;
    s.push(root);
    cout << root->data << " ";
    while(!s.empty()){
        temp = s.top();
        /// we get to most left leaf of current node.
        /// flag = 0 indicates that the left subtree of current node has been checked.
        if(flag){
            while(temp->left != NULL){
            if(once && temp->data != root->data)
                cout << temp->data << " ";
            s.push(temp->left);
            temp = temp->left;
            }
            once = 0;
            flag = 0;
        }
        s.pop();
        if(!(temp->left || temp->right))
            cout << temp->data << " ";
        if(special->right == temp && (temp->left || temp->right)){
            s2.push(temp->data);
            special = temp;
        }

        /// left subtree has been checked check it's right subtree
        if(temp->right != NULL){
            s.push(temp->right);
            /// if a new node is added then it's left must be checked so flag set to one.
            flag = 1;
        }
    }
    while(!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << "\n";
}
/// we are given a preorder sequence of a tree where n is an internal node and l is lead and we are supposed
/// to find height of tree given that the tree is a full binary tree.
int findHeightfromPreOrder(char arr[]){
    static int index = 0;
    int left,right;
   if(arr[index] == 'n'){
        index++;
        left = findHeightfromPreOrder(arr);
        index++;
        right = findHeightfromPreOrder(arr);
        return left>right?left+1:right+1;
    }
    if(arr[index] ==  'l'){
        return 0;
    }
}
/// It's a recursive approach to check children sum property.
bool childrenSumProperty(Node* root){
    /// base case.
    /// if it's a leaf return true or NULL node.
    if(root==NULL || (root->left == NULL && root->right==NULL)){
        ///cout << "1st if condition\n";
        return true;
    }
    /// If it's a node having only right child.
    else if(root->left == NULL && root->right!=NULL){
        ///cout << "2nd if condition\n";
        if(root->data == root->right->data)
            return true;
        else
            return false;

    }
    /// If it's a node having only left child.
    else if(root->left != NULL && root->right==NULL){
       /// cout << "3rd if condition\n";
        if(root->data == root->left->data)
            return true;
        else
            return false;

    }
    /// recursive case.
    else if((root->data == root->left->data + root->right->data) && childrenSumProperty(root->left) && childrenSumProperty(root->right)){
       /// cout << "4th if condition\n";
        return true;
    }
    else{
       /// cout << "else condition\n";
        return false;
    }

}
/// finds sum of nodes at left boundry left boundry includes root node too.
int sumOfLeftBoundry(Node* root){
    static int sum = 0;
    /// base case if root is null sum is zero.
    if (root==NULL)
        return 0;
    sum+=root->data;
    /// first we keep going to left
    if(root->left)
        sumOfLeftBoundry(root->left);
    /// there is no left we now must traverse right
    else if(root->right)
        sumOfLeftBoundry(root->right);
    /// there is no left neither right it must be a leaf so return sum.
    return sum;
}
/// finds sum of nodes at right boundry right boundry includes root node too.
int sumOfRightBoundry(Node* root){
    static int sum = 0;
    /// base case if root is null sum is zero.
    if (root==NULL)
        return 0;
    sum+=root->data;
    /// first we keep going to right
    if(root->right)
        sumOfRightBoundry(root->right);
    /// there is no left we now must traverse right
    else if(root->left)
        sumOfRightBoundry(root->left);
    /// there is no left neither right it must be a leaf so return sum.
    return sum;
}
/// gfg verified this function asumes all nodes have distinct values.
/// basic idea is simple during level order traversal we find the nodes with value a and b.
bool areCousions(Node *root, int a, int b){
    /// corner cases.
    if(root==NULL)
        return false;
    if(root->data == a || root->data ==b)
        return false;

    int level = 1, count=1; bool flag = 0;
    Node *temp;
    int parent_a = -1,parent_b =-1,height_a,height_b;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if (flag ==0 && (temp->left !=NULL || temp->right !=NULL)){
            flag = 1;
            level++;
        }
        if(temp->left){
            /// this if finds node a in left of current node.
            if(temp->left->data == a){
                parent_a = temp->data;
                height_a = level;
            }
            /// this if finds node b in left of current node.
            if(temp->left->data == b){
                parent_b = temp->data;
                height_b = level;
            }
            q.push(temp->left);
        }
        if(temp->right){
            /// this if finds node a in right of current node.
            if(temp->right->data == a){
                parent_a = temp->data;
                height_a = level;
            }
            /// this if finds node b in right of current node.
            if(temp->right->data == b){
                height_b = level;
                parent_b = temp->data;
            }
            q.push(temp->right);
        }
        /// we have found parents of both so break the loop
        if(parent_a!=-1 && parent_b!=-1)
            break;
        count--;
        if(!count){
            count = q.size();
            flag = 0;
        }
    }
    /// if parent are same or height are diifrent then return false else true.
    if(parent_a == parent_b || height_a!=height_b)
        return false;
    return true;
}
/// gfg verfied the idea is that during level order traversal we determine the type of level using first node.
/// either all nodes are leaf or none are if any of node breaks the type of level we return false.
bool allLeafAtSameLevel(Node *root){
    /// corner cases.
    if(root==NULL)
        return true;

    int level = 1, count=1; bool flag = 0,type;
    Node *temp;
    queue<Node*> q;
    q.push(root);

    temp = q.front();
    /// type 0 means it's a leafy level
    if(temp->left == NULL && temp->right==NULL)
        type = 0;
    /// type 1 means non-leafy level.
    else
        type = 1;

    while(!q.empty()){
        temp = q.front();
        /// type 1 means it's non leafy level but current node is a leaf so we return false.
        if(type ==1 && temp->left==NULL && temp->right==NULL){
            return false;
        }
        /// type 0 means all nodes are leaf but current node has a child so we return false.
        else if(type==0 && (temp->left!=NULL || temp->right!=NULL)){
            return false;
        }
        q.pop();
        if (flag ==0 && (temp->left !=NULL || temp->right !=NULL)){
            flag = 1;
            level++;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        count--;
        if(!count){
            count = q.size();
            flag = 0;
            if(count){
            temp = q.front();
            /// type 0 means it's a leafy level
            if(temp->left == NULL && temp->right==NULL)
                type = 0;
            /// type 1 means non-leafy level.
            else
                type = 1;
            }

        }
    }
    /// none of condition are broken so we return false.
    return true;
}
/// finds the sum of all nodes of a tree. gfg verified.
int TreeSum(Node *root){
    /// base cases.
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    /// recursive cases.
    return root->data + TreeSum(root->left) + TreeSum(root->right);
}
/// gfg verified determines whether a tree is sum tree or not check gfg for finding out what is sum tree.
bool isSumTree(Node* root){
    /// base cases.
    if(root==NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    /// recursive cases.
    if(isSumTree(root->left) && isSumTree(root->right) && (root->data == TreeSum(root->left) + TreeSum(root->right)))
        return true;
    else
        return false;
}
/// gfg has no test question but I am pretty sure it's right one.
bool isPerfectBiaryTree(Node *root){
     /// corner cases.
    if(root==NULL)
        return true;

    int level = 1, count=1; bool flag = 0,type;
    Node *temp;
    queue<Node*> q;
    q.push(root);

    temp = q.front();
    /// type 0 means it's a leafy level
    if(temp->left == NULL && temp->right==NULL)
        type = 0;
    /// type 1 means non-leafy level.
    else if(temp->left != NULL && temp->right!=NULL)
        type = 1;
    else
        return false;

    while(!q.empty()){
        temp = q.front();
        /// type 1 means it's non leafy level but current node is a leaf so we return false.
        if(type ==1 && (temp->left==NULL || temp->right==NULL)){
            return false;
        }
        /// type 0 means all nodes are leaf but current node has a child so we return false.
        else if(type==0 && (temp->left!=NULL || temp->right!=NULL)){
            return false;
        }
        q.pop();
        if (flag ==0 && (temp->left !=NULL || temp->right !=NULL)){
            flag = 1;
            level++;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        count--;
        if(!count){
            count = q.size();
            flag = 0;
            if(count){
            temp = q.front();
            /// type 0 means it's a leafy level
            if(temp->left == NULL && temp->right==NULL)
                type = 0;
            /// type 1 means non-leafy level.
            else if(temp->left != NULL && temp->right!=NULL)
                type = 1;
            else
                return false;
            }
        }
    }
    /// none of condition are broken so we return false.
    return true;
}
/// gfg verified checks whether a binary tree is full or not It's really simple just chec whether any node has
/// one children or not if does return false else return true.
bool isFullBinaryTree(Node *root){
      /// corner cases.
    if(root==NULL)
        return true;

    int level = 1, count=1; bool flag = 0;
    Node *temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if((temp->left == NULL && temp->right!=NULL) || (temp->left != NULL && temp->right==NULL))
            return false;
        if (flag ==0 && (temp->left !=NULL || temp->right !=NULL)){
            flag = 1;
            level++;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        count--;
        if(!count){
            count = q.size();
            flag = 0;
        }
    }
    /// none of condition are broken so we return false.
    return true;
}
/// recursive version of FullBinary Tree function.
bool isFullBinaryTreeRecursive (Node* root)
{
      /// corner cases.
    if(root==NULL)
        return true;
    /// return true for leaf.
    if(root->left==NULL && root->right==NULL)
        return true;
    /// return false for node having one child.
    if((root->left == NULL && root->right!=NULL) || (root->left != NULL && root->right==NULL))
            return false;
    /// recursive case.
    return isFullBinaryTreeRecursive(root->left) && isFullBinaryTreeRecursive(root->right);
}
/// though this code is LeetCode verified and similar to gfg solution.
/// a complete binary tree is a wierd tree type in which we have to check for 2 condition
/// i) all level except last level must be completely filled last level may be complete or may not
/// ii) all nodes are left as possible.
bool isCompleteBinaryTree(Node *root){
    if(root==NULL)
        return true;

    int level = 1, count=1; bool flag = 0,full_node = 1;
    Node *temp;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        /// we have encountered a non-full node now all following nodes must be leaf according to definition
        /// after a non full nodes all following nodes must be leaf.
        if(!full_node && (temp->left!=NULL || temp->right!=NULL))
            return false;
        /// we have seen a non full node so all following nodes must be leaf
        if( !(temp->left!=NULL && temp->right!=NULL))
            full_node = false;
        /// this condition takes care of the fact that tree has to be left as possible which makes sense to me.
        if(temp->left==NULL && temp->right!=NULL)
            return false;
        if (flag ==0 && (temp->left !=NULL || temp->right !=NULL)){
            flag = 1;
            level++;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        count--;
        if(!count){
            count = q.size();
            flag = 0;
        }
    }
    /// none of condition are broken so we return false.
    return true;
}
/// gfg verified determines whether two trees are identical or not.
/// basic idea is to traverse both trees in preorder manner in which we also push null into stack
/// by pushing null into stack the pre order traversal become unique for tree. if pre order is same
/// trees must be identical.
/// same uniqeness goes for postorder but not for inorder
bool areTreeIdentical(Node *t1,Node *t2){
    stack<Node*> s1;
    stack<Node*> s2;
    Node *temp1;
    Node *temp2;
    s1.push(t1);
    s2.push(t2);
    while( !s1.empty() && !s2.empty()){
        temp1 = s1.top(); temp2 = s2.top(); s1.pop(); s2.pop();
        /// both are null hence they are eual.
        if(temp1 == NULL && temp2 == NULL)
            continue;
        /// nodes are uneuqal
        if( (temp1==NULL && temp2!=NULL) || (temp1!=NULL && temp2==NULL) )
            return false;
        /// none of node are NULL
        if(temp1->data!=temp2->data)
            return false;

        s1.push(temp1->right);
        s2.push(temp2->right);

        s1.push(temp1->left);
        s2.push(temp2->left);
    }
    if(s1.empty() && s2.empty())
        return true;
    else
        return false;
}
/// gfg verified
bool isSubTree(Node *s, Node *t){
    /// first we find the root of subtree in t by traversing in pre order fashion.
    stack<Node*> stk;
    Node *temp;
    stk.push(t);
    while(!stk.empty()){
    temp = stk.top(); stk.pop();
    /// if data of node is identical to root of s then we call function to determine whether they are
    /// identical or not.
        if(temp->data==s->data){
        if(areTreeIdentical(s,temp))
            return true;
        }
        if(temp->right)
            stk.push(temp->right);
        if(temp->left)
            stk.push(temp->left);
    }
    return false;
}
/// Similiar to finding middle of linked list fast pointer moves to left while slow one performes level order
/// traversal.
void printMiddleLevelOfPerfectTree(Node *root){
    Node *fast = root; int count = 1;
    Node *slow;
    queue<Node*> q;
    q.push(root);
    while(1){
        /// breaking condition
        if(fast->left==NULL)
            break;
        if(fast->left->left==NULL)
            fast = fast->left;
        else
            fast = fast->left->left;
        /// now level order traversal is performed by slow pointer.
        while(count){
        slow = q.front(); q.pop();
        q.push(slow->left); q.push(slow->right);
        count--;
        }
        if(!count){
            count = q.size();
        }

    }
    /// now we print the middle level.
    while(!q.empty()){
        cout << q.front()->data << " ";
        q.pop();
    }
}
/// I have tested on my own but no test for this exists.
void printCousionsOfNode(Node *root,int x){
    Node *temp; int count=1,i; bool flag = 0;
    queue<Node*> q;
    q.push(root);

    if( root->data == x ||(root->left!=NULL && root->left->data == x) || (root->right!=NULL && root->right->data == x) ){
        cout << "No cousions are possible\n";
        return;
    }
    while(!q.empty()){
        /// our job is done break the loop.
        if(flag)
            break;
        /// perform level order traversal
        temp = q.front(); q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        count--;
        if(!count){
            count = q.size();
            i = count;
        while(i--){
            temp = q.front(); q.pop();
            if( (temp->left!=NULL && temp->left->data == x) || (temp->right!=NULL && temp->right->data == x) ){
            /// we have found the node's parent now print the cousions.
                while(!q.empty()){
                    temp = q.front(); q.pop();
                    if(temp->left)
                        cout << temp->left->data << " ";
                    if(temp->right)
                        cout << temp->right->data << " ";
                }
                flag = 1;
                break;
            }
            else
                q.push(temp);
            }
        }
    }

}

void printAllRootToLeafPaths_util(Node *root,vector<int> &v){
    /// if we visit a node we insert it.
    if(root==NULL)
        return;
    v.push_back(root->data);
    /// if it's a leaf print it.
    if(root->left==NULL && root->right==NULL){
        for(int i=0;i<v.size();i++)
            cout << v[i] << " ";
        cout << "\n";
        v.pop_back();
        return;
    }
    printAllRootToLeafPaths_util(root->left,v);
    printAllRootToLeafPaths_util(root->right,v);
    v.pop_back();

}
/// prints all root to leaf paths. gfg verified.
void printAllRootToLeafPaths_recurisve(Node *root){
    vector<int> v;
    printAllRootToLeafPaths_util(root,v);
}
/// incomplete. iterative.
void printAllRootToLeafPaths(Node *root){
    Node *temp;
    stack<Node*> s;
    vector<int> v;
    s.push(root);
    while(!s.empty()){
        temp = s.top(); s.pop();
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left)
            s.push(temp->left);
    }
}
/// gfg verfied nothing but level order traversal.
void printNodesAtOddLevels(Node *root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    Node *temp; bool flag = true; int count =1;
    while(!q.empty()){
        temp = q.front();q.pop();
        if(flag)
            cout <<temp->data << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        count--;
        if(!count){
            flag = !flag;
            count = q.size();
        }
    }

}
/// gfg verified.
void printNodesAtKDistance_rec(Node *root,int k){
    if(root==NULL)
        return;
    if(k==0){
        cout << root->data <<" ";
        return;
    }
    printNodesAtKDistance_rec(root->left,k-1);
    printNodesAtKDistance_rec(root->right,k-1);
}
/// iterative approach gfg verified.
void printNodesAtKDistance(Node *root,int k){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    Node *temp; int count =1;
    while(!q.empty()){
        if(k<0)
            break;
        temp = q.front();q.pop();
        if(k==0)
            cout <<temp->data << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        count--;
        if(!count){
            k--;
            count = q.size();
        }
    }
}
/// finds the target node and fills child-->parent hash map
/// and returns {pointer to target node,distance of target from root}.
pair<Node*,int> findTargetNode(Node *root,int target,unordered_map<Node*,Node*> &Map,int dis,Node* pre = NULL){
    if(!root)
        return {NULL,-1};
    /// filling the map.
    Map[root] = pre;
    if(root->data == target){
        return {root,dis};
    }
    else{
        dis++;
        pair<Node*,int> left = findTargetNode(root->left,target,Map,dis,root);
        pair<Node*,int> right = findTargetNode(root->right,target,Map,dis,root);
        if( left.first == NULL && right.first == NULL)
            return {NULL,-1};
        else
            return left.first == NULL ? right : left;
    }
}
/// prints all nodes that are k distance from a target node.
/// return distance of target node from root
int printNodeAtKDistanceFromTargetNode(Node *root,int target,int k){
    unordered_map<Node*,Node*> Map;
    pair<Node*,int> target_ptr = findTargetNode(root,target,Map,0);
    if(!target_ptr.first)
        return -1;
    /// takes care of nodes downwards.
    printNodesAtKDistance(target_ptr.first,k);
    Node *child = target_ptr.first,*parent;

    while(1){
        k--;
        parent = Map[child];
        if(parent == NULL || k <0)
            break;
        if(k==0 && parent != NULL)
            cout << parent->data << " ";
        else{
            if ( parent->left != child)
                printNodesAtKDistance(parent->left,k-1);
            else
                printNodesAtKDistance(parent->right,k-1);
        }
        child = parent;
    }

    return target_ptr.second;
}
void printVector(vector<int> v,bool newLine){
    for(auto x:v)
        cout <<x<<" ";
    if(newLine)
        cout << "\n";
}
void printPathFromRootWithSumK_util(Node *root,int k,vector<int> &path,int &pathCount){
    static int sum = 0;
    if(!root)
        return;
    path.push_back(root->data);
    sum+=root->data;

    if(sum == k){
        printVector(path,true);
        pathCount++;
    }

    printPathFromRootWithSumK_util(root->left,k,path,pathCount);
    printPathFromRootWithSumK_util(root->right,k,path,pathCount);

    sum-=root->data;
    path.pop_back();

}
int printPathFromRootWithSumK(Node *root,int k){
    vector<int> path;
    int pathCount = 0;
    printPathFromRootWithSumK_util(root,k,path,pathCount);
    return pathCount;
}
void printAllKPaths_util(Node *root,int k,int &pathCount){
    if(!root)
        return;
    pathCount+=printPathFromRootWithSumK(root,k);

    printAllKPaths_util(root->left,k,pathCount);
    printAllKPaths_util(root->right,k,pathCount);

}
/// leet code verified but inefficient approach.
int printAllKPaths(Node *root,int k){
    int pathCount = 0;
    printAllKPaths_util(root,k,pathCount);
    return pathCount;
}
/// gfg verified. gfg wants sorted output that the case. simply print children of nodes having only one child.
void printNodesNotHavingSiblings(Node *root){
    vector<int> v;
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    Node *temp;
    while(!q.empty()){
        temp = q.front();q.pop();
        /// if it has only left child print it
        if((temp->left!=NULL && temp->right==NULL) ){
            v.push_back(temp->left->data);
        }
        /// if it has only right child print it
        if((temp->left==NULL && temp->right!=NULL)){
            v.push_back(temp->right->data);
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout << v[i] <<" ";
}
/// gfg verified. same code prints left view if below mentioned lines are commented.
void printLeftAndRightMostNodes(Node *root){
    queue<Node*> q; int count = 1; Node *temp;
    q.push(root);
    while(!q.empty()){

        if(!count){
            count = q.size();
            /// We have entered the new level process the first node here.
            temp = q.front();q.pop();
            cout <<temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            count--;
            /// level had only one node so we need to skip next statements.
            if(count==0)
                continue;
        }
        temp = q.front();q.pop();
        /// signifies it as the only node or last node so print it. comment this line to print tree left view.
        if(count==1)
            cout <<temp->data << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        count--;
    }
}
/// gfg verified litterlaly level order traversal just from right side. and printing first node of level.
void printRightView(Node *root){
    if(!root)
        return;
    queue<Node*> q; int count = 1; Node *temp;
    q.push(root);
    cout << root->data << " ";
    while(!q.empty()){
        if(!count){
            count = q.size();
            /// We have entered the new level process the first node here.
            temp = q.front();q.pop();
            cout <<temp->data << " ";
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
            count--;
            /// level had only one node so we need to skip next statements.
            if(count==0)
                continue;
        }
        temp = q.front();q.pop();
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        count--;
    }
}
/// gfg verified. just simply perform level order traversal with horizontal distance
/// the first node encountered at a specific horizontal distance should be node as we are traversing in
/// top down manner.
void printTopView(Node *root){
    if(root==NULL)
        return;
    /// queue for traversing level order wise. we need to keep track of level as well that's why we are using a pair
    queue<pair<Node*,int>> q;
    /// map will have first node on specific horizontal distance.
    map<int,int> m;
    /// current level here signifies the horizontal level not the vertical level.
    Node * temp; int current_level; pair <Node*,int> tp;
    q.push(make_pair(root,0));
    while(!q.empty()){
        tp = q.front(); q.pop();
        temp = tp.first; current_level = tp.second;
        /// if we don't have any node at that specific horizontal distance then insert it. else we already have
        /// node so don't insert it.
        if(m.find(current_level) ==m.end())
            m[current_level] = temp->data;

        if(temp->left)
            q.push(make_pair(temp->left,current_level-1));
        if(temp->right)
            q.push(make_pair(temp->right,current_level+1));
    }
    /// now print the map.
    for(map<int,int> :: iterator it=m.begin();it!=m.end();it++){
        cout <<m[it->first] << " ";
    }
}

/// -----------------------------------------------------------------------------------------------
///
/// ---------------------------here after we start with summation section of binary tree.----------
///
/// -----------------------------------------------------------------------------------------------

/// gfg verified
long long sumOfTree(Node *root){
    long long sum = 0;
    if(!root)
        return 0;
    return root->data + sumOfTree(root->left) + sumOfTree(root->right);
}
/// finds the sum of all left leaves leet code verified gfg verified.
long long sumOfLeftLeaves(Node *root){
    long long sum = 0;
    if(!root)
        return 0;
    stack<Node*> s; Node *temp;
    s.push(root);
    while(!s.empty()){
        temp = s.top(); s.pop();
        if(temp->left!=NULL && temp->left->left == NULL && temp->left->right == NULL)
            sum+=temp->left->data;
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }

    return sum;
}
/// gfg verified similar to vertical traversal nothing special to explain.
void diagnalSum(Node *root){
    if(root==NULL)
        return;
    /// queue for traversing level order wise. we need to keep track of level as well that's why we are using a pair
    queue<pair<Node*,int>> q;
    /// map will have a vector mapped to corresponding level.
    map<int,int> m;
    Node * temp; int current_level; pair <Node*,int> tp;
    q.push(make_pair(root,0));
    while(!q.empty()){
        tp = q.front(); q.pop();
        temp = tp.first; current_level = tp.second;
        m[current_level]+=temp->data;
        if(temp->left)
            q.push(make_pair(temp->left,current_level+1));
        if(temp->right)
            q.push(make_pair(temp->right,current_level));
    }
    /// now print the map.
    for(map<int,int> :: iterator it=m.begin();it!=m.end();it++){
        cout <<m[it->first]<< "\n";
    }
}

void printPairSumEqualsToRoot_util(Node *root,Node *real_root,map<int,int> &m){
    if(!root)
        return;
    int temp = real_root->data - root->data;
    if(root!=real_root){
        if(m.find(temp)!=m.end())
            cout <<"pair found (" <<root->data << "," << temp <<")\n";
        m[root->data] = 1;
    }
    printPairSumEqualsToRoot_util(root->left,real_root,m);
    printPairSumEqualsToRoot_util(root->right,real_root,m);
    m.erase(root->data);
}
/// finds whether a pair exists on path from root to leaf
void printPairSumEqualsToRoot(Node *root){
    if(!root)
        return;
    map<int,int> m;
    printPairSumEqualsToRoot_util(root,root,m);
}
/// gfg verified. we basically have node with it's parent's sum attached to it.
/// we find the last level which would be level with only leaves on that level we find max value.
void sumOfNodesOnLongestRootToLeafPath(Node *root){
    /// corner cases.
    if(!root)
        return;
    if(root->left==NULL && root->right==NULL){
        cout <<root->data << "\n";
        return;
    }
    queue<pair<Node*,int>> q; Node *temp; int parent_sum,count = 1; pair<Node*,int> tp; bool flag = false;
    int max_sum = -1;
    q.push(make_pair(root,0));
    while(!q.empty()){
        /// asuuming level is last.
        flag = true;
        while(count--){
            tp = q.front(); q.pop();
            temp = tp.first; parent_sum = tp.second;
            /// level is not last one.
            if(temp->left != NULL || temp->right!=NULL){
                flag = false;
                max_sum = -1;
            }
            if(flag){
                if(max_sum<parent_sum+temp->data)
                    max_sum = parent_sum + temp->data;
            }

            if(temp->left)
                q.push(make_pair(temp->left,parent_sum+temp->data));

            if(temp->right)
                q.push(make_pair(temp->right,parent_sum+temp->data));
        }
        count = q.size();
    }
    cout <<max_sum << "\n";
}
/// leet code verified. this code assumes no negative node value but leet code does.
bool removePathWithSumLessThanK(Node *root,int k){
    /// we have reached root and still we have k>0 k represents how much sum is left to subtract from
    /// orignal k value.
    if(!root && k>0)
        return false;
    else if(!root && k<=0)
        return true;
    /// root is not null still k <=0 return true.
    else if(root!=NULL && k<=0)
        return true;
    /// left represent possiblity of path from left and same goes for right.
    bool left,right;
    left = removePathWithSumLessThanK(root->left,k-root->data);
    /// as there is no possiblity of path from node's left node make it null.
    if(left==false)
        root->left = NULL;
    right = removePathWithSumLessThanK(root->right,k-root->data);
    if(right==false)
        root->right = NULL;
    /// return false if there is no path possible from either left or right thus this node must be removed
    /// by it's parent.
    return left || right;
}

bool removePathWithSumLessThanK_util(Node *root,int limit,int pathSum){
    if(!root)
        return false;
    if( root->left==NULL && root->right==NULL){
        if(pathSum+root->data < limit)
            return false;
        else
            return true;
    }

    bool left,right;
    left = removePathWithSumLessThanK_util(root->left,limit,pathSum+root->data);
    if(left==false)
        root->left = NULL;
    right = removePathWithSumLessThanK_util(root->right,limit,pathSum+root->data);
    if(right==false)
        root->right = NULL;
    return left || right;
}
/// leet code version of same code. which has sligh diifrent requirements
/// if path isn't possible from current node then remove the node we don't prune tree here instead only
/// consider the nodes of orignal tree.
Node* removePathWithSumLessThanKLeetCode(Node* root, int limit) {
    bool flag = removePathWithSumLessThanK_util(root,limit,0);
    if(flag==true)
        return root;
    else
        return NULL;
}
int maxSumOfLeafToLeafPath_util(Node *root,int &max_sum){
    /// for null return INT_MIN so it's non null child would be selected.
    if(!root)
        return INT_MIN;
    /// for leaf node return root data.
    if(root->left == NULL && root->right==NULL)
        return root->data;
    /// call left and right subtrees
    int left = maxSumOfLeafToLeafPath_util(root->left,max_sum);
    int right = maxSumOfLeafToLeafPath_util(root->right,max_sum);
    /// only update max if root has both left and right child.
    if(root->left!=NULL && root->right!=NULL && root->data+left+right > max_sum)
        max_sum = root->data+left+right;

    return left > right ? left+root->data : right+root->data;
}
/// gfg verified.
int maxSumOfLeafToLeafPath(Node *root){
    int max_sum = INT_MIN;
    maxSumOfLeafToLeafPath_util(root,max_sum);
    return max_sum;
}

/// gfg verified
int diffrenceBwOddEvenLevels(Node *root){
    queue<Node*> q;
    q.push(root);
    Node *temp; int count = 1,level = 1,sum=0;
    while(!q.empty()){
        temp = q.front(); q.pop();
        /// odd level
        if(level & 1)
            sum+=temp->data;
        else
            sum-=temp->data;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        count -- ;
        if(!count){
            count = q.size();
            level++;
        }
    }
    return sum;
}
/// gfg verified.
int maxLevelSum(Node *root){
    if(!root)
        return 0;
    queue<Node*> q;
    q.push(root);
    Node *temp; int count = 1,sum=0,max_sum=INT_MIN;
    while(!q.empty()){
        temp = q.front(); q.pop();
        sum+=temp->data;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

        count -- ;
        if(!count){
            count = q.size();
            if(sum > max_sum)
                max_sum = sum;
            sum = 0;
        }
    }
    return max_sum;
}
int sumOfLeaves_util(Node *root,int &sum){
    if(!root)
        return 0;
    if(root->left==NULL && root->right==NULL)
        sum+=root->data;
    sumOfLeaves_util(root->left,sum);
    sumOfLeaves_util(root->right,sum);
}
/// gfg verified.
int sumOfLeaves(Node *root){
    int sum = 0;
    sumOfLeaves_util(root,sum);
    return sum;
}
/// gfg verified.
/// return sum of nodes at min level means sum of leaf nodes where the first leaf or leaves occur.
int sumOfLeavesAtMinLevel(Node *root){
    if(!root)
	    return 0;
    int sum = 0,count =1;
    queue<Node*> q; Node *temp;
    q.push(root);
    while(!q.empty()){
        while(count--){
            temp = q.front(); q.pop();
            if(temp->left==NULL && temp->right==NULL)
                sum+=temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(sum!=0)
            break;
        count = q.size();
    }
    return sum;
}
/// leet code, gfg verified. basic idea we have reached to leaf and if sum of path is zero return true else false.
bool rootToLeafPathSum(Node *root,int sum){
    if(!root)
        return false;
    if(root->left==NULL && root->right==NULL && (sum-root->data)==0)
        return true;
    if(root->left==NULL && root->right==NULL && (sum-root->data)!=0)
        return false;

    return rootToLeafPathSum(root->left,sum-root->data) || rootToLeafPathSum(root->right,sum-root->data);
}
void sumOfNumbersFormedFromRootToLeafPath_util(Node *root,int &sum,int path_sum){
    if(!root)
        return;
    if(root->left == NULL && root->right == NULL){
        sum += path_sum*10 + root->data;
        return;
    }
    sumOfNumbersFormedFromRootToLeafPath_util(root->left,sum,path_sum*10+root->data);
    sumOfNumbersFormedFromRootToLeafPath_util(root->right,sum,path_sum*10+root->data);
}
/// leet code verified.
/*
                1
              /  \
            2     3
*/
/// for above tree output would be 13+12 = 25;
int sumOfNumbersFormedFromRootToLeafPath(Node *root){
    int sum = 0;
    sumOfNumbersFormedFromRootToLeafPath_util(root,sum,0);
    return sum;
}
/// this code is also leet code verified this is the first approach you thought of which I think is mixture
/// of recurisve and iterative. clearly it's a messy approach.
Node* mergeTwoBinaryTree(Node* root1,Node* root2){
    if( (root1==NULL && root2 == NULL) || (root1!=NULL && root2==NULL) )
        return root1;
    if(root1==NULL && root2!=NULL){
        return root2;
    }
    if(root1 != NULL && root2 !=NULL){
        root1->data+=root2->data;
    }
    if( root1->left == NULL && root1->right == NULL && root2->left != NULL && root2->right != NULL){
        root1->left = root2->left;
        root1->right = root2->right;
        return root1;
    }
    if(root1->left == NULL && root2->left !=NULL  ){
        root1->left = root2->left;
        if(root1->right && root2->right)
            mergeTwoBinaryTree(root1->right,root2->right);
        return root1;
    }
    if(root1->right == NULL && root2->right != NULL){
        root1->right = root2->right;
        if(root1->left && root2->left)
            mergeTwoBinaryTree(root1->left,root2->left);
        return root1;
    }
    if(root1->left && root2->left)
        mergeTwoBinaryTree(root1->left,root2->left);
    if(root1->right && root2->right)
        mergeTwoBinaryTree(root1->right,root2->right);
    return root1;
}
/// leetcode verified.
/// merge two trees recursively we are merging the root1 and root into root1.
/// dry run this code you will get what is happenig here.
Node* mergeTrees(Node* root1,Node *root2){
    /// if both are null or root1 isn't null then return root1.
    if( (root1 == NULL && root2==NULL) || (root1!=NULL && root2==NULL) )
        return root1;
    /// if both are null or root1 isn't null then return root1.
    if( root1==NULL && root2 !=NULL)
        return root2;
    /// both are non null so we should add thier data.
    root1->data+=root2->data;
    /// now left of current node would be return value of function same is case for right one.
    /// dry run to see what exactly happening here..
    root1->left = mergeTrees(root1->left,root2->left);
    root1->right = mergeTrees(root1->right,root2->right);
    /// after adding data root1 is ther merged tree.
    return root1;
}

int maxSubTreeSum_util(Node *root,int &maxSum){
    if(!root)
        return 0;

    int left = maxSubTreeSum_util(root->left,maxSum);
    int right = maxSubTreeSum_util(root->right,maxSum);

    if ( max(left,max(right,left+right+root->data)) > maxSum)
        maxSum = max(left,max(right,left+right+root->data));

    return root->data + left + right;
}
/// can't verify but gfg approach is same.
int maxSubTreeSum(Node *root){
    int max = INT_MIN;
    maxSubTreeSum_util(root,max);
    return max;
}

int countOfSubTreeHavingSum_util(Node *root,int x,int &count){
     if(!root)
        return 0;

    int left = countOfSubTreeHavingSum_util(root->left,x,count);
    int right = countOfSubTreeHavingSum_util(root->right,x,count);
    if ( root->data + left + right == x)
        count ++;

    return root->data + left + right;
}
/// gfg verified Microsoft question.
int countOfSubTreeHavingSum(Node *root,int x){
    int count = 0;
    countOfSubTreeHavingSum_util(root,x,count);
    return count;
}
/// format of string (node_value (left_subtree) (right_subtree) )
/// ------------------imcomplete -----------------------------
Node* buildTreeFromString(string str){
    static int len = str.length(),index = 0;
    Node* root = NULL;

    if(str[index]=='('){
        index++;
        if(str[index] != ')'){
            //root = newNode(atoi(str[index++]));
            root->left = buildTreeFromString(str);
            root->right = buildTreeFromString(str);
        }
        index++;
    }

    return root;
}

/// -----------------------------------------------------------------------------------------------

/// ---------------------------------STARTING OF LCA PART OF GFG-----------------------------------

///------------------------------------------------------------------------------------------------

/// gfg verified.
Node * lca(Node* root ,int a ,int b )
{
   if(!root){
        return NULL;
    }
    if(root->data == a || root->data == b){
        return root;
    }
    Node* temp;
    Node* prev;
    bool flag = 1;
    stack<Node*> s;
    vector<Node*> ancestor_a,ancestor_b;

    s.push(root);
    while(!s.empty()){
        temp = s.top();

        /// we get to most left leaf of current node.
        /// flag = 0 indicates that the left subtree of current node has been checked.
        if(flag){
            while(temp->left != NULL){
            s.push(temp->left);
            temp = temp->left;
            }
            flag = 0;
        }
        /// we pop an element either if it's right child is null or right child was previously processed node.
        if(temp->right == NULL || temp->right == prev){
                s.pop();
                prev = temp;
                if(!ancestor_a.size() && temp->data == a){
                    ancestor_a.push_back(temp);
                    while(!s.empty()){
                        ancestor_a.push_back(s.top());
                        s.pop();
                    }

                    for(int i= ancestor_a.size()-1; i>0;i--)
                        s.push(ancestor_a[i]);
                }
                if(!ancestor_b.size() && temp->data == b){
                    ancestor_b.push_back(temp);
                    while(!s.empty()){
                        ancestor_b.push_back(s.top());
                        s.pop();
                    }

                    for(int i= ancestor_b.size()-1; i>0;i--)
                        s.push(ancestor_b[i]);
                }
                if(ancestor_a.size() && ancestor_b.size())
                    break;
        }
        else{
            s.push(temp->right);
            flag = 1;
        }
    }
    if(!ancestor_a.size() || !ancestor_b.size()){
        return NULL;
    }
    for(int i = 0; i < ancestor_a.size(); i++){
        int key = ancestor_a[i]->data;
        for(int j = 0 ;j<ancestor_b.size(); j++){
            if(key== ancestor_b[j]->data){
                return ancestor_b[j];
            }
        }
    }
}
/// it's a recursive version of ancesor printer function the iterative version is defined in LCA function.
/// we are returning one as indicator of sucess and returning zero as indicator of failure.
/// once one is returned the one is passed from node to root and all in between roots are printed.
int ancestors_recursive(Node* root, int x, vector<Node*> &ancestors){
    /// base case
    if(!root)
        return 0;
    /// base case
    if(root->data == x){
        ancestors.push_back(root);
        return 1;
    }
    else{
        if(ancestors_recursive(root->left,x,ancestors)){
            ancestors.push_back(root);
            return 1;
        }
        if(ancestors_recursive(root->right,x,ancestors)){
            ancestors.push_back(root);
            return 1;
        }
        return 0;
    }
}

/// gfg verified find LCA by finding ancestors of node a and b and the finds the first one that
/// matches
Node* LCA_rec(Node * root, int a,int b){
    /// base case
    if(!root){
        return NULL;
    }
    /// base case
    if(root->data == a || root->data == b){
        return root;
    }
    vector<Node*> ances_a,ances_b;

    /// if both has ancestors then we return the common one
    if ( ancestors_recursive(root,a,ances_a) && ancestors_recursive(root,b,ances_b) ){
        for(int i = 0; i < ances_a.size(); i++){
            Node* key = ances_a[i];
            for(int j = 0 ;j<ances_b.size(); j++){
                if(key->data == ances_b[j]->data){
                    return key;
                }
            }
        }
    }
    /// else return null.
    return NULL;
}
/// gfg verified leet code verified
Node* LCA_OneTraversal(Node* root,int a,int b){
    if(!root)
        return NULL;

    if( root->data == a || root->data == b)
        return root;

    Node *left = LCA_OneTraversal(root->left,a,b);
    Node *right = LCA_OneTraversal(root->right,a,b);

    if (left && right)
        return root;

    return left == NULL ? right : left;
}
/// gfg verified
int distanceOfNodeFromRoot(Node* root,int x,int dis = 0){

    if(!root)
        return -1;
    if(root->data == x)
        return dis;

    return max(distanceOfNodeFromRoot(root->left,x,dis+1),
            distanceOfNodeFromRoot(root->right,x,dis+1));

}
/// gfg verified the formula given below works on fact that the lca node is the intersection
/// of any two nodes of tree so the min distance has to pass from lca. so the min dis can be calculated
/// by using below formula dry run the below formula on tree and u will get the idea why?
int minDistanceBwTwoNodes(Node *root, int a,int b){
    return distanceOfNodeFromRoot(root,a) + distanceOfNodeFromRoot(root,b) - 2*distanceOfNodeFromRoot(root,LCA_OneTraversal(root,a,b)->data);
}

void maxDiffBwNodeAndAncestor_util(Node* root,int &max_diff,int max_ancestor){
    if(!root)
        return;

    if(max_ancestor - root->data > max_diff && max_ancestor !=root->data)
        max_diff = max_ancestor - root->data;

    if(root->data > max_ancestor)
        max_ancestor = root->data;

    maxDiffBwNodeAndAncestor_util(root->left,max_diff,max_ancestor);
    maxDiffBwNodeAndAncestor_util(root->right,max_diff,max_ancestor);
}
/// gfg verified but I have serious doubts.
int maxDiffBwNodeAndAncestor(Node* root){
    if(!root)
        return 0;
    int max_diff = INT_MIN;
    maxDiffBwNodeAndAncestor_util(root,max_diff,root->data);
    return max_diff;
}

void maxDiffBwNodeAndAncestorLeetCode_util(Node* root,int &max_diff,int max_node,int min_node ){
    if(!root)
        return;

    if (root->data > max_node)
        max_node = root->data;
    if(root->data < min_node)
        min_node = root->data;

    if ( root->left == NULL && root->right == NULL && max_diff < max_node-min_node ){
        max_diff = max_node-min_node;
    }

    maxDiffBwNodeAndAncestorLeetCode_util(root->left,max_diff,max_node,min_node);
    maxDiffBwNodeAndAncestorLeetCode_util(root->right,max_diff,max_node,min_node);
}
/// leet code verified this one is quite easier in this we can find sol by finding max and
/// min node along the path and calculate the diff and update max_diff accordingly.
int maxDiffBwNodeAndAncestorLeetCode(Node* root){
    if(!root)
        return 0;
    int max_diff = INT_MIN;
    maxDiffBwNodeAndAncestorLeetCode_util(root,max_diff,root->data,root->data);
    return max_diff;
}

void printKthAncestor_util(Node* root,int &target,int &k,bool &flag){

    if(!root)
        return ;
    if(root->data == target){
        flag = true;
        return;
    }


    if(!flag)
        printKthAncestor_util(root->left,target,k,flag);
    if(flag){
        k--;
        if(k==0){
            target = root->data;
        }
        return;
    }

    if(!flag)
        printKthAncestor_util(root->right,target,k,flag);
    if(flag){
        k--;
        if(k==0){
            target = root->data;
        }
        return;
    }

}
/// gfg verified
int printKthAncestor(Node* root,int target,int k){
    bool flag = false;
    printKthAncestor_util(root,target,k,flag);
    if(!flag || k>0)
        return -1;

    return target;
}

/// -----------------------------------------------------------------------------------------------

///-------------------------------START OF MISC SECTION GFG----------------------------------------

///------------------------------------------------------------------------------------------------

void deleteTree_util(Node* &root){
    if(!root)
        return;

    if( root->left == NULL &&  root->right == NULL){
        cout << "Deleting " << root->data << "\n";
        free(root);
        return;
    }

    deleteTree_util(root->left);
    deleteTree_util(root->right);
    cout << "Deleting " << root->data << "\n";
    free(root);
}
/// there is no verification but it seems to work fine.
void deleteTree(Node* &root){
    deleteTree_util(root);
    root = NULL;
}

void deleteLeafHavingXval_util(Node* root,int x,Node* parent){
    if(!root)
        return;

    if( root->left == NULL && root->right == NULL && root->data == x){
        if (parent && parent->left == root){
            parent->left = NULL;
        }
        if (parent && parent->right == root){
            parent->right = NULL;
        }
        free(root);
        if(!parent)
          root = NULL;
        return;
    }

    deleteLeafHavingXval_util(root->left,x,root);
    deleteLeafHavingXval_util(root->right,x,root);

    if( root->left == NULL && root->right == NULL && root->data == x){
        if (parent && parent->left == root){
            parent->left = NULL;
        }
        if (parent && parent->right == root){
            parent->right = NULL;
        }
        free(root);
        if(!parent)
          root = NULL;
        return;
    }

}
/// leet code verified logically but using free causes runtime error.
void deleteLeafHavingXval(Node* &root,int x){
    Node * parent = NULL;
    deleteLeafHavingXval_util(root,x,parent);
}
/// gfg sligh modification function in this we are considering the height of leaves on even level.
int findHeightConsiderEvenLevelLeaf(Node *root,int level = 1){
    if(!root)
        return 0;

    if( !root->left && !root->right ){
        /// if level is odd height is zero
        if(level & 1)
            return 0;
        /// if level is odd then we consider height
        else
            return level;
    }

    return max(findHeightConsiderEvenLevelLeaf(root->left,level+1),
               findHeightConsiderEvenLevelLeaf(root->right,level+1));
}

/// pair has int for height and bool for whether tree is height balanced or not
pair<int,bool> isHeightBalanced_util(Node *root){
    /// base case
    if(!root)
        return {0,true};

    pair<int,bool> left =  isHeightBalanced_util(root->left);
    pair<int,bool> right =  isHeightBalanced_util(root->right);

    /// if left and right subtree are balanced and the diff b/w thier height is less than 1
    /// then tree is height balanced else not.
    if( left.second && right.second && abs(left.first-right.first) <=1)
        return { max(left.first,right.first) + 1  ,true};
    else
        return { max(left.first,right.first) + 1  ,false};
}
/// leet and gfg verified. we are calculating height and determining tree are balanced in same
/// recursion.
bool isHeightBalanced(Node *root){
    if(!root)
        return true;
    return isHeightBalanced_util(root).second;
}

void findHeightSpiralTree_util(Node* root,int &height,int level=1){
    if(!root)
        return;

    if(level > height)
        height = level;
    /// check whether the node is leaf or not, now as all leaves form CLL then to detect leaf node
    /// it's left and right won't be null and also it's left's right would be node itself
    /// because it's a CLL.
    if( root->left && root->right && root->left->right == root ){
        return;
    }

    findHeightSpiralTree_util(root->left,height,level+1);
    findHeightSpiralTree_util(root->right,height,level+1);
}
/// gfg verified your idea was right but not optimized
int findHeightSpiralTree(Node* root){
    int height = 0;
    if(!root)
        return 0;
    findHeightSpiralTree_util(root,height);
    return height;
}

/// gfg and leet code verified
int minDepthNode(Node* root){
    if(!root)
        return 0;
    if( root->left==NULL && root->right == NULL )
        return 1;

    int left = minDepthNode(root->left);
    int right = minDepthNode(root->right);

    if(left !=0 && right !=0)
        return min(left,right) + 1;
    return left == 0 ? right+1 : left+1;

}

void maxWidthOfBinaryTree_util(Node* root,unordered_map <int,int> &Map,int level = 1){
    if(!root)
        return;
    if(Map.find(level) == Map.end())
        Map[level] = 1;
    else
        Map[level] ++;

    maxWidthOfBinaryTree_util(root->left,Map,level+1);
    maxWidthOfBinaryTree_util(root->right,Map,level+1);
}
/// gfg verified we are visiting all nodes and then we are counting the occurence at a specific
/// level using hash maps
int maxWidthOfBinaryTree_rec(Node* root){
    if(!root)
        return 0;
    unordered_map <int,int> Map;
    unordered_map <int,int> :: iterator itr;
    int max = INT_MIN;

    maxWidthOfBinaryTree_util(root,Map);
    for(itr = Map.begin();itr!=Map.end();itr++ ){
        if(itr->second > max)
            max = itr->second;
    }
    return max;
}
/// gfg verified, while level order traversal max queue size is max width.
int maxWidthOfBinaryTree(Node* root){
    if(!root)
        return 0;

    int maxWidth ;
    queue<Node*> q; Node* temp;

    q.push(root);
    q.push(NULL);
    maxWidth = 1;

    while(!q.empty()){
        temp = q.front(); q.pop();
        if(temp != NULL){
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else{
            if(q.size() !=0){
                if(q.size() > maxWidth)
                    maxWidth = q.size();
                q.push(NULL);
            }
        }
    }
    return maxWidth;
}
/// leet code verified those bitches use number way over the limit of int,long long had to use
/// double in leet code here I am using int. This is diff question than gfg here we also consider the
/// null b/w nodes for width here we are using node's position to provide position to it's childs
/// position start from one and goes to max no of nodes at that level
int maxWidthOfBinaryTreeLeetCode(Node* root){
    if(!root)
        return 0;

    int maxWidth ;
    queue<pair<Node*,int>> q; pair<Node*,int> temp;
    Node* node; int num,min_num=1,max_num=INT_MIN; /// min_num is position of very first node of level
    q.push({root,1});                            /// max_num is pos of last child.
    q.push({NULL,-1});
    maxWidth = 1;

    while(!q.empty()){
        temp = q.front(); q.pop();
        node = temp.first;
        num = temp.second;

        if(node != NULL){
            if (num > max_num)
                max_num = num;
            if(node->left)
                q.push({node->left,2*num-1}); /// position for left child is 2*parent -1
            if(node->right)
                q.push({node->right,2*num}); /// position for right child is 2*parent
        }
        else{
            if(q.size() !=0){
                if ( max_num - min_num +1 > maxWidth)
                    maxWidth = max_num - min_num +1;
                min_num = q.front().second;
                q.push({NULL,-1});
                max_num = INT_MIN;
            }
            else if(max_num - min_num +1 > maxWidth){
                maxWidth = max_num - min_num +1;
            }
        }
    }
    return maxWidth;
}

/// gfg verified pretty straight forward doing level order travesal save the latest value of
/// a node at vertical distance
void bottomViewBinaryTree(Node* root){
    if(!root)
        return;
    map<int,int> Map;
    queue<pair<Node*,int>> q; pair<Node*,int> temp;
    Node* node; int vertical_dis;
    q.push({root,0});
    q.push({NULL,INT_MIN});

    while(!q.empty()){
        temp = q.front(); q.pop();
        node = temp.first;
        vertical_dis = temp.second;
        if(node!=NULL){
            Map[vertical_dis] = node->data;
            if(node->left)
                q.push({node->left,vertical_dis-1});
            if(node->right)
                q.push({node->right,vertical_dis+1});
        }
        else if(q.size() !=0){
            q.push({NULL,INT_MIN});
        }
    }
    map<int,int> ::iterator itr;
    for(itr = Map.begin();itr!=Map.end();itr++)
        cout << itr->second << " ";
}
/// gfg verified
int countNonLeafNodes(Node* root){
    if(!root)
        return 0;
    if(root->left ==NULL && root->right ==NULL)
        return 0;

    return 1+ countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

vector<Node*> largestSubTreeHavingIdenticalLeftRightSubTree_util(Node* root,int &maxLength){
    /*
    vector<Node*> v;

    if(!root){
        v.push_back(NULL);
        return v;
    }

    vector<Node*>  left = largestSubTreeHavingIdenticalLeftRightSubTree_util(root->left,maxLength);
    vector<Node*>  right = largestSubTreeHavingIdenticalLeftRightSubTree_util(root->right,maxLength);

    cout << "Root " << root->data << " left " << left << " right " << right << "\n";

    if( left.size() == right.size()){
        int len = 0 ;
        for(int i=0;i<left.length();i++){
            if(left[i]=='N')
                continue;
            len++;
        }
        if ( maxLength < 2*len+1)
            maxLength = 2*len+1;
    }

    return to_string(root->data) + left +right;
    */

}
/// your idea was to use linked list also ur idea is similar to gfg to use bottom up approach
/// but somehow stl list isn't working implement required function in list itself.
int largestSubTreeHavingIdenticalLeftRightSubTree(Node* root){
    int maxLength = INT_MIN;
    ///largestSubTreeHavingIdenticalLeftRightSubTree_util(root,maxLength);
    return maxLength;
}

pair<Node*,bool> noOfSingleValueSubTree_util(Node* root,int &treeCount){
    if(!root)
        return {NULL,true};

    if ( root->left == NULL && root->right == NULL ){
        treeCount++;
        return {root,true};
    }

    pair<Node*,bool> left = noOfSingleValueSubTree_util(root->left,treeCount);
    pair<Node*,bool> right =noOfSingleValueSubTree_util(root->right,treeCount);

    if (left.first !=NULL && right.first !=NULL && left.second && right.second
        && root->data == left.first->data && root->data == right.first->data ){
        treeCount++;
        return {root,true};
    }

    else if (left.first ==NULL && right.first !=NULL && right.second
        &&  root->data == right.first->data ){
        treeCount++;
        return {root,true};
    }

    else if (right.first ==NULL && left.first !=NULL && left.second
        &&  root->data == left.first->data ){
        treeCount++;
        return {root,true};
    }

    return {root,false};
}
/// a single valued tree is a tree which has all nodes values same same
/// approach as gfg  we are simply traversing in bottom up manner a tree would be single values sub
/// tree if it's left as well as right are single valued sub tree and the value of root matches
/// with it's left as well as right
int noOfSingleValueSubTree(Node* root){
    int treeCount = 0;
    noOfSingleValueSubTree_util(root,treeCount);
    return treeCount;
}

void removeHalfNodes_util(Node* root,Node* parent ){
    if(!root)
        return;

    removeHalfNodes_util(root->left,root);
    removeHalfNodes_util(root->right,root);


    if(parent == NULL ){
        if ( root->left == NULL && root->right !=NULL){
            Node* temp = root;
            root = root->right;
            ///free(temp);  using this free cause some unexpected results
            return;
        }
        else if(root->right == NULL && root->left !=NULL){
            Node* temp = root;
            root = root->left;
            ///free(temp);
            return;
        }
    }

    if ( root->left == NULL && root->right != NULL ){
        if ( parent->left == root){
            parent->left = root->right;
            root->right = NULL;
            free(root);
        }
        else{
            parent->right = root->right;
            root->right = NULL;
            free(root);
        }
    }
    else if(root->left != NULL && root->right == NULL){
        if ( parent->left == root){
            parent->left = root->left;
            root->left = NULL;
            free(root);
        }
        else{
            parent->right = root->left;
            root->left = NULL;
            free(root);
        }
    }
}
/// gfg verified logic is fine but use of free is confusing
void removeHalfNodes(Node* root){
    Node* parent = NULL;
    removeHalfNodes_util(root,parent);
}

bool pairWiseSwapLeaf_util(Node* root,Node** &pre){
    if(!root)
        return 0;
    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    bool left = pairWiseSwapLeaf_util(root->left,pre);
    if (left){
        if(pre == NULL)
            pre = &(root->left);
        else{
            swap(*pre,root->left);
            pre = NULL;
        }
    }
    bool right = pairWiseSwapLeaf_util(root->right,pre);
    if (right){
        if(pre == NULL)
            pre = &(root->right);
        else{
            swap(*pre,root->right);
            pre = NULL;
        }
    }
    return 0;
}
/// gfg verified
void pairWiseSwapLeaf(Node* root){
    Node** pre = NULL;
    pairWiseSwapLeaf_util(root,pre);
}
void printNoOfRootToLeafPaths_util(Node* root,map<int,int> &Map,int level = 1){
    if(!root)
        return;
    if( root->left == NULL && root->right == NULL ){
        if (Map.find(level) == Map.end() )
            Map[level] = 1;
        else
            Map[level]++;
    }

    printNoOfRootToLeafPaths_util(root->left,Map,level+1);
    printNoOfRootToLeafPaths_util(root->right,Map,level+1);
}
/// gfg verified really straight forward simply travese DFS and when a lead enter the path count
/// in hash map
void printNoOfRootToLeafPaths(Node* root){
    map<int,int> Map;
    printNoOfRootToLeafPaths_util(root,Map);
    map<int,int> :: iterator itr;
    for ( itr=Map.begin() ; itr!=Map.end();itr++ )
        cout << itr->second << " " << itr->first << " $";

}

Node* LeafToDLL_util(Node* root,Node** headptr,Node* &pre){
    if(!root)
        return NULL;

    if(root->left == NULL && root->right == NULL){
        if(*headptr==NULL){
            *headptr = root;
            pre = root;
        }
        else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        return root;
    }


    Node* left = LeafToDLL_util(root->left,headptr,pre);
    Node* right = LeafToDLL_util(root->right,headptr,pre);

    if(left != NULL)
        root->left = NULL;
    if(right != NULL)
        root->right = NULL;

    return NULL;
}
/// gfg verfied removes leaf and put them in DLL simply traverse and put leaves in DLL
/// and remove them from tree.
Node* LeafToDLL(Node* root,Node** headptr ){
    Node* pre = NULL;
    LeafToDLL_util(root,headptr,pre);
}

/// this function removes nodes on path that are of length less than k. bottom up approach
/// same approach as gfg
bool removeNodeOnPathLengthLessThanK(Node* &root,int k,int len = 1){
    if(!root){
        if(len-1 < k)
            return true;
        return false;
    }

    bool left = removeNodeOnPathLengthLessThanK(root->left,k,len+1);
    bool right = removeNodeOnPathLengthLessThanK(root->right,k,len+1);

    if(left && root->left){
        Node* temp = root->left;
        root->left = NULL;
        free(temp);
    }

    if(right && root->right ){
        Node* temp = root->right;
        root->right = NULL;
        free(temp);
    }

    if ( len == 1 && k>1 && left && right){
        Node* temp = root;
        root = NULL;
        free(temp);
    }

    return (left && right );
}

int NoOfBendsToReachNode_util(Node* root,char dir,int bends,int x){
    if(!root)
        return -1;
    if(root->data == x)
        return bends;

    if(dir == 'l'){
        return max(NoOfBendsToReachNode_util(root->left,'l',bends,x),
                   NoOfBendsToReachNode_util(root->right,'r',bends+1,x) );
    }
    else{
        return max(NoOfBendsToReachNode_util(root->left,'l',bends+1,x),
                   NoOfBendsToReachNode_util(root->right,'r',bends,x) );
    }
}
/// return no of bends if node present else return -1
int NoOfBendsToReachNode(Node* root,int x){
    if(!root)
        return -1;
    if(root->data == x)
        return 0;

    return max (NoOfBendsToReachNode_util(root->left,'l',0,x),
    NoOfBendsToReachNode_util(root->right,'r',0,x)) ;
}
/// gfg verified we find lca then we find no of turns takes from lca to reach node a and node b
/// and then accordingly handle cases
int NoOfTurnsToReachFromOneNodeToOther(Node* root,int a,int b){
    Node* lca = LCA_OneTraversal(root,a,b);

    int left = NoOfBendsToReachNode(lca,a);
    int right = NoOfBendsToReachNode(lca,b);

    if( lca->data == a || lca->data == b ){
        if(!left && !right){
            return -1;
        }
        else{
            return left+right;
        }
    }

    return left+right +1;
}
/// special node version of finding node at k distance
TreeNode* NodeAtKDistance(TreeNode* root,int d){
    if(!root)
        return NULL;
    if(d==0)
        return root;

    TreeNode* left =  NodeAtKDistance(root->left,d-1);
    TreeNode* right = NodeAtKDistance(root->right,d-1);
    return left == NULL ? right : left;
}
/// gfg verified this q uses a special node with parent pointers. we are using bottom up approach
/// we come to parent node and try to find node at distance dis from parent node in rightSubTree
/// recursively until either tree is completly scanned or we find one. O(n) complexity
TreeNode* rightSiblingOfNode(TreeNode* node){
    TreeNode* parent,*ans=NULL;
    int dis = 1;

    while(1){
        parent = node->parent;
        if(!parent)
            break;
        if(parent->left == node){
            ans = NodeAtKDistance(parent->right,dis-1);
            if(ans)
                break;
        }
        node = parent;
        dis++;
    }
    return ans;
}

string printDuplicateSubTrees_util(Node* root,unordered_map<string,int> &Map){
    if(!root)
        return "N";

    if(root->left == NULL && root->right == NULL){
        Map[to_string(root->data)]++;
        return to_string(root->data);
    }


    string left = printDuplicateSubTrees_util(root->left,Map);
    string right = printDuplicateSubTrees_util(root->right,Map);

    Map[to_string(root->data)+"|" + left +"|"+ right]++;
    return to_string(root->data)+"|" + left +"|"+ right;
}
/// leet and gfg verified identifying tree uniqness considering pre order by taking care of nulls.
/// stroring all possible tree in map
void printDuplicateSubTrees(Node* root){
    unordered_map<string,int> Map;
    printDuplicateSubTrees_util(root,Map);
    unordered_map<string,int> ::iterator itr;

    for(itr=Map.begin();itr!=Map.end();itr++){
        cout << itr->first << " " << itr->second <<"\n";
    }

}

///------------------------------------------------------------------------------------------------
///-----------------------------Construction and conversion Questions------------------------------
///------------------------------------------------------------------------------------------------

/// gfg verified k should be passed as sizeofarray - 1 left as zero and right as sizeofarray - 1
Node* createTreeUsingInAndPost(int *in, int *post,int left,int right,int &k){
    if(left>right)
        return NULL;
    int key = post[k--];
    Node* root =  newNode(key);
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
/// gfg verified k should be passed as zero left also as zero and right is index of last element
/// of preOrder Array
Node* createTreeUsingInAndPre(int *in, int *pre,int left,int right,int &k){
    if(left>right)
        return NULL;
    int key = pre[k++];
    Node* root =  newNode(key);
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

int main(){

    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);


/*
    Node* root = newNode(1);

    root->left =newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);


    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);

    ///int in[] = {6,4,12,13,7,2,5,9,8,11,10,1,3}, pre[] = {1,2,4,6,7,12,13,5,8,9,10,11,3};
    ///char arr[] = "nlnll";
    */

    printDuplicateSubTrees(root);
    return 0;
}
