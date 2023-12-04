#include<iostream>
using namespace std;
int ans(int x) {
    int ans=0;
    while(x!=0){
        int lst_digit=x%10;
        if(ans>INT_MAX/10 || ans<INT_MIN/10){ // if ans is out of the range of integer then it give 0
            return 0;
        }
        ans=ans*10+lst_digit;
        x/=10;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<"The reverse integer is :"<<ans(n);
    return 0;
}