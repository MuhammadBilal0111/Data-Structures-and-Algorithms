// Time Complexity : O(n)
// space Complexity : O(n)
#include<iostream>
#include<stack>
using namespace std;
bool redundant_brackets(string &s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch =='(' || ch =='+' || ch == '-' || ch =='*' || ch == '/'){
            st.push(s[i]);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if(top == '(' || top =='+' || top == '-' || top =='*' || top == '/'){
                        isRedundant = false;
                }
                st.pop();
            }
            if(isRedundant == true){
                return true;
            }
            st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str="((a+b)/5)";
    cout<<redundant_brackets(str);
    return 0;
}