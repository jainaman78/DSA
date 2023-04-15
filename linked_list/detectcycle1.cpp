#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
    ListNode *slow=head;
	ListNode* fast=head;
	if(head==NULL){
		return false;
	}
	if(slow->next==NULL){
		return false;
	}
	while(slow!=NULL && fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;

		if(slow==fast){
			return true;
		}
	}
	return false;  
    }
};