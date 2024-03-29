#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        bool condition=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>res(size);
            for(int i=0;i<size;i++){
                TreeNode*front=q.front();
                q.pop();
                int index=condition?i:size-i-1;
                res[index]=front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            condition=!condition;
            ans.push_back(res);
        }
        return ans;

    }
};