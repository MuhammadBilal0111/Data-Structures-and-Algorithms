// Time complexity : O(n)
// Space Complexity : O(n)
// n is the size of linked list
// Practice question of Geeks for geeks 
//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// uncomment it and change random to arb
#include<iostream>
#include<map>
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
        return;
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

    // Step 2 : Create a map and save the mapping
    map<Node *,Node *>oldToNewNode;
    Node * originalNode=head;
    Node * cloneNode=clonehead;
    while(originalNode!=NULL && cloneNode!=NULL)
    {
        oldToNewNode[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    originalNode=head;
    cloneNode=clonehead;
    // Step 3 : Copy random pointer to cloneNode
    while(originalNode!=NULL && cloneNode!=NULL){
        cloneNode->random=oldToNewNode[originalNode->random];
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    return clonehead;

}
