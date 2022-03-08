#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node *next;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d){
        key = k;
        data = d;
    }
};

class SingleLinkedList{
    public:
    Node *head;
    SingleLinkedList(){
        head = NULL;
    }
    SingleLinkedList(Node *n){
        head = n;
    }

    Node *nodeExist(int k){
        Node *temp = NULL;
        Node *ptr = head;
        while(ptr != NULL){
            if(ptr ->key){
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // Append A node

    void appendNode(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout<<"Node Allready Exist \n";
        }
        else{
            if(head == NULL){
                head = n;
                cout<<"Node Appended\n";
            }
            else{
                Node *ptr = head;
                while(ptr ->next != NULL){
                    ptr = ptr->next;
                }
                ptr ->next = n;
                cout<<"Node Appended\n";
            }
        }
    }

    //Prepend Node

    void prepend(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout<<"Node allready Exist\n";
        }
        else{
            n->next = head;
            head = n;
            cout<<"Node Prepended\n";
        }
    }

    // Insert a node after a particular node in the list whose key value is k

    void insertNode(int k, Node *n){
        Node *ptr = nodeExist(k);
        if(ptr == NULL){
            cout<<"No node Exist with key value "<<k<<endl;
        }
        else{
            if(nodeExist(n->key)!=NULL){
                cout<<"Node already exist\n";
            }
            else{
                n->next = ptr->next;
                ptr->next = n;
                cout<<"Node is inserted\n";
            }
        }
    }

    // Delete a node by unique key

    void deleteNode(int k){
        if(head== NULL){
            cout<<"Single Linked List is empty\n";
        }
        else if(head != NULL){
            if(head->key == k){
                head = head->next;
                cout<<"Node is unlinked\n";
            }
            else{
                Node *temp = NULL;
                Node *preptr = head;
                Node *curptr = head->next;
                while(curptr != NULL){
                    if(curptr -> key == k){
                        temp = curptr;
                        curptr = NULL;
                    }
                    else{
                        preptr ->next = preptr;
                        curptr->next= curptr;
                    }
                    if(temp!=NULL){
                        preptr->next = temp->next;
                        cout<<"Node Deleted\n";
                    }
                }
            }
        }
    }

    // Update a node

    void updateNode(int k, int d){
        Node *ptr = nodeExist(k);
        if(ptr != NULL){
            ptr ->data = d;
            cout<<"Node updated\n";
        }
        else{
            cout<<"Node not present in the Linked List\n";
        }
    }

    // printing the Single Linked List

    void printing(){
        if(head == NULL){
            cout<<"No node is present in the Single Linked List\n";
        }
        else{
            cout<<"Single Linked List values :\n";
            Node *temp = head;
            while(temp!=NULL){
                cout<<"( "<<temp->key<<" , "<<temp->data<<" )\n";
                temp = temp->next;
            }
        }
    }

};


int main(){
    SingleLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    // cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prepend(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertNode(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNode(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNode(key1, data1);

      break;
    case 6:
      s.printing();

      break;
    
    default:
    cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
    return 0;
}