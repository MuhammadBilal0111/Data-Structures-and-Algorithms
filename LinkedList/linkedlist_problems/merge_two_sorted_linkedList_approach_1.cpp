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
    // O(n)
    // n is the length of merged linkedlist
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
// if only one element is present according to given condition
Node * solve(Node * &small,Node * &large){ 
    // Time complexity of solve function will O(m)
    // m is the length of smaller linkedlist
    // if there are onlu one element in both linked list
    if(small->next==NULL){
        small->next=large;
        return small;
    }
    Node * curr1=small;
    Node * next1=curr1->next;
    Node * curr2=large;
    Node * next2=curr2->next;
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data >=curr1->data) && (curr2->data <=next1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return small;
            }
        }
    }
    return small;
}
Node * mergeTwoSortedLinkedList(Node * &head1,Node * &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data <= head2->data){
        return solve(head1,head2);
    }
    else{
        return solve(head2,head1);
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* head2 = node2;
    Node* tail2 = node2;

    insertTail(tail1, 4);
    insertTail(tail1, 5);
    insertTail(tail2, 3);
    insertTail(tail2, 5);
    print(head1);
    print(head2);
    Node * newHead=mergeTwoSortedLinkedList(head1,head2);
    print(newHead);
    return 0;
}


