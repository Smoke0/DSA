#include <iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

typedef struct node{
    int data;
    struct node* next;
}Node;

void insertNode(Node **head, int x){
    Node *temp;
    Node *cur;
    if(*head==NULL){
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = x;
        (*head)->next = *head;
    }
    else{
        temp = (Node*)malloc(sizeof(Node));
        temp->data = x;
        cur = *head;
        while(cur->next != *head){
            cur = cur->next;
        }
        cur->next = temp;
        temp ->next = *head;
    }
}
void printCircularList(Node *head){
    Node* cur = head;
    do{
        cout << cur->data << " ";
        cur = cur->next;
    }while(cur !=head);
    cout <<"\n";
}
void printMidOfList(Node *head){
    Node *slow = head;
    Node *fast = head;
    do{
        fast = fast->next->next;
        slow = slow->next;
        if(fast->next ==head)
            break;
        if(fast==head)
            break;
    }while(1);
    cout << slow->data <<"\n";
}

int main() {
    Node *head = NULL;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);
    insertNode(&head,6);
    printCircularList(head);
    printMidOfList(head);
	return 0;
}
