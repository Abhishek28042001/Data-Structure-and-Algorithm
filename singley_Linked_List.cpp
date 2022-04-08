#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

//insertion at head

Node* insertionAtHead(Node* head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    return head;
}

// display the sll

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// insert at End

Node* insertionAtEnd(Node* head,int d){
    Node *ptr, *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    ptr = new Node(d);
    temp->next = ptr;
    return head;
}

//insert before x
Node* insertBeforeX(Node* head, int d, int x){
    Node *temp = head;
    if(temp==NULL){
        cout<<x<<" not FOUND in SLL";
        return head;
    }
    while(temp!=NULL){
        if(temp->next->data == x){
            Node *ptr = new Node(d);
            ptr->next = temp->next;
            temp->next = ptr;
            return head;
        }
        temp = temp->next;
    }
}

// insert after x
Node* insertAfterX(Node *head, int d, int x){
    Node *temp = head;
    if(temp== NULL){
        cout<<"SLL is empty";
        return head;
    }
    while(temp!=NULL){
        if(temp->data == x){
            Node *ptr = new Node(d);
            ptr->next = temp->next;
            temp->next = ptr;
            return head; 
        }
        temp = temp->next;
    }
}

int main(){
    Node* first = NULL;
    cout<<"Enter data: ";
    int n;
    cin>>n;
    first = insertionAtHead(first,n);
    cout<<"Enter data: ";
    cin>>n;
    first = insertionAtHead(first,n);
    display(first);
    cout<<endl;
    first = insertionAtEnd(first,999);
    display(first);
    cout<<endl;
    first = insertBeforeX(first,77,999);
    display(first);
    cout<<endl;
    first = insertAfterX(first,88,999);
    display(first);
    return 0;
}