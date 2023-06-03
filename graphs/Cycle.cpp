#include<bits/stdc++.h>
using namespace std;

//love babbar adjacency list
class graph{
    public:
    unordered_map<int,list<int>> adj;
    void add(int u,int v, bool direction){
        //directiom=0 undirected
        //directiom=1 directed

        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
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

