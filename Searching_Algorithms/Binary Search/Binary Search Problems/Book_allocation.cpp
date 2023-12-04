#include<iostream>
using namespace std;
bool ispossible(int *arr,int n,int m,int mid){
    int pgsum=0;
    int std=1;
    for(int i=0;i<n;i++){
        if(pgsum+arr[i]<=mid){
            pgsum+=arr[i];
        }
        else{
            std++;
            if(std>m || pgsum>mid){
                return false;
            }
            pgsum=arr[i];
        }
    }
    return true;
}

int book_allocation(int *arr,int n, int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int s=0;
    int e=sum;
    int ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(ispossible(arr,n,m,mid)){
            e=mid-1;
            ans=mid;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n=4;
    int *arr=new int[n]{10,20,30,40};
    cout<<book_allocation(arr,n,2);
    return 0;
}