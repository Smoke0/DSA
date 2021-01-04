#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next,*pre;
    Node(int d){
        data = d;
        pre = next = NULL;
    }
};

/// gfg verified
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
void insertBack(Node* &head,int key){
    if(head==NULL){
        head = new Node(key);
        return;
    }
    Node* cur = head;
    Node* temp = new Node(key);

    while(cur->next!=NULL)
        cur = cur->next;

    temp->pre = cur;
    cur->next = temp;
}
/// gfg verified
void deleteFront(Node* &head){
    if(head == NULL || head->next ==NULL){
        head = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    head->pre = NULL;
    temp->next = NULL;

    delete temp;
}
/// gfg verified
void deleteBack(Node* &head){
    if(head == NULL || head->next == NULL){
        head = NULL;
        return;
    }

    Node* prev = NULL,*cur = head;
    while(cur->next!=NULL){
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    cur->pre = NULL;
    delete cur;

}
/// gfg verified
void print(Node* head){
    if(head==NULL)
        cout<<"List is empty"<<endl;
    Node* pre = NULL;
    while(head!=NULL){
        cout<<head->data<<" ";
        pre = head;
        head=head->next;
    }
    cout <<"\n";
}

/// gfg verified
Node* reverseList(Node* head){
if(head==NULL || head->next==NULL)
        return head;
    Node* pre = NULL,*cur = head;

    while(cur!=NULL){
        cur->pre = cur->next;
        cur->next = pre;

        pre = cur;
        cur = cur->pre;
    }

    head = pre;
    return head;
}

/// gfg leet verified
Node* part(Node* &head,Node* end=NULL){
    if(head==NULL || head->next == NULL)
        return head;

    Node* d1 = new Node(1),*d2 = new Node(1),*cur = head->next,*pivotNode = head;
    Node* i = d1, *j = d2; int pivot = head->data;
    head->next = NULL;

    while(cur!=end){
        if( cur->data < pivot){
            i->next = cur;
            cur->pre = i;
            cur = cur->next;
            i = i->next;
            i->next = NULL;
        }
        else{
            j->next = cur;
            cur->pre = j;
            cur = cur->next;
            j = j->next;
            j->next = NULL;
        }
    }


    j->next = cur;
    if(cur!=NULL)
        cur->pre = j;
    i->next = head;
    head->pre = i;
    i = i->next;
    i->next = d2->next;
    if(d2->next!=NULL)
        d2->next->pre = i;
    head = d1->next;
    head->pre = NULL;

    d1->next = NULL;
    d2->next = NULL;

    return pivotNode;
}

/// gfg leet verified
Node* quickSort(Node* head,Node* end=NULL){

    if( head==NULL || head==end || head->next==NULL  )
        return head;

    Node* pivot = part(head,end);

    Node* head2 = pivot->next;
    pivot->next = NULL;
    if(head2!=NULL)
        head2->pre = NULL;
    head = quickSort(head,pivot);
    head2 = quickSort(head2);

    pivot->next = head2;
    if(head2!=NULL)
        head2->pre = pivot;

    return head;
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
                i->pre = k;
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
                j->pre = k;
                k = k->next;
            }
            j=j->next;
        }
    }

    if(i==NULL){
        if( k == NULL )
            head1 = j;
        else{
            k->next = j;
            j->pre = k;
        }

    }

    if(j==NULL && k!=NULL){
        k->next = i;
        i->pre = k;
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
    head2->pre = NULL;

    head = mergeSort(head);
    head2 = mergeSort(head2);

    return sortedMerge(head,head2);

}

int main(){
    Node* head1 = NULL,*head2 = NULL;

    insertBack(head1,1);
    insertBack(head1,3);
    insertBack(head1,5);
    insertBack(head1,7);

    insertBack(head1,2);
    insertBack(head1,4);
    insertBack(head1,6);
    insertBack(head1,8);

    Node* res = mergeSort(head1);
    print(res);
    return 0;
}
