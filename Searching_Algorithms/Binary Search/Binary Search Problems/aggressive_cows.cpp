#include <iostream>
using namespace std;
bool ispossible(int *arr,int n,int mid,int k){
    int countcow=1;
    int lastpos=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-lastpos>=mid){
            countcow++;
            if(countcow==k){
                return true;
            }
            lastpos=arr[i];
        }
    }
    return false;
}
int aggressive_cow(int *arr,int n,int k){
    int s=0;
    int mx=-1;
    int ans;
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
    }
    int e=mx;
    while(s<=e){
        int mid=(s+e)/2;
        if(ispossible(arr,n,mid,k)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main() {
    int n=5;
    int k=2;
    int *arr=new int[n]{1,2,3,4,6};
    cout<<aggressive_cow(arr,n,k);

    return 0;
}