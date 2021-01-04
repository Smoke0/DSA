/// Successful implement of linked list in c.
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

typedef struct node{  /// List is a compound data type so implemented using structure we also defined struct as
  int val;            /// a user defined data type using typedef.
  struct node *next;
}n;

n* head=NULL;

void add(n** hpt,int x)  /// adds items to end of list. // This fn works perfectly.
{
        if(*hpt==NULL)
        {
            (*hpt)=(n*)malloc(sizeof(n));
            (*hpt)->val=x;
            (*hpt)->next=NULL;
        }
        else
        {
            n* cur=*hpt;
            while(cur->next!=NULL)
            {
                cur=cur->next;
            }
            cur->next=(n*)malloc(sizeof(n));
            cur->next->val=x;
            cur->next->next=NULL;
        }
}

void push(n** hpt,int x)            /// pushing an item to front of list. // This fn works perfectly.
{
    n* new_head;
    new_head=(n*)malloc(sizeof(n));
    new_head->val=x;
    new_head->next=(*hpt);
    (*hpt)=new_head;
}

int del_b(n** hpt)               /// it works for more than one items. it has a bug with removal of one item.
{
    n* cur=*hpt;
    int removed;
    if ((*hpt)==NULL)
        cout<<"List is empty"<<endl;

    if((*hpt)->next==NULL)  ///removes if only one item is present
    {
        removed=(*hpt)->val;
        free((*hpt));

    }

              /// removes if there are more than one items
    while(cur->next->next!=NULL)
    cur=cur->next;
    removed=cur->next->val;
    free(cur->next);
    cur->next=NULL;
    cout<<"The "<<removed<<" was removed"<<endl;
}

void del_f(n** hpt)            /// it has a little bug if list is empty.
{
    int rem;
    n* new_head;

    if((*hpt)==NULL)
    {
        cout<<"List is empty"<<endl;
    }


    rem=(*hpt)->val;
    new_head=(*hpt)->next;
    free((*hpt));
    *hpt=new_head;
    cout<<rem<<" was removed"<<endl;
}

void print(n* head)               /// This fn works perfectly.
{
    n* cur = head;
    if(head==NULL)
        cout<<"List is empty"<<endl;
    while(cur!=NULL)
    {
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    cout<<"\n";
}
/// gfg verified
/// reverse linked list in O(N) time. uses three pointers t1 t2 t3 for doing so
/// t2-> next is reversed to t1 and t3 is for proceding in linked list and at the end head is placed to last element.
n* reverseList(n *head)
{
    n* pre = NULL;
    n* cur = head;
    n* nxt = head->next;

    while(1){
        /// end of linked list
        if( nxt == NULL ){
            cur->next = pre;
            head = cur;
            break;
        }
        cur->next = pre;
        pre = cur;
        cur = nxt;
        nxt = nxt->next;
    }

    return head;

}
/// function worls perfectly
/// it reverses the linked list pair wise like 1 2 3 4 would become 2 1 4 3
/// this loop changes data not the nodes.
void reversePairWise_data(n** head){
    n* t1 = *head;
    n* t2 = t1->next;
    int temp;

    while(1){
    /// here we are basically swapping the values pointed by t1 and t2.
    temp = t1->val;
    t1->val = t2->val;
    t2->val = temp;

    /// and then we just update values of pointer.
    t1 = t2->next;
    if(t1==NULL)
        break;

    t2 = t1->next;
    if(t2==NULL)
        break;
    }
}
/// this function actually swaps nodes instead of changing data
/// swapping data is costly under condition that nodes have multiple values.
void reversePairWise(n** head){
    /// Initialize three temp pointers.
    n* t1 = *head;
    n* t2 = t1->next;
    n* prev;
    /// changing the first pair;
    *head = t2;
    t1->next = t2->next;
    t2->next = t1;
    /// updates the value of pointers.
    prev = t1;
    t1 = t1->next;
    t2 = t1->next;
    /// while loop changes the rest of pairs.
    while(1){
        /// changing the nodes
        prev->next = t2;
        t1->next = t2->next;
        t2->next = t1;

        prev = t1;
        /// if t1->next is empty we have even list and also we just swapped last pair above.
        t1 = t1->next;
        if(t1==NULL)
            break;
        /// if t2->next is empty we have odd list and also we just swapped last pair above.
        t2 = t1->next;
        if(t2==NULL)
            break;

    }
}
/// This function removes the duplicate elements from the list.
void removeDuplicateSorted(n** head){
    /// Initialize t1 and t2.
    n* t1 = *head;
    n* t2 = t1->next;
    /// Iterates the list finds and delete the duplicates.
    while(t2!=NULL){
        /// if t1 and t2 value match means there is duplicate pointed by t2 and remove t2
        /// and update elemets accordingly.
        if(t1->val==t2->val){
            t1->next = t2->next;
            free(t2);
            t2 = t1->next;
        }
    /// if they don't match proceed.
        else{
            t1 = t2;
            t2 = t2->next;
        }
    }
}
bool inVector(vector<int> arr,int value){
    bool flag = false;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==value){
            flag = true;
            break;
        }
    }
    return flag;
}
/// this method removed duplicate in unsorted list.
/// this is inefficient method better method uses hashing implementing soon;
void removeDuplicateUnSorted(n** head){
    n* t1;
    n* t2 = *head;
    vector<int> arr; /// vector keeping distinct elements.

    while(t2!=NULL){
        /// if duplicate element is found then remove it.
        /// t2 is pointer scanning the list and t1 is pointer just behind the t2 so we can delete elements
        /// whenever we want.
        if(inVector(arr,t2->val)){
            t1->next = t2->next;
            free(t2);
            t2 = t1->next;
        }
        else{
            arr.push_back(t2->val);  /// we only push into vector if element is distinct.
            t1 = t2;
            t2 = t2->next;
        }
    }
}

/// this function arranges the even and odd number in list alternatively
void arrangeOddEvenAlternately(n** head){
    n* t1 = *head;
    n* t2 = t1->next;
    bool z;
    int temp;
    while(t2!=NULL){
            /// this z values determines whether two adjacent numbers are even even or odd odd or odd even.
        z = (t1->val%2)^(t2->val%2);
        /// if z=0 then they are same(either both odd or even) then we need to swap them else we need to skip.
        if(z==0){
                ///cout<<"If statement\n";
            while(t2->next!=NULL){
                t2 = t2->next;
                if((t1->val%2)^(t2->val%2)){
                    /// just swapping values of elements
                    temp = t1->next->val;
                    t1->next->val = t2->val;
                    t2->val = temp;
                    /// incrementing them accordingly.
                    t1 = t1->next;
                    t2 = t1->next;
                    break;
                }
            }
        }
        else{
                ///cout<<"ELSE statement\n";
            /// if they are already alternate we need to just increment the pointer.
            t1 = t2;
            t2 = t2->next;
        }
    }
}
/// this function delete alternate nodes by using a flag.
void deleteAlternate(n** head){
    n* t1 = *head;
    n* t2 = t1->next;
    bool flag = true;

    while(t2!=NULL){
        if(flag){
            t1->next = t2->next;
            free(t2);
            t1 = t1->next;
            if(t1==NULL)
                break;
            t2 = t1->next;
            flag = false;
        }
        else{
            flag = true;
        }
    }


}
/// this function rotates list by k nodes.
void rotateList(n** head,int k,int direction){
        n* cur = *head;
        int length;
        if(*head==NULL)
            length = 0;
        else
            length = 1;
            /// this loops finds the length and iterate to last node and make list circular.
        while(1){
            if(cur->next==NULL){
                cur->next = *head;
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
            *head = cur->next;
            cur->next = NULL;
        }
        else{
            /// we break the circular list after k iterations.
            for(int i=0;i<k;i++){
                cur = cur->next;
            }
            *head = cur->next;
            cur->next = NULL;
        }
}


/// this function merges two sorted list such that resulted list is also sorted.
/// this function mimics the merge function in merge sort.
n* mergeSorted(n* head_1,n* head_2){
    n* sorted = NULL;
    n* cur = head_1;
    n* cur_2 = head_2;

    while(1){
        if(cur->val > cur_2->val){
                ///cout<<"IF statement\n";
            add(&sorted,cur_2->val);
            cur_2 = cur_2->next;
            if(cur_2==0)
                break;
        }
        else{
            ///cout<<"ELSE statement\n";
            add(&sorted,cur->val);
            cur = cur->next;
            if(cur==0)
                break;
        }
    }

    while(cur!=NULL){
        ///cout<<"1st While\n";
        add(&sorted,cur->val);
            cur = cur->next;
    }
    while(cur_2!=NULL){
        ///cout<<"2nd While\n";
        add(&sorted,cur_2->val);
            cur_2 = cur_2->next;
    }
    return sorted;
}

/// gfg verified
/// this function finds the middle of linked list using fast and slow pointer.
/// this function return mid node.
n* findMiddle(n* head){
    n* slow = head;
    n* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}
/// this is implementation of merge sort.
void mergeSort(n** head){
    n* a = *head;
    n* b;
    n* temp;
    /// base case
    if(a==NULL || a->next == NULL){
        return;
    }
    /// temp is pointer to mid node we split the list into first node to mid node(including) and rest of nodes.
    temp = findMiddle(a);
    b = temp->next;
    temp->next = NULL;
    /// then we call merge sort recursively on two halfes.
    mergeSort(&a);
    mergeSort(&b);
    /// at end we merge the list into sorted order.
    *head = mergeSorted(a,b);

}
/// this function reverse list in group sizes of k.
/// basic idea here is to reverse sub lists of k size and attach these reversed sub list together.
void reverse_kSizeList(n** head, int k){
    /// ruling out -ve zero and 1 value of k.
    if(k<2){
        cout<<"The Value of k must be greater than 1\n";
        return;
    }
    /// we take three pointers t1 t2 t3 to reverse list s1 and s2 are used for attaching alternate sub lists.
    n* t1 = *head;
    n* t2 = t1->next;
    n* t3 = t2->next;
    /// s1 is pointed to first element of list which will become last element in reversed list.
    n* s1 = *head;
    n* s2;
    /// the first for loop reverses and handles all cases of reversing first sub list
    for(int i=1;i<=k-1;i++){
            /// t2==0 means list is smaller or equal to k.
            if(t2==0)
                break;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
        if(t3!=0)
            t3 = t3->next;
    }

    *head = t1;
    s1->next = NULL;
    /// if t2 is 0 then we reached end of list.
    if(t2==0)
        return ;
    /// set pointer to next sub list.
    t1 = t2;
    s2 = t1;
    t2 = t3;
    if(t3!=0)
        t3 = t3->next;
    /// this loop reverses and attaches all other sub list of size k.
    while(1){
            bool last = false; /// variable last indicate end of list.
        /// this loop reverses list of size k.
        for(int i=1;i<=k;i++){
            /// t2 = 0 means we are at end of list.
            if(t2==0){
            s1->next = t1;
            s1 = s2;
            s1->next = 0;
            last = true;
            break;
            }
            /// loop is done reversing sublist of size k.
            if(i==k){
            s1->next = t1;
            s1 = s2;
            s1->next = 0;
            break;
            }
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            if(t3!=0)
                t3 = t3->next;
        }
        if(last)        /// break loop if we are at last of list.
            break;
        /// else move to next sublist.
        else{
            t1 = t2;
            s2 = t1;
            t2 = t3;
            if(t3!=0)
                t3 = t3->next;
        }
    }
}
/// this function swaps nodes with a given keys x1 and x2.
void swapNodes(n** head,int x1,int x2){
    n* t1 = *head;
    n* t2 = *head;
    n* p1 = NULL;
    n* p2 = NULL;
    n* n1;
    n* n2;
    bool flag_1=false,flag_2=false;
    int count_1 = 0, count_2 = 0;
    /// We iterate to node having key x1.
    while(t1!=NULL){
        count_1++;
        if(t1->val==x1){
            flag_1 = true;
            break;
        }
        p1 = t1;
        t1 = t1->next;
    }
    /// We iterate to node having key x2.
    while(t2!=NULL){
            count_2++;
        if(t2->val==x2){
            flag_2 = true;
            break;
        }
        p2 = t2;
        t2 = t2->next;
    }
    if(flag_1 == 0 || flag_2 ==0){
        cout<<"Key Not Found!\n";
        return;
    }
    /// function assumes t1 appearing before t2 so if doesn't we swap them.
    if(count_1 > count_2){
        n* temp = t1;
        t1 = t2;
        t2 = temp;
        temp = p1;
        p1 = p2;
        p2 = temp;
    }
    n1 = t1->next;
    n2 = t2->next;
        /// t1 is head and they are adjacent.
      if(*head == t1 && p2 == t1){
        t1->next = n2;
        *head = t2;
        t2->next = p2;
     }
     /// t1 is head and they aren't  adjacent.
     else if(*head == t1){
        t1->next = n2;
        *head = t2;
        p2->next = t1;
        t2->next = n1;
     }
     /// nodes are adjacent to each other.
     else if(p2 == t1){
        t1->next = n2;
        p1->next = t2;
        t2->next = p2;
     }
     /// if they are same we do nothing.
     else if(t1==t2){
        return;
     }
     /// niether nodes are adjacent nor head.
     else {
        t1->next = n2;
        p1->next = t2;
        p2->next = t1;
        t2->next = n1;
     }

}

/// gfg leetcode verified
bool isPalindrome(n *head)
{
    if(head->next == NULL)
        return true;

    n* mid = findMiddle(head);
    mid->next =  reverseList(mid->next);

    n* i = head;
    n* j = mid->next;


    while( j!=NULL ){
        if( i->val !=j->val)
            return false;
        i = i->next; j = j->next;
    }

    return true;
}

int main()
{

    add(&head,1);
    //add(&head,2);
    //add(&head,3);
    //add(&head,4);
    //add(&head,5);
    //intsertionSort(&head);

    n* mid = findMiddle(head);
    cout << mid->val << "\n";
    mid->next =  reverseList(mid->next);
    print(head);
    return 0;
}

