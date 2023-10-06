class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words;
        for(int i=0;i<wordList.size();i++){
            words.insert(wordList[i]);
        }
        
        if(words.find(endWord) == words.end())
            return 0;
        
        int len = 0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            
            len++;
            int qlen = q.size();
            for(int i=0;i<qlen;i++){
                string s = q.front();
                q.pop();
                
                // cout<<s<<" "<<len<<endl;
                
                for(int j=0;j<beginWord.size();j++){
                    char retrieve = s[j];
                    for(char ch = 'a';ch<='z';ch++){
                        s[j] = ch;
                        if(words.find(s) == words.end())
                            continue;
                        if(s == endWord)
                            return len+1;
                        q.push(s);
                        words.erase(s);
                    }
                    s[j] = retrieve;
                }
                
            }
            
        }
    
    return 0;    
    }
};
