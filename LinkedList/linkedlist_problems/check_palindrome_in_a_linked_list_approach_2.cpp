// Total Time complexity : O(n)
// Total Space complexity : O(1)
// n is the size of Linkedlist
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

void print(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
Node * getMid(Node * &head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast!=NULL && fast->next!=NULL){  // for  odd or even linkedlist respectively
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node * reverse(Node * &head){
    Node * prev=NULL;
    Node * curr=head;
    Node * next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(Node *head){
    if(head==NULL){ // For Empty LinkedList
        return true;
    }
    if(head->next==NULL){
        return true;
    }
    // step 1
    Node * mid=getMid(head);
    Node * temp=mid->next;
    // step 1
    mid->next=reverse(temp);
    Node *head1=head;
    Node * head2=mid->next;
    // step 3
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    // step 4
    // optional step
    temp=mid->next; 
    mid->next=reverse(temp);
    return true;
}
int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertTail(tail, 2);
    insertTail(tail, 1);
    insertTail(tail, 4);
    print(head);
    if(isPalindrome(head)){
        cout<<"it is a palindrome"<<endl;
    }
    else{
        cout<<"it is not a palindrome"<<endl;
    }

    return 0;
}