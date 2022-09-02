#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* previous;
	
	node(int val){
		next=NULL;
		previous=NULL;
		data=val;
	}
};

void insertAtHead(node* &head,int val){
	node* n=new node(val);
	n->next=head;
	if(head!=NULL){
		head->previous=n;
	}

	head=n;
}

void insertAtTail(node* &head,int val){
	if(head==NULL){
		insertAtHead(head,val);
		return;
	}
	
	node* n=new node(val);
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->previous=temp;
}

void deleteAtHead(node* &head){
	node* temp=head;
	head=head->next;
	head->previous=NULL;
	
	delete temp;
}

void deletion(node* &head,int pos){
	if(pos==1){
		deleteAtHead(head);
		return;
	}
	
	node* temp=head;
	int count=1;
	while(temp!=NULL && count!=pos){
		temp=temp->next;
		count++;
	}
	
	temp->previous->next=temp->next;
	if(temp->next!=NULL){
		temp->next->previous=temp->previous;
	}

	
	delete temp;
}

void display(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
	node* head = NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,2);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtHead(head,6);
	display(head);
	deletion(head,6);
	display(head);
	return 0;
}