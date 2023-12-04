#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string digits,string output,int index,vector<string> &ans,string mapping[]){
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    int number=digits[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        output.pop_back();
    }
}
vector<string> letterCombination(string digits){
    vector<string> ans;
    if(digits==""){
        return ans; 
    }
    string output;
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,mapping);
    return ans;
}
int main()
{
    vector<string>arr=letterCombination("89");
    cout<<"[";
    for(int i=0;i<arr.size();i++){
        if(arr[i]==arr[arr.size()-1]){
            cout<<arr[i]<<"";
        }
        else{
            cout<<arr[i]<<", ";

        }
    }
    cout<<"]";
    
    return 0;
}