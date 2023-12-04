// Total Time complexity : O(n)
// Total Space complexity : O(1)
// n is the size of Linkedlist
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
    
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
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
int nodeLength(Node *&head){
    int len=0;
    Node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len-1;
}
Node * midNode(Node *&head){
    Node *temp=head;
    int len=nodeLength(head);
    int ans=len/2;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
}
int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertTail(tail, 2);
    insertTail(tail, 7);
    insertTail(tail, 1);
    print(head);
    cout<<"mid is "<<midNode(head)->data<<endl;
    return 0;
}