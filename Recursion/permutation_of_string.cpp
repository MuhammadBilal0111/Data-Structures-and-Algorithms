#include<iostream>
using namespace std;
void permutation(string s,int index){
    if(index>=s.size()){
        cout<<s<<" ";
        return;
    }
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        permutation(s,index+1);
        swap(s[index],s[i]);
    }
}
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main()
{
    string s="cat";
    int index=0;
    cout<<"The number of permutations are "<<factorial(s.size())<<endl;
    permutation(s,index);
    return 0;
}