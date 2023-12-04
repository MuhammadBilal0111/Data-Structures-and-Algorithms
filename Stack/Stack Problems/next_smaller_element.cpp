// Space complexity : O(n)
// Time Complexity : O(n)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{
    int n = 4;
    vector<int> arr = {2, 1, 4, 3};
    vector<int> ans = nextSmallElement(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}