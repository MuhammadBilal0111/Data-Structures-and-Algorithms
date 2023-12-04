//time Complexity:O(1)
//space complexity:O(1)
#include<iostream>
using namespace std;
int add_two_numbers(int a,int b){
    while(b!=0){
        int carry=(a&b)<<1;
        a=a^b;
        b=carry;
    }
    return a;
}
int main()
{
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<"Sum : "<<add_two_numbers(a , b);
    return 0;
}