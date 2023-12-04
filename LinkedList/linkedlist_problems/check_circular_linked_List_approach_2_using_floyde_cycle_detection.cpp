// time complexitty:O(n)
// space complexity : O(1)
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
// make a circular linked list
void insertNode(Node * &tail,int element,int d){
    if(tail==NULL){
        Node * temp=new Node(d);
        tail=temp;
        tail->next=tail;
        return ;
    }
    else{
        Node * current=tail;
        while(current->data!=element){
            current=current->next;
        }
        Node * newnode=new Node(d);
        newnode->next=current->next;
        current->next= newnode;
    }
}
// for making a circular linked list
void insertTail(Node * &head,Node * &tail,int data){
    if(tail==NULL){
        Node * newNode=new Node(data);
        tail=newNode;
        head=newNode;
    }
    else{
        Node * newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
}
bool checkCircularLinkedList(Node * &head){
    if(head==NULL){
        return true;
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
            return true;
        }  
    }
    return false;
}
int main() {
    // make a circular linked list
    Node * circulartail = NULL;
    insertNode(circulartail,5,3);
    insertNode(circulartail,3,5);
    insertNode(circulartail,3,9);
    // make a non circular linked list
    Node * node1=new Node(7);
    Node * singlehead=node1;
    Node * singletail=singlehead;
    insertTail(singlehead ,singletail , 20);
    insertTail(singlehead ,singletail, 21);
    // check for circular linked list
    if(checkCircularLinkedList(circulartail)){
        cout<<"It is a circular linkedlist"<<endl;
    }
    else{
        cout<<"It is not a circular linkedlist"<<endl;
    }
    // checy for single linked list
    if(checkCircularLinkedList(singlehead)){
        cout<<"It is a circular linkedlist"<<endl;
    }
    else{
        cout<<"It is not a circular linkedlist"<<endl;
    }
    return 0;
}