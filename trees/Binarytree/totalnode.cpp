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

void Printleaf(node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    Printleaf(root->left);
    Printleaf(root->right);

}

int main(){
    node*root=NULL;
    root=create(root);
    cout<<"printing leaf node: "<<endl;
    Printleaf(root);

}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1