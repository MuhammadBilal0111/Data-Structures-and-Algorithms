#include<iostream>
using namespace std;
int pivot(int *arr,int n){
    int s=0;
    int e=n-1;
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
int main()
{
    int m=5;
    int *arr=new int[m]{7,9,1,2,3};
    cout<<pivot(arr,m);
    return 0;
}