#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void printsQueue(queue<int> q){
    ///prints queue.
    while(!q.empty()){
        cout<<q.front() <<" ";
        q.pop();
    }
}
/// function interleaves queue.
void interleaveQueue(queue<int>* q){
    stack<int> s;
    int x = (*q).size();
    /// initial queue 1 2 3 4 5 6
    /// moving first half back to queue.
    /// 4 5 6 1 2 3
    for(int i=0;i<x/2;i++){
        (*q).push((*q).front());
        (*q).pop();
    }
    /// putting first half into stack.
    /// stack : 6(top) 5 4 and queue : 1 2 3
    for(int i=0;i<x/2;i++){
        s.push((*q).front());
        (*q).pop();
    }
    /// enqueue stack elements to queue.
    /// stack : empty queue : 1 2 3 6 5 4
    while(!s.empty()){
        (*q).push(s.top());
        s.pop();
    }
    /// again moving first half back to queue.
    /// 6 5 4 1 2 3
    for(int i=0;i<x/2;i++){
        (*q).push((*q).front());
        (*q).pop();
    }
    /// putting first half into stack.
    /// stack : 4(top) 5 6 and queue : 1 2 3
    for(int i=0;i<x/2;i++){
        s.push((*q).front());
        (*q).pop();
    }
    /// now we first push front element back to queue then we push stack element to queue.
    while(!s.empty()){
        (*q).push((*q).front());
        (*q).pop();
        (*q).push(s.top());
        s.pop();

    }
}
int main()
{
    queue<int> q;
    stack<int> s;
    int x;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    interleaveQueue(&q);
    printsQueue(q);

    return 0;
}
