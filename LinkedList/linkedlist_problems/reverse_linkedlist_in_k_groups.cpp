#include<iostream>
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

// for making a linked list
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
// reversing in K groups
Node * reverse_in_k_groups(Node * &head,int k){
    // base condition
    if(head==NULL){
        return NULL;
    }
    Node * prev=NULL;
    Node * next=NULL;
    Node * curr=head;
    int count=0;
    Node * temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(count<k){
        return head;
    }
    count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    // recursive call
    if(next != NULL) {
        head->next=reverse_in_k_groups(curr,k);
    }
    return prev;
}

void print(Node * &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
int main()
{
    Node * head=NULL;
    Node * tail=NULL;
    insertTail(head,tail,5);
    insertTail(head,tail,4);
    insertTail(head,tail,3);
    insertTail(head,tail,7);
    insertTail(head,tail,9);
    insertTail(head,tail,2);
    int k=4;
    Node * newnode=reverse_in_k_groups(head,k);
    print(newnode);
    return 0;
}