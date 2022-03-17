#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;

    public:
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};


void addToList(Node* &tail, int val){
    Node* temp = new Node(val);
    if(tail == NULL){
        tail = temp;
        temp->next = temp;
    }
    else{
        temp->next = tail->next;
        tail->next = temp;
    }
}


void answer(Node* head){
    Node* ptr = head;
    int size =0;
    int i=0;
    Node* ansTail = NULL;
    Node* ansTail2 = NULL;
    while(ptr->next != head){
        size++;
        ptr = ptr->next;
    }
    ptr = head;
    while(i< size/2){
        int val = ptr->data;
        addToList(ansTail, val);
        i++;
        ptr = ptr->next;
    }
    while(i< size){
        int val = ptr->data;
        addToList(ansTail2, val);
        i++;
        ptr = ptr->next;
    }

    // printing the list
    Node* a1 = ansTail;
    do{
        cout<<a1->data<<" <-> ";
        a1 = a1->next;
    }while(a1->next != ansTail);

    Node* a2 = ansTail2;
    do{
        cout<<a2->data<<" <-> ";
        a2 = a2->next;
    }while(a2->next != ansTail2);

}

///// abhi mujhe circular ll ka data bhi dalna hai





int main(){
    int k;
    Node* head = NULL;
    Node* temp = head;
    cout<<"Enter size of circular linked list : ";
    cin>>k;
    cout<<"\nEnter data :\n"
    for(int i=0;i<k;i++){
        int data;
        cin>>data;
        temp = new Node(data);
        if(head == NULL){
            head = temp;
            temp->next = temp;
        }
        else{
            temp->next = head->next;
            head->next = temp;
        }
        
    }
    Node qw;
    qw.answer(head);


    return 0;
}