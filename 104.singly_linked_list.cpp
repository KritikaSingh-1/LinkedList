//singly linked list operation
//1.appendNode()
//2.prependNode()
//3.insertNodeAfter()
//4.deleteNodeBykey()
//5.updateNodeByKey()
//6.print()

#include<iostream>
using namespace std;

class node{
	public:
		int key;
		int data;
		node* next;
		node(){
			key=0;
			data=0;
			next=NULL;
		}
		node(int k,int d){
			key=k;
			data=d;
		}
};

class singlyLinkedList{
	public:
		node* head;
		singlyLinkedList()
		{
			head=NULL;
		}
		singlyLinkedList(node *n)
		{
			head=n;
		}
		//1.check if node exist using key value
		node* nodeExist(int k){
		
			node* ptr=head;
			while(ptr!=NULL){
				if(ptr->key==k){
					return ptr;
				}
				ptr=ptr->next;
			}
			return ptr;
		}
		//2. append a node to the list
		void appendNode(node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"node already exist with key value:"<<n->key<<". Append another node with different key value"<<endl;
			}
			else{
				if(head==NULL){
					head=n;
					cout<<"node appended"<<endl;
				}
				else{
					node* ptr=head;
					
					while(ptr->next!=NULL){
			        	ptr=ptr->next;
		        	}
		        	ptr->next=n;
		        	cout<<"node appended"<<endl;
			
				}
			}
		}
		
		//prepend node- node at the start
		void prependNode(node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"node already exist with key value:"<<n->key<<". Prepend another node with different key value"<<endl;
			}
			else{
				n->next=head;
				head=n;
				cout<<"node prepended";
			}
		}
		
		//4.inset a node after a particular node in the list
		void insertNodeafter(int k,node* n){
			node* ptr=nodeExist(k);
			if(ptr==NULL){
				cout<<"no node exist with key value:"<<k<<endl;
			}
			else{
				if(nodeExist(n->key)!=NULL){
				    cout<<"node already exist with key value:"<<n->key<<". append another node with different key value"<<endl;
		     	}
		     	else{
		     		n->next=ptr->next;
		     		ptr->next=n;
		     		cout<<"node inserted"<<endl;
				 }
			}
		}
		//5.delete node by unique key
		void deleteNodeByKey(int k){
			if(head==NULL){
				cout<<"singly linked list already empty. Can't delete"<<endl;
			}
			else if(head!=NULL){
				if(head->key==k){
					head=head->next;
					cout<<"node unlinked with keys value:"<<k<<endl;
				}
				else{
					node* ptr=head;
					node* temp=NULL;
					while((ptr->next)!=NULL)
					{
					   if(ptr->next->key==k){
					   	    temp=ptr->next;
					   	    ptr->next=NULL;    
					   }
						else{
							ptr=ptr->next;	
						}			
					}
					if(temp!=NULL)
					{
					    ptr->next=temp->next;	
						cout<<"node deleted";
						temp=NULL;
					}
					else{
						cout<<"node not exist";
					}
					
				}
			}
		}
		
		//6. update node
		void updateNodeByKey(int k,int d){
			node* ptr=nodeExist(k);
			if(ptr!=NULL){
				ptr->data=d;
				cout<<"node data update successfully"<<endl;
			}
			else{
				cout<<"Node doesn't exist with key value:"<<k<<endl;
			}
		}
		
		//7.printing
		void printList(){
			if(head==NULL){
				cout<<"no nodes in singly linked list";
			}
			else{
				cout<<endl<<"singly linked lst values:";
				node* temp=head;
				
				while(temp!=NULL){
					cout<<"("<<temp->key<<","<<temp->data<<") -->";
					temp=temp->next;
				}
			}
		}
};

int main(){
	singlyLinkedList s;
	int option;
	int key1,k1,data1;
	do{
		cout<<"\nWhat operation do you want to perform ? Select option nu,ber. Enter 0 to exit."<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insetNodeAfter()"<<endl;
		cout<<"4. deleteNodeByKey()"<<endl;
		cout<<"5. updateNodeByKey()"<<endl;
		cout<<"6. print()"<<endl;
		cout<<"7. clear screen"<<endl<<endl;
		
		cin>>option;
		node* n1=new node();
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				cout<<"Append node operation \nEnter key and data of the node to be append"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				//cout<<n1.key<<"  "<<n1.data<<endl;
				break;
				
			case 2:
			    cout<<"prepend node operation \nEnter the key and data of the node to be prepended"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
				
			case 3:
			    cout<<"Insert node fter operation \nEnter key of existing node after which you want to insert this new node:"<<endl;
				cin>>k1;
				cout<<"Enter key and data of the new node first:"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.insertNodeafter(k1,n1);		
				break;
				
			case 4:
			    cout<<"delete node by key operation - \nEnter key of the node to be deleted:"<<endl;
			    cin>>k1;
			    s.deleteNodeByKey(k1);
			    break;
			    
			case 5:
			    cout<<"Update node by key operation-\n Enter key and new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNodeByKey(key1,data1);		
			    break;
					
			case 6:
			    s.printList();
				break;
				
			case 7:
			    system("cls");
				break;
				
			default:
			    cout<<"enter proper option number"<<endl;		    	
		}
	}while(option!=0);
	return 0;
}
