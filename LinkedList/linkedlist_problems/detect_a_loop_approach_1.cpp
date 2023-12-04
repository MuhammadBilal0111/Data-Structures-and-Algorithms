// Time Complexity : O(n)
// Space Complexity : O(n)
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
bool detect_loop(Node * &head){
    if(head==NULL){
        return false;
    }
    map<Node*,bool>visited;
    Node *temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Cycle present at "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

int main()
{
    Node * node1=new Node(7);
    Node * head=node1;
    Node * tail=node1;
    insertTail(tail,8);
    insertTail(tail,9);
    print(head);
    tail->next=head->next;
    if(detect_loop(head)){
        cout<<"Loop detected"<<endl;
    }
    else{
        cout<<"No loop detected"<<endl;
    }
    return 0;
}
