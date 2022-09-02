/*
fast pointer=m+n+ l*j
slow pointer=m+n+ l*i
fast= 2*slow
m+n+ L*j = 2(m+n+ l*i)
m+n =l(j- 2*i)
*/

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

void makeCycle(node* &head,int pos){
	node* temp=head;
	node* startNode;
	int count=0;
	while(temp->next!=NULL){
		if(count==pos){
			startNode=temp;
		}
		temp= temp->next;
		count++;
	}
	
	temp->next=startNode;
}

void removeCycle(node* &head){
	node* fast=head;
	node* slow=head;
	
	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);
	
	fast=head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	
	slow->next=NULL;
}

bool circular(node* &head){
	node* fast=head;
	node* slow=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}

int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,5);
	insertAtTail(head,8);
	insertAtTail(head,9);
	display(head);
	makeCycle(head,4);
//	display(head);
	cout<<circular(head)<<endl;
	
	//remove cycle
	removeCycle(head);
	cout<<circular(head);
	return 0;
}
