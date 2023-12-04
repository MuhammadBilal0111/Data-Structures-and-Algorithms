// Total Time Complexity : O(n)
// n is the length of merged linkedlist
// Total Space Complexity : O(1)

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int d){
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

void print(Node* &head) {
    // O(n)
    // n is the length of merged linkedlist
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void insertAtTail(Node * &head,Node * &tail,int d){
    if(tail==NULL){
        Node * temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}
Node * solve(Node * &first,Node * &second){
    Node * newhead=NULL;
    Node * newtail=NULL;
    Node * head1=first;
    Node * head2=second;
    while(head1!=NULL && head2!=NULL){      // Time complexity of solve function will O(m) m is the length of smaller linkedlist
        if(head1->data<=head2->data){
            insertAtTail(newhead,newtail,head1->data);
            head1=head1->next;
        }
        else{
            insertAtTail(newhead,newtail,head2->data);
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        insertAtTail(newhead,newtail,head1->data);
        head1=head1->next;
    }
    while(head2!=NULL){
        insertAtTail(newhead,newtail,head2->data);
        head2=head2->next;
    }
    return newhead;
}
Node * mergeTwoSortedLinkedList(Node * &first,Node * &second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
}
int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(head1,tail1, 4);
    insertAtTail(head1,tail1, 5);
    insertAtTail(head2,tail2, 3);
    insertAtTail(head2,tail2, 5);
    
    print(head1);
    print(head2);
    Node * newHead=mergeTwoSortedLinkedList(head1,head2);
    print(newHead);
    return 0;
}