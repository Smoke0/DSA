#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void print(Node* head)               /// This fn works perfectly.
{
    if(head==NULL)
        cout<<"List is empty"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout <<"\n";
}
void deleteFront(Node* &head){
    if(head==NULL)
        return;
    else if(head->next==NULL){
        delete head;
        head = NULL;
    }
    else{
    Node* n = head->next;
    delete head;
    head = n;
    }
    print(head);
}
/// gfg verified
int lenghtOfList(Node* head){
    int len = 0;
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 1;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}
void deleteBack(Node* &head){
    if(head==NULL)
        return;
    else if(head->next==NULL){
        delete head;
        head = NULL;
    }
    else{
        Node* n = head;
        while(n->next->next)
            n = n->next;
        /// now n must be standing at 2nd last node.
        delete n->next;
        n->next = NULL;
    }
    print(head);
}
void deleteGivenIndex(Node* &head,int index){
    int len = lenghtOfList(head);
    if(index == 0){
        deleteFront(head);
        return;
    }
    else if(index>=len-1){
        deleteBack(head);
        return;
    }
    else{
        Node* prev = NULL;
        Node* cur = head;
        while(index>=1){
            prev = cur;
            cur = cur->next;
            index--;
        }
        prev->next = cur->next;
        delete cur;
    }
}

void bubbleSort(Node* &head){
    int n = lenghtOfList(head);
    Node* t1 ;
    Node* t2 ;
    Node* t0 ;
    for(int i=0;i<n-1;i++){
        /// we need three nodes.
        t0 = NULL;
        t1 = head;
        t2 = head->next;
        for(int j=0;j<n-1-i;j++){
            /// we would want to swap nodes at j and j+1 if node at j is greater than node at j+1.
            if(t1->data > t2->data){
                /// if t1 is head we change head
                if(t1==head){
                    /// swapping nodes.
                    t1->next = t2->next;
                    t2->next = t1;
                    head = t2;
                    /// incrementing nodes t1 is at right place  so change t2 only.
                    t0 = t2;
                    t2 = t1->next;
                }
                /// we don't change head.
                else{
                    t1->next = t2->next;
                    t2->next = t1;
                    t0->next = t2;
                    /// incrementing nodes t1 is at right place  so change t2 only.
                    t0 = t2;
                    t2 = t1->next;
                }
            }
            /// simply increment nodes
            else{
                t0 = t1;
                t1 = t1->next;
                t2 = t2->next;
            }
        }

    }
}
/// gfg verified
/// insert item to front of list.
void insertFront(Node* &head,int key){
    if(head==NULL){
        head = new Node(key);
        return;
    }
    Node* temp = new Node(key);
    temp->next = head;
    head = temp;
}
/// gfg verified
void insertBack(Node* &head,int x)  /// adds items to end of list. // This fn works perfectly.
{
    if(head==NULL)
        head = new Node(x);
    else{
        Node* cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next= new Node(x);
    }
}
/// insert a node with given key into a sorted list on it's proper position.
void insertInSortedList(Node* &head,int key){
    if(head==NULL){
        head = new Node(key);
        return;
    }

    Node* pre = NULL;
    Node* cur = head;

    while(cur && cur->data < key){
        pre = cur;
        cur = cur->next;
    }
    /// we are inserting at front.
    if(pre==NULL){
        insertFront(head,key);
    }
    /// we are inserting at last.
    else if(cur == NULL){
        insertBack(head,key);
    }
    /// we are inserting in b/w.
    else{
        pre->next = new Node(key);
        pre->next->next = cur;
    }

}
void insertionSort(Node* &head){
    Node* sorted = NULL;
    Node* cur = head;
    while(cur){
    insertInSortedList(sorted,cur->data);
    cur = cur->next;
    }
    head =  sorted;
}
/// this is bit modified algorithm it breaks the list even if it's circular.
bool floyedCycleDetection(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* pre = NULL;

    /// don't move fast and slow if fast or fast next is null. analyse this
    /// you were moving fast until fast is null if fast->next is null you move fast by one step.
    while(fast && fast->next){
        pre = fast->next;
        fast = fast->next->next;
        slow = slow->next;
        /// cycle has been detected.
        if(fast == slow){
            slow = head;
            while(fast!=slow){
                pre = fast;
                fast = fast->next;
                slow =  slow->next;
            }
            pre->next = NULL;
            return true;
        }
    }
    return false;
}

/// gfg verified
bool detectloop(Node *head) {

    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if ( fast == slow)
            return 1;
    }
    return 0;
}

/// gfg verified
int countNodesinLoop(struct Node *head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        /// loop has been detected
        if ( fast == slow){
            int count = 1;
            fast = fast->next;
            while(fast != slow){
                fast = fast->next;
                count++;
            }
            return count;
        }

    }
    return 0;
}

/// gfg verified
/// swap nodes at given index. 0 based indexing
void swapNodes(Node* &head,int x, int y){
    /// there are cases to handle.
    /// one of node is head
    /// nodes are adjacent to each other
    /// nodes aren't adjacent to each other
    if(x==y)
        return;
    int len = lenghtOfList(head);
    if(x>=len || y>=len)
        return;
    /// one of node is head
    if(x==0 || y==0){
        /// we are assuming that x is pointing to head.
        if(x!=0)
            swap(x,y);
        /// nodes are adjacent to each other
        if(y==1){
            Node* cur = head->next;
            head->next = cur->next;
            cur->next = head;
            head = cur;
        }
        /// nodes aren't adjacent to each other.
        else{
            Node* pre = NULL;
            Node* cur = head;
            Node* nxt = cur->next;
            while(y--){
                pre = cur;
                cur = cur->next;
                nxt = cur->next;
            }
            cur->next = head->next;
            head->next = nxt;
            pre->next = head;
            head = cur;
        }

    }
    else{
        /// we here assumes that the node x comes before y.
        if(x>y)
            swap(x,y);
        Node* p1 = NULL; Node* c1 = head; Node* n1 = c1->next;
        Node* p2 = NULL; Node* c2 = head; Node* n2 = c2->next;
        while(x--){
            p1 = c1;
            c1 = c1->next;
            n1 = c1->next;
        }
        while(y--){
            p2 = c2;
            c2 = c2->next;
            n2 = c2->next;
        }
        /// nodes are adjacent to each other
        if(n1==c2){
            c1->next = n2;
            p1->next = c2;
            c2->next = p2;
        }
        /// nodes aren't adjacent to each other
        else{
            c1->next = n2;
            p1->next = c2;
            p2->next = c1;
            c2->next = n1;
        }
    }
}
/// selection sort for linked list.
void selectionSort(Node* &head){
    Node* new_head = NULL;
    int max,index,max_index; Node* cur;
    int n = lenghtOfList(head);
    /// n times we find the max value in linked list.
    for(int i=0;i<n;i++){
        max = head->data; index = 0; max_index = 0;
        cur = head;
        while(cur){
            if(cur->data > max){
                max = cur->data;
                max_index = index;
            }
            cur = cur->next;
            index++;
        }
        insertFront(new_head,max);
        deleteGivenIndex(head,max_index);
    }
    head = new_head;
}
/// gfg verified
void sortLLOf012(Node* &head){
    if(!head)
        return;

    Node* head0 = new Node(-1); /// these are nodes that are needed to avoid if(head==NULL)
    Node* head1 = new Node(-1); /// situation head0 is head of list containing zero and same
    Node* head2 = new Node(-1); /// for head1 and head2

    Node* cur = head;    /// iterateres for different lists
    Node* cur0 = head0;
    Node* cur1 = head1;
    Node* cur2 = head2;

    while(cur){              /// iterate the list and add node to appropriate list

        if(cur->data == 0){
            cur0->next = cur;
            cur0 = cur0->next;
        }
        else if (cur->data == 1){
            cur1->next = cur;
            cur1 = cur1->next;
        }
        else{
            cur2->next = cur;
            cur2 = cur2->next;
        }

        cur = cur->next;
    }

    cur0->next = cur1->next = cur2->next = NULL;  /// as list has been iterated last node next
                                                  /// needed to be null

    /// below if else just attach the list of 0,1 and 2 to each other appropriately
    if(head0->next){
        head = head0->next;
        if(head1->next){
            cur0->next = head1->next;
            cur1->next = head2->next;
        }
        else{
            cur0->next = head2->next;
        }
    }
    else{
        if(head1->next){
            head = head1->next;
            cur1->next = head2->next;
        }
        else
            head = head2->next;
    }
    /// delete dummy nodes
    cur0 = head0; cur1 = head1; cur2 = head2;
    delete cur0; delete cur1; delete cur2;
}

/// gfg verified
void deleteNodeWithOutHead(Node* node){
    Node* temp = node->next;
    *node = *(node->next); /// this seems like magic but actually we are putting one struct node{};
    delete temp;           /// into another instead of node->data = node->next->data; node->next = node->next->next;
                        /// this approach will copy what ever the node has this works only because
                        /// we can use assignment on structures
}

/// gfg verified 1 based indexing
Node* nthNode(Node* head,int n){

    while(n>1){
        head = head->next;
        n--;
    }
    return head;
}

/// gfg verified
Node* nthNodeFromLast(Node* head,int n){

    Node* nth = head;
    while(head && n--)
        head = head->next;
    if(n>0)
        return NULL;
    while(head){
        head = head->next;
        nth = nth->next;
    }
    return nth;
}

/// gfg verified return later element in case of even length list
/// 1-> 2-> 3-> 4-> NUll will return 3
Node* midOfLinkedList(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
       fast = fast->next->next;
       slow = slow->next;
    }
    return slow;
}

/// gfg verified return first element in case of even length list
/// 1-> 2-> 3-> 4-> NUll will return 2
Node* midOfLinkedList2(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

/// gfg verified
Node* removeDuplicateSorted(Node* head){
    Node* cur = head;
    Node* temp;

    while(cur!=NULL){
        temp = cur->next;

        while( temp!=NULL &&  temp->data == cur->data )
            temp = temp->next;

        cur-> next = temp;
        cur = temp;
    }

    return head;
}

/// gfg verified
Node* removeDuplicateUnSorted(Node* head){
    unordered_map<int,Node*> Map;
    /// iterate list and store first appearence
    Node* cur = head;
    Node* temp;
    while(cur!=NULL){
        if ( Map.find( cur->data ) == Map.end() ){
            Map[ cur->data ] = cur;
        }
        cur = cur->next;
    }

    cur = head;
    while(cur!=NULL){
        temp = cur->next;

        while(temp!=NULL && Map[temp->data] != temp ){
            temp = temp->next;
        }

        cur->next = temp;
        cur = temp;
    }

    return head;
}

/// gfg verified
Node* reversePairWise(Node* head){

    if( head==NULL || head->next == NULL )
        return head;

    Node* t1 = head;
    Node* t2 = t1->next;
    Node* prev;
    /// changing the first pair;
    head = t2;
    t1->next = t2->next;
    t2->next = t1;
    /// updates the value of pointers.
    prev = t1;
    if(t1!=NULL)
        t1 = t1->next;
    if(t1!=NULL)
        t2 = t1->next;
    /// while loop changes the rest of pairs.
    while( t1!=NULL && t2!=NULL ){
        /// changing the nodes
        prev->next = t2;
        t1->next = t2->next;
        t2->next = t1;

        prev = t1;
        /// if t1->next is empty we have even list and also we just swapped last pair above.
        if(t1!=NULL)
            t1 = t1->next;
        if(t1!=NULL)
        /// if t2->next is empty we have odd list and also we just swapped last pair above.
            t2 = t1->next;

    }

    return head;
}

/// gfg leet verified idea is simple for unequal length list we traverse larger list by length difference and then traverse them
/// simultaneously
Node* intersectionOfYShapedLL(Node* head1, Node* head2){

    int len1 = lenghtOfList(head1);
    int len2 = lenghtOfList(head2);
    int temp;
    Node* i = head1, *j = head2;

    if( len1 > len2){
        temp = len1 - len2;
        while(temp--)
            i = i->next;
    }
    else{
        temp = len2 - len1;
        while(temp--)
            j = j->next;
    }


    while(i!=NULL){
        if(i == j)
            return i;
        i = i->next; j = j->next;
    }

    return NULL;
}

/// gfg leet verified
Node* rotateListbyK(Node* head,int k,int direction){
        Node* cur = head;
        int length;
        if(head==NULL){
            length = 0;
            return head;
        }
        else
            length = 1;

        k = k%lenghtOfList(head);
            /// this loops finds the length and iterate to last node and make list circular.
        while(1){
            if(cur->next==NULL){
                cur->next = head;
                break;
            }
            length++;
            cur = cur->next;
        }
        /// direction == 0 means clockwise 1 means anti-clockwise
        if(direction == 0){
                /// we break the circular list after length - k iterations.
            for(int i=0;i<length-k;i++){
                cur = cur->next;
            }
            head = cur->next;
            cur->next = NULL;
        }
        else{
            /// we break the circular list after k iterations.
            for(int i=0;i<k;i++){
                cur = cur->next;
            }
            head = cur->next;
            cur->next = NULL;
        }

        return head;
}

Node* part(Node* &head,Node* end=NULL){
    ///cout << "Calling part\n";
    if(head==NULL || head->next == NULL)
        return head;

    Node* d1 = new Node(1),*d2 = new Node(1),*cur = head->next,*pivotNode = head;
    Node* i = d1, *j = d2; int pivot = head->data;
    head->next = NULL;

    while(cur!=end){
        if( cur->data < pivot){
            i->next = cur;
            cur = cur->next;
            i = i->next;
            i->next = NULL;
        }
        else{
            j->next = cur;
            cur = cur->next;
            j = j->next;
            j->next = NULL;
        }
    }


    j->next = cur;
    i->next = head;
    i = i->next;
    i->next = d2->next;
    head = d1->next;

    d1->next = NULL;
    d2->next = NULL;

    return pivotNode;
}

/// gfg leetcode verified
Node* quickSort(Node* head,Node* end=NULL){

    if( head==NULL || head==end)
        return head;

    Node* pivot = part(head,end);

    Node* head2 = pivot->next;
    pivot->next = NULL;

    head = quickSort(head,pivot);
    pivot->next = quickSort(head2);

    print(head);

    return head;
}

/// gfg verified
void segregateEvenOdd(Node* &head){
    if(head==NULL || head->next == NULL)
        return ;

    Node* d1 = new Node(1),*d2 = new Node(1),*cur = head;
    Node* i = d1, *j = d2;

    while(cur!=NULL){
        if( (cur->data)%2 == 0 ){
            i->next = cur;
            cur = cur->next;
            i = i->next;
            i->next = NULL;
        }
        else{
            j->next = cur;
            cur = cur->next;
            j = j->next;
            j->next = NULL;
        }
    }
    /// even list is empty
    if( i == d1 )
        head = d2->next;
    else{
        head = d1->next;
        i->next = d2->next;
    }

    d1->next = NULL;
    d2->next = NULL;

}

/// gfg verified
Node* reverseList(Node*head){
    if(head == NULL)
        return head;
    Node* pre = NULL;
    Node* cur = head;
    Node* nxt = head->next;

    while(1){
        /// end of linked list
        if( nxt == NULL ){
            cur->next = pre;
            head = cur;
            break;
        }
        cur->next = pre;
        pre = cur;
        pre = cur;
        cur = nxt;
        nxt = nxt->next;
    }

    return head;
}

/// gfg leetcode verified idea is to reverse sublist of size k and then attach them
Node* reverseListByK(Node* head,int k){
    if(head == NULL)
        return head;

    Node* pre = NULL;
    Node* cur = head;
    Node* nxt = head->next;
    Node* pretail =head, *tail; /// we use pretail and tail to attach sublists

    /// reverse first sub list
    for(int i=1;i<=k;i++){

        if( nxt == NULL ){
            cur->next = pre;
            head = cur;
            break;
        }
        cur->next = pre;

        if( i==k ){
            head = cur;
            break;
        }

        pre = cur;
        cur = nxt;
        nxt = nxt->next;
    }

    while(nxt!=NULL){
        pre = NULL;
        cur = nxt;
        tail = cur;
        nxt = nxt->next;
        /// reverse the sublist of size k
        for(int i=1;i<=k;i++){

            if( nxt == NULL ){
                cur->next = pre;
                pretail->next = cur;
                break;
            }
            cur->next = pre;

            if( i==k ){
                pretail->next = cur;
                break;
            }

            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        pretail = tail;
    }

    return head;
}

/// gfg  verified
bool isPalindrome(Node *head){
    if(head->next == NULL)
        return true;
    Node* mid = midOfLinkedList2(head); /// because we need former element
    mid->next =  reverseList(mid->next);

    Node* i = head;
    Node* j = mid->next;


    while( j!=NULL ){
        if( i->data !=j->data )
            return false;
        i = i->next; j = j->next;
    }

    return true;
}

/// gfg leet verified
/// merge two sorted linked lists
Node* sortedMerge(Node* head1,   Node* head2){

    Node* i = head1;
    Node* j = head2;
    Node* k = NULL;

    while(i!=NULL && j!=NULL){
        if(i->data < j->data){
            if(k==NULL)
                k = i;
            else{
                k->next = i;
                k = k->next;
            }
            i = i->next;

        }
        else{
            if(k==NULL){
                head1 = j;
                k = j;
            }
            else{
                k->next = j;
                k = k->next;
            }
            j=j->next;
        }
    }

    if(i==NULL){
        if( k == NULL )
            head1 = j;
        else
            k->next = j;
    }


    if(j==NULL && k!=NULL){
        k->next = i;
    }
    return head1;
}

/// gfg verified
Node* mergeSort(Node* head){
    if( head == NULL || head->next == NULL )
        return head;

    Node* mid = midOfLinkedList2(head), * head2 = NULL;

    head2 = mid->next;
    mid->next = NULL;

    head = mergeSort(head);
    head2 = mergeSort(head2);

    return sortedMerge(head,head2);

}

/// gfg verified
Node* deleteNodeHavingGreterValueRight(Node* head){
    Node* cur;
    Node* reversed = reverseList(head),*d = new Node(1),*j;
    cur = reversed; j = d;
    int max_ = reversed->data;

    while(cur!=NULL){
        if( (cur->data) >= max_){
            max_ = cur->data;
            j->next = cur;
            cur = cur->next;
            j = j->next;
            j->next = NULL;
        }
        else
            cur = cur->next;

    }

    return reverseList(d->next);
    d->next = NULL;
}

Node* deleteN_NodesAfterM_Nodes(Node* head,int n,int m){
    Node* cur = head,*j;

    while( cur!=NULL ){

        for(int i=1; cur!=NULL && i<=m-1;i++)
            cur = cur->next;
        if( cur==NULL )
            break;
        j = cur->next;
        for(int i=1;j!=NULL && i<=n;i++)
            j = j->next;

        cur->next = j;
        cur = cur->next;
    }

    return head;
}

/// gfg verified arrange list in such a way that N1->N2->N3............NM becomes N1->NM - > N2->N(M-1) -> N3 -> so on
Node* reorderList(Node* head){

    Node* mid = midOfLinkedList2(head);
    Node* head2 = mid->next;
    mid->next = NULL;

    head2 = reverseList(head2);

    Node* i = head,*next_i = head->next;
    Node* j = head2, *next_j = head2->next;

    while(i!=NULL || j!=NULL){
        if( i!=NULL )
            i->next = j;
        i = next_i;
        if( i!=NULL )
            next_i = i->next;
        if( j!=NULL )
            j->next = i;
        j = next_j;
        if(j!=NULL)
            next_j = j->next;
    }

    return head;
}

/// gfg leet verified
Node* rearrangeEvenOddPlacedTogether(Node* head){
    if(head==NULL || head->next == NULL)
        return head;
    Node* d1 = new Node(1), *d2 = new Node(1);
    Node *i = d1,*j = d2;
    bool flag = 1;

    while(head!=NULL){
        if(flag){
            i->next = head;
            head = head->next;
            i = i->next;
            i->next = NULL;
        }
        else{
            j->next = head;
            head = head->next;
            j = j->next;
            j->next = NULL;
        }
        flag = !flag;
    }

    i->next = d2->next;
    return d1->next;
}

/// gfg verified
Node* intersectionOfTwoLists(Node* head1,Node* head2){
    unordered_map<int,bool> Map;

    while(head2!=NULL){
        Map[head2->data] = 1;
        head2 = head2->next;
    }

    Node* d = new Node(1);
    Node* i = d;

    while(head1!=NULL){
        if( Map.find(head1->data) !=Map.end()){
            i->next = head1;
            head1 = head1->next;
            i = i->next;
            i->next = NULL;
        }
        else
            head1 = head1->next;
    }

    return d->next;
}

/// gfg leet verified
/// we are given k lists that are sorted and we need to merge them
Node* mergeKListIntoSorted(Node* arr[],int n){
    Node* res = NULL;

    for(int i=0;i<n;i++)
        res = sortedMerge(res,arr[i]);

    return res;
}

int main() {
    Node* head1 = NULL,*head2 = NULL;

    insertBack(head1,1);
    insertBack(head1,2);
    insertBack(head1,3);
    insertBack(head1,4);
    insertBack(head1,3);
    insertBack(head1,8);

    insertBack(head2,1);
    insertBack(head2,2);
    insertBack(head2,8);
    insertBack(head2,6);


    Node* res = intersectionOfTwoLists(head1,head2);
    print(res);
    return 0;
}
