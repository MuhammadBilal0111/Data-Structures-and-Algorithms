#include<iostream>
using namespace std;
int dec_to_bin(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int bit=n&1;
        ans=ans+(bit * x);
        n=n>>1;
        x=x*10;
    }
    return ans;
}
int main()
{
    int n=8;
    cout<<"the binary number of"<<n<<" is"<<dec_to_bin(n);
    return 0;
}