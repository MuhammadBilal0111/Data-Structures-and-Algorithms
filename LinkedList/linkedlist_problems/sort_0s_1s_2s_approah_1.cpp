// Total Time Complexity : O(n)
// Total Space Complexity : O(1)
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
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
void insertTail(Node*& tail, int d) {
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
Node * sortedList(Node * &head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    Node * temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else{
            twoCount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }
        else{
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
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
    Node * newhead=sortedList(head);
    print(newhead);
    return 0;
}

