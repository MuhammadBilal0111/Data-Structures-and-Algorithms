#include<iostream>
#include<map>
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
void insertTail(Node * &tail,int d){
    Node * temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void print(Node * &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
Node* floyde_cycle_detection(Node * &head){
    if(head==NULL){
        return NULL;
    }

    Node * slow=head;
    Node * fast=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
Node * getStartingLoop(Node * &head){
    if(head==NULL){
        return NULL;
    }
    Node * slow=head;
    Node * fast=floyde_cycle_detection(head);
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
int main()
{
    Node * node1=new Node(10);
    Node * head=node1;
    Node * tail=node1;
    insertTail(tail,12);
    insertTail(tail,15);
    insertTail(tail,22);
    print(head);
    tail->next=head->next;
    Node * loop=getStartingLoop(head);
    cout<<"Started at "<<loop->data<<endl;

    return 0;
}
