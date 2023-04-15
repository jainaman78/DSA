#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

  class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node*cur=head;
        while(cur!=NULL){
            Node *temp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=temp;
            cur=temp;
        }
        cur=head;

        while(cur!=NULL){
            if(cur!=NULL){
                cur->next->random=(cur->random!=NULL)? cur->random->next:NULL;
            }
            cur=cur->next->next;
        }

        Node*orig=head;
        Node*copy=head->next;
        Node*temp=copy;

        while(orig!=NULL && copy!=NULL){
            orig->next=copy->next;
            orig=orig->next;
            if(orig!=NULL){
                copy->next=orig->next;    
            }
            
            copy=copy->next;
        }
        return temp;
    }
};