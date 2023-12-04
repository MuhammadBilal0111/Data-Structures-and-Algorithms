#include <iostream>
#include <string>
using namespace std;
// Time Complexity: O(max(N, M))
// Space Complexity: O(max(N, M))
// Function to add two binary strings
string addBinary(string s1, string s2) {
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    string str = "";
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += s1[i] - '0'; // Convert character to integer
            i--;
        }
        if (j >= 0) {
            sum += s2[j] - '0'; // Convert character to integer
            j--;
        }
        carry = sum / 2;
        sum %= 2;
        str = to_string(sum) + str;
    }
    return str; // Return the binary sum as a string
}
int main() {
    string s1 = "1101";
    string s2 = "1011";
    cout << addBinary(s1, s2); 

    return 0;
}
