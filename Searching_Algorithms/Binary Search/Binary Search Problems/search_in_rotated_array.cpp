#include<iostream>
using namespace std;
int findPivot(int *arr,int n){
    int s=0;
    int e=n-1;
    int result;
    while(s<e){
        int mid=(s+e)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}
int binary_search(int arr[],int key,int pivot,int n){
    int s=pivot;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int main()
{
    int m=5;
    int target=2;
    int *arr=new int[m]{7,9,1,2,3};
    int p=findPivot(arr,m);
    if(target>arr[p] && target<=arr[m-1]){
        cout<<binary_search(arr,target,p,m-1);
    }
    else{
        cout<<binary_search(arr,target,0,p-1);
    }
    return 0;
}