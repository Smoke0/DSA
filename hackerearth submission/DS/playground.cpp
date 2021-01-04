#include <iostream>
#include<cstdio>
using namespace std;
int front=0,rear=0;

void in(int queue[], int element, int rear, int arraySize) {
    if(rear == arraySize)
        printf("OverFlow\n");
    else {
        queue[rear] = element;
        rear++;
    }
}
void out(int queue[], int front, int rear) {
    if(front == rear)            // Queue is empty
        printf("UnderFlow\n");
    else {
        queue[front] = 0;        // Delete the front element
        front++;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);
    int queue[10];
    in(queue,10,rear,10);
    out(queue,front,rear);
    cout<<queue[0];

return 0;
}

