// worst and average Time Complexity: O(N^2)
// Best Time compexity : O(N)
// Auxiliary Space: O(1)
#include <iostream>
using namespace std;
// definition of function
void bubblesort(int arr[], int n){
    bool swapped = false;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}
int main()
{
    int n=5;
    int arr[n]={3,4,1,0,3};
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}