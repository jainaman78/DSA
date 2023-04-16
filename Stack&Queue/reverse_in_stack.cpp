#include<bits/stdc++.h>
using namespace std;

#include <stack>

string reverse(string str) 
{
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{'||str[i]=='['){
            s.push(str[i]);
            continue;
        }
    }
    string ans;
    while (!s.empty()){
        char c=s.top();
        ans.push_back(c);
        s.pop();
    }
    return ans;
    
}            