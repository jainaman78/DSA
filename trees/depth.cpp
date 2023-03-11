#include<bits/stdc++.h>

using namespace std;
template<typename t>
class treenode{
    public:
    t data;
    vector<treenode<t>*> children;

    treenode(t data){
        this->data=data;
    }
};

//inputlevel

treenode<int>* inputlevel(){
    int rootdata;
    cout<<"enter rootdata:"<<endl;
    treenode<int>* root= new treenode<int>(rootdata);
    queue<treenode<int>*> pending;
    pending.push(root);

    while(pending.size()!=0){
        treenode<int>* front=pending.front();
        pending.pop();
        cout<<"enter no of children of:"<<front->data<<endl;

        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int child;
            cout<<"enter "<<i<<"th children"<<endl;
            cin>>child;
            treenode<int>* childr=new treenode<int>(child);
            front->children.push_back(childr);
            pending.push(childr);
        }
    }
}



//printlevel
void printtree(treenode<int>* root) {
    queue<treenode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        treenode<int>* front=pending.front();
        pending.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            if(i<(front->children.size()-1)){
                cout<<front->children[i]->data<<",";
            }
            else{
                cout<<front->children[i]->data;
            }
            pending.push(front->children[i]);
        }
        cout<<endl;
    }
}
//depth

void depth(treenode<int>*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }

    for(int i=0;i<(root->children.size());i++){
        depth(root->children[i],k-1);
    }
}
//count leaf node

int leaf(treenode<int>*root){
    int l=0;
    for(int i=0;i<(root->children.size());i++){
        l+=leaf(root->children[i]);
    }
    if(l==0){
        return l+1;
    }
    return l;
}

int main(){
    treenode<int>* root=inputlevel();
    printtree(root);
    return 0;
}