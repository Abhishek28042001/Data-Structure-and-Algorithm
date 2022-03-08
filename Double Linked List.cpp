#include<iostream>
using namespace std;
// done by abhi
class Node{
	public:
		int key;
		int data;
		Node *next;
		Node* previous;
		
		Node(){
			key = 0;
			data = 0;
			next = NULL;
			previous = NULL;
		}
		Node(int k, int d){
			key =k;
			data =d;
		}
};

class DoubleLinkedList{
	public:
		Node *head;
		DoubleLinkedList(){
			head = NULL;
		}
		DoubleLinkedList(Node *n){
			head = n;
		}
		
		// 1. Check whether the node is available in the list or not
		Node* checkNode(int k){
			Node *temp = NULL;
			Node *ptr = head;
			while(ptr!=NULL){
				if(ptr->key == k){
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		// 2. Append a node in the list
		void appendNode(Node *n){
			if(checkNode(n->key)!=NULL){
				cout<<"Node already Available/n";
			}
			else{
				if(head==NULL){
					head = n;
				}
				else{
					Node* ptr = head;
					while(ptr!=NULL){
						ptr = ptr->next;
					}
					ptr->next = n;
					n->previous = ptr;
					cout<<"Node Appended\n";
				}
			}
		}
		
		// 3. Prepend Node
		void prependNode(Node* n){
			if(checkNode(n->key)!=NULL){
				cout<<"Node Already Exist in the list\n";
			}
			else{
				if(head==NULL){
					head = n;
				}
				else{
					n->next = head;
					head = n;	
				}
				cout<<"Node Prepended\n";
			}
		}
		
		//4. Inserting a node in the list after key value k
		void insertNode(int k, Node* n){
			Node* ptr = checkNode(k);
			if(ptr == NULL){
				cout<<"No node is available in the list for inserting\n";
			}
			else{
				if(checkNode(n->key)!=NULL){
					cout<<"Already node exist\n";
				}
				else{
					Node* nextNode = ptr->next;
					if(nextNode == NULL){
						nextNode = n;		// nextNode ke place pe ptr->next
						n->previous = ptr;
						cout<<"Node Inserterted in the end\n";
					}
					else{
						n->next = ptr->next;
						nextNode->previous = n;
						n->previous = ptr;
						ptr->next = n;
						cout<<"Node inserted in between the list\n";
					}
				}
			}
		}
		
		// 5. Deleting the node in the list
		void deleteNode(int k){
			Node* ptr = checkNode(k);
			if(ptr==NULL){
				cout<<"Node doesnot exist\n";
			}
			else{
				if(head->key == k){
					head = head->next;
					cout<<"Node deleted in the start\n";
				}
				else{
					Node* nextNode = ptr->next;
					Node* prevNode = ptr->previous;
					if(nextNode == NULL){
						prevNode->next = NULL;
						cout<<"Node deleted in the end\n";
					}
					else{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout<<"Node deleted in between the list\n";
					}
				}
			}
		}
		
		//6. Updating the node in the list
		void update(int k, int d){
			Node* ptr = checkNode(k);
			if(ptr==NULL){
				cout<<"Node doesnot exist\n";
			}
			else{
				ptr->data = d;
				cout<<"Node updated\n";
			}
		}
		
		// 7. Printing the list
		void printing(){
			if(head == NULL){
				cout<<"List is empty\n";
			}
			else{
				Node* ptr = head;
				cout<<"( ";
				while(ptr!=NULL){
					cout<<ptr->data<<" , "<<ptr->key<<" <--> ";
					ptr = ptr->next;
				}
				cout<<" )";
			}
			cout<<endl;
		}
};


int main(){
	DoubleLinkedList obj;
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
    cout << "7. Clear Screen" << endl << endl;

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
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      obj.insertNode(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNode(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.update(key1, data1);

      break;
    case 6:
      obj.printing();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
	return 0;
}
