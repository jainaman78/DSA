#include<bits/stdc++.h>
using namespace std;

#include <stack>

bool isBalanced(string str) 
{
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{'||str[i]=='['){
            s.push(str[i]);
            continue;
        }

        if(s.empty())
            return false;
        char c;
        
        switch(str[i]) {
            case ')' : c = s.top();
                	   s.pop();
                	   if(c == '}' or c == ']')
                         return false;
                	   break;
            case '}' : c = s.top();
                	   s.pop();
                	   if(c == ')' or c == ']')
                         return false;
                	   break;   
                
            case ']' : c = s.top();
                	   s.pop();
                	   if(c == ')' or c == '}')
                         return false;
                	   break;  
        }
    }
    
   return s.empty(); 
}