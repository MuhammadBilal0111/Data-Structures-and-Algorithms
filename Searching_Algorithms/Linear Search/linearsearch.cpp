#include<iostream>
using namespace std;
// time complexity is O(n)
// n is the size of array
int linearSearch(int arr[],int n,int key){
    int i=0;
    while(i<n){
        if(arr[i]==key){
            return i;
        }
        i++;
    }
    return -1;
}
int main()
{
    int n;//size of array
    cin>>n;
    int *arr=new int[n]; //take memory from heap
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<"the index of "<<key << "in given array is "<<linearSearch(arr,n,key);
    return 0;
}