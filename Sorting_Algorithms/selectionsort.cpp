// Best, Worst, Average Time Complexity : (n*n)
// Space Complexity : (1)
// n is the size of an array
#include <iostream>
using namespace std;

// definition of function
void selection_sort(int *arr, int n){
    for (int i = 0; i < n - 1; i++){
        int minindex = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}
int main()
{
    int n = 6;
    int *arr = new int[n]{12, 45, 23, 51, 19, 8};
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}