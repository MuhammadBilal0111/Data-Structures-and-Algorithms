// Total Time complexity : O(n)
// Total Space complexity : O(n)
// n is the size of Linkedlist
#include <iostream>
#include<vector>
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
bool checkpalindrome(vector<int>arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool isPalindrome(Node *&head){
    vector<int>arr;
    Node * temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkpalindrome(arr);
}
int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertHead(head, 2);
    insertHead(head, 1);
    
    print(head);
    if(isPalindrome(head)){
        cout<<"it is a palindrome"<<endl;
    }
    else{
        cout<<"it is not a palindrome"<<endl;
    }

    return 0;
}