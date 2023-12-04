// The time complexity is O(n^2)
// The space complexity is O(n)
#include<iostream>
using namespace std;
int pairsum(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n=8;
    int k=31;
    int arr[n]={2,4,7,11,14,16,20,21};
    cout<<pairsum(arr,n,k)<<endl;
    return 0;
}