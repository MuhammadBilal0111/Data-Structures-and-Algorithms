#include <iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node * next;
    
    Node(int d){
        Node *prev=NULL;
        this->data=d;
        Node *next=NULL;
    }
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};
void addHead(Node * &head,Node * &tail,int val){
    if(head==NULL){
        Node * node=new Node(val);
        head=node;
        tail=node;
    }
    else{
        Node * node=new Node(val);
        node->next=head;
        head->prev=node;
        head=node;
    }
}
void addTail(Node * &head,Node * &tail,int val){
    if(head==NULL){
        Node * node=new Node(val);
        head=node;
        tail=node;
    }
    else{
        Node * node=new Node(val);
        node->prev=tail;
        tail->next=node;
        tail=node;
    }
}
void print(Node* &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
void insert(Node *&head,Node * &tail,int val,int pos){
    if(pos==1){
        addHead(head,tail,val);
        return;
    }
    else{
        Node *temp=head;
        int cnt=1;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            addHead(head,tail,val);
            return;
        }
        Node *nodetoinsert=new Node(val);
        nodetoinsert->next=temp->next;
        temp->next->prev=nodetoinsert;
        temp->next=nodetoinsert;
        nodetoinsert->prev=temp;
    }
}
int count(Node*head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void deletenode(Node *&head,int pos){
    if(pos==1){
        Node *temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node *current=head;
        Node *prev=NULL;
        int cnt=1;
        while(cnt<pos){
            prev=current;
            current=current->next;
            cnt++;
        }
        prev->next=current->next;
        current->prev=NULL;
        current->next=NULL;
        delete current;
    }
}
int main() {
    Node* head=NULL;
    Node* tail=NULL;
    print(head);
    Node *node1=new Node(9);
    // Node *head=node1;
    // Node *tail=node1;
    head=node1;
    tail=node1;
    addHead(head,tail,7);
    addTail(head,tail,7);
    print(head);
    insert(head,tail,5,2);
    print(head);
    deletenode(head,1);
    print(head);
    cout<<"The number of nodes are "<<count(head)<<endl;
    
    return 0;
}