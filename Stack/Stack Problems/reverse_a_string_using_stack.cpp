// Time complexity : O(n)
// Space complexity : O(n)
// where n is the size of string
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string str = "bilal";
    stack<char>s;

    for(int i = 0;i < str.length();i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<ans<<endl;
    return 0;
}