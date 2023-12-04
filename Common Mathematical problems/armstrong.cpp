#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int orig_n=n;
    while(n>0){
        int lastdigit=n%10;
        sum=sum+pow(lastdigit,3);
        n=n/10;
    }
    if(orig_n==sum){
        cout<<"Armstrong"<<endl;
    }
    else{
        cout<<"Not a Armstrong"<<endl;
    }

    return 0;
}