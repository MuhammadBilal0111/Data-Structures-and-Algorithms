// Time Complexity : O(mx+k)
// Space Complexity : O(mx+k)
#include <iostream>
using namespace std;

void countSort(int *arr, int n) {
    int mx = arr[0];
    for (int i = 0; i < n; i++) {
        mx = max(mx, arr[i]);
    }

    // countArr contain the counting of individual element

    int countArr[mx + 1] = {0};
    for (int i = 0; i < n; i++) {
        countArr[arr[i]]++;
    }
    // Now we are updating the countArr to store the indexes of individual element
    for (int i = 1; i <= mx; i++) {  
        countArr[i] += countArr[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--countArr[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n = 8;
    int arr[] = {3, 5, 7, 11 , 4, 1, 1, 3};
    countSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
