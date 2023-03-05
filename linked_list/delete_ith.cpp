#include<bits/stdc++.h>
using namespace std;

//node class

class node{
    public:
    int data;
    node* next;

    node (int data){
        this->data=data;
        next=NULL;
    }
};

//print
void print(node* head){
    node*temp=head;
    cout<<head->data<<endl;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

//insertion input

node* takeinput(){
    int data;
    cin>>data;
    node *head=NULL;
    while(data!=-1){
        node* newnode=new node(data);
        if(head==NULL){
            head=newnode;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        cin>>data;

    }
    return head;
}
// delete ith

node *deleteNode(node *head, int pos)
{
	if(head==NULL){
		return head;
	}
    if(pos==0){
		node* t=head;
		head=head->next;
		return head;
		delete t;
	}

	node* temp=head;
	int c=0;
	while(temp!=NULL && c<pos-1){
		temp=temp->next;
		c++;
	}
	if(temp!=NULL && temp->next!=NULL){
		node*de = temp->next;
		temp->next=temp->next->next;
		delete de;
	}
	
	return head;
}

int main(){
    node* head=takeinput();
    print(head);

}