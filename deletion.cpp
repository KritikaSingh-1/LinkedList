#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data=val;
			next=NULL;
		}
};

void insertAtHead(node* &head,int val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	n->next=head;
	head=n;
	return;
}

void insertAtTail(node* &head , int val){
	node* n = new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	return;
}

void deletion(node* &head,int val){
	node* temp=head;
	if(head==NULL){
		return;
	}
	if(head->data==val){
		node* deleten=head;
		head=head->next;
		delete deleten;
		return;
	}
	while(temp->next!=NULL){
		if(temp->next->data==val){
			node* deleten=temp->next;
			temp->next=temp->next->next;
			delete deleten;
			return;
		}
		temp=temp->next;
	}
	cout<<"key not found"<<endl;
}

void display(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}



int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,5);
	
	deletion(head,5);
	display(head);
	
	return 0;
}