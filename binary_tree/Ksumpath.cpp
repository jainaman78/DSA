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
    void solve(TreeNode* root,int &c,int k, vector<int>path){
        if(root==NULL){
            return ;
        }
        path.push_back(root->val);
        solve(root->left,c,k,path);
        solve(root->right,c,k,path);

        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==k){
                c++;
            }
        }
        path.pop_back();

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int c=0;
        solve(root,c,targetSum,path);
        if(c>0){
            return true;
        }
        else{
            return false;
        }

    }
};