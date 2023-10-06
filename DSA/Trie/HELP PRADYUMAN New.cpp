#include <bits/stdc++.h>
using namespace std;

class trieNode{
  public:
    
    trieNode** children;
    bool isEnd;
    trieNode(){
        children = new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

void insert(string s,trieNode* head){
    if(s.size() == 0){
        head->isEnd = true;
        return;
    }
    trieNode* curr = head;
    int index = s[0] - 'a';
    if(!curr->children[index]){
        curr->children[index] = new trieNode();
    }
    curr = curr->children[index];
    insert(s.substr(1),curr);
}


void DFS(trieNode* head,string s){
    if(head->isEnd){
        cout<<s<<endl;
    }
    
    trieNode* curr = head;
    
    for(int i=0;i<26;i++){
        if(curr->children[i]){
            s.push_back('a' + i);
            DFS(curr->children[i],s);
            s.pop_back();
        }
    }
}

void query(string s,trieNode* head){
    trieNode* curr = head;
    
    for(int i=0;i<s.length();i++){
        int index = s[i] - 'a';
        if(!curr->children[index]){
            cout<<"No suggestions"<<endl;
            insert(s,head);
            return;
        }
        curr = curr->children[index];
    }
    
    DFS(curr,s);
}

int main()
{
    int n;
    cin>>n;
    
    trieNode* head = new trieNode();
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(s,head);
    }
    
    int q;
    cin>>q;
    
    while(q--){
        string s;
        cin>>s;
        query(s,head);
    }
    return 0;
}

