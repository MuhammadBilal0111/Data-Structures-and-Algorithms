#include<iostream>
using namespace std;
int bin_to_hex(string s){
    int ans=0;
    int x=1;
    int strlength=s.size();
    for(int i=strlength-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            ans=ans+(x*(s[i]-'0'));
        }
        else if(s[i]>='A' && s[i]<='F'){
            ans=ans+((x*(s[i]-'A')+10));
        }
        x=x*16; 
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    cout<<bin_to_hex(str);
    return 0;
}