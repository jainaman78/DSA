//leetcode 215

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        int ans=q.top();
        return ans;
    }
};