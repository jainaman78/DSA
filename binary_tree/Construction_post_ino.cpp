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
    TreeNode* solve(vector<int> in,vector<int>post,int &index,int inorderstart,int inorderend,int n){
            if(index<0 || inorderstart>inorderend){
                return {};
            }
            int element=post[index--];
            TreeNode* root=new TreeNode(element);
            int position=findposition(in,element,n);
            root->right=solve(in,post,index,position+1,inorderend,n);
            root->left=solve(in,post,index,inorderstart,position-1,n);
            return root;

        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int index=n-1;
        TreeNode*ans=solve(inorder,postorder,index,0,n-1,n);
        return ans;
    }
};