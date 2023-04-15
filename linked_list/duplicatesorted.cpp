#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if (head==NULL){
           return head;
       }

       ListNode* temp=head;
       while(temp!=NULL){
           if((temp->next!=NULL)&& temp->val == temp->next->val){
               ListNode*cur=temp->next->next;
               ListNode * del=temp->next;
               delete(del);
               temp->next=cur;
           }
           else{
               temp=temp->next;
           }
       } 
       return head; 
    }
};