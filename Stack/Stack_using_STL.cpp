#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    // push operation
    s.push(9);
    s.push(8);
    // pop operation remove last element
    s.pop();
    cout<<"The top element is "<<s.top()<<endl;
    if(s.empty()){
        cout << "Stack is empty"<<endl;
    }
    else{
        cout << "Stack is not empty"<<endl;
    }
    cout<<"The size of stack is "<<s.size()<<endl;
    return 0;
}