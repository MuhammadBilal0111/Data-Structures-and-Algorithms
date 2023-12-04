#include<iostream>
using namespace std;
int factorial(int n){
    int fact=1;
    int i=1;
    while(i<=n){
        fact=fact*i;
        i=i+1;
    }
    return fact;
}
int main()
{
    int n,r;
    cin>>n>>r;
    int nCr=(factorial(n))/(factorial(n-r)*factorial(r));
    cout<<nCr;
    return 0;
}