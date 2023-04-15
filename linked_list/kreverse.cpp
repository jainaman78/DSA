#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL ){
            return NULL;
        }
        

        ListNode * next=NULL;
        ListNode* cur=head;
        ListNode* prev=NULL;
        int c=0;
        while(c<k && cur!=NULL ){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            c++;
        }
        if (c < k) {
            ListNode* temp = NULL;
            while (c > 0) {
                temp = prev->next;
                prev->next = cur;
                cur = prev;
                prev = temp;
                c--;
            }
            return cur;
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }

        return prev;

    }
};