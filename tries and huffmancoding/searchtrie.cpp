#include <bits/stdc++.h>
#include<string.h>
using namespace std;
class Trienode{
    public:
    char data;
    Trienode ** children;
    bool isTerminal;
    
    Trienode(char data){
        this->data=data;
        children=new Trienode*[26];
        for (int i = 0; i <26; i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
        
    }
};

class Trie{
    Trienode *root;
    Trie(){
        root=new Trienode('\0');
    }
    void insertword(Trienode* root,string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        insertword(child,word.substr(1));
    }
    void insertword(string word){
        insertword(root,word);
    }
    bool searchtrie(Trienode*root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }

    int index=word[0]-'a';
    Trienode*child;
    if(root->children[index]!=NULL){
        child=root->children[index];
        return searchtrie(child,word.substr(1));

    }
    else{
        return false;
    }
}

bool search(string word) {
    return searchtrie(this->root,word);
}
};




