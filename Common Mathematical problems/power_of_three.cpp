//The time complexity of the solution provided to check if a number is a power of three is O(1)
#include<iostream>
using namespace std;
bool pow_of_three(int n){
    int ans=1;
    for(int i=0;i<31;i++){
        if(ans==n){
            return true;
        }
        if(ans<INT_MAX/3){
            ans*=3;
        }
        else{
            break;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    if(pow_of_three(n)){
        cout<<"It is included in the power of three"<<endl;
    }
    else{
        cout<<"It is not included in the power of three"<<endl;
    }
    return 0;
}