// Time Complexity : O(n) due to while loop in main()
// Space complexity : O(n)

#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> & myStack, int x){

    // base condition
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }
    int num = myStack.top();
    myStack.pop();

    // recursive call
    solve(myStack,x);
    myStack.push(num);
}
stack<int> addElementAtBottom(stack<int> & myStack, int x){
    solve(myStack,x);
    return myStack;
}
int main()
{
    stack<int>s;
    s.push(5);
    s.push(9);
    s.push(12);
    s.push(8);
    s.push(4);
    s=addElementAtBottom(s,56);
    cout<<"After adding element at bottom"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}