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
    //delete from destructor
    ~treenode(){
        for(int i=0;i<childre.size();i++){
            delete children[i];
        }
    }
};

//input

treenode<int>* takeinput(){
    int rootdata;
    cout<<"enter data:"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);

    int n;
    cout<<"enter number of children"<<" ";
    cin>>n;
    for(int i=0;i<n;i++){
       treenode<int>* child= takeinput();
       root->children.push_back(child);

    }
    return root;
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
    treenode<int>* root=takeinput();
    printtree(root);
    delete root;
    return 0;
}