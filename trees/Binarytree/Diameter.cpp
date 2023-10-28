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

void levelorder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=
}

int main(){
    node*root=NULL;
    root=create(root);
    cout<<"printing"<<endl;
    levelorder(root);

}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1