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

void display(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

int length(node* head){
	int l=0;
	while(head!=NULL){
		l++;
		head=head->next;
	}
	return l;
}

void kAppend(node* &head,int k){
	int c=length(head);
	
	node* newHead;
	node* newTail;
	node* tail=head;
	int r=1;
	while(tail->next!=NULL){
		
		if(r==(c-k)){
			newTail=tail;
			newHead=tail->next;
		}
		r++;
		tail=tail->next;
	}
	
	newTail->next=NULL;
	tail->next=head;
	head=newHead;
}

int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,5);
	display(head);
	kAppend(head,2);
	display(head);
	return 0;
}