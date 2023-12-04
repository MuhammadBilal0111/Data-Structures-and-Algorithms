// Time Complexity : O(logn)
// The space complexity of the provided code is O(1), which means it uses a constant amount of memory regardless of the input size.
#include <iostream>
using namespace std;
int left_occurance(int arr[],int key,int n){
    int s=0;
    int e=n-1;
    int leftoutermost=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            leftoutermost=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return leftoutermost;
}
int right_occurance(int arr[],int key,int n){
    int s=0;
    int e=n-1;
    int rightoutermost=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            rightoutermost=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return rightoutermost;
}

int main(){
    int n=11;
    int arr[n]={2,5,5,5,6,6,8,9,9,9,9};
    int key=8;
    
    if((left_occurance(arr,key,n)) && (right_occurance(arr,key,n)==-1)){
        cout<<"Element not found";
    }
    else{
        cout<<"The number of occurances of "<<key<<" is "<<right_occurance(arr,key,n)-left_occurance(arr,key,n)+1<<endl;
    }
    
    return 0;
}