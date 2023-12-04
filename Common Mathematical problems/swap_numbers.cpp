#include<iostream>
using namespace std;
int main()
{
    //Approach 1
    int a=3;
    int b=4;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a="<<a<<"\n"<<"b="<<b;

    // Approach 2

    a=a-b;
    b=a+b;
    a=b-a;
    cout<<"a="<<a<<"\n"<<"b="<<b;
    return 0;
}
