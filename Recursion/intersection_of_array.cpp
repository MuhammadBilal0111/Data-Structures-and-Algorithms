#include<iostream>
#include<vector>
using namespace std;
vector<int> intersection_of_array(vector<int>&arr1,vector<int>&arr2){
    vector<int>ans;
    int i=0;int j=0;
    int m=arr1.size()-1;
    int n=arr2.size()-1;
    while(i<=m && j<=n){
        if (arr1[i]== arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr1={1,2,2,2,3,4,7};  
    vector<int>arr2={2,2,3,3,4,8,9};
    vector<int>res=intersection_of_array(arr1,arr2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}