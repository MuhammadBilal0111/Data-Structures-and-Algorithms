// Time complexity : O(n*n)
// Space complexity : O(n)

#include<iostream>
#include<stack>
using namespace std;
void solveStack(stack<int> &s, int num){

    // base condition
    if(s.empty() || (s.top()<num)){
        s.push(num);
        return ;
    }
    int n = s.top();
    s.pop();

    // recursive call
    solveStack(s, num);
    s.push(n);
}
void sortStack(stack<int> &s){

    // base condition
    if(s.empty()){
        return ;
    }
    int num = s.top();
    s.pop();

    // recursive call
    sortStack(s);
    solveStack(s,num);
}
int main()
{
    stack<int>s;
    s.push(50);
    s.push(9);
    s.push(12);
    s.push(20);
    s.push(4);
    s.push(40);
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}