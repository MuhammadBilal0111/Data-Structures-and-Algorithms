#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return ;
    }//exclude
    solve(nums,output,index+1,ans);
    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
    //backtracking
    output.pop_back();
}
vector<vector<int>>subset(vector<int>&nums){
   vector<vector<int>>ans;
   vector<int>output;
   int index=0;
   solve(nums,output,index,ans); 
   return ans;
}
int main()
{
    vector<int>nums={1,2,3};
    vector<vector<int>>result=subset(nums);
    cout<<"[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;






    return 0;
}