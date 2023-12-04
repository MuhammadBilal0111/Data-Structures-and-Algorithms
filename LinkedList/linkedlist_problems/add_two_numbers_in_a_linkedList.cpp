// Total Time Complexity : O(N+M)
// Total Space Complexity : O(max(N,M))
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
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
Node* reverse(Node * &head){
    Node * prev=NULL;
    Node * current=head;
    Node * forword=NULL;
    while(current!=NULL){
        forword=current->next;
        current->next=prev;
        prev=current;
        current=forword;
    }
    return prev;
}
void insertatTail(Node * &head,Node * &tail,int digit){
    Node * temp=new Node(digit);
    if(head==NULL){
        head=temp;
        tail=temp;
        return ;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
Node * add(Node * &first,Node * &second){
    int carry=0;
    Node * ansHead=NULL;
    Node * ansTail=NULL;
    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        int val2=0;
        if(first!=NULL){
            val1=first->data;
        }
        if(second!=NULL){
            val2=second->data;
        }
        int sum=carry+val1+val2;
        int digit=sum%10;
        insertatTail(ansHead,ansTail,digit);
        carry=sum/10;
        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){
            second=second->next;
        }
    }
    return ansHead;
}
Node * addTwoList(Node * &head1,Node * &head2){
    // Step 1
    Node * first=reverse(head1);
    Node * second=reverse(head2);
    // Step 2
    Node * ans=add(first,second);
    // Step 3
    ans=reverse(ans);
    return ans;

}
int main() {
    Node* node1 = new Node(5);
    Node* node2 = new Node(2);
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* head2 = node2;
    Node* tail2 = node2;
    insertTail(tail1, 4);
    insertTail(tail2, 3);
    insertTail(tail2, 0);
    print(head1);
    print(head2);
    Node * result=addTwoList(head1,head2);
    print(result);
    return 0;
}


