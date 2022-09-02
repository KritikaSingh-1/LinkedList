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

void intersect(node* &head,node* &head2,int pos){
	node* temp=head;
	pos--;
	while(pos--){
		temp=temp->next;
	}
	node* temp2=head2;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=temp;
}

int length(node* head){
	int l=0;
	while(head!=NULL){
		l++;
		head=head->next;
	}
	return l;
}
int intersection(node* &head,node* &head2){
	int f=length(head);
	int s=length(head2);
	int c=0;
	node* temp;
	node* temp2;
	if(f>s){
		c=f-s;
		temp=head;
		temp2=head2;
		
   }
	
	else{
		c=s-f;
		temp=head2;
		temp2=head;
		
	}
		while(c!=0){
			temp=temp->next;
			if(temp==NULL){
				return -1;
			}
			
			c--;
		}
		while(temp!=NULL && temp2!=NULL){
			if(temp==temp2){
				
				return temp->data;
			}
			temp=temp->next;
			temp2=temp2->next;
			
		}
	
	return -1;
}

int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,5);
	insertAtHead(head,7);
	insertAtHead(head,8);
	display(head);
	
	node* head2=NULL;
	insertAtTail(head2,1);
	insertAtTail(head2,2);
	insertAtTail(head2,7);
	insertAtHead(head2,8);
	display(head2);
	intersect(head,head2,3);
	cout<<intersection(head,head2);
	return 0;
}