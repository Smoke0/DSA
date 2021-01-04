#include<iostream>
#include<stack>
using namespace std;

void putInBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int top = s.top(); s.pop();
    putInBottom(s,x);
    s.push(top);
}
void reverseStack(stack<int> &s){
    if(s.empty())
        return;
    int top = s.top();s.pop();
    reverseStack(s);
    putInBottom(s,top);
}
void printStack(stack<int> s){
    while(!s.empty()){

        cout << s.top() << "\n";
        s.pop();
    }
    cout << "\n";
}
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
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
class myStack{
    Node* head;
    Node* mid;
    int count;
public:
    myStack(){
        head = mid = NULL;
        count = -1;
    }
    void push(int x){
        if(!head){
        insertBack(head,x);
        mid = head;
        count++;
        }
        else{
            insertBack(head,x);
            count++;
            if(count == 2){
                mid = mid->next;
                count = 0;
            }
        }
    }
    int midElement(){
        return mid->data;
    }
};
/// not verified but passed test cases on coding blocks.
bool isDuplicateParanthesis(string str){
    bool flag = false;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            s.push(str[i]);
            if(flag)
                flag = false;
        }
        else if(str[i] ==')'){
            if(s.top()=='e'){
                s.pop(); s.pop(); flag = false;
            }
            else
                return true;
        }
        else if(!flag){
            flag = true;
            s.push('e');
        }
    }
    return false;
}
int main(){
    stack<int> s;
    int n,temp;
    cin >> n;
    while(n--){
        cin >> temp;
        s.push(temp);
    }
    reverseStack(s);
    printStack(s);
    return 0;
}
