#include<iostream>
#include<stack>
using namespace std;

/// this function uses stack to find the count of number of greater element on right.
/// a greater element is an element just greater than current value.
int* no_of_NGE_to_right(int arr[],int n){
    /// a is our array storing count of each element.
    int* a;
    a = (int*)malloc(n*sizeof(int));
    /// we are using stack for storing greater elements.
    stack<int> st;
    st.push(n-1);
    *(a+n-1) = 0;
    /// we start scan from right from 2nd last element
    for(int i = n-2;i>=0;i--){
        while(!st.empty() && arr[i]>arr[st.top()])
            st.pop();
        if(st.empty()){
            *(a+i) = 0;
        }
        else{
            *(a+i) = st.empty() ? 0 : *(a+st.top())+1;
        }

        st.push(i);
    }
    return a;
}
/// this function only uses stack function to sort stack.
void sortStack(stack<int> arr){
    /// we use a temp stack here to where we will place items in sorted order.
    stack<int> temp;
    int x,y;
    /// iterate through orignal stack.
    while(!arr.empty()){
        x = arr.top();
        arr.pop();
        while(!temp.empty() && x>temp.top()){
            y = temp.top();
            temp.pop();
            arr.push(y);
        }
        temp.push(x);
    }
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<"\n";
}
int main()
{
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);
    sortStack(st);

    return 0;
}

