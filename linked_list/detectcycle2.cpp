#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode *slow=head;
	ListNode* fast=head;
	if(head==NULL){
		return NULL;
	}
	if(slow->next==NULL){
		return NULL;
	}
	while(slow!=NULL && fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;

		if(slow==fast){
            slow=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
		}
        
	}
	return NULL; 
    }
};