// Time Complexity : O(n)
// Space Complexity : O(1)
#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
Node* floyde_cycle_detection(Node * &head){
    if(head==NULL){
        return NULL;
    }
    Node * slow=head;
    Node * fast=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
Node * getStartingLoop(Node * &head){
    if(head==NULL){
        return NULL;
    }
    Node * slow=head;
    Node *fast=floyde_cycle_detection(head);
    if(fast==NULL){ // for 0 node,,avoiding seqmentation error 
        return NULL;
    }
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
Node * removeLoop(Node *&head){
    if(head==NULL){
        return head;
    }
    Node * start=getStartingLoop(head);
    if(start==NULL){  // if no loop 
        return head; 
    }
    Node *temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
