#include<iostream>
using namespace std;
void fibonacci(int n){
    int num1=0;
    int num2=1;
    for(int i=0;i<n;i++){
        cout<<num1<<" ";
        int next_element=num1+num2;
        num1=num2;
        num2=next_element;
    }
}
int main()
{
    int n;
    cout<<"How many numbers of fibonacci series do you want to print?"<<endl;
    cin>>n;
    fibonacci(n);
    return 0;
}