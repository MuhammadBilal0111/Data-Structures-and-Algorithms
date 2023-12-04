

#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &inputStack, int count, int size){
    // base condition
    if(count == size/2){
        inputStack.pop();
        return ;
    }
    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    solve(inputStack, count+1, size);
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N){
    int count = 0;
    solve(inputStack, count, N);
}
int main()
{
    stack<int>s;
    s.push(5);
    s.push(9);
    s.push(12);
    s.push(8);
    s.push(4);
    deleteMiddle(s,5);
    cout<<"After deleting middle element of stack"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}