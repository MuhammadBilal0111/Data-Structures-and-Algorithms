#include<iostream>
using namespace std;
int binary_search(int arr[],int key,int n){
    int s=0;
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
int main(){
    int n;
    cin>>n;
    int arr[n];
    int key;
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    cin>>key;
    cout<<binary_search(arr,key,n);
    return 0;
}