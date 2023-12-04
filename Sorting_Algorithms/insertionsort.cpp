// The worst-case time complexity of the Insertion sort is O(N^2)
// The average case time complexity of the Insertion sort is O(N^2)
// The time complexity of the best case is O(N).
#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    for(int i = 1;i < n;i++){
        int current = arr[i];
        int j = i - 1;
        while(current < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main()
{
    int n=5;
    int arr[n] = {3,4,1,0,3};
    insertion_sort(arr,n);
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}