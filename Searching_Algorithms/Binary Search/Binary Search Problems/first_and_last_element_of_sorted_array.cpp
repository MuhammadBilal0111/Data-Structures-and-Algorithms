// The time complexity is O(log n), and the space complexity is O(n) due to the array.
#include<iostream>
using namespace std;
int first_element(int *arr,int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int last_element(int *arr,int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n=5;
    int key=3;
    int *arr=new int[n]{1,2,3,3,7};
    cout<<"The first and last occurance of "<<key<<" are "<<first_element(arr,n,key)<<" "<<last_element(arr,n,key)<<" respextively"<<endl;
    return 0;
}