// valid only when you have only one element in duplicate
#include<iostream>
using namespace std;
int duplicate_in_array(int *arr,int n){
    int result=0;
    for(int i=0;i<n;i++){
        result^=arr[i];
    }
    for(int i=1;i<n;i++){
        result=result^i;
    }
    return result;
}
int main()
{
    int n=5;
    int *arr=new int[n]{1,2,3,4,3};
    cout<<duplicate_in_array(arr,n);
    return 0;
}
