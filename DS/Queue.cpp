#include<iostream>
#include<queue>
using namespace std;

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() <<" ";
        q.pop();
    }
    cout <<"\n";
}

void reverseQueue(queue<int> &q){
    if(q.empty())
        return;
    int front = q.front(); q.pop();
    reverseQueue(q);
    q.push(front);
}
void insertMinToRear(queue<int> &q,int min_index){
    int n = q.size();
    int temp,min;
    for(int i=0;i<n;i++){
        temp = q.front(); q.pop();
        if(i!=min_index)
            q.push(temp);
        else
            min = temp;
    }
    q.push(min);
}
int findMinIndex(queue<int> q,int n){
    int min=INT_MAX,min_index,temp;
    for(int i=0;i<n;i++){
        temp = q.front(); q.pop();
        if(temp < min){
            min_index = i;
            min = temp;
        }
    }
    return min_index;
}
void sortQueue(queue<int> &q){
    int n = q.size(),min_index;
    for(int i=0;i<n;i++){
        min_index = findMinIndex(q,n-i);
        insertMinToRear(q,min_index);
    }
}
int main(){
    queue<int> q;
    int n,temp;
    cin >> n;
    while(n--){
        cin >> temp;
        q.push(temp);
    }
    reverseQueue(q);
    printQueue(q);
    return 0;
}
