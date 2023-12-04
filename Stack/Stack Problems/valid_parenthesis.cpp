// Time complexity : O(n)
// Space Complexity (best) : O(1)
// Space complexity (worst) : O(n)
#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string expression){
    stack<char>s;
    for (int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        // if opening bracket, push in stack
        if(ch == '{' || ch == '[' || ch=='('){
            s.push(ch);
        }
        else{
            // for closing bracket
            if(!s.empty()){
                char top = s.top();
                if(
                    (ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')
                )
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
}
int main()
{
    cout<<isValidParenthesis("[{()}]");
    
    return 0;
}