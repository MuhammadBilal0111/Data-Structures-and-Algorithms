//The time complexity of the solution provided to check if a number is a power of four is O(1)
#include<iostream>
#include<math.h>
using namespace std;
bool power_of_four(int n){
    int ans=1;
    for(int i=0;i<31;i++){
        if(ans==n){
            return true;
        }
        if(ans<INT_MAX/4){
            ans*=4;
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
    if(power_of_four(n)){
        cout<<"It is included in the power of four"<<endl;
    }
    else{
        cout<<"It is not included in the power of four"<<endl;
    }
    return 0;
}