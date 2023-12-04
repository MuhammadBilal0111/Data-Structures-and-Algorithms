// Space complexity : O(n)
// Time Complexity : O(n)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> previousSmall(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    int n = 4;
    vector<int> arr = {2, 1, 4, 3};
    vector<int> ans = previousSmall(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}