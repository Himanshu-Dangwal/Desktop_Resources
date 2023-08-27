int query(string s,trieNode *root){
    trieNode *curr = root;
    int best_weight = -1;
    for(int i=0;i<s.length();i++){
        int index = s[i] - 'a';
        trieNode *child = curr->children[index];
        if(child){
            curr = child;
            best_weight = child->weight;
        }else{
            return -1;
        }
    }
    return best_weight;
}
