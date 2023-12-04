#include<iostream>
using namespace std;
int fact(int n){
    int fac=1;
    int i=1;
    while(i<=n){
        fac=fac*i;
        i++;
    }
    return fac;
}
int main()
{
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<fact(i)/(fact(j)*fact(i-j));
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}