#include<iostream>
using namespace std;
//we are not using head pointer ,only tail pointer
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
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
// Make a circular linked
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
void deleteNode(Node * &tail,int val){
    if(tail==NULL){
        cout<<"no list";
    }
    else{
        Node *prev=tail;
        Node *curr=prev->next;
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev){  // 1 node
            tail=NULL;
        }
        if(tail==curr){  // for deleting first element
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* tail){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    Node* temp=tail;
    do{
        cout<<tail->data<<" ";  // create segmentation error when we have 1 node and we already delete the memory
        tail=tail->next;
    }
    while(tail!=temp);
}
int main()
{   
    Node * tail = NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,5);
    insertNode(tail,3,9);
    // print(tail);
    //deleteNode(tail,3);
    print(tail);


    return 0;
}