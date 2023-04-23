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
    int findposition(vector<int>in,int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }

        }
        return -1;
    }
    TreeNode* solve(vector<int> in,vector<int>pre,int &index,int inorderstart,int inorderend,int n){
        if(index>=n || inorderstart>inorderend){
            return {};
        }
        int element=pre[index++];
        TreeNode* root=new TreeNode(element);
        int position=findposition(in,element,n);
        root->left=solve(in,pre,index,inorderstart,position-1,n);
        root->right=solve(in,pre,index,position+1,inorderend,n);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=inorder.size();
        TreeNode*ans=solve(inorder,preorder,index,0,n-1,n);
        return ans;
    }
};