//  the time complexity of this code is O(31), which simplifies to O(1). This is because the loop always iterates 
//exactly 31 times, regardless of the input value n. The number of iterations is constant, so it's considered to 
//have a time complexity of O(1).
#include<iostream>
using namespace std;
bool pow_of_two(int n){
    int ans=1;
    for(int i=1;i<=31;i++){
        if(ans==n){
            return true;
        }
        if(ans<INT_MAX/2){
            ans*=2;
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
    if(pow_of_two(n)){
        cout<<"It is included in the power of two"<<endl;
    }
    else{
        cout<<"It is not included in the power of two"<<endl;
    }
    return 0;
}
