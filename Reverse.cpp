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

node* reverseList(node* &head){
	node* prev=NULL;
	node* curr=head;
	node* nextp;
	
	while(curr!=NULL){
		nextp=curr->next;
		curr->next=prev;
		
		prev=curr;
		curr=nextp;
		
		
	}
	
	return prev;
}

node* reverseRecursive(node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* newhead=reverseRecursive(head->next);
	head->next->next=head;
	head->next=NULL;
	
	return newhead;
}

int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,5);
	
	display(head);
	
//	node* newHead=reverseList(head);
	//display(newHead);
	 
	node* newHea=reverseRecursive(head);
	display(newHea);
	
	return 0;
}