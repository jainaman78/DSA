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
    cout<<"Head:"<<" ";
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

//length
int length(node *head)
{
    node*temp=head;
	int c=0;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}


int main(){
    node* head=takeinput();
    print(head);
    int l;
    l=length(head);
    cout<<"length is:"<<l;
}