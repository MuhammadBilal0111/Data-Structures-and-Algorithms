// Total Time Complexity : O(n)
// Total Space Complexity : O(1)
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
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
void insertTail(Node* &tail, int d) {
    if(tail==NULL){
        Node * temp=new Node(d);
        tail=temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}
void print(Node* &head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void insertattail(Node * &tail,Node * &curr){
    tail->next=curr;
    tail=curr;
}
Node * sort(Node * &head){
    if(head==NULL){
        return head;
    }
    Node * zeroHead=new Node(-1);
    Node * zeroTail=zeroHead;
    Node * oneHead=new Node(-1);
    Node * oneTail=oneHead;
    Node * twoHead=new Node(-1);
    Node * twoTail=twoHead;
    
    Node * temp=head;
    // Add 0, 1, 2 in their respective nodes
    while(temp!=NULL){
        if(temp->data==0){
            insertattail(zeroTail,temp);
        }
        else if(temp->data==1){
            insertattail(oneTail,temp);
        }
        else{
            insertattail(twoTail,temp);
        }
        temp=temp->next;
    }
    // Merging nodes
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zeroHead->next;
    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertTail(tail, 1);
    insertTail(tail, 2);
    insertTail(tail, 1);
    insertTail(tail, 0);
    insertTail(tail, 2);
    print(head);
    Node * newhead=sort(head);
    print(newhead);

    return 0;
}