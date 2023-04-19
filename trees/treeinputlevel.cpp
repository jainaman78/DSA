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


//print
void printtree(treenode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";

    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printtree(root->children[i]);
    }

}
int main(){
    treenode<int>* root=inputlevel();
    printtree(root);
    return 0;
}