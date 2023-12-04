// Time complexity : O(n)
// space complexity : O(1)
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
void insertHead(Node * &head,Node * &tail,int d){
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
void print(Node * &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
Node* reverse(Node * &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node * prev=NULL;
    Node *current=head;
    Node * forword=NULL;
    while(current!=NULL){
        forword=current->next;
        current->next=prev;
        prev=current;
        current=forword;
    }
    return prev;
}

int main()
{
    Node * node1=new Node(7);
    Node * head=node1;
    Node * tail=head;
    insertTail(head ,tail , 20);
    insertTail(head ,tail, 21);
    print(head);
    Node * newNode=reverse(head);
    print(newNode);

    return 0;
}