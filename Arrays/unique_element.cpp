// only valid when you have only one unique element in array
#include<iostream>
using namespace std;
int unique_element(int *arr,int n){
    int result=0;
    for(int i=0;i<n;i++){
        result^=arr[i];
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<"the unique element is "<<unique_element(arr,n);
    return 0;
}