#include <iostream>
#include <vector>
using namespace std;

void solve(string s, int index, string output, vector<string>& ans) {
    if (index >= s.size()) {
            if(output.length()>0){
            ans.push_back(output);
            
        }
        return;
    }

    // Exclude the current character
    solve(s, index + 1, output, ans);

    // Include the current character
    output.push_back(s[index]);
    solve(s, index + 1, output, ans);
}

int main() {
    string s = "abc";
    string output = "";
    vector<string> ans;
    int index = 0;
    solve(s, index, output, ans);

    for (const string& subset : ans) {
        cout <<  subset << " " ;
    }

    return 0;
}
