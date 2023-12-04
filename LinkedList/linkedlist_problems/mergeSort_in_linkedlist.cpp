// Time complexity is O(n log n) due to the merge sort algorithm.
// Space complexity is O(log n).
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int d){
        this->data=d;
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
void print(Node * &head){
    Node * current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
Node * midNode(Node *&head){
    
    Node * slow=head;
    Node * fast=head->next;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
    
}
Node * merge(Node * &left,Node * &right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node * ans=new Node(-1);
    Node * temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;
}
Node * mergeSort(Node * &head){
    // base case
    if(head==NULL || head->next==NULL){    
        return head; 
    }
    Node * mid=midNode(head);
    Node * left=head;
    Node * right=mid->next;
    mid->next=NULL;
    // recursive call to sort both half
    left=mergeSort(left);
    right=mergeSort(right);
    Node * result=merge(left,right);
    return result;
}
int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertTail(tail, 2);
    insertTail(tail, 1);
    insertTail(tail, 5);
    print(head);
    Node * newhead=mergeSort(head);
    print(newhead);
    return 0;
}