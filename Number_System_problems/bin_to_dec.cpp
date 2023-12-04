#include<iostream>
using namespace std;
int bin_to_dec(int n){
    int x=1;
    int ans=0;
    while(n>0){
        int lst_digit=n%10;
        ans=ans+(x*lst_digit);
        x=x*2;
        n=n/10;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<bin_to_dec(n)<<endl;
    return 0;
}