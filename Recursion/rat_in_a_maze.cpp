#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}
void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
    if ((x == n - 1) && (y == n - 1)) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(m, n, ans, newx, newy, visited)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // Left
    newx = x;
    newy = y - 1;
    if (isSafe(m, n, ans, newx, newy, visited)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(m, n, ans, newx, newy, visited)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(m, n, ans, newx, newy, visited)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}
vector<string> rat_in_a_maze(vector<vector<int>>& m, int n) {
    vector<string> ans;
    int srcx = 0;
    int srcy = 0;
    if (m[0][0] == 0) {
        return ans;
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    return ans;
}
int main() {
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> paths = rat_in_a_maze(m, n);

    for (const string& path : paths) {
        cout << path << " ";
    }
    return 0;
}
