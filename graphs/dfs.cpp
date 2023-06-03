#include<bits/stdc++.h>
using namespace std;
void prints(int **edges,int n,int sv,bool*visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            prints(edges,n,i,visited);
        }
    }
}

int main(){
    int n,e;
    cout<<"enter vertices and edges:";
    cin>>n>>e;
    cout<<endl;
    int **edges=new int*[n];

    for (int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    cout<<"enter edges"<<endl;
    for(int i=0;i<e;i++){
        int f,s;
        cout<<"enter first and second:";
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            prints(edges, n, i, visited);
    }

}
