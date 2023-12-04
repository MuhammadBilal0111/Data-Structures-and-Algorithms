// Time Complexity : O(n)
// space Complexity : O(n)
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> & myStack, int element){

    // base Condition
    if(myStack.empty()){
        myStack.push(element);
        return ;
    }
    int num = myStack.top();
    myStack.pop();

    // recursive call
    insertAtBottom(myStack, element);
    myStack.push(num);
}

void reverseStack(stack<int> & myStack){

    // base condition
    if(myStack.empty()){
        return ;
    }

    int num = myStack.top();
    myStack.pop();

    // recursive call
    reverseStack(myStack);
    insertAtBottom(myStack, num);
}
int main()
{
    stack<int>s;
    s.push(5);
    s.push(9);
    s.push(12);
    s.push(8);
    s.push(4);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}