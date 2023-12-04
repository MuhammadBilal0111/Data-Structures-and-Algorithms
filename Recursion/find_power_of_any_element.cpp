#include<iostream>
using namespace std;
int pow(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==0){
        return a;
    }
    int ans=pow(a,b/2);
    if(b%2==0){
        return ans * ans;
    }
    else{
        return a*(ans*ans);
    }
}
int main()
{
    cout<<pow(2,4);

    return 0;
}