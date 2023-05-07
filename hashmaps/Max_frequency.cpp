#include<bits/stdc++.h>
#include<unordered_map>
int highestFrequency(int arr[], int n) {
    unordered_map<int,int> seen;
    for(int i=0;i<n;i++){
        seen[arr[i]]++;    
    }
    int key=0,value=0;
    for (int i = 0; i < n; i++){
        if(seen[arr[i]]>value){
            key=arr[i];
            value=seen[arr[i]];
        }
    }
      return key;
}