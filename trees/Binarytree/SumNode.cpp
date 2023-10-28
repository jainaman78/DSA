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

int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
}

int main(){
    node*root=NULL;
    root=create(root);
    cout<<"printing"<<endl;
    cout<<sum(root);
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1