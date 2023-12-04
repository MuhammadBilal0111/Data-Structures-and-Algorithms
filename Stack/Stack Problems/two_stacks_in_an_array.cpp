#include<iostream>
using namespace std;
class TwoStack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    // Constructor to initialize the stacks and set initial values of top pointers.
   
    TwoStack(int s){
        size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    void push1(int num){
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop1(){
        if(top1>=0){
            arr[top1]=0;
            top1--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    void pop2(){
        if(top2<size){
            arr[top2]=0;
            top2++;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    void print(){
        cout<<"Stack 1"<<endl;
        for(int i=0;i<=top1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        cout<<"Stack 2"<<endl;
        for(int i=size-1;i>=top2;i--){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
int main() {
    TwoStack twoStack(10);
    twoStack.push1(1);
    twoStack.push2(2);
    twoStack.push1(3);
    twoStack.push2(4);
    cout << "\nAfter pushing elements:" << endl;
    twoStack.print();
    
    // after popping from stack1
    cout << "\nAfter popping elements:" << endl;

    twoStack.pop1();
    twoStack.pop2();

    // after popping from stack2
    twoStack.print();
    return 0;
}