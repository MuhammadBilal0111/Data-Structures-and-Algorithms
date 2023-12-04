// Time complexity : O(n)
// Space Complexity : O(1)
// n is the size of linked list
// Practice question of Geeks for geeks 
//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// uncomment it and change random to arb
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node * random;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->random=NULL;
    }
};
void insertAtTail(Node * &head,Node * &tail,int data){
    Node * newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return ;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
Node * copyList(Node * &head){
    // Step 1 : Create a clone Linked List
    Node * clonehead=NULL;
    Node * clonetail=NULL;
    Node * temp=head;
    while(temp!=NULL){
        insertAtTail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }
    // Step : 2 Clone Node add between
    Node * originalNode=head;
    Node * cloneNode = clonehead;

    while(originalNode!=NULL && cloneNode!=NULL){
        Node * next=originalNode->next;
        originalNode->next=cloneNode;
        originalNode=next;

        next=cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=next;
    }
    // Step : 3 make random pointer
    temp=head;
    while (temp!=NULL)
    {
        if(temp->next!=NULL){
            // temp->next->random=temp->random?temp->random->next:temp->random;
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            else{
                temp->next->random= temp->random;
            }

        }
        temp=temp->next->next;
    }
    // Step : 3 revert changes
    originalNode=head;
    cloneNode=clonehead;
    while(originalNode!=NULL && cloneNode!=NULL){
        originalNode->next=cloneNode->next;
        originalNode=originalNode->next;
        if(originalNode!=NULL){
            cloneNode->next=originalNode->next;
        }
        cloneNode=cloneNode->next;
    }
    return clonehead;
}

