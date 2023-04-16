//stack using  linked list
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        next=NULL;
    }
};

class stack{
    node* head;
    int size;
    public:
    stack(){
        head=NULL;
        size=0;
    }

    int size(){
        return size;
    }

    bool empty(){
        return size==0;
    }

    void push(int dt){
        node* newnode = new node(dt);
        if(head==NULL){
            head=newnode;
            size++;
            return;
        }
        newnode->next=head;
        head=newnode;
        size++;
        return;
    }
    int pop(){
        if(head==NULL){
            return -1;
        }
        int temp=head ->data;
        head=head->next;
        size--;
        return temp;
    }
    int top(){
        if(head==NULL){
            return -1;
        }
        return head->data;
    }
};
