#include <iostream>
using namespace std;

int count_inversions(int arr[], int n) {
    int inversions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}
int main(){
    int n = 8;
    int arr[] = {3,5,6,9,1,2,7,8};
    cout << "Number of inversions: " << count_inversions(arr, n) << endl;
    return 0;
}
