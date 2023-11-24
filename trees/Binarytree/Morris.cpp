#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node (int dt){
        this->data=dt;
        this->left=NULL;
        this->right=NULL;
    }
};

node* create(node* root){
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter left data "<<endl;
    root->left=create(root->left);
    cout<<"Enter Right data "<<endl;
    root->right=create(root->right);
    return root;
}

void Morris(node* root){
    node* curr;
    node* pre;
    if(root==NULL){
        return;
    }
    curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }

}

int main(){
    node*root=NULL;
    root=create(root);
    cout<<"printing Morris Traversal"<<endl;
    Morris(root);

}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1