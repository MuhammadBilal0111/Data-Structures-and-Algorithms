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

void insertTail(Node*& tail, int d) {
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

Node* uniqueSortedList(Node* head) {
    // Empty List
    if (head == NULL)
        return NULL;
    Node* curr = head;

    while (curr != NULL) {
        if ((curr->next != NULL) && curr->data == curr->next->data) {
            Node* next_next = curr->next->next;
            delete curr->next; // Delete the duplicate node
            curr->next = next_next;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertTail(tail, 2);
    insertTail(tail, 2);
    insertTail(tail, 3);
    
    print(head); // Print the original list
    
    Node* h = uniqueSortedList(head); // Remove duplicates and get the modified list
    print(h); // Print the modified list

    return 0;
}
