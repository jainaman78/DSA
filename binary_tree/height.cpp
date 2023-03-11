#include<bits/stdc++.h>
using namespace std;
template<typename t>
class binary_tree{
    public:
    t data;
    binary_tree* left;
    binary_tree* right;

    binary_tree( t data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~binary_tree(){
        delete left;
        delete right;
    }

};

binary_tree<int>* takeinput(){
    int rootdata;
    cout<<"enter root:"<<endl;
    cin>>rootdata;

    binary_tree<int>* root=new binary_tree<int>(rootdata);
    queue<binary_tree<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        binary_tree<int>*front=pending.front();
        pending.pop();
        cout<<"enter left child of:"<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            binary_tree<int>* child=new binary_tree<int>(leftchild);
            front->left=child;
            pending.push(child);
        }
        cout<<"enter right child of:"<<front->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            binary_tree<int>* child=new binary_tree<int>(rightchild);
            front->right=child;
            pending.push(child);
        }

    }
    return root;

}

//print level wise
void printlevel(binary_tree<int>* root){
    if(root==NULL){
        return;

    }
    queue<binary_tree<int>*> pending;
    pending.push(root);

    while(pending.size()!=NULL){
        binary_tree<int>* front=pending.front();
        pending.pop();
        cout<<front->data;

        if(front->left!=NULL){
            cout<<front->left->data;
            pending.push(front->left);
        }
        if(front->right!=NULL){
            cout<<front->right->data;
            pending.push(front->right);
        }
    }
}

//height
int height(binary_tree<int> * root) {
    int h = 0;
    if (root == NULL)
      return h;

    int lefth = height(root->left);
    int righth = height(root->right);

    if (lefth > righth)
      return lefth + 1;
    else
      return righth + 1;

  // Write our code here
}