// time complexitty:O(n)
// space complexity : O(1)
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data=data;
        this->next = NULL;
    }
};
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
// Make a circular linked list
void insertNode(Node * &tail,int element,int d){
    if(tail==NULL){
        Node * newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        Node * current=tail;
        while(current->data!=element){
            current=current->next;
        }
        Node * temp=new Node(d);
        temp->next=current->next;
        current->next=temp;
    }
}
// it check that linkedlist is circular
bool check_circular_linkedList(Node *&head){
    if(head==NULL){
        return true;
    }
    Node * temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
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
    // checy for circular linked list
    if(check_circular_linkedList(circulartail)){
        cout<<"It is a circular linkedlist"<<endl;
    }
    else{
        cout<<"It is not a circular linkedlist"<<endl;
    }
    // checy for single linked list
    if(check_circular_linkedList(singlehead)){
        cout<<"It is a circular linkedlist"<<endl;
    }
    else{
        cout<<"It is not a circular linkedlist"<<endl;
    }
    return 0;
}