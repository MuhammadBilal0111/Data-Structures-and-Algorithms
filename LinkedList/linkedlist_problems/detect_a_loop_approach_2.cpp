// Time Complexity : O(n)
// Space Complexity : O(1)
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertHead(Node * &head,int d){
    if(head==NULL){
        Node * temp=new Node(d);
        head=temp;
    }
    else{
        Node * temp=new Node(d);
        temp->next=head;
        head=temp;
    }
}
void insertTail(Node * &tail,int d){
    if(tail==NULL){
        Node * temp=new Node(d);
        tail=temp;
    }
    else{
        Node * temp=new Node(d);
        tail->next=temp;
        tail=temp;
    }
}
void print(Node * &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}

bool floyde_cycle_detection(Node * &head){
    if(head==NULL){
        return false;
    }

    Node * slow=head;
    Node * fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"Cycle present at "<<slow->data<<endl;
            return true;
        }
    }
    return false;
}
int main()
{
    Node * node1=new Node(7);
    Node * head=node1;
    Node * tail=node1;
    insertTail(tail,8);
    insertTail(tail,9);
    print(head);
    tail->next=head->next;
    if(floyde_cycle_detection(head)){
        cout<<"Loop detected"<<endl;
    }
    else{
        cout<<"No loop detected"<<endl;
    }
    return 0;
}
