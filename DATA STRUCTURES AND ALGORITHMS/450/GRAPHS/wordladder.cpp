class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> word;
        int n = wordList.size();
        for(auto i=0;i<n;i++){
            word.insert(wordList[i]);
        }
        queue <string> q;
        q.push(beginWord);
        map <string,int> dist;
        dist[beginWord] = 1;
        word.erase(beginWord);
        while(!q.empty()){
            string cur = q.front();
            if(cur==endWord)
                return dist[cur];
            q.pop();
            int m = cur.length();
            string s = cur;
            for(auto i=0;i<m;i++){
                for(char j='a';j<='z';j++){
                    s[i] = j;
                    if(word.find(s)!=word.end()){
                        q.push(s);
                        word.erase(s);
                        dist[s] = dist[cur]+1;
                    }
                }
                s[i] = cur[i];
            }
        }
        return 0;
    }
};




