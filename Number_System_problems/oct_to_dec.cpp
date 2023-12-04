#include<iostream>
using namespace std;
int bin_to_oct(int n){
    int x=1;
    int ans=0;
    while(n>0){
        int lstdigit=n%10;
        ans=ans+(lstdigit*x);
        x=x*8;
        n=n/10;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<bin_to_oct(n)<<endl;
    return 0;
}