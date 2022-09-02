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

node* merge(node* &head1,node* &head2){
	node* p1=head1;
	node* p2=head2;
	node* dummy=new node(-1);
	
	node* p3=dummy;
	
	while(p1!=NULL && p2!=NULL){
		
		if(p1->data<p2->data){
			p3->next=p1;
			p1=p1->next;
		}
		else{
			p3->next=p2;
			p2=p2->next;
		}
		
		p3=p3->next;
		
	}
	while(p1!=NULL){
		p3->next=p1;
		p1=p1->next;
		p3=p3->next;
	}
	
	while(p2!=NULL){
		p3->next=p2;
		p2=p2->next;
		p3=p3->next;
	}
	
	return dummy->next;
}

node* mergeRecursive(node* &head1,node* &head2){
	
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	
	node* result;
	if(head1->data<head2->data){
		result=head1;
		result->next=mergeRecursive(head1->next,head2);
	}
	
	else{
		result=head2;
		result->next=mergeRecursive(head1,head2->next);
	}
	
	return result;
}
int main(){
	node* head1=NULL;
	insertAtTail(head1,1);
	insertAtTail(head1,2);
	insertAtTail(head1,3);
//	insertAtHead(head1,5);
	display(head1);
	
	node* head2=NULL;
	insertAtTail(head2,1);
	insertAtTail(head2,2);
	insertAtTail(head2,4);
//	insertAtHead(head2,);
	display(head2);
    
//    node* newHead=merge(head1,head2);
     node* newHead=mergeRecursive(head1,head2);
    display(newHead);
	return 0;
}