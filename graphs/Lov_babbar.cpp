#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;
    void add(int u,int v, bool direction){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"enter number of nodes=";
    cin>>n;
    int m;
    cout<<"enter number of edges=";
    cin>>m;
    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.add(u,v,0);
    }

    g.print();
    return 0;
}
// 1-> 2,3
// 2->3,4


/*
Pointer
array
OOPS pillar 4
linkedlist 
complexity
for(i=0;i<n/2;i++)------->O(logn)

*/
/*
int arr[4]={1,2,3,4};
for (int i=0;i<n;i++){
arr[i];
}


*/