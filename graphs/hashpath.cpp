#include <iostream>
#include <queue>
using namespace std;
bool hashpath(int **edges,int n,int v1,int v2,bool*visited){
    if(v1>=n||v2>=n){
        return false;
    }
    if(v1==v2){
        return true;
    }
    if(edges[v1][v2]==1||edges[v2][v1]==1){
        return true;
    }

    queue<int> pending;
    pending.push(v1);
    visited[v1]=true;
    while(!pending.empty()){
        int current=pending.front();
        cout<<current<<" ";
        pending.pop();
        for(int i=0;i<n;i++){
            if(i==current){
                continue;
            }
            if(visited[i]){
                continue;
            }
            if((edges[current][i]==1)&&(!visited[i])){
                pending.push(i);
                visited[i]=true;
            }
    
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
    int v1, v2;
    cin >> v1 >> v2;
    if (hashpath(edges, n, v1, v2,visited))
        cout << "true";
    else
        cout << "false";
    return 0;
}
