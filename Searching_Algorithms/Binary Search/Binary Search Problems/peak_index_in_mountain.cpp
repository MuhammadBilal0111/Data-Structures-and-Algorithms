#include<iostream>
using namespace std;
int peak_index(int *arr,int m){
    int s=0;
    int e=m-1;
    while(s<e){
        int mid=(s+e)/2;
        if(arr[mid]<=arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return arr[s];
}
int main()
{
    int m=6;
    int *arr=new int[m]{3,4,5,5,6,1};
    cout<<peak_index(arr,m);
    return 0;
}