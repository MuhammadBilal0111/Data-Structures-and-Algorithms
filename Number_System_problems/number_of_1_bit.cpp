#include<iostream>
using namespace std;
int number_of_1_bit(int n){
    int count=0;
    while(n!=0){
        if(n&1){
            count+=1;
        }
        n=n>>1;
    }
    return count;
}
int main()
{
    int n=010010010100;
    cout<<number_of_1_bit(n);
    return 0;
}