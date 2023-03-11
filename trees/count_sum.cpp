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

//count

int count(treenode<int>* root){
    int c=1;
    for(int i=0;i<(root->children.size());i++){
        c=c+count(root->children[i]);
    }
    return c;
}

//sum
int sumOfNodes(treenode<int>* root) {
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum=sum+sumOfNodes(root->children[i]);

    }
    return sum;
}

//max
treenode<int> *maxDataNode(treenode<int> *root) {

  treenode<int> *max = new treenode<int>(root->data);

  for (int i = 0; i < root->children.size(); i++) {
    treenode<int> *child = maxDataNode(root->children[i]);
    if (child->data > max->data)
      max = child;
  }

  return max;
}


int main(){
    treenode<int>* root=inputlevel();
    printtree(root);
    return 0;
}