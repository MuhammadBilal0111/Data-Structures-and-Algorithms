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
    Node * temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertTail(Node * &tail,int d){
    Node * temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertpos(Node *&head,int pos,int val){
    if(pos==1){
        insertHead(head,val);
        return ;
    }
    Node * current=head;
    int cnt=1;
    while(cnt<pos-1){
        current=current->next;
        cnt++;
    }
    Node * temp=new Node(val);
    temp->next=current->next;
    current->next=temp;
}
void deleteNode(Node * &head,int pos){
    if(pos==1){
        Node * temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node * prev=NULL;
        Node * current=head;
        int cnt=1;
        while(cnt<pos){
            prev=current;
            current=current->next;
            cnt++;
        }
        prev->next=current->next;
        current->next=NULL;
        delete current;
    }
}
void print(Node * &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
}
int main()
{
    Node * node1=new Node(7);
    Node * head=node1;
    Node * tail=node1;
    insertHead(head,6);
    insertTail(tail,8);
    insertTail(tail,9);
    insertpos(head,5,10);
    deleteNode(head,5);
    print(head);

    
    return 0;
}