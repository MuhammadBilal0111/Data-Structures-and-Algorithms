#include<iostream>
using namespace std;
int sqrt(int n){
    int s=0;
    int e=n;
    int result;
    while (s<=e) {
        int mid=(s+e)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            s=mid+1;
            result=mid;
        }
        else{
            e=mid-1;
        }
    }
    return result;
}
double morePrrecision(int n,int p,int tmp){
    double factor=1;
    double ans=tmp;
    for(int i=0;i<p;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main()
{
    int n=6;
    int ans=sqrt(n);
    cout<<ans<<endl;
    cout<<morePrrecision(n,5,ans);
    return 0;
}