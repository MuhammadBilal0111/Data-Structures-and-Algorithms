#include <iostream>
#include<climits>
using namespace std;
void swap_0s_1s(int *arr,int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==0){
            i++;
        }
        else{
            swap(arr[i],arr[j]);
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int n=8;
    int *arr=new int[n]{1,1,0,0,0,0,1,0};
    swap_0s_1s(arr,n);
    

    return 0;
}