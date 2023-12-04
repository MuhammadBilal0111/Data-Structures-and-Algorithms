// Time Complexity : O((d*(mx+k))
// Space Compexity : O(mx+k)
// mx is maximum number
// d is no of digits

#include<iostream>
using namespace std;
int getMax(int * arr, int n){
    int mx = arr[0];
    for(int i = 0 ; i < n; i++){
        mx = max(mx , arr[i]);
    }
    return mx;
}
void countSort(int *arr, int n,int pos) {
    // countArr contain the counting of individual element

    int mx = 10;
    int countArr[mx]={0};
    for (int i = 0; i < n; i++) {
        countArr[(arr[i]/pos)%10]++;
    }
    // Now we are updating the countArr to store the indexes of individual element
    for (int i = 1; i <= mx; i++) {  
        countArr[i] += countArr[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--countArr[(arr[i]/pos)%10]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixSort(int *arr,int n){
    int mx=getMax(arr,n);
    for(int pos = 1 ; mx/pos>0;pos*=10){
        countSort(arr,n,pos);
    }
}
int main()
{
    int n = 5;
    int arr[n]={101,306,807,708,67};
    radixSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}