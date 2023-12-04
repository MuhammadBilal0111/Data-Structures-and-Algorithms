// the time complexity is O(n/2), which is commonly simplified to O(n)
#include<iostream>
using namespace std;
int pairsum(int arr[],int n,int sum){
    int low=0;
    int end=n-1;
    while(low<end){
        if(arr[low]+arr[end]==sum){
            cout<<low<<" "<<end<<endl;
            return 0;
        }
        else if(arr[low]+arr[end]>sum){
            end--;
        }
        else{
            low++;
        }
    }
    return 0;
}

int main()
{
    int n=8;
    int k=31;
    int arr[n]={2,4,7,11,14,16,20,21};
    cout<<pairsum(arr,n,k)<<endl;
    return 0;
}