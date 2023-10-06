#include <bits/stdc++.h>
using namespace std;

class trieNode{
  public:
    trieNode** children;
    int val;
    
    trieNode(){
        children = new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        val = INT_MIN;
    }
};

void insert(trieNode* head,string s,int val){
    if(s.size() == 0){
        return;
    }
    trieNode* curr = head;
    int idx = s[0] - 'a';
    if(!curr->children[idx]){
        curr->children[idx] = new trieNode();
    }
    curr = curr->children[idx];
    if(curr->val < val){
        curr->val = val;
    }
    
    insert(curr,s.substr(1),val);
}

int query(string s,trieNode* head){
    trieNode* curr = head;
    
    for(int i=0;i<s.length();i++){
        int idx = s[i] - 'a';
    	if(!curr->children[idx]){
            return -1;
        }
        curr = curr->children[idx];
    }
    return curr->val;
}

int main()
{
    int n,q;
    cin>>n>>q;
    
    trieNode* head = new trieNode();
    
    for(int i=0;i<n;i++){
        string s;
        int val;
        
        cin>>s>>val;
        
        insert(head,s,val);
    }
    
    while(q--){
    	
        string s;
        cin>>s;
        cout<<query(s,head)<<endl;
        
    }
    
    return 0;
}

