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

node* reverseList(node* &head,int k){
	node* prev=NULL;
	node* curr=head;
	node* nextp;
	int count=0; 
	while(curr!=NULL && count<k){
		nextp=curr->next;
		curr->next=prev;
		
		prev=curr;
		curr=nextp;
		
		count++;
	}
	if(nextp!=NULL){
		head->next = reverseList(nextp,k);
	}
	
	return prev;
}

int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,5);
	insertAtTail(head,9);
	insertAtTail(head,8);
	insertAtTail(head,7);
	insertAtTail(head,6);
	insertAtTail(head,4);
	insertAtTail(head,0);
	insertAtTail(head,3);
	display(head);
	
	int k=3;
	node*newhead=reverseList(head,k);
	display(newhead);
	
	return 0;
}