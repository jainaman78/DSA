#include<bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int>q;
    for(int i=0;i<k;i++){
        q.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<=q.top()){
           q.pop();
           q.push(arr[i]); 
        }
    }
    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}