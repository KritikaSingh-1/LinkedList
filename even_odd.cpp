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

void evenAfterOdd(node* &head){
	node* odd=head;
	node* even=head->next;
	node*evenStart=even;
	while(odd->next!=NULL && even->next!=NULL){
		odd->next=even->next;
		odd=odd->next;
		
		even->next=odd->next;
		even=even->next;
	}
	odd->next=evenStart;
	if(odd->next!=NULL){
		even->next=NULL;
	}
	
}

int main(){
	node* head=NULL;
	insertAtTail(head,7);
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtTail(head,6);
	insertAtTail(head,8);
	insertAtTail(head,9);
	insertAtHead(head,5);
	display(head);

	evenAfterOdd(head);
	display(head);
	return 0;
}