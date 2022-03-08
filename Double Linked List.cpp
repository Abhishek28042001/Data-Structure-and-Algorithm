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
	cout<<"Menu\n"<<"1. To check whether node exist in the list or not./n"<<"2. To append a node.\n"<<"3. To Prepend a noded in the list./n"<<"4. To insert a node in the list.\n"<<"5. To delete a node in the list.\n"<<"6. To Update a node.\n7. To print the list.\n";
	
	return 0;
}
