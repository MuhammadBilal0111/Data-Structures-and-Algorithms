#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top;
    int size;
    //constructor to initialize the stack
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool is_empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    Stack stack(5);
    stack.push(9);
    stack.push(8);
    stack.push(7);
    cout<<stack.peek()<<endl;
    stack.pop();
    cout<<stack.peek()<<endl;

    if(stack.is_empty()){
        cout << "Stack is empty"<<endl;
    }
    else{
        cout << "Stack is not empty"<<endl;
    }
    stack.push(77);
    stack.push(7);
    stack.push(7);
    stack.push(73);

    return 0;
}